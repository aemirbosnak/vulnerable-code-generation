//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PROXY_PORT 8888
#define SERVER_PORT 80
#define MAX_BUFFER_SIZE 4096

void handle_client_request(int client_socket, struct sockaddr_in *client_addr) {
    char buffer[MAX_BUFFER_SIZE];
    int received_size, sent_size;

    // Receive request from client
    received_size = recv(client_socket, buffer, MAX_BUFFER_SIZE-1, 0);
    if (received_size <= 0) {
        perror("Error receiving client request");
        return;
    }
    buffer[received_size] = '\0';

    // Check if request is valid
    if (strncmp(buffer, "GET", 3) != 0) {
        printf("Invalid request from %s:%d\n", inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
        return;
    }

    // Extract host and path from request
    char *host_pos = strstr(buffer, "Host:");
    if (host_pos == NULL) {
        printf("Invalid request from %s:%d\n", inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
        return;
    }
    host_pos += 6; // Skip "Host: "
    char *path_pos = strstr(buffer, "GET ");
    if (path_pos == NULL) {
        printf("Invalid request from %s:%d\n", inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
        return;
    }
    path_pos += 4; // Skip "GET "
    char *space_pos = strchr(path_pos, ' ');
    if (space_pos == NULL) {
        printf("Invalid request from %s:%d\n", inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port));
        return;
    }
    *space_pos = '\0';

    // Open connection to server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(host_pos);
    if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return;
    }

    // Send request to server
    sent_size = send(server_socket, buffer, strlen(buffer), 0);
    if (sent_size < 0) {
        perror("Error sending request to server");
        return;
    }

    // Receive response from server and send to client
    do {
        received_size = recv(server_socket, buffer, MAX_BUFFER_SIZE-1, 0);
        if (received_size <= 0) {
            break;
        }
        buffer[received_size] = '\0';
        sent_size = send(client_socket, buffer, received_size, 0);
        if (sent_size < 0) {
            perror("Error sending response to client");
            return;
        }
    } while (received_size > 0);

    close(server_socket);
}

int main() {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;
    int addr_len = sizeof(client_addr);

    // Create proxy socket
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating proxy socket");
        exit(EXIT_FAILURE);
    }

    // Bind proxy socket to port
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(PROXY_PORT);
    if (bind(proxy_socket, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding proxy socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, SOMAXCONN) < 0) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr *) &client_addr, (socklen_t *) &addr_len);
        if (client_socket < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Handle client request
        handle_client_request(client_socket, &client_addr);

        close(client_socket);
    }

    close(proxy_socket);
    return 0;
}