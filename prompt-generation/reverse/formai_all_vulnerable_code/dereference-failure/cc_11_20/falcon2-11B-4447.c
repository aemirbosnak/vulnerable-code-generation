//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int listen_fd, conn_fd, n;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("listen");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, (socklen_t*)&n);
        if (conn_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(cli_addr.sin_addr));

        while (1) {
            n = read(conn_fd, buffer, sizeof(buffer));
            if (n < 0) {
                perror("read");
                close(conn_fd);
                break;
            }

            if (n == 0) {
                printf("Client disconnected\n");
                break;
            }

            if (write(conn_fd, buffer, n) < 0) {
                perror("write");
                close(conn_fd);
                break;
            }

            printf("Server: %s\n", buffer);
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}