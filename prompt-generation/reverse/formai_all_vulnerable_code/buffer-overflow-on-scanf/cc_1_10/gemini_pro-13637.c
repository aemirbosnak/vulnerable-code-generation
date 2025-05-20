//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    // Step 1: Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        exit(1);
    }

    // Step 2: Set up the server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Step 3: Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect() failed");
        exit(1);
    }

    // Step 4: Send a command to the server
    char command[MAX_LINE];
    printf("Enter a command (e.g., LIST, RETR, STOR): ");
    scanf("%s", command);
    strcat(command, "\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send() failed");
        exit(1);
    }

    // Step 5: Receive the response from the server
    char response[MAX_LINE];
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, MAX_LINE, 0) == -1) {
        perror("recv() failed");
        exit(1);
    }

    // Step 6: Process the response
    printf("%s\n", response);

    // Step 7: Close the socket
    close(sockfd);

    return 0;
}