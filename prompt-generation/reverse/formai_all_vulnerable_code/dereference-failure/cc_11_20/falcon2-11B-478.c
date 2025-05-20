//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 1000

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    int sockfd, portno, newsockfd, pid, valread, valwrite;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_PACKET_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 3) < 0)
    {
        perror("ERROR on listen");
        exit(1);
    }

    for (;;)
    {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &portno);
        if (newsockfd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        pid = fork();

        if (pid == 0)
        {
            close(sockfd);
            close(newsockfd);

            if (fork() == 0)
            {
                while ((valread = read(newsockfd, buffer, sizeof(buffer))) > 0)
                {
                    if (buffer[0] == 'A' && buffer[1] == 'B' && buffer[2] == 'C')
                    {
                        printf("Denied packet %s\n", buffer);
                    }
                    else
                    {
                        printf("Allowed packet %s\n", buffer);
                    }
                }

                printf("All packets processed.\n");

                exit(0);
            }

            exit(0);
        }
        else
        {
            close(newsockfd);

            while ((valwrite = write(sockfd, buffer, sizeof(buffer))) > 0)
            {
                if (valwrite == sizeof(buffer))
                {
                    printf("Sent %d bytes\n", valwrite);
                }
            }

            printf("All packets sent.\n");

            exit(0);
        }
    }

    return 0;
}