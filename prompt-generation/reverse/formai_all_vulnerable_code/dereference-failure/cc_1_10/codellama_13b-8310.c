//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
    // Check if the port number is provided as an argument
    if (argc != 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to a specific address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0)
    {
        perror("listen");
        return 1;
    }

    printf("Listening on port %s\n", argv[1]);

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0)
    {
        perror("accept");
        return 1;
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive and print the message
    char buf[BUF_SIZE];
    ssize_t n = recv(client_sock, buf, BUF_SIZE, 0);
    if (n < 0)
    {
        perror("recv");
        return 1;
    }

    printf("Received message: %s\n", buf);

    // Send a response
    char *response = "Hello, client!";
    send(client_sock, response, strlen(response), 0);

    // Close the socket
    close(client_sock);
    close(sock);

    return 0;
}