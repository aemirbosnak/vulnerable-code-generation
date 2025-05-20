//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLEN 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXLEN];

    if (argc < 3) {
       fprintf(stderr, "Usage: %s hostname username\r\n", argv[0]);
       exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\r\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(143);

    if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    char *login = "LOGIN ";
    strncat(login, argv[2], MAXLEN - strlen(login) - 1);
    strncat(login, " ", MAXLEN - strlen(login) - 1);
    strncat(login, argv[2], MAXLEN - strlen(login) - 1);
    strncat(login, "\r\n", MAXLEN - strlen(login) - 1);

    n = send(sockfd, login, strlen(login), 0);
    if (n < 0) {
        perror("ERROR sending to socket");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    char *list = "LIST\r\n";
    n = send(sockfd, list, strlen(list), 0);
    if (n < 0) {
        perror("ERROR sending to socket");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    return 0;
}