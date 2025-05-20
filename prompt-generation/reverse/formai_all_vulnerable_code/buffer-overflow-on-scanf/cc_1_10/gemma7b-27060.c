//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char host[256];
    char message[1024];
    int sockfd, port, i, j, status, bytes_sent, bytes_received;
    struct sockaddr_in server_addr;

    printf("Enter the host name: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (status < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter the message: ");
    scanf("%s", message);

    bytes_sent = send(sockfd, message, strlen(message), 0);

    if (bytes_sent < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    bytes_received = recv(sockfd, message, 1024, 0);

    if (bytes_received < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    printf("Received message: %s\n", message);

    close(sockfd);

    return 0;
}