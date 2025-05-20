//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Step 1: Resolve the hostname to an IP address.

    struct hostent *host_info = gethostbyname(argv[1]);
    if (host_info == NULL)
    {
        perror("gethostbyname()");
        return EXIT_FAILURE;
    }

    // Step 2: Create a socket.

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket()");
        return EXIT_FAILURE;
    }

    // Step 3: Connect to the POP3 server.

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect()");
        return EXIT_FAILURE;
    }

    // Step 4: Send the USER command.

    char buf[MAX_BUF_SIZE];
    snprintf(buf, sizeof(buf), "USER %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) == -1)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    // Step 5: Receive the response to the USER command.

    if (recv(sockfd, buf, sizeof(buf), 0) == -1)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    // Step 6: Send the PASS command.

    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    // Step 7: Receive the response to the PASS command.

    if (recv(sockfd, buf, sizeof(buf), 0) == -1)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    // Step 8: Send the STAT command.

    snprintf(buf, sizeof(buf), "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    // Step 9: Receive the response to the STAT command.

    if (recv(sockfd, buf, sizeof(buf), 0) == -1)
    {
        perror("recv()");
        return EXIT_FAILURE;
    }

    // Step 10: Send the LIST command.

    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    // Step 11: Receive the response to the LIST command.

    while (recv(sockfd, buf, sizeof(buf), 0) > 0)
    {
        printf("%s", buf);
    }

    // Step 12: Send the QUIT command.

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1)
    {
        perror("send()");
        return EXIT_FAILURE;
    }

    // Step 13: Close the socket.

    close(sockfd);

    return EXIT_SUCCESS;
}