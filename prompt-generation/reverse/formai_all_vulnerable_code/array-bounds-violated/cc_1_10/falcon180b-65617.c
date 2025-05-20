//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char command[100];
    char response[200];
    int n;

    printf("Enter IMAP server IP address: ");
    scanf("%s", &server_addr.sin_addr.s_addr);

    printf("Enter IMAP server port: ");
    scanf("%d", &server_addr.sin_port);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_addr.sin_port);

    if (inet_pton(AF_INET, server_addr.sin_addr.s_addr, &server_addr.sin_addr) <= 0) {
        printf("Error converting IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to IMAP server\n");

    sprintf(command, "A001 LOGIN %s %s", username, password);

    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, sizeof(response), 0);

    response[n] = '\0';

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}