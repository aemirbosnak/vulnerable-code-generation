//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>      // for printf
#include <stdlib.h>     // for exit
#include <string.h>     // for memset
#include <sys/socket.h> // for socket functions
#include <arpa/inet.h>  // for inet_addr
#include <unistd.h>     // for close

int main(int argc, char *argv[]) {
    // Check for command line arguments
    if (argc != 3) {
        printf("Usage: %s <proxyport> <serverip>\n", argv[0]);
        exit(1);
    }
    // Create a socket for the proxy
    int proxy_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (proxy_sock == -1) {
        printf("Error: Could not create proxy socket\n");
        exit(1);
    }
    // Parse the port number and server IP address from the command line arguments
    int proxy_port = atoi(argv[1]);
    char *server_ip = argv[2];
    // Bind the proxy socket to a local address and port
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(proxy_port);
    if (bind(proxy_sock, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) == -1) {
        printf("Error: Could not bind proxy socket\n");
        close(proxy_sock);
        exit(1);
    }
    // Listen for incoming connections from clients
    if (listen(proxy_sock, SOMAXCONN) == -1) {
        printf("Error: Could not listen on proxy socket\n");
        close(proxy_sock);
        exit(1);
    }
    printf("Proxy listening on port %d\n", proxy_port);
    // Main loop to handle connections
    while (1) {
        // Accept a new connection from a client
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(proxy_sock, (struct sockaddr *) &client_addr, &client_len);
        if (client_sock == -1) {
            printf("Error: Could not accept client connection\n");
            continue;
        }
        printf("Accepted a connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        // Create a socket for the server
        int server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (server_sock == -1) {
            printf("Error: Could not create server socket\n");
            close(client_sock);
            continue;
        }
        // Connect to the server
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(server_ip);
        server_addr.sin_port = htons(80); // HTTP port
        if (connect(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            printf("Error: Could not connect to server\n");
            close(server_sock);
            close(client_sock);
            continue;
        }
        // Loop to read data from the client and forward it to the server
        char buf[BUFSIZ];
        int bytes_read, bytes_written;
        while ((bytes_read = recv(client_sock, buf, BUFSIZ, 0)) > 0) {
            bytes_written = send(server_sock, buf, bytes_read, 0);
            if (bytes_written != bytes_read) {
                printf("Error: Could not forward request to server\n");
                close(server_sock);
                close(client_sock);
                break;
            }
        }
        // Loop to read data from the server and forward it to the client
        while ((bytes_read = recv(server_sock, buf, BUFSIZ, 0)) > 0) {
            bytes_written = send(client_sock, buf, bytes_read, 0);
            if (bytes_written != bytes_read) {
                printf("Error: Could not forward response to client\n");
                close(server_sock);
                close(client_sock);
                break;
            }
        }
        // Close the sockets for this connection
        close(server_sock);
        close(client_sock);
        printf("Connection closed\n");
    }
    close(proxy_sock);
    return 0;
}