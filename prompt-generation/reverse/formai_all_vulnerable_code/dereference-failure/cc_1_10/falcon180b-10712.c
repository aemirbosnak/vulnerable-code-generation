//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
    char hostname[256];
    char buff[BUFF_SIZE];
    int port = 80;
    int sockfd;
    int n;
    int count = 0;
    int total_size = 0;
    double start_time, end_time;
    double elapsed_time;
    double speed;

    if (argc!= 2)
    {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *server = gethostbyname(hostname);

    if (server == NULL)
    {
        printf("Error resolving hostname\n");
        return 1;
    }

    struct sockaddr_in serv_addr;

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to host\n");
        return 1;
    }

    start_time = difftime(time(NULL), time(NULL));

    while ((n = read(sockfd, buff, BUFF_SIZE)) > 0)
    {
        total_size += n;
        count++;
    }

    end_time = difftime(time(NULL), start_time);

    elapsed_time = end_time - start_time;

    speed = (double)total_size / elapsed_time;

    printf("Connection speed: %.2f kbps\n", speed / 1024);

    close(sockfd);

    return 0;
}