//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    char buffer[MAX_RESPONSE_LENGTH];
    char username[MAX_COMMAND_LENGTH];
    char password[MAX_COMMAND_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    int n;

    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <server> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", argv[1]);
        exit(1);
    }

    portno = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        fprintf(stderr, "Could not create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)server, sizeof(struct sockaddr)) < 0) {
        fprintf(stderr, "Could not connect to server: %s\n", strerror(errno));
        exit(1);
    }

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    sprintf(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}