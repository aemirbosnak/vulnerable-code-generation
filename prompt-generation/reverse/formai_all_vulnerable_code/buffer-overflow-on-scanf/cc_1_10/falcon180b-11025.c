//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024 // size of buffer for receiving data

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char command[50];
    char response[BUFFER_SIZE];
    int n;
    int port = 110; // POP3 port number

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("localhost"); // change to server IP address if needed

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    sprintf(command, "STAT\r\n");
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    sprintf(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}