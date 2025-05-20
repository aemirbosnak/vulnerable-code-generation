//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 256
#define MAX_ADDRESS 256

int main() {
    char command[MAX_LINE], line[MAX_LINE], host[MAX_ADDRESS],
        port[MAX_ADDRESS], user[MAX_ADDRESS], password[MAX_ADDRESS];
    int sockfd, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    /* Initialize host */
    printf("Enter host: ");
    gets(host);
    printf("Enter port: ");
    gets(port);
    printf("Enter user: ");
    gets(user);
    printf("Enter password: ");
    gets(password);

    /* Initialize socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize server */
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port));

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server!\n");

    /* Login to server */
    printf("Enter command: ");
    gets(command);
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    printf("Received response: %s\n", line);

    /* Close connection */
    close(sockfd);
    return 0;
}