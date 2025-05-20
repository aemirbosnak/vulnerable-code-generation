//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sock, n;
    struct sockaddr_in server;
    char buffer[MAX_LINE];

    if (argc != 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    while (1) {
        printf("Enter message: ");
        fgets(buffer, MAX_LINE, stdin);
        n = write(sock, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }
        n = read(sock, buffer, MAX_LINE);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        printf("Message received: %s\n", buffer);
    }

    close(sock);
    return 0;
}