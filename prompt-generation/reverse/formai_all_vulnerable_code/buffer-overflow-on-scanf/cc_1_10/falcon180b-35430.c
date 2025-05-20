//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define POP3_PORT 110
#define POP3_USER "user"
#define POP3_PASS "password"
#define POP3_SERVER "localhost"
#define BUFFER_SIZE 1024

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    servaddr.sin_addr.s_addr = inet_addr(POP3_SERVER);

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    char username[100] = {0};
    char password[100] = {0};

    printf("Enter POP3 username: ");
    scanf("%s", username);

    printf("Enter POP3 password: ");
    scanf("%s", password);

    char auth[100] = {0};
    sprintf(auth, "USER %s\r\n", username);
    send(sockfd, auth, strlen(auth), 0);

    char response[BUFFER_SIZE] = {0};
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    sprintf(auth, "PASS %s\r\n", password);
    send(sockfd, auth, strlen(auth), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    char list[100] = {0};
    sprintf(list, "LIST\r\n");
    send(sockfd, list, strlen(list), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    char retr[100] = {0};
    sprintf(retr, "RETR 1\r\n");
    send(sockfd, retr, strlen(retr), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}