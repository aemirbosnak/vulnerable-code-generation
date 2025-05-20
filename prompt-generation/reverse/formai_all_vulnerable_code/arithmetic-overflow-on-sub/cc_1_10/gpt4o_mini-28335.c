//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10

void handle_client(int client_socket);
double get_time_diff(struct timeval start, struct timeval end);

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept client connections
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) >= 0) {
        printf("Client connected!\n");
        handle_client(client_socket);
        close(client_socket);
    }

    if (client_socket < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;
    double total_time = 0.0;
    int request_count = 0;

    while (request_count < NUM_REQUESTS) {
        memset(buffer, 0, BUFFER_SIZE);
        
        // Receive message from client
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
            perror("Receive failed");
            break;
        }

        // Start timing the response
        gettimeofday(&start_time, NULL);

        // Simulate processing
        snprintf(buffer, BUFFER_SIZE, "Echo: %s", buffer);
        send(client_socket, buffer, strlen(buffer), 0);

        // End timing the response
        gettimeofday(&end_time, NULL);
        double response_time = get_time_diff(start_time, end_time);
        total_time += response_time;
        request_count++;

        printf("Processed request %d in %.6f seconds\n", request_count, response_time);
    }

    printf("Total requests: %d\nAverage response time: %.6f seconds\n", request_count, total_time / request_count);
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
}

// Client Program

void client_program() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client_socket);
        return;
    }

    for (int i = 0; i < NUM_REQUESTS; i++) {
        snprintf(buffer, BUFFER_SIZE, "Hello %d", i);
        send(client_socket, buffer, strlen(buffer), 0);

        // Receive response from server
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_socket, buffer, BUFFER_SIZE, 0);
        printf("Received from server: %s\n", buffer);
    }

    close(client_socket);
}