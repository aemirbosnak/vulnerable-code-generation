//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];
    char username[BUF_SIZE];
    char password[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("IMAP server connected.\n");

    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s", buffer);

    printf("Enter your username: ");
    fgets(username, BUF_SIZE - 1, stdin);
    username[strcspn(username, "\n")] = '\0';

    snprintf(buffer, BUF_SIZE, "A001 LOGIN %s\r\n", username);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    if (strstr(buffer, "OK") == NULL) {
        printf("Login failed.\n");
        exit(1);
    }

    printf("Enter your password: ");
    fgets(password, BUF_SIZE - 1, stdin);
    password[strcspn(password, "\n")] = '\0';

    snprintf(buffer, BUF_SIZE, "A002 LOGIN %s\r\n", password);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    if (strstr(buffer, "OK") == NULL) {
        printf("Login failed.\n");
        exit(1);
    }

    printf("You are now logged in.\n");

    n = sprintf(buffer, "A003 LIST \"\" \"*\"\r\n");

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s", buffer);

    n = sprintf(buffer, "A004 LOGOUT\r\n");

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUF_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s", buffer);

    close(sockfd);

    return 0;
}