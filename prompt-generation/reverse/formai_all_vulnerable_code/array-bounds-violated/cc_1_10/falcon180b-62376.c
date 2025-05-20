//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <termios.h>

#define MAX_LINE_LEN 1024
#define POP3_PORT 110
#define USER "username"
#define PASS "password"

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE_LEN], recvline[MAX_LINE_LEN];
    char *ptr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send USER command
    sprintf(sendline, "USER %s\r\n", USER);
    send(sockfd, sendline, strlen(sendline), 0);

    // Read server response
    n = recv(sockfd, recvline, MAX_LINE_LEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Send PASS command
    sprintf(sendline, "PASS %s\r\n", PASS);
    send(sockfd, sendline, strlen(sendline), 0);

    // Read server response
    n = recv(sockfd, recvline, MAX_LINE_LEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Send LIST command
    sprintf(sendline, "LIST\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // Read server response
    n = recv(sockfd, recvline, MAX_LINE_LEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Close socket
    close(sockfd);

    return 0;
}