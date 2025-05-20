//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int len;

    // Interactive client loop
    while ((len = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[len] = '\0';
        printf("Received command: %s\n", buffer);

        // Simple command processing
        if (strcmp(buffer, "LIGHT ON") == 0) {
            printf("Light turned ON\n");
            send(client_socket, "OK: Light ON", strlen("OK: Light ON"), 0);
        } else if (strcmp(buffer, "LIGHT OFF") == 0) {
            printf("Light turned OFF\n");
            send(client_socket, "OK: Light OFF", strlen("OK: Light OFF"), 0);
        } else if (strcmp(buffer, "TEMP GET") == 0) {
            int temperature = 72;  // Dummy temperature value
            char response[50];
            snprintf(response, sizeof(response), "TEMP: %d", temperature);
            send(client_socket, response, strlen(response), 0);
        } else if (strcmp(buffer, "SECURITY ON") == 0) {
            printf("Security system activated\n");
            send(client_socket, "OK: Security ON", strlen("OK: Security ON"), 0);
        } else if (strcmp(buffer, "SECURITY OFF") == 0) {
            printf("Security system deactivated\n");
            send(client_socket, "OK: Security OFF", strlen("OK: Security OFF"), 0);
        } else {
            send(client_socket, "ERROR: Unknown command", strlen("ERROR: Unknown command"), 0);
        }
    }

    if (len == 0) {
        printf("Client disconnected\n");
    } else {
        perror("recv");
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Smart Home Automation Server is running on port %d\n", PORT);

    // Main loop to accept clients
    while (1) {
        printf("Waiting for a connection...\n");
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue; // Skip this iteration
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}