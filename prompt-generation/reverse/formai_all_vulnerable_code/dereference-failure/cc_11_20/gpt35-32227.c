//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./qos_monitor <port_number>\n");
        return 1;
    }

    int port_number = atoi(argv[1]);

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error opening socket.\n");
        return 1;
    }

    // Configure socket address
    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket to port.\n");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening for clients.\n");
        return 1;
    }

    printf("QoS Monitor is now listening on port %d...\n", port_number);

    // Set up client tracking
    int client_sockets[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    // Start monitoring
    while (1) {
        // Accept incoming connection
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            printf("Error accepting client connection.\n");
            continue;
        }

        // Add client to tracking array
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                printf("New client connected.\n");
                break;
            }
        }
        if (i == MAX_CLIENTS) {
            printf("Maximum number of clients reached.\n");
            close(client_socket);
            continue;
        }

        // Listen for messages from client
        char buffer[BUFFER_SIZE];
        int bytes_received;
        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message from client: %s\n", buffer);
            if (strlen(buffer) > 5) {
                send(client_socket, "Low QoS", strlen("Low QoS"), 0);
            } else {
                send(client_socket, "High QoS", strlen("High QoS"), 0);
            }
        }

        // Remove client from tracking array and close socket
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == client_socket) {
                client_sockets[i] = 0;
                printf("Client disconnected.\n");
                break;
            }
        }
        close(client_socket);
    }

    return 0;
}