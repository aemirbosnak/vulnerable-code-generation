//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main()
{
    char *hostname = "pop.example.com";
    char *username = "username";
    char *password = "password";
    char buffer[1024];
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd, n;

    if ((host = gethostbyname(hostname)) == NULL)
        error("gethostbyname()");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error("socket()");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error("connect()");

    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1)
        error("recv()");

    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0)
        error("server did not respond with +OK");

    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) == -1)
        error("send()");

    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1)
        error("recv()");

    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0)
        error("server did not respond with +OK");

    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) == -1)
        error("send()");

    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1)
        error("recv()");

    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0)
        error("server did not respond with +OK");

    snprintf(buffer, sizeof(buffer), "STAT\r\n");
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) == -1)
        error("send()");

    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1)
        error("recv()");

    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0)
        error("server did not respond with +OK");

    printf("%s\n", buffer);

    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) == -1)
        error("send()");

    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1)
        error("recv()");

    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0)
        error("server did not respond with +OK");

    printf("%s\n", buffer);

    snprintf(buffer, sizeof(buffer), "RETR 1\r\n");
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) == -1)
        error("send()");

    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1)
        error("recv()");

    buffer[n] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0)
        error("server did not respond with +OK");

    printf("%s\n", buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if ((n = send(sockfd, buffer, strlen(buffer), 0)) == -1)
        error("send()");

    close(sockfd);

    return 0;
}