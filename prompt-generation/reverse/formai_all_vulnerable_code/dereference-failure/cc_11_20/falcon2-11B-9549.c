//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 143

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int n;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set up server address struct
    server = gethostbyname("imap.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // login to server
    char username[] = "yourusername";
    char password[] = "yourpassword";
    char *login_command = "LOGIN \"%s\" \"%s\"\r\n";
    char *result;

    if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    if (recv(sockfd, &result, 1024, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s", result);

    // check for valid login
    if (strstr(result, "OK") == NULL) {
        printf("Login failed\n");
        exit(1);
    }

    // list mailbox
    char *list_command = "LIST \"\"\r\n";
    if (send(sockfd, list_command, strlen(list_command), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    if (recv(sockfd, &result, 1024, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s", result);

    // fetch messages
    char *fetch_command = "UID FETCH 1 (BODY.PEEK[])\r\n";
    if (send(sockfd, fetch_command, strlen(fetch_command), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    if (recv(sockfd, &result, 1024, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s", result);

    // close socket
    close(sockfd);

    return 0;
}