//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function to create a socket and connect to the server
int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sock;
    struct hostent *host_entry;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Get the server's IP address
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        perror("Failed to resolve hostname");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Fill server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr_list[0], host_entry->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send an HTTP GET request
void send_get_request(int sock, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];

    // Create the HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);

    // Send HTTP request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sock);
        exit(EXIT_FAILURE);
    }
}

// Function to receive the server response
void receive_response(int sock) {
    char response[BUFFER_SIZE];
    int bytes_received;

    // Print the server response
    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null-terminate the response
        printf("%s", response); // Print the response
    }

    if (bytes_received < 0) {
        perror("Failed to receive response");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    const int port = 80; // Default HTTP port

    // Create a socket and connect to the server
    int sock = create_socket(hostname, port);

    // Send HTTP GET request
    send_get_request(sock, hostname, path);

    // Receive and print the server response
    receive_response(sock);

    // Close the socket
    close(sock);

    return 0;
}