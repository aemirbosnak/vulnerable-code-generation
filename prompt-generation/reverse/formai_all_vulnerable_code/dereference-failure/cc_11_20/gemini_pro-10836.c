//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUF_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <remote-port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    int remote_port = atoi(argv[3]);

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(listen_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        int client_fd = accept(listen_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        int remote_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_fd == -1) {
            perror("socket");
            close(client_fd);
            continue;
        }

        struct sockaddr_in remote_addr;
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(remote_port);
        remote_addr.sin_addr.s_addr = inet_addr(host);

        if (connect(remote_fd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
            perror("connect");
            close(client_fd);
            close(remote_fd);
            continue;
        }

        char buf[BUF_SIZE];
        int n;

        while ((n = read(client_fd, buf, BUF_SIZE)) > 0) {
            if (write(remote_fd, buf, n) == -1) {
                perror("write");
                break;
            }
        }

        if (n == -1) {
            perror("read");
        }

        close(client_fd);
        close(remote_fd);
    }

    close(listen_fd);

    return 0;
}