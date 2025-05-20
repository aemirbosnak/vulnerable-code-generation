//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define DEFAULT_PORT 80
#define BUFFER_SIZE 4096

void create_http_request(const char *host, const char *path, char *request_buffer) {
    sprintf(request_buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
}

int create_socket(const char *host, int port) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void send_request(int sock, const char *request_buffer) {
    if (send(sock, request_buffer, strlen(request_buffer), 0) < 0) {
        perror("Send failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    printf("Response from server:\n");

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the buffer
        printf("%s", buffer);  // Print the buffer
    }
    if (bytes_received < 0) {
        perror("Receive failed");
    }
    printf("\n");

    close(sock);  // Close the socket after receiving the response
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *path = argv[2];
    
    char request_buffer[BUFFER_SIZE];

    printf("Creating HTTP GET request for %s%s\n", host, path);

    create_http_request(host, path, request_buffer);
    
    int sock = create_socket(host, DEFAULT_PORT);
    
    send_request(sock, request_buffer);
    
    receive_response(sock);

    return EXIT_SUCCESS;
}