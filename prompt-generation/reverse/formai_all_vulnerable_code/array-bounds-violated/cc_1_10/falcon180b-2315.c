//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    int client_socket[MAX_CLIENTS];
    int max_socket = -1;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
    int response_len = strlen(response);
    int i;

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr) == -1) {
        perror("inet_pton");
        exit(1);
    }

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, addrlen) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        // Accept client connections
        if ((client_socket[max_socket] = accept(server_socket, (struct sockaddr *)&server_addr, &addrlen)) == -1) {
            perror("accept");
            exit(1);
        }

        printf("Client connected on socket %d\n", client_socket[max_socket]);

        if (max_socket == -1) {
            max_socket = 0;
        } else {
            max_socket++;
        }
    }

    return 0;
}