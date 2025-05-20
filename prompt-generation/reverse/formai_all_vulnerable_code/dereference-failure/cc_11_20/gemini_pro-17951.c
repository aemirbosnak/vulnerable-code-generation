//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main() {
    // Create a listening socket
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        return 1;
    }

    // Bind the listening socket to the loopback interface and port 8080
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(8080);
    listen_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (bind(listen_sock, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(listen_sock, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Main loop
    while (1) {
        // Accept an incoming connection
        int client_sock = accept(listen_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Read the HTTP request from the client
        char buf[MAX_BUF_SIZE];
        int bytes_received = recv(client_sock, buf, MAX_BUF_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            close(client_sock);
            continue;
        }

        // Parse the HTTP request
        char *method = strtok(buf, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Check if the request is valid
        if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
            // Send a 400 Bad Request response
            char *response = "HTTP/1.1 400 Bad Request\r\n\r\n";
            send(client_sock, response, strlen(response), 0);
            close(client_sock);
            continue;
        }

        // Send a 200 OK response
        char *response = "HTTP/1.1 200 OK\r\n\r\n";
        send(client_sock, response, strlen(response), 0);

        // Send the requested file
        FILE *file = fopen(path, "rb");
        if (file == NULL) {
            // Send a 404 Not Found response
            char *response = "HTTP/1.1 404 Not Found\r\n\r\n";
            send(client_sock, response, strlen(response), 0);
            close(client_sock);
            continue;
        }

        // Send the file contents
        char chunk[MAX_BUF_SIZE];
        while ((bytes_received = fread(chunk, 1, MAX_BUF_SIZE, file)) > 0) {
            send(client_sock, chunk, bytes_received, 0);
        }

        // Close the file
        fclose(file);

        // Close the client socket
        close(client_sock);
    }

    // Close the listening socket
    close(listen_sock);

    return 0;
}