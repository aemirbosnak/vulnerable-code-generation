//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <local-ip> <local-port> <remote-ip>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket for listening on the local IP and port
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options for reuse of the address and port
    int optval = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to the local IP and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections on the local socket
    if (listen(server_sock, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections from the client
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1) {
        perror("accept");
        return EXIT_FAILURE;
    }

    // Read the HTTP request from the client
    char request[MAX_BUF_SIZE];
    int request_len = recv(client_sock, request, MAX_BUF_SIZE - 1, 0);
    if (request_len == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    request[request_len] = '\0';

    // Parse the HTTP request to get the remote IP and port
    char *remote_ip = argv[3];
    char *remote_port = "80";
    char *ptr = strstr(request, "Host: ");
    if (ptr != NULL) {
        ptr += strlen("Host: ");
        char *colon = strchr(ptr, ':');
        if (colon != NULL) {
            *colon = '\0';
            remote_ip = ptr;
            ptr = colon + 1;
            remote_port = ptr;
        } else {
            remote_ip = ptr;
        }
    }

    // Create a socket for connecting to the remote IP and port
    int remote_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the remote IP and port
    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(remote_ip);
    remote_addr.sin_port = htons(atoi(remote_port));
    if (connect(remote_sock, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HTTP request to the remote server
    if (send(remote_sock, request, request_len, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response from the remote server
    char response[MAX_BUF_SIZE];
    int response_len = recv(remote_sock, response, MAX_BUF_SIZE - 1, 0);
    if (response_len == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    response[response_len] = '\0';

    // Send the HTTP response to the client
    if (send(client_sock, response, response_len, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the client and remote sockets
    close(client_sock);
    close(remote_sock);

    // Close the server socket
    close(server_sock);

    return EXIT_SUCCESS;
}