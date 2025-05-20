//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_LINE 1024
#define DELIM "\r\n"

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if (conn_fd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            n = read(conn_fd, buffer, MAX_LINE);
            if (n == 0) {
                printf("Client disconnected\n");
                break;
            } else if (n == -1) {
                perror("read");
                exit(1);
            }

            buffer[n] = '\0';
            printf("%s", buffer);

            char *pos = strchr(buffer, DELIM);
            if (pos!= NULL) {
                *pos = '\0';
            }

            for (int i = 0; i < strlen(buffer); i++) {
                if (buffer[i] == '\n') {
                    buffer[i] = '\0';
                    printf("%s", buffer);
                    break;
                }
            }
        }

        close(conn_fd);
    }

    return 0;
}