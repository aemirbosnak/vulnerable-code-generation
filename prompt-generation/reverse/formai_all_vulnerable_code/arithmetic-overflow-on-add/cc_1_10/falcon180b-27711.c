//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main(int argc, char *argv[])
{
    int sockfd, bytes_sent, bytes_recv, total_sent = 0, total_recv = 0;
    char buffer[1024];
    struct sockaddr_in server_addr;
    int opt = 1;
    int result;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    result = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (result == -1)
    {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (result == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        sprintf(buffer, "GET /speedtest.php HTTP/1.1\r\nHost: %s\r\n\r\n", SERVER_IP);

        bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

        if (bytes_sent == -1)
        {
            printf("Error sending data\n");
            exit(1);
        }

        total_sent += bytes_sent;

        bytes_recv = recv(sockfd, buffer, sizeof(buffer), 0);

        if (bytes_recv == -1)
        {
            printf("Error receiving data\n");
            exit(1);
        }

        total_recv += bytes_recv;

        if (bytes_recv <= 0)
        {
            break;
        }
    }

    close(sockfd);

    printf("Total bytes sent: %d\n", total_sent);
    printf("Total bytes received: %d\n", total_recv);

    return 0;
}