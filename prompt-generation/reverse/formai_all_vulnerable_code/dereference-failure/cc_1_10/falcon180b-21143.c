//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "localhost", &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send USER command
    sprintf(sendline, "USER %s\r\n", argv[1]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send PASS command
    sprintf(sendline, "PASS %s\r\n", argv[2]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send STAT command
    sprintf(sendline, "STAT\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // Receive server response
    n = recv(sockfd, recvline, MAX_LINE, 0);
    recvline[n] = '\0';
    printf("Server response: %s", recvline);

    // Close socket
    close(sockfd);

    return 0;
}