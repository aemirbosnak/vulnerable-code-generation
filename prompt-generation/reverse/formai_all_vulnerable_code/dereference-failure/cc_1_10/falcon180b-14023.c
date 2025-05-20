//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define POP3_PORT 110
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server_addr;
    char *host, buf[BUF_SIZE];
    int len, n;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s host [port]\n", argv[0]);
        return 1;
    }

    host = argv[1];
    if (argc >= 3) {
        port = atoi(argv[2]);
    } else {
        port = POP3_PORT;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: socket() failed: %s\n", strerror(errno));
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error: inet_pton() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: connect() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    fprintf(stdout, "Connected to %s:%d\n", host, port);

    while (1) {
        fprintf(stdout, "POP3> ");
        fflush(stdout);
        memset(buf, 0, BUF_SIZE);
        n = read(0, buf, BUF_SIZE - 1);
        if (n <= 0) {
            fprintf(stdout, "Error: read() failed: %s\n", strerror(errno));
            close(sock);
            return 1;
        }
        buf[n] = '\0';
        if (strcmp(buf, "quit") == 0) {
            break;
        }
        len = strlen(buf);
        send(sock, buf, len, 0);
        memset(buf, 0, BUF_SIZE);
        n = recv(sock, buf, BUF_SIZE - 1, 0);
        if (n <= 0) {
            fprintf(stdout, "Error: recv() failed: %s\n", strerror(errno));
            close(sock);
            return 1;
        }
        buf[n] = '\0';
        fprintf(stdout, "POP3< %s\n", buf);
    }

    close(sock);
    return 0;
}