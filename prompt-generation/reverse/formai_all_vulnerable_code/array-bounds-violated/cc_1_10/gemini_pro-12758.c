//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

// Server code
void* serverThread(void* arg) {
    int *client_socket = (int *)arg;
    char buffer[1024];

    while (true) {
        // Read the message from the client
        int bytes_received = recv(*client_socket, buffer, 1024, 0);
        if (bytes_received == 0) {
            // Client disconnected
            break;
        }

        // Process the message
        buffer[bytes_received] = '\0'; // Null-terminate the string

        printf("Received message from client: %s\n", buffer);

        // Echo the message back to the client
        send(*client_socket, buffer, strlen(buffer), 0);
    }

    // Close the client socket
    close(*client_socket);
    return NULL;
}

// Client code
void* clientThread(void* arg) {
    int server_socket = *(int *)arg;
    char buffer[1024];

    while (true) {
        // Get user input
        printf("Enter a message to send to the server: ");
        fgets(buffer, 1024, stdin);

        // Send the message to the server
        int bytes_sent = send(server_socket, buffer, strlen(buffer), 0);
        if (bytes_sent == 0) {
            // Server disconnected
            break;
        }

        // Receive the response from the server
        int bytes_received = recv(server_socket, buffer, 1024, 0);
        if (bytes_received == 0) {
            // Server disconnected
            break;
        }

        // Print the response
        printf("Received response from server: %s\n", buffer);
    }

    // Close the server socket
    close(server_socket);
    return NULL;
}

// Main function
int main() {
    int server_socket, client_socket;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    // Bind the server socket to an address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int bind_status = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status == -1) {
        perror("bind");
        return 1;
    }

    // Listen for connections on the server socket
    int listen_status = listen(server_socket, 5);
    if (listen_status == -1) {
        perror("listen");
        return 1;
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, clientThread, &server_socket);

    while (true) {
        // Accept connections from clients
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a thread to handle the client connection
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, serverThread, &client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}