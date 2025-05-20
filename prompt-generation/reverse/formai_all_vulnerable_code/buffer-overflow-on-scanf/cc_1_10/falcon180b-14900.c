//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

#define PORT 110
#define MAX 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX];
    char user[50], pass[50];

    printf("Enter Username: ");
    scanf("%s", user);

    printf("Enter Password: ");
    scanf("%s", pass);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Error creating socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "localhost", &serv_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    char auth[100];
    sprintf(auth, "USER %s\r\n", user);
    send(sockfd, auth, strlen(auth), 0);

    char auth_pass[100];
    sprintf(auth_pass, "PASS %s\r\n", pass);
    send(sockfd, auth_pass, strlen(auth_pass), 0);

    char response[MAX];
    bzero(response, MAX);
    n = recv(sockfd, response, MAX, 0);
    response[n] = '\0';
    printf("%s", response);

    close(sockfd);
    return 0;
}