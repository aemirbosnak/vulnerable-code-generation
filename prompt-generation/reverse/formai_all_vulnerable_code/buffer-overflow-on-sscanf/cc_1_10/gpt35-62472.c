//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE 4096
#define SERVER_PORT 21
#define LOGIN_USER "username"
#define LOGIN_PASS "password"
#define MAX_DEPTH 10

void connect_to_server(int *sockfd, char *ip_address);
void login(int sockfd);
void send_cmd(int sockfd, char *cmd);
int get_response(int sockfd, char *buf);
void send_mode(int sockfd);
void send_type(int sockfd);
void change_dir(int sockfd, char *path, int *current_depth);
void list_files(int sockfd, char *path, int current_depth);
void download_file(int sockfd, char *file_path, char *destination);
void recursive_download(int sockfd, char *path, char *local_path, int current_depth);

int main(int argc, char *argv[]) {
    int sockfd;
    char *ip_address;
    char *server_path;
    char *local_path;

    if (argc == 4) {
        ip_address = argv[1];
        server_path = argv[2];
        local_path = argv[3];
    } else {
        printf("Invalid argument count. Usage: ./ftp_client <server_ip_address> <server_path> <local_path>\n");
        exit(1);
    }

    connect_to_server(&sockfd, ip_address);
    login(sockfd);
    send_mode(sockfd);
    send_type(sockfd);
    recursive_download(sockfd, server_path, local_path, 0);

    close(sockfd);
    printf("Finished downloading files\n");
    return 0;
}

void connect_to_server(int *sockfd, char *ip_address) {
    struct sockaddr_in server_addr;

    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        perror("Error invalid address");
        exit(1);
    }

    if (connect(*sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error could not connect to server");
        exit(1);
    }
    printf("Connected to server: %s\n", ip_address);
}

void login(int sockfd) {
    char buf[BUF_SIZE];
    int code;

    get_response(sockfd, buf);

    send_cmd(sockfd, "USER " LOGIN_USER);
    code = get_response(sockfd, buf);
    if (code != 331) {
        printf("Error invalid response code when sending user, code: %d\n", code);
        exit(1);
    }

    send_cmd(sockfd, "PASS " LOGIN_PASS);
    code = get_response(sockfd, buf);
    if (code != 230) {
        printf("Error invalid response code when sending password, code: %d\n", code);
        exit(1);
    }

    printf("Login successful\n");
}

void send_cmd(int sockfd, char *cmd) {
    char buf[BUF_SIZE];
    snprintf(buf, sizeof(buf), "%s\r\n", cmd);
    if (send(sockfd, buf, strlen(buf), 0) != strlen(buf)) {
        perror("Error sending command");
        exit(1);
    }
}

int get_response(int sockfd, char *buf) {
    int code, byte_count;
    memset(buf, 0, BUF_SIZE);

    if ((byte_count = recv(sockfd, buf, sizeof(buf), 0)) < 0) {
        perror("Error receiving response from server");
        exit(1);
    }
    printf("%s", buf);
    sscanf(buf, "%d", &code);

    return code;
}

void send_mode(int sockfd) {
    char buf[BUF_SIZE];
    send_cmd(sockfd, "MODE S");
    int code = get_response(sockfd, buf);
    if (code != 200) {
        printf("Error invalid response code when sending mode, code: %d", code);
        exit(1);
    }
    printf("Mode set to stream\n");
}

void send_type(int sockfd) {
    char buf[BUF_SIZE];
    send_cmd(sockfd, "TYPE I");
    int code = get_response(sockfd, buf);
    if (code != 200) {
        printf("Error invalid response code when sending type, code: %d", code);
        exit(1);
    }
    printf("Type set to binary\n");
}

void change_dir(int sockfd, char *path, int *current_depth) {
    char buf[BUF_SIZE];
    char cmd[BUF_SIZE];

    if (*current_depth >= MAX_DEPTH) {
        printf("Max depth reached\n");
        return;
    }
    *current_depth += 1;

    snprintf(cmd, sizeof(cmd), "CWD %s", path);
    send_cmd(sockfd, cmd);
    int code = get_response(sockfd, buf);

    if (code == 550) {
        printf("Error directory not found\n");
        exit(1);
    } else if (code != 250) {
        printf("Error invalid response code when changing directory, code: %d\n", code);
        exit(1);
    }

    send_cmd(sockfd, "PWD");
    get_response(sockfd, buf);
    printf("Changed directory to: %s\n", buf);
}

void list_files(int sockfd, char *path, int current_depth) {
    char buf[BUF_SIZE];
    char cmd[BUF_SIZE];

    if (current_depth >= MAX_DEPTH) {
        printf("Max depth reached\n");
        return;
    }

    snprintf(cmd, sizeof(cmd), "LIST %s", path);
    send_cmd(sockfd, cmd);
    get_response(sockfd, buf);
    printf("%s", buf);
}

void download_file(int sockfd, char *file_path, char *destination) {
    FILE *fp;
    int received_bytes = 0, total_bytes = 0;
    char buf[BUF_SIZE];

    if ((fp = fopen(destination, "wb")) == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    send_cmd(sockfd, "TYPE I");
    int code = get_response(sockfd, buf);

    if (code != 200) {
        printf("Error invalid response code when sending type, code: %d\n", code);
        exit(1);
    }

    snprintf(buf, sizeof(buf), "RETR %s", file_path);
    send_cmd(sockfd, buf);
    code = get_response(sockfd, buf);

    if (code != 150) {
        printf("Error invalid response code when requesting file, code: %d\n", code);
        exit(1);
    }

    while ((received_bytes = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
        fwrite(buf, sizeof(char), received_bytes, fp);
        total_bytes += received_bytes;
    }

    fclose(fp);
    printf("Downloaded file %s (%d bytes)\n", file_path, total_bytes);
}

void recursive_download(int sockfd, char *path, char *local_path, int current_depth) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(path)) == NULL) {
        download_file(sockfd, path, local_path);
        return;
    }

    change_dir(sockfd, path, &current_depth);
    snprintf(local_path + strlen(local_path), BUF_SIZE - strlen(local_path), "/%s", path);

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(".", ent->d_name) != 0 && strcmp("..", ent->d_name) != 0) {
            if (ent->d_type == DT_DIR) {
                recursive_download(sockfd, ent->d_name, local_path, current_depth);
            } else {
                char file_path[BUF_SIZE];
                snprintf(file_path, sizeof(file_path), "%s/%s", path, ent->d_name);

                char file_dest[BUF_SIZE];
                snprintf(file_dest, sizeof(file_dest), "%s/%s", local_path, ent->d_name);

                download_file(sockfd, file_path, file_dest);
            }
        }
    }

    closedir(dir);
    send_cmd(sockfd, "CDUP");
    get_response(sockfd, NULL);
    snprintf(local_path + strlen(local_path) - strlen(path), BUF_SIZE - strlen(local_path) + strlen(path), "");
    current_depth -= 1;
}