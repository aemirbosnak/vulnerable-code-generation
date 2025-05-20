//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define POP3_PORT 110

int main()
{
    int sockfd;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Set the servaddr structure
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);

    // Let's try a bit of mind-bending code here!
    char *ip = "12.34.56.78";
    servaddr.sin_addr.s_addr = *(long*)ip;

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    // Now we're going to authenticate using our username and password
    char user[MAXLINE], pass[MAXLINE];
    printf("Username: ");
    fgets(user, MAXLINE, stdin);
    printf("Password: ");
    fgets(pass, MAXLINE, stdin);

    char auth[MAXLINE];
    sprintf(auth, "USER %sPASS %s", user, pass);
    if (send(sockfd, auth, strlen(auth), 0) < 0) {
        fprintf(stderr, "Error sending auth data\n");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
        fprintf(stderr, "Error receiving response\n");
        exit(EXIT_FAILURE);
    }

    printf("Response: %s\n", recvline);

    // Now we're going to send the LIST command to get the list of emails
    char list_cmd[] = "LIST\r\n";
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
        fprintf(stderr, "Error sending LIST command\n");
        exit(EXIT_FAILURE);
    }

    int n;
    while ((n = recv(sockfd, recvline, MAXLINE, 0)) > 0) {
        recvline[n] = '\0';
        if (fputs(recvline, stdout) == EOF) {
            fprintf(stderr, "Error fputs\n");
            exit(EXIT_FAILURE);
        }
    }

    if (n < 0) {
        fprintf(stderr, "Error receiving LIST command response\n");
        exit(EXIT_FAILURE);
    }

    // Let's close the socket
    close(sockfd);

    return 0;
}