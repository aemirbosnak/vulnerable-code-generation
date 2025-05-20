//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {

    if(argc < 4) {
        printf("Usage: ./proxy <ip_address> <port> <listening_port>\n");
        exit(0);
    }

    char* ip_address = argv[1];
    int server_port = atoi(argv[2]);
    int listening_port = atoi(argv[3]);

    struct sockaddr_in client_addr, server_addr, listening_addr;

    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(listening_socket == -1) {
        printf("Error creating listening socket!\n");
        exit(1);
    }

    listening_addr.sin_family = AF_INET;
    listening_addr.sin_addr.s_addr = INADDR_ANY;
    listening_addr.sin_port = htons(listening_port);

    if(bind(listening_socket, (struct sockaddr*) &listening_addr, sizeof(listening_addr)) == -1) {
        printf("Error binding socket to address!\n");
        exit(1);
    }

    if(listen(listening_socket, 10) == -1) {
        printf("Error listening on socket!\n");
        exit(1);
    }

    printf("Proxy server running on port %d\n", listening_port);

    while(1) {

        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(listening_socket, (struct sockaddr*) &client_addr, &client_len);

        if(client_socket == -1) {
            printf("Error accepting connection from client!\n");
            exit(1);
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        if(recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
            printf("Error receiving data from client!\n");
            exit(1);
        }

        printf("Received request from client:\n%s\n", buffer);

        int server_socket = socket(AF_INET, SOCK_STREAM, 0);

        if(server_socket == -1) {
            printf("Error creating server socket!\n");
            exit(1);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(server_port);
        server_addr.sin_addr.s_addr = inet_addr(ip_address);

        if(connect(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
            printf("Error connecting to server!\n");
            exit(1);
        }

        if(send(server_socket, buffer, strlen(buffer), 0) == -1) {
            printf("Error sending data to server!\n");
            exit(1);
        }

        memset(buffer, 0, BUFFER_SIZE);

        if(recv(server_socket, buffer, BUFFER_SIZE, 0) == -1) {
            printf("Error receiving data from server!\n");
            exit(1);
        }

        printf("Received response from server:\n%s\n", buffer);

        if(send(client_socket, buffer, strlen(buffer), 0) == -1) {
            printf("Error sending data to client!\n");
            exit(1);
        }

        close(client_socket);
        close(server_socket);
    }
    return 0;
}