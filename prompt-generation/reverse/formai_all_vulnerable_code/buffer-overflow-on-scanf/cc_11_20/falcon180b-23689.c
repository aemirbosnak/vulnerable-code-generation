//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <fcntl.h>

#define DEBUG 1

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x)
#endif

#define BUFFER_SIZE 1024

#define IMAP_PORT 143

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[100];
    char password[100];
    char hostname[100];
    int port;
    char *command;
    char *response;
    char buffer[BUFFER_SIZE];
    char *ptr;
    int n;
    char *token;
    int i;
    int j;
    int len;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &port);

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("socket failed with error %d\n", errno);
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    serveraddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
    {
        printf("connect failed with error %d\n", errno);
        exit(1);
    }

    printf("Connected to %s:%d\n", hostname, port);

    if (login(sockfd, username, password) == 0)
    {
        printf("Login failed\n");
        exit(1);
    }

    printf("Login successful\n");

    while (1)
    {
        printf("Enter the command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        if (send(sockfd, command, strlen(command), 0) < 0)
        {
            printf("send failed with error %d\n", errno);
            exit(1);
        }

        response = (char *) malloc(BUFFER_SIZE);
        memset(response, 0, BUFFER_SIZE);

        while (1)
        {
            n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);

            if (n < 0)
            {
                printf("recv failed with error %d\n", errno);
                exit(1);
            }

            if (n == 0)
            {
                printf("Connection closed\n");
                exit(1);
            }

            buffer[n] = '\0';

            strcat(response, buffer);

            if (strstr(response, "* OK ")!= NULL)
            {
                break;
            }
        }

        printf("%s\n", response);

        free(response);
    }

    close(sockfd);

    return 0;
}