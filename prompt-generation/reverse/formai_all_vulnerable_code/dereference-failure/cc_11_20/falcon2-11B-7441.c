//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int server_fd, new_fd;
    int listen_fd = -1;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    listen_fd = listen(server_fd, MAX_CLIENTS);
    if (listen_fd < 0) {
        perror("listen failed");
        return 1;
    }

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);

        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = 0;

        int num_clients = select(server_fd + 1, &read_fds, NULL, NULL, &tv);
        if (num_clients < 0) {
            perror("select failed");
            return 1;
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            if (listen_fd > 0) {
                close(listen_fd);
                listen_fd = -1;
            }

            new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
            if (new_fd < 0) {
                perror("accept failed");
                return 1;
            }

            FD_SET(new_fd, &read_fds);

            printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            while (1) {
                memset(buffer, 0, sizeof(buffer));
                ssize_t bytes_read = recv(new_fd, buffer, sizeof(buffer), 0);
                if (bytes_read < 0) {
                    perror("recv failed");
                    return 1;
                }

                printf("%s\n", buffer);

                ssize_t bytes_sent = send(new_fd, "You said: ", strlen("You said: "), 0);
                if (bytes_sent < 0) {
                    perror("send failed");
                    return 1;
                }

                memset(buffer, 0, sizeof(buffer));
                bytes_read = recv(new_fd, buffer, sizeof(buffer), 0);
                if (bytes_read < 0) {
                    perror("recv failed");
                    return 1;
                }

                printf("%s\n", buffer);

                if (strcmp(buffer, "quit") == 0) {
                    break;
                }

                memset(buffer, 0, sizeof(buffer));
                bytes_sent = send(new_fd, "Server: ", strlen("Server: "), 0);
                if (bytes_sent < 0) {
                    perror("send failed");
                    return 1;
                }

                memset(buffer, 0, sizeof(buffer));
                bytes_read = recv(new_fd, buffer, sizeof(buffer), 0);
                if (bytes_read < 0) {
                    perror("recv failed");
                    return 1;
                }

                printf("%s\n", buffer);
            }

            close(new_fd);
        }
    }

    close(server_fd);
    return 0;
}