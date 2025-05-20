//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE_SIZE 1024
#define POP3_PORT 110
#define POP3_USERNAME "your_username"
#define POP3_PASSWORD "your_password"

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char host[NI_MAXHOST];
    char port[NI_MAXSERV];
    int rv;
    int numbytes;

    printf("Enter hostname: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%s", port);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(host, port, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);

    char username[MAX_LINE_SIZE];
    char password[MAX_LINE_SIZE];
    sprintf(username, "USER %s\r\n", POP3_USERNAME);
    send(sockfd, username, strlen(username), 0);
    numbytes = recv(sockfd, (char*)&username, sizeof(username), 0);

    if (numbytes > 0) {
        printf("Server response: %s\n", username);
    } else {
        printf("Server did not respond.\n");
        exit(1);
    }

    sprintf(password, "PASS %s\r\n", POP3_PASSWORD);
    send(sockfd, password, strlen(password), 0);
    numbytes = recv(sockfd, (char*)&username, sizeof(username), 0);

    if (numbytes > 0) {
        printf("Server response: %s\n", username);
    } else {
        printf("Server did not respond.\n");
        exit(1);
    }

    char command[MAX_LINE_SIZE];
    sprintf(command, "LIST\r\n");
    send(sockfd, command, strlen(command), 0);
    numbytes = recv(sockfd, (char*)&username, sizeof(username), 0);

    if (numbytes > 0) {
        printf("Server response: %s\n", username);
    } else {
        printf("Server did not respond.\n");
        exit(1);
    }

    close(sockfd);
    return 0;
}