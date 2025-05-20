//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int server_fd, new_socket;
    struct sockaddr_in server_addr;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    // Listen for incoming connections
    listen(server_fd, 5);

    while (1) {
        // Accept a new connection
        new_socket = accept(server_fd, NULL, NULL);
        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        // Handle the new connection
        int client_fd = new_socket;
        char buffer[1024];
        char client_name[1024];
        char message[1024];
        char broadcast_message[1024];
        char disconnect_message[1024];
        int num_connected_clients = 0;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        // Get the name of the connected client
        if (getsockname(new_socket, (struct sockaddr *)&client_addr, &client_addr_len) == -1) {
            printf("Error getting client name\n");
            continue;
        }
        strcpy(client_name, inet_ntoa(client_addr.sin_addr));

        // Get the message from the client
        if (recv(new_socket, buffer, sizeof(buffer), 0) == -1) {
            printf("Error receiving message from client\n");
            continue;
        }
        strcpy(message, buffer);

        // Check if the message is valid
        if (strcmp(message, "disconnect") == 0) {
            send(new_socket, disconnect_message, sizeof(disconnect_message), 0);
            close(new_socket);
            continue;
        }

        // Increment the number of connected clients
        num_connected_clients++;

        // Broadcast the message to all other clients
        for (int i = 0; i < num_connected_clients; i++) {
            if (i!= new_socket) {
                if (send(i, message, sizeof(message), 0) == -1) {
                    printf("Error broadcasting message to client\n");
                    continue;
                }
            }
        }

        // Print the message
        printf("%s: %s\n", client_name, message);

        // Close the connection
        close(new_socket);
        break;
    }

    // Close the socket
    close(server_fd);
    return 0;
}