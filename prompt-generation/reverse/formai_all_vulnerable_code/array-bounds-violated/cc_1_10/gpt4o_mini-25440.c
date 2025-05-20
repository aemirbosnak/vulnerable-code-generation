//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    char method[10], host[255], path[255];
    int bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_read < 0) {
        close(client_sock);
        return;
    }

    buffer[bytes_read] = '\0';

    // Parse the request
    if (sscanf(buffer, "%s %s %*s", method, path) < 2) {
        close(client_sock);
        return;
    }

    // Simple handling for GET method
    if (strcmp(method, "GET") == 0) {
        char *host_start = strstr(buffer, "Host: ");
        if (host_start == NULL) {
            close(client_sock);
            return;
        }
        
        sscanf(host_start, "Host: %s", host);
        char *port_pos = strchr(host, ':');
        int port = 80; // Default HTTP port

        if (port_pos) {
            *port_pos = '\0';
            port = atoi(port_pos + 1);
        }

        // Create a socket to the target server
        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock < 0) {
            close(client_sock);
            return;
        }

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use actual DNS resolution for production

        // Connect to the server
        if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            close(server_sock);
            close(client_sock);
            return;
        }

        // Forward the request to the server
        send(server_sock, buffer, bytes_read, 0);

        // Receive the response from the server
        while ((bytes_read = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
            send(client_sock, buffer, bytes_read, 0);
        }

        close(server_sock);
    }

    close(client_sock);
}

int main() {
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        error("Failed to create socket");
    }

    int opt = 1;
    setsockopt(proxy_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_sock, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        close(proxy_sock);
        error("Bind failed");
    }

    if (listen(proxy_sock, 5) < 0) {
        close(proxy_sock);
        error("Listen failed");
    }

    printf("Proxy server listening on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addrlen = sizeof(client_addr);
        int client_sock = accept(proxy_sock, (struct sockaddr*)&client_addr, &addrlen);
        if (client_sock < 0) {
            perror("Failed to accept connection");
            continue;
        }

        handle_client(client_sock);
    }

    close(proxy_sock);
    return 0;
}