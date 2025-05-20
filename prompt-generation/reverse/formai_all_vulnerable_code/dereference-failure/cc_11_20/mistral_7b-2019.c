//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    fd_set master_fds, read_fds;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);
    FD_SET(server_fd, &master_fds);

    while (true) {
        read_fds = master_fds;
        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_fd) {
                    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                             (socklen_t *)&addrlen)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }

                    printf("New connection, ip: %s, port: %d\n",
                           inet_ntoa(address.sin_addr), ntohs(address.sin_port));

                    FD_SET(new_socket, &master_fds);
                } else {
                    valread = recv(i, buffer, BUFFER_SIZE, 0);
                    if (valread > 0) {
                        printf("Client: %s\n", buffer);
                        send(i, buffer, valread, 0);
                    } else if (valread == 0) {
                        printf("Client disconnected\n");
                        FD_CLR(i, &master_fds);
                        close(i);
                    } else {
                        perror("recv failed");
                        FD_CLR(i, &master_fds);
                        close(i);
                    }
                }
            }
        }
    }

    return 0;
}