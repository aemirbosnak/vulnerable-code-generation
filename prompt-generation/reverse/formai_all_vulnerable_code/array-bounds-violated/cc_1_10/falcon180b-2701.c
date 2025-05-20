//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_line[MAX_LINE_LENGTH];
    char recv_line[MAX_LINE_LENGTH];
    char *user;
    char *pass;
    char *host;
    char *port;
    int n;

    // Get user input for host, port, username, and password
    printf("Enter hostname: ");
    scanf("%s", host);
    printf("Enter port number: ");
    scanf("%s", port);
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    inet_pton(AF_INET, host, &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send USER command
    sprintf(send_line, "USER %s\r\n", user);
    send(sockfd, send_line, strlen(send_line), 0);

    // Send PASS command
    sprintf(send_line, "PASS %s\r\n", pass);
    send(sockfd, send_line, strlen(send_line), 0);

    // Send STAT command
    sprintf(send_line, "STAT\r\n");
    send(sockfd, send_line, strlen(send_line), 0);

    // Receive response
    n = recv(sockfd, recv_line, MAX_LINE_LENGTH, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }
    recv_line[n] = '\0';
    printf("Response: %s", recv_line);

    // Close socket
    close(sockfd);
    return 0;
}