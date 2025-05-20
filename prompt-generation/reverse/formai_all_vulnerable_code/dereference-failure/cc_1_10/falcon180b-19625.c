//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT "12345"

// Function to handle errors
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Function to receive data from server
void receive_data(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Connection closed by server.\n");
            break;
        }

        printf("Received message: %s\n", buffer);
    }
}

// Function to send data to server
void send_data(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        printf("Enter message to send: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        int bytes_sent = send(sock, buffer, strlen(buffer), 0);

        if (bytes_sent <= 0) {
            printf("Connection closed by server.\n");
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *server_info = NULL;
    int result = getaddrinfo(argv[1], PORT, &hints, &server_info);

    if (result!= 0) {
        error("getaddrinfo");
    }

    int sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

    if (sock == -1) {
        error("socket");
    }

    result = connect(sock, server_info->ai_addr, server_info->ai_addrlen);

    if (result!= 0) {
        error("connect");
    }

    printf("Connected to server at %s:%s\n", argv[1], PORT);

    send_data(sock);
    receive_data(sock);

    close(sock);

    return 0;
}