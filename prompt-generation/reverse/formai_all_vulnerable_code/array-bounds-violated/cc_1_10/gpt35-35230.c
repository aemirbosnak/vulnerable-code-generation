//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <sys/time.h>

#define SERVER_PORT 9876
#define MAX_PENDING 5
#define MAX_LINE 256

// Signal handler to gracefully shutdown the server on SIGINT
void sigint_handler(int signal) {
    printf("Stopping server...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_addrlen = sizeof(client_address);
    char message[MAX_LINE];
    int len, qos;

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(SERVER_PORT);

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_socket, MAX_PENDING) < 0) {
        perror("Error listening");
        exit(1);
    }

    // Register signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    printf("Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Accept incoming client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_addrlen)) < 0) {
            perror("Error accepting client connection");
            exit(1);
        }

        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Read client message
        if ((len = recv(client_socket, message, MAX_LINE, 0)) < 0) {
            perror("Error receiving message");
            exit(1);
        }

        message[len] = '\0';
        printf("Received message from client: %s\n", message);

        // Calculate network quality of service (QoS) based on message length
        qos = len > 50 ? 1 : 0;

        printf("Calculated QoS level for message: %d\n", qos);

        // Send QoS level back to client
        if (send(client_socket, &qos, sizeof(qos), 0) < 0) {
            perror("Error sending QoS level");
            exit(1);
        }

        printf("Sent QoS level to client\n");

        // Close client socket
        close(client_socket);

        printf("Closed client connection\n");
    }

    // Close server socket
    close(server_socket);

    printf("Server stopped\n");

    return 0;
}