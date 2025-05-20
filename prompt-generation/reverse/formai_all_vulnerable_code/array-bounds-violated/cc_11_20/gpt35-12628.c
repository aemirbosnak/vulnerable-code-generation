//FormAI DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread, clients_count = 0;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d..\n", PORT);

    // Initialize client sockets array
    int client_sockets[MAX_CLIENTS] = {0};

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Add new client to client_sockets array
        client_sockets[clients_count++] = new_socket;

        char new_client_msg[BUFFER_SIZE] = "New client joined the chat!";
        write(new_socket, new_client_msg, strlen(new_client_msg));

        // Fork a new process for each client
        int pid = fork();

        if (pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) { // Child process
            close(server_fd); // Close server socket in child process

            while (1) {
                valread = read( new_socket , buffer, BUFFER_SIZE); // Read message from client
                printf("Client : %d - %s\n", new_socket, buffer);

                if (strcmp(buffer, "exit")==0) { // If client sends 'exit' message
                    char exit_msg[BUFFER_SIZE] = "You left the chat!";
                    write(new_socket, exit_msg, strlen(exit_msg)); // Send exit message to client
                    break;
                }

                // Broadcast message to other clients
                for (int i = 0; i < clients_count; i++) {
                    if (client_sockets[i] != new_socket) {
                        write(client_sockets[i], buffer, strlen(buffer));
                    }
                }
                memset(buffer, 0, BUFFER_SIZE); // Clear buffer
            }
            close(new_socket); // Close client socket in child process
            exit(0); // Exit child process
        }
        else { // Parent process
            close(new_socket); // Close client socket in parent process
        }
    }

    // Close server socket
    close(server_fd);

    return 0;
}