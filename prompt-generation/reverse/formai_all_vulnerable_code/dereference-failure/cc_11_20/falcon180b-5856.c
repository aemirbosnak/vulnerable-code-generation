//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

#define MAX 1000

int main(int argc, char *argv[])
{
    int sock, val, portno, i, j, maxsd, activity, sd;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    fd_set readfds;
    struct timeval timeout;

    if(argc!= 2)
    {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0)
    {
        printf("Error opening socket\n");
        exit(0);
    }

    printf("Socket created\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error on binding\n");
        exit(0);
    }

    printf("Bind done\n");

    if(listen(sock, MAX) < 0)
    {
        printf("Error on listening\n");
        exit(0);
    }

    printf("Listening on port %d\n", portno);

    FD_ZERO(&readfds);

    FD_SET(sock, &readfds);

    maxsd = sock;

    for(i = 0 ; i < MAX ; i++)
    {
        sd = accept(sock, (struct sockaddr *)NULL, NULL);

        if(sd > maxsd)
        {
            maxsd = sd;
        }

        FD_SET(sd, &readfds);
    }

    for(i = 0 ; i <= maxsd ; i++)
    {
        if(FD_ISSET(i, &readfds))
        {
            activity = 0;

            if(i == sock)
            {
                printf("New connection arrived\n");

                while(1)
                {
                    memset(buffer, 0, sizeof(buffer));

                    val = recv(i, buffer, 1024, 0);

                    if(val <= 0)
                    {
                        break;
                    }

                    printf("%s", buffer);
                }

                close(i);
            }
            else
            {
                printf("Activity on socket %d\n", i);

                while(1)
                {
                    memset(buffer, 0, sizeof(buffer));

                    val = recv(i, buffer, 1024, 0);

                    if(val <= 0)
                    {
                        break;
                    }

                    printf("%s", buffer);
                }

                close(i);
            }
        }
    }

    return 0;
}