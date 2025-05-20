//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_MSG_SIZE 4096

int main(int argc, char **argv) {
    int sockfd, portnum, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_MSG_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s servername portnumber\n", argv[0]);
        exit(1);
    }

    portnum = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(portnum);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to server...\n");

    char user[50];
    char pass[50];

    printf("Username: ");
    scanf("%s", user);

    sprintf(buffer, "tag01 LOGIN %s\r\n", user);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_MSG_SIZE);
    n = read(sockfd, buffer, MAX_MSG_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    printf("Password: ");
    scanf("%s", pass);

    sprintf(buffer, "tag02 LOGIN %s %s\r\n", user, pass);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_MSG_SIZE);
    n = read(sockfd, buffer, MAX_MSG_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    sprintf(buffer, "tag03 SELECT inbox\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_MSG_SIZE);
    n = read(sockfd, buffer, MAX_MSG_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    sprintf(buffer, "tag04 FETCH 1 BODY[TEXT]\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_MSG_SIZE);
    n = read(sockfd, buffer, MAX_MSG_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);

    return 0;
}