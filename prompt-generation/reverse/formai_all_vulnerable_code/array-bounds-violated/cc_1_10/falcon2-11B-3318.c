//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 4096
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8080

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int server_addr_len, client_addr_len;
    char packet[MAX_PACKET_SIZE], buffer[MAX_PACKET_SIZE];
    int buffer_len, packet_len;

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind to the server address and port
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Accept a client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Receive the client request
        bzero(packet, MAX_PACKET_SIZE);
        packet_len = recv(client_socket, packet, MAX_PACKET_SIZE, 0);
        if (packet_len == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        packet[packet_len] = '\0';

        // Process the client request
        printf("Received request: %s\n", packet);

        // Send the server response
        bzero(buffer, MAX_PACKET_SIZE);
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello, World!</body></html>");
        buffer_len = strlen(buffer);
        if (send(client_socket, buffer, buffer_len, 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        // Close the client connection
        close(client_socket);
    }

    close(server_socket);
    return 0;
}