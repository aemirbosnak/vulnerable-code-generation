//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

void send_love_letters(int client_socket) {
    char message[BUF_SIZE];
    
    // A sweet message to touch hearts
    const char *love_letter = "Dear Beloved, \nIn the vast universe of ones and zeros, "
                              "you are the one whom I cherish more than any perfect byte. \n"
                              "Your presence fills my heart with joy and my code with purpose. \n"
                              "May our connection never timeout. \n"
                              "Forever yours, \nA Loving Programmer";
    
    // Sending the message, heart beating
    send(client_socket, love_letter, strlen(love_letter), 0);
    printf("Love letter sent: %s\n", love_letter);
}

void receive_heartbeats(int server_socket) {
    char buffer[BUF_SIZE];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Await the cherished responses from a beloved
    while(1) {
        // Pull in the heartbeat from afar
        int bytes_received = recvfrom(server_socket, buffer, BUF_SIZE, 0,
                                       (struct sockaddr*)&client_addr, &addr_len);
        if (bytes_received < 0) {
            perror("Failed to receive message");
            exit(EXIT_FAILURE);
        }

        // Null-terminate the received data and print
        buffer[bytes_received] = '\0';
        printf("Received heartbeat: %s\n", buffer);
        
        // If our beloved's heart beats back, send a gentle response
        send_love_letters(server_socket);
    }
}

int main() {
    // Create a socket to connect two souls separated by wires
    int server_socket;
    struct sockaddr_in server_addr;

    // Tonight, we begin our journey
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Build the heart of our server with love
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind our soul to the address
    if (bind(server_socket, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a heartbeat from afar...\n");

    // Listen for love to travel across the networks
    receive_heartbeats(server_socket);

    // Close the connection we built with love
    close(server_socket);
    
    return 0;
}