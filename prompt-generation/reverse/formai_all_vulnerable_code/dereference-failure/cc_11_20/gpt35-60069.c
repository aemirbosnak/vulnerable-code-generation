//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];

    // check if user has provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("error creating socket");
        exit(EXIT_FAILURE);
    }

    // get server details from hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "error: no such host\n");
        exit(EXIT_FAILURE);
    }

    // initialize serv_addr with server details and port number
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("error connecting");
        exit(EXIT_FAILURE);
    }

    // receive welcome message from server
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("error receiving welcome message");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // send login credentials to server
    char username[BUF_SIZE/2], password[BUF_SIZE/2];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    char login_msg[BUF_SIZE];
    sprintf(login_msg, "LOGIN %s %s\n", username, password);
    n = send(sockfd, login_msg, strlen(login_msg), 0);
    if (n < 0) {
        perror("error sending login credentials");
        exit(EXIT_FAILURE);
    }

    // receive server response to login
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("error receiving response to login credentials");
        exit(EXIT_FAILURE);
    }
    if (strstr(buffer, "OK") == NULL) {
        printf("login failed. server response: %s", buffer);
        exit(EXIT_FAILURE);
    }
    printf("login successful\n");

    // list all mailboxes
    n = send(sockfd, "LIST \"\" *\n", strlen("LIST \"\" *\n"), 0);
    if (n < 0) {
        perror("error sending list mailboxes command");
        exit(EXIT_FAILURE);
    }
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("error receiving list of mailboxes");
        exit(EXIT_FAILURE);
    }
    printf("List of mailboxes:\n%s", buffer);

    // logout and close connection
    n = send(sockfd, "LOGOUT\n", strlen("LOGOUT\n"), 0);
    if (n < 0) {
        perror("error sending logout command");
        exit(EXIT_FAILURE);
    }
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("error receiving response to logout command");
        exit(EXIT_FAILURE);
    }
    if (strstr(buffer, "BYE") == NULL) {
        printf("logout failed. server response: %s", buffer);
        exit(EXIT_FAILURE);
    }
    printf("logout successful\n");
    close(sockfd);

    return 0;
}