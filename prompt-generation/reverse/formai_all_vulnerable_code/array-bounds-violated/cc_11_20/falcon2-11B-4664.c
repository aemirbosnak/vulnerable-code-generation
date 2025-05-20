//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s port\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, conn_addr;
    socklen_t addr_size = sizeof(conn_addr);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("listen_fd");
        return 1;
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listen_fd, 5) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addr_size);
        if (conn_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Connected to: %s\n", inet_ntoa(conn_addr.sin_addr));
        char buffer[1024];
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            ssize_t bytes_read = recv(conn_fd, buffer, sizeof(buffer), 0);
            if (bytes_read < 0) {
                perror("recv");
                close(conn_fd);
                continue;
            }
            buffer[bytes_read] = '\0';
            printf("Received: %s\n", buffer);
            char *message = strtok(buffer, "\n");
            while (message!= NULL) {
                ssize_t bytes_written = send(conn_fd, message, strlen(message), 0);
                if (bytes_written < 0) {
                    perror("send");
                    close(conn_fd);
                    continue;
                }
                message = strtok(NULL, "\n");
            }
            close(conn_fd);
            break;
        }
    }

    return 0;
}