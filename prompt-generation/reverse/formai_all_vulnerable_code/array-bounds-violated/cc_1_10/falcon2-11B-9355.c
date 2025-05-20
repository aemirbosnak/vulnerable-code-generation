//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    // create socket
    int sockfd;
    struct sockaddr_in servaddr;
    int n = sizeof(servaddr);
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // assign ip and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, n) == -1)
    {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[1024];
    while (1)
    {
        // send request
        int n = send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n", 54, 0);
        if (n == -1)
        {
            perror("ERROR sending request");
            exit(1);
        }

        // receive response
        bzero(buffer, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (n == -1)
        {
            perror("ERROR receiving response");
            exit(1);
        }
        buffer[n] = '\0';
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}