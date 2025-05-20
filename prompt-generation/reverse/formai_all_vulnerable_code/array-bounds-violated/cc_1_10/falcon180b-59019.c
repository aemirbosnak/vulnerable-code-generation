//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    char command[100];
    int n;

    printf("Enter POP3 server IP address: ");
    scanf("%s", inet_ntoa(((struct sockaddr_in *)&server_addr)->sin_addr));
    printf("Enter POP3 server port number: ");
    scanf("%d", &server_addr.sin_port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket() failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("connect() failed\n");
        exit(1);
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}