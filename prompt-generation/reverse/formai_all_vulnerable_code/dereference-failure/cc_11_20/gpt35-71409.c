//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char buffer[BUFFSIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server...\n");

    bzero(buffer,BUFFSIZE);
    n = read(sockfd, buffer, BUFFSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("IMAP Server: %s", buffer);

    // Login to IMAP Server
    char cmd[1024];
    char username[128];
    char password[128];
    char tmpbuf[BUFFSIZE];

    printf("Username: ");
    fgets(username, 128, stdin);
    username[strlen(username)-1] = '\0';

    snprintf(cmd, 1024, "A001 LOGIN %s ", username);
    n = write(sockfd, cmd, strlen(cmd));
    bzero(tmpbuf,BUFFSIZE);
    n = read(sockfd, tmpbuf, BUFFSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    if (tmpbuf[0] != '+' && tmpbuf[1] != ' '){
        fprintf(stderr, "Login Error\n");
        exit(EXIT_FAILURE);
    }

    bzero(tmpbuf, BUFFSIZE);
    printf("Password: ");
    fgets(password, 128, stdin);
    password[strlen(password) - 1] = '\0';

    snprintf(cmd, 1024, "%s\r\n", password);
    n = write(sockfd, cmd, strlen(cmd));
    bzero(tmpbuf,BUFFSIZE);
    n = read(sockfd, tmpbuf, BUFFSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    if (tmpbuf[0] != 'A' || tmpbuf[1] != '0' || tmpbuf[2] != '1'){
        fprintf(stderr, "Password Error\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", tmpbuf);

    // List folders
    snprintf(cmd, 1024, "A002 LIST \"\" \"*\"\r\n");
    n = write(sockfd, cmd, strlen(cmd));
    bzero(tmpbuf, BUFFSIZE);
    n = read(sockfd, tmpbuf, BUFFSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("\n%s\n\n", tmpbuf);

    // Logout and Close Connection
    snprintf(cmd, 1024, "A003 LOGOUT\r\n");
    n = write(sockfd, cmd, strlen(cmd));

    close(sockfd);
    return 0;
}