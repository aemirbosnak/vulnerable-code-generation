//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <ctype.h>
#include <sys/stat.h>

#define BUFSIZE 8192

enum ftp_mode { FTP_ASCII, FTP_BINARY };

struct ftp_conn {
    int control_sock;
    int data_sock;
    char* hostname;
    char* username;
    char* password;
    enum ftp_mode mode;
};

int ftp_connect(struct ftp_conn* conn);
int ftp_login(struct ftp_conn* conn);
int ftp_pasv(struct ftp_conn* conn);
int ftp_send_cmd(struct ftp_conn* conn, const char* cmd, const char* arg);
int ftp_recv_resp(struct ftp_conn* conn, char* buf, int len);
int ftp_upload(struct ftp_conn* conn, const char* local_fname, const char* remote_fname);
int ftp_download(struct ftp_conn* conn, const char* remote_fname, const char* local_fname);
int ftp_disconnect(struct ftp_conn* conn);

int main(int argc, char* argv[]) {
    struct ftp_conn conn = {
        .control_sock = -1,
        .data_sock = -1,
        .hostname = argv[1],
        .username = argv[2],
        .password = argv[3],
        .mode = FTP_BINARY,
    };
    if (argc != 5) {
        fprintf(stderr, "Usage: %s HOST USERNAME PASSWORD FILENAME\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (ftp_connect(&conn) != 0) {
        fprintf(stderr, "Failed to connect\n");
        return EXIT_FAILURE;
    }
    if (ftp_login(&conn) != 0) {
        fprintf(stderr, "Failed to login\n");
        return EXIT_FAILURE;
    }
    if (ftp_pasv(&conn) != 0) {
        fprintf(stderr, "Failed to enter passive mode\n");
        return EXIT_FAILURE;
    }
    if (ftp_upload(&conn, argv[4], argv[4]) != 0) {
        fprintf(stderr, "Failed to upload file\n");
        return EXIT_FAILURE;
    }
    if (ftp_disconnect(&conn) != 0) {
        fprintf(stderr, "Failed to disconnect\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int ftp_connect(struct ftp_conn* conn) {
    struct hostent* he = gethostbyname(conn->hostname);
    if (he == NULL) {
        return -1;
    }
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(21),
    };
    memcpy(&addr.sin_addr, he->h_addr, he->h_length);
    conn->control_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(conn->control_sock, (struct sockaddr*)&addr, sizeof(addr)) != 0) {
        return -1;
    }
    char buf[BUFSIZE];
    if (ftp_recv_resp(conn, buf, sizeof(buf)) != 220) {
        return -1;
    }
    return 0;
}

int ftp_login(struct ftp_conn* conn) {
    char buf[BUFSIZE];
    if (ftp_send_cmd(conn, "USER", conn->username) != 331) {
        return -1;
    }
    if (ftp_send_cmd(conn, "PASS", conn->password) != 230) {
        return -1;
    }
    return 0;
}

int ftp_pasv(struct ftp_conn* conn) {
    char buf[BUFSIZE];
    if (ftp_send_cmd(conn, "PASV", "") != 227) {
        return -1;
    }
    int a, b, c, d, port;
    sscanf(strchr(buf, '(') + 1, "%d,%d,%d,%d,%d,%d", &a, &b, &c, &d, &port, &port);
    char ip[INET_ADDRSTRLEN];
    snprintf(ip, sizeof(ip), "%d.%d.%d.%d", a, b, c, d);
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
    };
    if (inet_pton(AF_INET, ip, &addr.sin_addr) != 1) {
        return -1;
    }
    conn->data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(conn->data_sock, (struct sockaddr*)&addr, sizeof(addr)) != 0) {
        return -1;
    }
    return 0;
}

int ftp_send_cmd(struct ftp_conn* conn, const char* cmd, const char* arg) {
    char buf[BUFSIZE];
    int len = snprintf(buf, sizeof(buf), "%s %s\r\n", cmd, arg);
    send(conn->control_sock, buf, len, 0);
    return ftp_recv_resp(conn, buf, sizeof(buf));
}

int ftp_recv_resp(struct ftp_conn* conn, char* buf, int len) {
    int n = 0;
    int code = 0;
    while (1) {
        int m = recv(conn->control_sock, buf + n, len - n, 0);
        if (m == 0) {
            return 0;
        }
        n += m;
        if (buf[n - 2] == '\r' && buf[n - 1] == '\n') {
            buf[n - 2] = '\0';
            if (isdigit(buf[0]) && isdigit(buf[1]) && isdigit(buf[2])) {
                code = atoi(buf);
            }
            break;
        }
    }
    return code;
}

int ftp_upload(struct ftp_conn* conn, const char* local_fname, const char* remote_fname) {
    char buf[BUFSIZE];
    struct stat st;
    if (stat(local_fname, &st) != 0) {
        return -1;
    }
    int fd = open(local_fname, O_RDONLY);
    if (fd < 0) {
        return -1;
    }
    if (ftp_send_cmd(conn, "TYPE", conn->mode == FTP_ASCII ? "A" : "I") != 200) {
        return -1;
    }
    if (ftp_send_cmd(conn, "STOR", remote_fname) != 150) {
        return -1;
    }
    while (1) {
        int n = read(fd, buf, sizeof(buf));
        if (n == 0) {
            break;
        }
        if (send(conn->data_sock, buf, n, 0) != n) {
            return -1;
        }
    }
    close(fd);
    close(conn->data_sock);
    conn->data_sock = -1;
    int code = ftp_recv_resp(conn, buf, sizeof(buf));
    return code == 226 || code == 250;
}

int ftp_download(struct ftp_conn* conn, const char* remote_fname, const char* local_fname) {
    char buf[BUFSIZE];
    int fd = open(local_fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        return -1;
    }
    if (ftp_send_cmd(conn, "TYPE", conn->mode == FTP_ASCII ? "A" : "I") != 200) {
        return -1;
    }
    if (ftp_send_cmd(conn, "RETR", remote_fname) != 150) {
        return -1;
    }
    while (1) {
        int n = recv(conn->data_sock, buf, sizeof(buf), 0);
        if (n == 0) {
            break;
        }
        if (write(fd, buf, n) != n) {
            return -1;
        }
    }
    close(fd);
    close(conn->data_sock);
    conn->data_sock = -1;
    int code = ftp_recv_resp(conn, buf, sizeof(buf));
    return code == 226 || code == 250;
}

int ftp_disconnect(struct ftp_conn* conn) {
    if (ftp_send_cmd(conn, "QUIT", "") != 221) {
        return -1;
    }
    close(conn->control_sock);
    conn->control_sock = -1;
    return 0;
}