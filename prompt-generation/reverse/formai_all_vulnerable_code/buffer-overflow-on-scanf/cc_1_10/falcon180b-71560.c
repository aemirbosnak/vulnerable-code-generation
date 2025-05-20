//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[50];
    char password[50];
    char buffer[1024];
    int n;
    int port = 110;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, "localhost", &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);

    if (n <= 0) {
        printf("Error receiving response from server\n");
        exit(1);
    }

    printf("Received response from server: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);

    if (n <= 0) {
        printf("Error receiving response from server\n");
        exit(1);
    }

    printf("Received response from server: %s", buffer);

    close(sockfd);
    return 0;
}