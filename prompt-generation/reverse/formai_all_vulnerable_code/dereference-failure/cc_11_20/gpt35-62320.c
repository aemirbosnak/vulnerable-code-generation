//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <local_port> <remote_port>\n", argv[0]);
        return 1;
    }

    int local_port = atoi(argv[1]);
    int remote_port = atoi(argv[2]);

    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        return 1;
    }

    struct sockaddr_in local_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(local_port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(server_socket, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        perror("Failed to bind server socket");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, SOMAXCONN) == -1) {
        perror("Failed to listen on server socket");
        close(server_socket);
        return 1;
    }

    printf("Listening on port %d...\n", local_port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_socket == -1) {
            perror("Failed to accept client connection");
            continue;
        }

        char ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, ip_address, INET_ADDRSTRLEN);
        printf("Accepted client connection from %s:%d\n", ip_address, ntohs(client_addr.sin_port));

        int remote_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (remote_socket == -1) {
            perror("Failed to create remote socket");
            close(client_socket);
            continue;
        }

        struct sockaddr_in remote_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(remote_port),
            .sin_addr.s_addr = inet_addr("127.0.0.1")
        };

        if (connect(remote_socket, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
            perror("Failed to connect to remote server");
            close(remote_socket);
            close(client_socket);
            continue;
        }

        printf("Connected to remote server\n");

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(client_socket, &read_fds);
        FD_SET(remote_socket, &read_fds);

        int max_fd = client_socket > remote_socket ? client_socket : remote_socket;

        while (1) {
            fd_set fds = read_fds;
            if (select(max_fd + 1, &fds, NULL, NULL, NULL) == -1) {
                perror("Failed to select sockets");
                break;
            }

            if (FD_ISSET(client_socket, &fds)) {
                char buffer[BUFFER_SIZE];
                ssize_t num_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
                if (num_bytes == -1) {
                    perror("Failed to receive data from client");
                    break;
                }

                if (num_bytes == 0) {
                    printf("Client closed the connection\n");
                    break;
                }

                printf("Received %zd bytes of data from client\n", num_bytes);

                if (send(remote_socket, buffer, num_bytes, 0) == -1) {
                    perror("Failed to send data to remote server");
                    break;
                }

                printf("Sent %zd bytes of data to remote server\n", num_bytes);
            }

            if (FD_ISSET(remote_socket, &fds)) {
                char buffer[BUFFER_SIZE];
                ssize_t num_bytes = recv(remote_socket, buffer, BUFFER_SIZE, 0);
                if (num_bytes == -1) {
                    perror("Failed to receive data from remote server");
                    break;
                }

                if (num_bytes == 0) {
                    printf("Remote server closed the connection\n");
                    break;
                }

                printf("Received %zd bytes of data from remote server\n", num_bytes);

                if (send(client_socket, buffer, num_bytes, 0) == -1) {
                    perror("Failed to send data to client");
                    break;
                }

                printf("Sent %zd bytes of data to client\n", num_bytes);
            }
        }

        close(remote_socket);
        close(client_socket);
        printf("Closed connections\n");
    }

    return 0;
}