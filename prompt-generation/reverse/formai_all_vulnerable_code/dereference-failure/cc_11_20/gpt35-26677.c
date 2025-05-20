//FormAI DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 12345
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int main(int argc, char **argv) 
{
    int server_socket_fd, client_socket_fd, opt, client_address_len;
    struct sockaddr_in server_address, client_address;   
    char buffer[BUFFER_SIZE];

    // Create the server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options to reuse the address and port
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set server socket options");
        exit(EXIT_FAILURE);
    }
    
    // Configure the server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Bind the socket to the server address struct
    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket to address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, MAX_CONNECTIONS) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Accept incoming connections and handle them
    while (1) {
        client_address_len = sizeof(client_address);

        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address_len)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // Check if the client's IP address is in the blacklist
        char *blacklist[] = {"192.168.0.1", "10.0.0.1"};

        for (int i = 0; i < sizeof(blacklist) / sizeof(blacklist[0]); i++) {
            if (strcmp(inet_ntoa(client_address.sin_addr), blacklist[i]) == 0) {
                printf("Connection from %s is rejected due to firewall rules.\n", inet_ntoa(client_address.sin_addr));

                // Close the client socket and continue to the next connection
                close(client_socket_fd);
                continue;
            }
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Send a welcome message to the client
        const char *welcome_msg = "Welcome to my server!\n";
        send(client_socket_fd, welcome_msg, strlen(welcome_msg), 0);

        // Receive data from the client and send it back
        while (1) {
            int num_bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);

            if (num_bytes_received <= 0) {
                printf("Lost connection to %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                break;
            }

            buffer[num_bytes_received] = '\0';
            printf("Received message from %s:%d: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

            send(client_socket_fd, buffer, strlen(buffer), 0);
        }

        // Close the client socket
        close(client_socket_fd);
    }

    // Close the server socket
    close(server_socket_fd);
    return 0;
}