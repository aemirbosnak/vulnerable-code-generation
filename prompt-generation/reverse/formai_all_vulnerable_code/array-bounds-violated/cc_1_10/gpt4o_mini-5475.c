//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

// Function to print usage instructions
void print_usage(const char *program_name) {
    printf("Usage: %s <hostname> <port> <path>\n", program_name);
}

// Function to create a TCP socket and connect to the server
int create_socket_and_connect(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Resolve hostname to IP
    if ((host = gethostbyname(hostname)) == NULL) {
        herror("gethostbyname");
        close(sock);
        return -1;
    }

    // Prepare server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -1;
    }
    
    return sock;
}

// Function to send an HTTP GET request
int send_http_get_request(int sock, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];

    // Create the HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", path, hostname);

    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Send failed");
        return -1;
    }

    return 0;
}

// Function to receive the server response
void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Receive and print the response
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *path = argv[3];

    // Create the socket and connect to the server
    int sock = create_socket_and_connect(hostname, port);
    if (sock < 0) {
        return EXIT_FAILURE;
    }

    // Send the HTTP GET request
    if (send_http_get_request(sock, hostname, path) < 0) {
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive and display the server's response
    receive_response(sock);

    // Clean up
    close(sock);
    return EXIT_SUCCESS;
}