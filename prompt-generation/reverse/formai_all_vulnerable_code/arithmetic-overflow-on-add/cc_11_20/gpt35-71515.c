//FormAI DATASET v1.0 Category: Socket programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 3

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *welcome_message = "Welcome to Retro Chatroom!\n";
    int client_sockets[MAX_CLIENTS] = {0};
    fd_set read_fds;
    int max_socket = 0;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Retro Chatroom is now open for connections!\n");

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        max_socket = server_fd;

        for (int i = 0; i < MAX_CLIENTS; i++) {
            int c_sock = client_sockets[i];
            if (c_sock > 0) {
                FD_SET(c_sock, &read_fds);
            }
            if (c_sock > max_socket) {
                max_socket = c_sock;
            }
        }

        int activity = select(max_socket + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            // Accept the incoming connection
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            // Add the new client socket to the list of client sockets
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    break;
                }
            }

            // Send a welcome message to the new client
            send(new_socket, welcome_message, strlen(welcome_message), 0);

            printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            int c_sock = client_sockets[i];
            if (FD_ISSET(c_sock, &read_fds)) {
                // Read and display the incoming message from client
                if ((valread = read(c_sock, buffer, 1024)) == 0) {
                    // The client has disconnected
                    getpeername(c_sock, (struct sockaddr *)&address, (socklen_t *)&addrlen);
                    printf("Client disconnected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(c_sock);
                    client_sockets[i] = 0;
                } else {
                    printf("%s:%d says: %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);
                }
            }
        }
    }

    return 0;
}