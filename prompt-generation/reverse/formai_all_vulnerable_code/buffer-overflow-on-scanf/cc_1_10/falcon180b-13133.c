//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char send_buf[MAX_COMMAND_LENGTH], recv_buf[MAX_RESPONSE_LENGTH];
    char username[64], password[64];

    printf("Enter POP3 server address: ");
    scanf("%s", argv[1]);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    recv(sockfd, recv_buf, MAX_RESPONSE_LENGTH, 0);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    recv(sockfd, recv_buf, MAX_RESPONSE_LENGTH, 0);

    if (strncmp(recv_buf, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    printf("Authentication successful\n");

    char command[MAX_COMMAND_LENGTH];
    strcpy(command, "LIST");
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, recv_buf, MAX_RESPONSE_LENGTH, 0);

    printf("Mailbox content:\n%s", recv_buf);

    close(sockfd);
    return 0;
}