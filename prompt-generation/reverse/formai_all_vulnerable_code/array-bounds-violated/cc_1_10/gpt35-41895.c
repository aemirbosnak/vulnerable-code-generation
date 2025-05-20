//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define SERVER "mail.example.com"
#define PORT "110"

int main()
{
    int sockfd, numbytes;
    char buf[1024];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char user[100], pass[100];

    printf("Enter username: ");
    fgets(user, 100, stdin);
    printf("Enter password: ");
    fgets(pass, 100, stdin);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(SERVER, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(2);
    }

    freeaddrinfo(servinfo);

    numbytes = recv(sockfd, buf, sizeof(buf), 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    char command[100];
    int id = 0;
    sprintf(command, "USER %s", user);
    send(sockfd, command, strlen(command), 0);
    numbytes = recv(sockfd, buf, sizeof(buf), 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    id++;
    sprintf(command, "PASS %s", pass);
    send(sockfd, command, strlen(command), 0);
    numbytes = recv(sockfd, buf, sizeof(buf), 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    id++;
    sprintf(command, "LIST");
    send(sockfd, command, strlen(command), 0);
    numbytes = recv(sockfd, buf, sizeof(buf), 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    id++;
    sprintf(command, "RETR %d", id);
    send(sockfd, command, strlen(command), 0);
    numbytes = recv(sockfd, buf, sizeof(buf), 0);
    buf[numbytes] = '\0';
    printf("%s", buf);

    close(sockfd);

    return 0;
}