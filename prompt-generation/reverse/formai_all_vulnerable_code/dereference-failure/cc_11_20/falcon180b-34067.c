//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[])
{
    int sock, numbytes, i, j, maxsd, activity, sd[MAX];
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    fd_set readfds;

    if(argc!= 2)
    {
        printf("Usage:./a.out <IP address>\n");
        exit(0);
    }

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Socket creation failed\n");
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if(connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Connection failed\n");
        exit(0);
    }

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    maxsd = sock;

    for(i = 0; i < MAX; i++)
    {
        if((sd[i] = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
            printf("Socket creation failed\n");
            exit(0);
        }
    }

    for(i = 0; i < MAX; i++)
    {
        bzero(&cliaddr, sizeof(cliaddr));
        cliaddr.sin_family = AF_INET;
        cliaddr.sin_port = htons(PORT);
        inet_pton(AF_INET, argv[1], &cliaddr.sin_addr);

        if(connect(sd[i], (struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0)
        {
            printf("Connection failed\n");
            exit(0);
        }

        FD_SET(sd[i], &readfds);

        if(sd[i] > maxsd)
            maxsd = sd[i];
    }

    while(TRUE)
    {
        readfds = readfds;
        activity = select(maxsd + 1, &readfds, NULL, NULL, NULL);

        if((activity < 0) && (errno!= EINTR))
        {
            printf("Select error\n");
            exit(0);
        }

        if(FD_ISSET(sock, &readfds))
        {
            if((numbytes = read(sock, buffer, sizeof(buffer))) <= 0)
            {
                printf("Reading error\n");
                exit(0);
            }

            for(i = 0; i < MAX; i++)
            {
                if(sd[i] > sock)
                    send(sd[i], buffer, numbytes, 0);
            }
        }

        for(i = 0; i < MAX; i++)
        {
            if(FD_ISSET(sd[i], &readfds))
            {
                if((numbytes = read(sd[i], buffer, sizeof(buffer))) <= 0)
                {
                    printf("Reading error\n");
                    exit(0);
                }

                write(sock, buffer, numbytes);
            }
        }
    }

    return 0;
}