//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_request(int client_socket);
void send_response(int client_socket, const char *response, int length);
void error_exit(const char *message);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error_exit("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Error binding socket");
    }

    if (listen(server_socket, 10) < 0) {
        error_exit("Error listening on socket");
    }

    printf("Proxy server is running on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        handle_request(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[10], url[256], protocol[10], host[256];
    int received = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (received < 0) {
        perror("Error receiving data");
        return;
    }

    buffer[received] = '\0';
    sscanf(buffer, "%s %s %s", method, url, protocol);

    if (strcmp(method, "GET") != 0) {
        const char *response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        send_response(client_socket, response, strlen(response));
        return;
    }

    char *host_start = strstr(url, "//") + 2;
    char *host_end = strchr(host_start, '/');
    int host_length = host_end ? host_end - host_start : strlen(host_start);
    
    strncpy(host, host_start, host_length);
    host[host_length] = '\0';

    // Create a connection to the intended server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // assuming HTTP traffic on port 80
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return;
    }

    // Send the request to the intended server
    send(server_socket, buffer, received, 0);

    // Read the response from the server
    while ((received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, buffer, received, 0);
    }

    if (received < 0) {
        perror("Error receiving from server");
    }

    close(server_socket);
}

void send_response(int client_socket, const char *response, int length) {
    send(client_socket, response, length, 0);
}

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}