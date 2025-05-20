//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, bytes_recv, i;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXSIZE];
    char username[20], password[20], email[50];
    char host[50], body[MAXSIZE];

    /* Get user input */
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter your email address: ");
    scanf("%s", email);

    /* Get the hostname from the email address */
    for (i = 0; email[i] != '@'; i++) {
        host[i] = email[i];
    }
    host[i] = '\0';

    /* Set up the socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    /* Get server information */
    server = gethostbyname(host);
    if (server == NULL) {
        perror("Error, no such host");
        exit(1);
    }

    /* Set up the structure to connect to the server */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(143); // IMAP Port

    /* Connect to the server */
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    /* Receive the server greeting */
    bzero(buffer,MAXSIZE);
    bytes_recv = recv(sockfd,buffer,MAXSIZE,0);
    if (bytes_recv < 0) {
        perror("Error receiving from socket");
        exit(1);
    }

    /* Send the login information */
    sprintf(body, "LOGIN %s %s\r\n", username, password);
    send(sockfd, body, strlen(body), 0);
    bzero(buffer,MAXSIZE);
    bytes_recv = recv(sockfd,buffer,MAXSIZE,0);
    if (bytes_recv < 0) {
        perror("Error receiving from socket");
        exit(1);
    }
    printf("%s", buffer);

    /* Send the select command */
    sprintf(body, "SELECT INBOX\r\n");
    send(sockfd, body, strlen(body), 0);
    bzero(buffer,MAXSIZE);
    bytes_recv = recv(sockfd,buffer,MAXSIZE,0);
    if (bytes_recv < 0) {
        perror("Error receiving from socket");
        exit(1);
    }
    printf("%s", buffer);

    /* Send the fetch command to retrieve the messages */
    sprintf(body, "FETCH 1:* BODY[TEXT]\r\n");
    send(sockfd, body, strlen(body), 0);
    bzero(buffer,MAXSIZE);
    bytes_recv = recv(sockfd,buffer,MAXSIZE,0);
    if (bytes_recv < 0) {
        perror("Error receiving from socket");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}