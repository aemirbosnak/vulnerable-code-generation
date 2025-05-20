//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR connecting");
        exit(1);
    }

    printf("Connected to the POP3 server\n");

    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        printf("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    char username[100];
    printf("Enter the username: ");
    fgets(username, 100, stdin);

    char password[100];
    printf("Enter the password: ");
    fgets(password, 100, stdin);

    char user_command[100] = "USER ";
    strcat(user_command, username);

    if (send(sockfd, user_command, strlen(user_command), 0) < 0) {
        printf("ERROR sending username");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        printf("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    char pass_command[100] = "PASS ";
    strcat(pass_command, password);

    if (send(sockfd, pass_command, strlen(pass_command), 0) < 0) {
        printf("ERROR sending password");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        printf("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    if (send(sockfd, "STAT\n", 5, 0) < 0) {
        printf("ERROR sending STAT command");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        printf("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    if (send(sockfd, "QUIT\n", 5, 0) < 0) {
        printf("ERROR sending QUIT command");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        printf("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}