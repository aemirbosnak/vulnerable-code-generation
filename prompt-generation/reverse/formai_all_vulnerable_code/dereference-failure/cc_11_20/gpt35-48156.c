//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXLEN 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXLEN];
    char username[MAXLEN];
    char password[MAXLEN];

    printf("POP3 Client Example Program\n");
    printf("===========================\n");

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    printf("Connected to server %s on port %d\n", argv[1], portno);

    /* read the server greeting message */
    memset(buffer, 0, MAXLEN);
    n = read(sockfd, buffer, MAXLEN-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }

    printf("%s\n", buffer);

    /* send the user name */
    printf("Username: ");
    scanf("%s", username);

    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }

    /* read the server response */
    memset(buffer, 0, MAXLEN);
    n = read(sockfd, buffer, MAXLEN-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }

    printf("%s\n", buffer);

    /* send the password */
    printf("Password: ");
    scanf("%s", password);

    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }

    /* read the server response */
    memset(buffer, 0, MAXLEN);
    n = read(sockfd, buffer, MAXLEN-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }

    printf("%s\n", buffer);

    /* list all the emails */
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }

    /* read the server response */
    memset(buffer, 0, MAXLEN);
    n = read(sockfd, buffer, MAXLEN-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }

    printf("%s\n", buffer);

    /* quit the session */
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }

    /* read the server response */
    memset(buffer, 0, MAXLEN);
    n = read(sockfd, buffer, MAXLEN-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }

    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}