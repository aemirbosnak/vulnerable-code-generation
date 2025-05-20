//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096
#define PORT 8888
#define MAX_CLIENT 10

void handle_client(int client_sock);

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Socket Creation
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Set Address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding Failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_sock, MAX_CLIENT) < 0) {
        perror("Listening Failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    printf("Proxy Server Listening on Port %d\n", PORT);

    while (1) {
        // Accept
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Client Acceptance Failed");
            continue; // to handle next client
        }
        printf("Client Connected\n");
        handle_client(client_sock);
        close(client_sock);
    }

    close(server_sock);
    return 0;
}

void handle_client(int client_sock) {
    char buffer[BUF_SIZE] = {0};
    recv(client_sock, buffer, sizeof(buffer), 0);

    // Parse the request
    char method[BUF_SIZE], url[BUF_SIZE], version[BUF_SIZE];
    sscanf(buffer, "%s %s %s", method, url, version);

    printf("Request: %s %s %s\n", method, url, version);

    // Extract host
    char host[BUF_SIZE];
    sscanf(url, "http://%99[^/]", host);
    printf("Extracted Host: %s\n", host);

    // Socket to connect to the target server
    int target_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (target_sock < 0) {
        perror("Target Socket Creation Failed");
        return;
    }

    // Target Server Address
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(80); // HTTP port
    target_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the target server
    if (connect(target_sock, (struct sockaddr*)&target_addr, sizeof(target_addr)) < 0) {
        perror("Connection to Target Server Failed");
        close(target_sock);
        return;
    }

    // Forward request to target server
    send(target_sock, buffer, strlen(buffer), 0);
    printf("Forwarded Request to Target Server\n");

    // Read response from target server and send back to client
    while (1) {
        int bytes_received = recv(target_sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break; // connection closed
        }
        send(client_sock, buffer, bytes_received, 0);
    }

    printf("Response Sent to Client\n");
    close(target_sock);
}