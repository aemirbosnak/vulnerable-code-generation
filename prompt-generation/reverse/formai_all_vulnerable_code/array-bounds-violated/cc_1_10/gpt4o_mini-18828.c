//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/sha.h>

#define PORT 8080
#define BUF_SIZE 1024
#define HASH_SIZE 65

// Function to compute SHA-256 hash of input
void compute_sha256(const char *input, char *outputBuffer) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input, strlen(input), hash);
    
    // Convert the hash into a hexadecimal string
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[HASH_SIZE - 1] = '\0';  // Null-terminate the string
}

// Function to handle client connections
void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    char hash_output[HASH_SIZE];

    // Receive the username and message from the client
    int received = recv(client_socket, buffer, BUF_SIZE, 0);
    if (received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }
    buffer[received] = '\0';  // Null-terminate the received data

    // Compute the hash for the received data
    compute_sha256(buffer, hash_output);

    // Send back the hashed output
    send(client_socket, hash_output, HASH_SIZE, 0);

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Failed");
        return -1;
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept any incoming address
    server_addr.sin_port = htons(PORT); // Port number

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        close(server_socket);
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen Failed");
        close(server_socket);
        return -1;
    }

    printf("Server listening on port %d...\n", PORT);

    // Infinite loop to accept and handle client connections
    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept Failed");
            continue;
        }

        printf("Accepted connection from client...\n");

        // Handle the client in a separate function
        handle_client(client_socket);
        printf("Handled client and sent hash back.\n");
    }

    close(server_socket);
    return 0;
}