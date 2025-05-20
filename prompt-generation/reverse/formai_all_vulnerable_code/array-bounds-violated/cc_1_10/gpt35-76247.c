//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);

    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(1);
    }

    if(connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(sock, buffer, strlen(buffer), 0);

    int received_size;
    while((received_size = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[received_size] = '\0';
        printf("%s", buffer);
    }

    if(received_size < 0) {
        perror("Failed to receive data from server");
        exit(1);
    }

    close(sock);
    return 0;
}