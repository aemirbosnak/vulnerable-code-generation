//GEMINI-pro DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Let's get our sockets talking!
int main() {
    // Create a socket, like a door to the network world
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the address we want to listen on, like our house address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(8080); 

    // Bind the socket to the address, like attaching a label to our house
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(1);
    }

    // Start listening for connections, like opening our door for guests
    if (listen(server_socket, 10) == -1) { 
        perror("Listen failed");
        exit(1);
    }

    printf("Server is listening on port 8080. Waiting for clients...\n");

    // Now, let's chat with our clients!
    while (1) {
        // Accept a connection, like welcoming a guest into our house
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Accept failed");
            continue;
        }

        // Let's read the message from the client, like listening to what they have to say
        char buffer[1024];
        int recv_size = recv(client_socket, buffer, sizeof(buffer), 0);
        if (recv_size == -1) {
            perror("Receive failed");
            close(client_socket);
            continue;
        }
        buffer[recv_size] = '\0'; // Null-terminate the string

        // Echo back the message to the client, like responding to their greeting
        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            perror("Send failed");
            close(client_socket);
            continue;
        }

        printf("Message from client: %s\n", buffer);

        // Close the connection, like saying goodbye to our guest
        close(client_socket);
    }

    // Clean up when we're done, like a good host
    close(server_socket);
    return 0;
}