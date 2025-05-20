//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

// A lovely thank you message
void print_welcome_message() {
    printf("Welcome to the Grateful HTTP Client!\n");
    printf("This program will help you fetch data from the web. Let's get started! \n");
}

// Function to create a socket and connect to the server
int create_socket(char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;

    // Create the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Convert hostname to IP address
    struct in_addr addr;
    if (inet_pton(AF_INET, hostname, &addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_addr = addr;

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send an HTTP GET request
void send_http_request(int sock, char *path) {
    char request[BUFFER_SIZE];

    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", path);
    
    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
}

// Function to read the response from the server
void read_http_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Read the response
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate
        printf("%s", buffer); // Output the response
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }
}

int main(int argc, char *argv[]) {
    print_welcome_message(); // Show welcoming message

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *path = argv[2];

    // Creating the socket and connecting to the server
    int sock = create_socket(hostname, 80);

    // Sending the HTTP request to the server
    send_http_request(sock, path);

    // Reading and printing the HTTP response
    read_http_response(sock);

    // Close the socket and exit gracefully
    close(sock);
    printf("\nThank you for using the Grateful HTTP Client. Goodbye!\n");

    return 0;
}