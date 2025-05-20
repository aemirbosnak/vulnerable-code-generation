//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr[0]);
    int max_fd = 0;
    fd_set master_fds, read_fds;

    memset(client_socket, 0, sizeof(client_socket));
    memset(client_addr, 0, sizeof(client_addr));

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    FD_ZERO(&master_fds);
    FD_SET(server_socket, &master_fds);

    printf("Server listening on port %d\n", PORT);

    while (1) {
        read_fds = master_fds;
        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) == -1) {
            printf("Error with select\n");
            exit(1);
        }

        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    addrlen = sizeof(client_addr[0]);
                    if ((client_socket[max_fd] = accept(server_socket, (struct sockaddr *)&client_addr[max_fd], &addrlen)) == -1) {
                        printf("Error accepting connection\n");
                        exit(1);
                    }
                    printf("Client %d connected\n", max_fd+1);
                    FD_SET(client_socket[max_fd], &master_fds);
                    if (max_fd < FD_SETSIZE - 1) {
                        max_fd++;
                    }
                } else {
                    if ((recv(i, buffer, BUFFER_SIZE, 0)) == 0) {
                        printf("Client %d disconnected\n", i+1);
                        close(i);
                        FD_CLR(i, &master_fds);
                    } else {
                        printf("Received message from client %d: %s\n", i+1, buffer);
                        send(i, buffer, strlen(buffer), 0);
                    }
                }
            }
        }
    }

    close(server_socket);
    return 0;
}