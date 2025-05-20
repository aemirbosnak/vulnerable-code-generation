//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

int main(int argc, char *argv[]) {
    int client_socket, server_socket, proxy_port, bytes_received;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in proxy_address, server_address;
    struct hostent *server_info;

    // Get the proxy port if provided, else use default port 8080
    if (argc > 1) {
        proxy_port = atoi(argv[1]);
    } else {
        proxy_port = DEFAULT_PORT;
    }

    // Create a socket for client connections
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating client socket: ");
        exit(EXIT_FAILURE);
    }

    // Bind the client socket to the proxy address and port
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(proxy_port);
    if (bind(client_socket, (struct sockaddr*) &proxy_address, sizeof(proxy_address)) < 0) {
        perror("Error binding client socket to proxy port: ");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections
    listen(client_socket, 5);
    printf("Simple HTTP Proxy is listening on port %d...\n", proxy_port);

    while (1) {
        // Accept a client connection
        socklen_t client_address_length = sizeof(struct sockaddr_in);
        int client_connection = accept(client_socket, (struct sockaddr*) &proxy_address, &client_address_length);
        if (client_connection < 0) {
            perror("Error accepting client connection: ");
            exit(EXIT_FAILURE);
        }

        printf("%s:%d connected to the proxy\n", inet_ntoa(proxy_address.sin_addr), ntohs(proxy_address.sin_port));

        // Receive the client request
        memset(buffer, 0, MAX_BUFFER_SIZE);
        if ((bytes_received = recv(client_connection, buffer, MAX_BUFFER_SIZE - 1, 0)) < 0) {
            perror("Error receiving client request: ");
            exit(EXIT_FAILURE);
        }

        // Extract the host name from the client request
        char *host_name_start = strstr(buffer, "Host:");
        if (host_name_start == NULL) {
            close(client_connection);
            continue;
        }
        host_name_start += 6;
        char *host_name_end = strstr(host_name_start, "\r\n");
        if (host_name_end == NULL) {
            close(client_connection);
            continue;
        }
        char host_name[host_name_end - host_name_start + 1];
        strncpy(host_name, host_name_start, host_name_end - host_name_start);
        host_name[host_name_end - host_name_start] = '\0';
        printf("Received request for: %s\n", host_name);

        // Resolve the server IP address from the host name
        server_info = gethostbyname(host_name);
        if (server_info == NULL) {
            fprintf(stderr, "Error resolving server host name: %s\n", hstrerror(h_errno));
            close(client_connection);
            continue;
        }

        // Create a socket for the server connection
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            perror("Error creating server socket: ");
            exit(EXIT_FAILURE);
        }

        // Connect to the server socket
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        memcpy(&server_address.sin_addr.s_addr, server_info->h_addr, server_info->h_length);
        server_address.sin_port = htons(80);
        if (connect(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
            perror("Error connecting to server: ");
            close(server_socket);
            close(client_connection);
            continue;
        }

        // Forward the client request to the server
        send(server_socket, buffer, bytes_received, 0);

        // Receive the server response and forward it to the client
        while ((bytes_received = recv(server_socket, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
            send(client_connection, buffer, bytes_received, 0);
        }

        close(server_socket);
        close(client_connection);
        printf("Connection closed\n");
    }

    return 0;
}