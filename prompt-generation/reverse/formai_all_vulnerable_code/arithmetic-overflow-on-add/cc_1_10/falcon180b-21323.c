//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_ADDRESS "localhost"
#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *message = "Subject: Test Message\r\n\r\nThis is a test message.";
    int bytes_sent, bytes_received;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    send(sockfd, message, strlen(message), 0);

    bytes_sent = strlen(message);
    bytes_received = 0;

    while (bytes_received < bytes_sent) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received += recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}