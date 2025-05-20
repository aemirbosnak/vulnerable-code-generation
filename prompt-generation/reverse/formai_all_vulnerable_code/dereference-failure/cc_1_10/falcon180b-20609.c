//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send USER command
    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    // send PASS command
    sprintf(buffer, "PASS %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    // send PWD command
    sprintf(buffer, "PWD\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // receive response
    memset(buffer, 0, BUF_SIZE);
    recv(sockfd, buffer, BUF_SIZE - 1, 0);
    printf("%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}