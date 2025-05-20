//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char *proxy_ip = "127.0.0.1"; // default proxy IP
    int proxy_port = 8080; // default proxy port

    if (argc == 3) {
        proxy_ip = argv[1];
        proxy_port = atoi(argv[2]);
    } else {
        printf("Usage: %s <proxy_ip> <proxy_port>\n", argv[0]);
    }

    printf("Starting proxy on %s:%d...\n", proxy_ip, proxy_port);

    // create a socket for incoming client requests
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // bind the socket to a local address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(proxy_port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        return 1;
    }

    // listen for incoming client requests
    if (listen(server_socket, 5) < 0) {
        perror("Failed to listen for incoming requests");
        return 1;
    }

    printf("Proxy running...\n");

    while (1) { // keep accepting client requests
        // accept an incoming client request
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Failed to accept client request");
            return 1;
        }

        // receive the client's request
        char buffer[MAX_BUFFER_SIZE];
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Failed to receive client request");
            continue; // move onto next client request
        }

        printf("Received client request:\n%s\n", buffer);

        // connect to the destination server
        int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (destination_socket < 0) {
            perror("Failed to create socket for destination server");
            close(client_socket);
            continue; // move onto next client request
        }

        struct sockaddr_in destination_address;
        destination_address.sin_family = AF_INET;
        destination_address.sin_addr.s_addr = inet_addr(proxy_ip);
        destination_address.sin_port = htons(proxy_port);

        if (connect(destination_socket, (struct sockaddr *) &destination_address, sizeof(destination_address)) < 0) {
            perror("Failed to connect to destination server");
            close(destination_socket);
            close(client_socket);
            continue; // move onto next client request
        }

        printf("Connected to destination server...\n");

        // send the client's request to the destination server
        int bytes_sent = send(destination_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("Failed to send client request to destination server");
            close(destination_socket);
            close(client_socket);
            continue; // move onto next client request
        }

        printf("Sent client request to destination server...\n");

        // receive the response from the destination server
        memset(buffer, 0, MAX_BUFFER_SIZE);
        bytes_received = recv(destination_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Failed to receive server response");
            close(destination_socket);
            close(client_socket);
            continue; // move onto next client request
        }

        printf("Received server response:\n%s\n", buffer);

        // send the server's response to the client
        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            perror("Failed to send server response to client");
            close(destination_socket);
            close(client_socket);
            continue; // move onto next client request
        }

        printf("Sent server response to client...\n");

        // close the sockets
        close(client_socket);
        close(destination_socket);
    }

    // close the server socket
    close(server_socket);
    return 0;
}