//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of connections that can be handled simultaneously.
#define MAX_CONNECTIONS 10

// Define the maximum length of a message that can be received.
#define MAX_MESSAGE_LENGTH 1024

// Define the port number to listen on.
#define PORT 8080

// Define the IP address of the server.
#define SERVER_IP "127.0.0.1"

// Define the list of trusted IP addresses.
char *trusted_ips[] = {
    "192.168.1.1",
    "192.168.1.2",
    "192.168.1.3",
};

// Define the number of trusted IP addresses.
#define NUM_TRUSTED_IPS 3

// Create a socket and listen for incoming connections.
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;

    // Create a socket.
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Set the server address.
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Bind the socket to the server address.
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections.
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("Error listening for connections");
        return EXIT_FAILURE;
    }

    // Accept incoming connections and handle them in a loop.
    while (1) {
        // Accept an incoming connection.
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        // Check if the client's IP address is trusted.
        int is_trusted = 0;
        for (int i = 0; i < NUM_TRUSTED_IPS; i++) {
            if (strcmp(inet_ntoa(client_address.sin_addr), trusted_ips[i]) == 0) {
                is_trusted = 1;
            }
        }

        // If the client's IP address is not trusted, log the connection attempt and close the connection.
        if (!is_trusted) {
            printf("Received connection from untrusted IP address: %s\n", inet_ntoa(client_address.sin_addr));
            close(client_socket);
            continue;
        }

        // Receive a message from the client.
        char message[MAX_MESSAGE_LENGTH];
        int message_length = recv(client_socket, message, MAX_MESSAGE_LENGTH, 0);
        if (message_length == -1) {
            perror("Error receiving message");
            close(client_socket);
            continue;
        }

        // Process the message.
        printf("Received message: %s\n", message);

        // Send a response to the client.
        char response[] = "Hello, world!";
        if (send(client_socket, response, strlen(response), 0) == -1) {
            perror("Error sending response");
            close(client_socket);
            continue;
        }

        // Close the connection.
        close(client_socket);
    }

    // Close the server socket.
    close(server_socket);

    return EXIT_SUCCESS;
}