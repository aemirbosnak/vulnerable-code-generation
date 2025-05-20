//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 2048

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <local port>\n", argv[0]);
        return 1;
    }

    // Create a socket for the proxy and bind it to the specified port.
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(atoi(argv[3]));

    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections on the proxy port.
    if (listen(proxy_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Main loop: accept incoming connections and handle them.
    while (1) {
        // Accept an incoming connection.
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Read the request from the client.
        char request[BUFF_SIZE];
        int request_len = recv(client_fd, request, BUFF_SIZE - 1, 0);
        if (request_len <= 0) {
            perror("recv");
            close(client_fd);
            continue;
        }

        // Parse the request to extract the target host and port.
        char *host = NULL;
        char *port = NULL;
        char *line = request;
        while ((line = strchr(line, '\n')) != NULL) {
            if (strncmp(line, "Host: ", 6) == 0) {
                host = line + 6;
                while (*host == ' ') host++;
                port = strchr(host, ':');
                if (port != NULL) *port++ = '\0';
                break;
            }
            line++;
        }

        if (host == NULL || port == NULL) {
            // Invalid request. Send a 400 Bad Request response.
            char response[] = "HTTP/1.1 400 Bad Request\n\n";
            send(client_fd, response, strlen(response), 0);
            close(client_fd);
            continue;
        }

        // Connect to the remote server.
        int remote_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_fd == -1) {
            perror("socket");
            close(client_fd);
            continue;
        }

        struct sockaddr_in remote_addr;
        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(host);
        remote_addr.sin_port = htons(atoi(port));

        if (connect(remote_fd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
            perror("connect");
            close(client_fd);
            close(remote_fd);
            continue;
        }

        // Forward the request to the remote server.
        send(remote_fd, request, request_len, 0);

        // Receive the response from the remote server.
        char response[BUFF_SIZE];
        int response_len = recv(remote_fd, response, BUFF_SIZE - 1, 0);
        if (response_len <= 0) {
            perror("recv");
            close(client_fd);
            close(remote_fd);
            continue;
        }

        // Send the response to the client.
        send(client_fd, response, response_len, 0);

        // Close the connections.
        close(client_fd);
        close(remote_fd);
    }

    // Close the proxy socket.
    close(proxy_fd);

    return 0;
}