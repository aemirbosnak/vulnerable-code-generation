//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h> // For socket functions
#include <time.h>      // For random quotes

#define PORT 8080
#define BUF_SIZE 256

// Quotes array
const char *quotes[] = {
    "The greatest glory in living lies not in never falling, but in rising every time we fall. - Nelson Mandela",
    "The way to get started is to quit talking and begin doing. - Walt Disney",
    "Life is what happens when you're busy making other plans. - John Lennon",
    "The future belongs to those who believe in the beauty of their dreams. - Eleanor Roosevelt",
    "You only live once, but if you do it right, once is enough. - Mae West"
};
#define NUM_QUOTES (sizeof(quotes) / sizeof(quotes[0]))

// Function to send a quote to the client
void send_quote(int sockfd, struct sockaddr_in *client_addr, socklen_t client_len) {
    srand(time(NULL)); // Seed for random number generation
    const char *quote = quotes[rand() % NUM_QUOTES];
    
    // Send the quote
    sendto(sockfd, quote, strlen(quote) + 1, 0, (struct sockaddr *)client_addr, client_len);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUF_SIZE];

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;        // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces
    server_addr.sin_port = htons(PORT);      // Port number

    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Quote server is running on port %d...\n", PORT);

    while (1) {
        // Wait for a client message
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &client_len);
        if (n < 0) {
            perror("Error receiving data");
            continue;
        }
        buffer[n] = '\0'; // Null-terminate the message

        printf("Received request: %s\n", buffer);
        
        send_quote(sockfd, &client_addr, client_len);
    }

    // Close the socket
    close(sockfd);
    return 0;
}