//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("Error opening socket.");

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"Error, host not found.\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("Connection failed.");

    // Authentication
    n = recv(sockfd, buffer, MAX_BUFFER-1, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    char user[100], pass[100];
    printf("Username: ");
    fgets(user, 100, stdin);
    printf("Password: ");
    fgets(pass, 100, stdin);

    sprintf(buffer, "1 LOGIN %s %s\r\n", user, pass);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_BUFFER);
    n = recv(sockfd, buffer, MAX_BUFFER-1, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    while (1) {
        printf("Enter command: ");
        bzero(buffer, MAX_BUFFER);
        fgets(buffer, MAX_BUFFER-1, stdin);
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n')
            buffer[len-1] = '\0';

        send(sockfd, buffer, strlen(buffer), 0);
        bzero(buffer, MAX_BUFFER);
        n = recv(sockfd, buffer, MAX_BUFFER-1, 0);
        buffer[n] = '\0';
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}