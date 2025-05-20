//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
/*
 * Simple HTTP Proxy
 *
 * This program acts as an HTTP proxy, forwarding requests to a target server and
 * returning the response to the client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 2) {
        printf("Usage: %s <target-server>\n", argv[0]);
        return 1;
    }

    // Create socket for client connections
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up address structure for target server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Resolve target server address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve target server address: %s\n", argv[1]);
        return 1;
    }
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to target server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Set up address structure for client
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    client_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to client address
    if (bind(sock, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for client connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    // Accept client connection
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Create buffers for client and server requests and responses
    char client_buf[BUFSIZE];
    char server_buf[BUFSIZE];

    // Read client request
    int client_req_len = recv(client_sock, client_buf, BUFSIZE, 0);
    if (client_req_len < 0) {
        perror("recv");
        return 1;
    }

    // Send client request to server
    int server_req_len = send(sock, client_buf, client_req_len, 0);
    if (server_req_len < 0) {
        perror("send");
        return 1;
    }

    // Read server response
    int server_resp_len = recv(sock, server_buf, BUFSIZE, 0);
    if (server_resp_len < 0) {
        perror("recv");
        return 1;
    }

    // Send server response to client
    int client_resp_len = send(client_sock, server_buf, server_resp_len, 0);
    if (client_resp_len < 0) {
        perror("send");
        return 1;
    }

    // Close sockets
    close(sock);
    close(client_sock);

    return 0;
}