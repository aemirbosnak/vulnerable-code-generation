//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUF_SIZE 1024

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_addr, client_addr;
    char buf[MAX_BUF_SIZE];
    int recv_len;

    // Create a TCP server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Loop forever, accepting connections and forwarding requests
    while (1) {
        // Accept an incoming connection
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Receive the request from the client
        memset(buf, 0, MAX_BUF_SIZE);
        recv_len = recv(client_socket, buf, MAX_BUF_SIZE, 0);
        if (recv_len < 0) {
            perror("recv");
            close(client_socket);
            continue;
        }

        // Print the request to the console
        printf("Received request:\n%s\n", buf);

        // Parse the request to get the target hostname and port
        char *host = strstr(buf, "Host: ") + 6;
        char *port = strstr(host, ":");
        if (port == NULL) {
            port = "80";
        } else {
            *port = '\0';
            port++;
        }

        // Create a TCP socket to connect to the target server
        int target_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (target_socket < 0) {
            perror("socket");
            close(client_socket);
            continue;
        }

        // Set up the target server address
        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(host);
        target_addr.sin_port = htons(atoi(port));

        // Connect to the target server
        if (connect(target_socket, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
            perror("connect");
            close(client_socket);
            close(target_socket);
            continue;
        }

        // Forward the request to the target server
        if (send(target_socket, buf, recv_len, 0) < 0) {
            perror("send");
            close(client_socket);
            close(target_socket);
            continue;
        }

        // Receive the response from the target server
        memset(buf, 0, MAX_BUF_SIZE);
        recv_len = recv(target_socket, buf, MAX_BUF_SIZE, 0);
        if (recv_len < 0) {
            perror("recv");
            close(client_socket);
            close(target_socket);
            continue;
        }

        // Forward the response to the client
        if (send(client_socket, buf, recv_len, 0) < 0) {
            perror("send");
            close(client_socket);
            close(target_socket);
            continue;
        }

        // Close the client and target sockets
        close(client_socket);
        close(target_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}