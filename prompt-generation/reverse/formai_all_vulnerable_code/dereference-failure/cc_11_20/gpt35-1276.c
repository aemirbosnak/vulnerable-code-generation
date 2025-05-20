//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];

    if(argc < 3) {
        fprintf(stderr, "Usage: %s server_address port_number\n", argv[0]);
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
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    memset(buffer, '\0', BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    printf("Username: ");
    fgets(username, BUFFER_SIZE - 1, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Password: ");
    fgets(password, BUFFER_SIZE - 1, stdin);
    password[strcspn(password, "\n")] = '\0';

    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, '\0', BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, '\0', BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, '\0', BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}