//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s hostname port message\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get server IP address
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL)
    {
        fprintf(stderr, "Unknown host: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    char *server_ip = inet_ntoa(*(struct in_addr *)he->h_addr);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send message
    char *message = argv[3];
    int n = send(sockfd, message, strlen(message), 0);
    if (n == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response
    char buf[BUF_SIZE];
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("Response: %s\n", buf);

    // Close socket
    close(sockfd);

    return 0;
}