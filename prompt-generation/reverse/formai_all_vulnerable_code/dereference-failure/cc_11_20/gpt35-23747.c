//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <proxy_port> <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    int proxy_port = atoi(argv[1]);
    char *server_ip = argv[2];
    int server_port = atoi(argv[3]);

    // Create the proxy socket
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Bind the socket to the proxy port
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind socket");
        close(proxy_socket);
        return 1;
    }

    // Listen for client connections
    if (listen(proxy_socket, 1) < 0) {
        perror("Failed to listen");
        close(proxy_socket);
        return 1;
    }

    printf("Proxy server started on port %d\n", proxy_port);

    while (1) {
        // Accept client connection
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Failed to accept");
            close(proxy_socket);
            return 1;
        }

        // Connect to the server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            perror("Failed to create socket");
            close(client_socket);
            continue;
        }

        struct hostent *server = gethostbyname(server_ip);
        if (server == NULL) {
            perror("Failed to get server by hostname");
            close(client_socket);
            close(server_socket);
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = ((struct in_addr *)(server->h_addr))->s_addr;
        server_addr.sin_port = htons(server_port);

        if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Failed to connect to server");
            close(client_socket);
            close(server_socket);
            continue;
        }

        // Forward requests from the client to the server
        char buffer[MAX_BUFFER_SIZE];
        int bytes_read;

        while ((bytes_read = read(client_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
            if (write(server_socket, buffer, bytes_read) < 0) {
                perror("Failed to write to server");
                break;
            }
        }

        if (bytes_read < 0) {
            perror("Failed to read from client");
        }

        // Forward responses from the server to the client
        while ((bytes_read = read(server_socket, buffer, MAX_BUFFER_SIZE)) > 0) {
            if (write(client_socket, buffer, bytes_read) < 0) {
                perror("Failed to write to client");
                break;
            }
        }

        if (bytes_read < 0) {
            perror("Failed to read from server");
        }

        close(client_socket);
        close(server_socket);
    }

    close(proxy_socket);
    return 0;
}