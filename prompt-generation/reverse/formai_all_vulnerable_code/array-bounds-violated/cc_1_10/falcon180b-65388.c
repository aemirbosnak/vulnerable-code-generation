//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_SIZE];
    int addr_len;
    int bytes_received;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("Socket created\n");

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Receive data from server
    addr_len = sizeof(server_addr);
    while (TRUE) {
        bytes_received = recv(sock, buffer, MAX_SIZE, 0);
        if (bytes_received <= 0) {
            if (bytes_received == -1) {
                perror("recv");
            } else {
                printf("Connection closed\n");
            }
            break;
        } else {
            buffer[bytes_received] = '\0';
            printf("Received: %s", buffer);
        }
    }

    // Close socket
    close(sock);

    return 0;
}