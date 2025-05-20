//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <netinet/in.h>

#define SERVER_IP "imap.gmail.com"
#define SERVER_PORT 143
#define USER_NAME "your_username"
#define USER_PASS "your_password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *buffer = malloc(1024);
    int n;

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // convert IP address to binary format
    if ((server = gethostbyname(SERVER_IP)) == NULL) {
        perror("gethostbyname failed");
        exit(1);
    }
    memcpy((char *)&serveraddr, server->h_addr, server->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connection failed");
        exit(1);
    }

    // login to the server
    printf("Enter your username: ");
    scanf("%s", USER_NAME);
    printf("Enter your password: ");
    scanf("%s", USER_PASS);

    // send a login request
    if (send(sockfd, USER_NAME, strlen(USER_NAME), 0) < 0 ||
        send(sockfd, USER_PASS, strlen(USER_PASS), 0) < 0) {
        perror("Sending login request failed");
        exit(1);
    }

    // receive the server response
    if ((n = recv(sockfd, buffer, 1024, 0)) < 0) {
        perror("Receiving server response failed");
        exit(1);
    }

    // check if the login was successful
    if (buffer[0]!= '+') {
        printf("Login failed. Please check your username and password.\n");
        exit(1);
    }

    // list the available mailboxes
    printf("Available mailboxes:\n");
    if ((n = recv(sockfd, buffer, 1024, 0)) < 0) {
        perror("Receiving mailbox list failed");
        exit(1);
    }
    while (n > 0) {
        printf("%s\n", buffer);
        n = recv(sockfd, buffer, 1024, 0);
    }

    // log out from the server
    printf("Logging out...\n");
    if ((n = send(sockfd, "QUIT", strlen("QUIT"), 0)) < 0) {
        perror("Sending QUIT command failed");
        exit(1);
    }

    // receive the server response
    if ((n = recv(sockfd, buffer, 1024, 0)) < 0) {
        perror("Receiving server response failed");
        exit(1);
    }

    // close the socket
    printf("Connection closed.\n");
    close(sockfd);

    return 0;
}