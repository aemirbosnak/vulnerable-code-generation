//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: lively
// Hey there! Welcome to this super cool IMAP Client program
// that I created just for you!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

char username[255];
char password[255];
char mailbox[255];

void login(char* hostname, int port) {
    // Connect to the IMAP server and begin the login process
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent* server = gethostbyname(hostname);
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[1024];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    printf("Username: ");
    scanf("%s", username);
    sprintf(buffer, "a001 LOGIN %s ", username);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "a002 LOGIN %s %s\r\n", username, password);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    strcpy(mailbox, "INBOX");
    sprintf(buffer, "a003 SELECT %s\r\n", mailbox);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

void list_messages(int sockfd) {
    char buffer[1024];
    sprintf(buffer, "a004 FETCH 1:* BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)]\r\n", mailbox);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname [port]\n", argv[0]);
        exit(1);
    }

    char* hostname = argv[1];
    int port = 143;
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    login(hostname, port);

    list_messages(1);

    return 0;
}