//FormAI DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

#define PORT 8888
#define BUFFER_SIZE 1024

void handle_client_request(int client_sockfd);

int main(int argc, char **argv) {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    char recv_buffer[BUFFER_SIZE];
    int optval = 1;

    // Create server socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("Socket option setting error");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);
    memset(&(server_address.sin_zero), '\0', 8);

    if (bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Socket binding error");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_sockfd, 10) == -1) {
        perror("Socket listening error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        socklen_t client_address_len = sizeof(client_address);

        // Accept new client connection
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_address_len)) == -1) {
            perror("Socket accepting error");
            continue;
        }

        printf("Client %s:%d connected\n", 
            inet_ntoa(client_address.sin_addr), 
            ntohs(client_address.sin_port));

        // Handle client request
        handle_client_request(client_sockfd);

        printf("Client %s:%d disconnected\n", 
            inet_ntoa(client_address.sin_addr), 
            ntohs(client_address.sin_port));

        close(client_sockfd);
    }

    close(server_sockfd);
    return 0;
}

void handle_client_request(int client_sockfd) {
    char recv_buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive HTTP request
    if ((bytes_received = recv(client_sockfd, recv_buffer, BUFFER_SIZE - 1, 0)) == -1) {
        perror("Could not receive HTTP request from client");
        exit(EXIT_FAILURE);
    }
    recv_buffer[bytes_received] = '\0';

    printf("HTTP request received:\n%s\n", recv_buffer);

    // Get request method and URL
    char method[BUFFER_SIZE], url[BUFFER_SIZE];
    sscanf(recv_buffer, "%s %s", method, url);

    // Check if request method is GET
    if (strcasecmp(method, "GET") != 0) {
        // Unsupported method
        const char *response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
        send(client_sockfd, response, strlen(response), 0);
        return;
    }

    // Open file corresponding to requested URL
    char file_path[BUFFER_SIZE];
    sprintf(file_path, ".%s", url);
    FILE *file = fopen(file_path, "r");

    // Check if file exists
    if (file == NULL) {
        // File not found
        const char *response = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(client_sockfd, response, strlen(response), 0);
        return;
    }

    // Read file contents into buffer
    char file_buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(file_buffer, 1, BUFFER_SIZE, file)) > 0) {
        send(client_sockfd, file_buffer, bytes_read, 0);
    }

    fclose(file);
}