//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFF_SIZE 4096

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Create a socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 2;
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 3;
    }
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 4;
    }

    // Send a message to the server.
    char *msg = "Hello, server!";
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("send");
        return 5;
    }

    // Receive a message from the server.
    char buf[BUFF_SIZE];
    int n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 6;
    }
    buf[n] = '\0';

    // Print the message from the server.
    printf("Received from server: %s\n", buf);

    // Close the socket.
    close(sock);

    return 0;
}