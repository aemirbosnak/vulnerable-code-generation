//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 9000
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    struct sockaddr_in servAddr;
    struct timeval start, end;
    int sockfd, numbytes, totalbytes;
    char buf[BUFSIZE];
    double elapsedtime;
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(struct sockaddr)) == -1)
    {
        perror("connect");
        exit(1);
    }

    printf("Connected to server on port %d\n", PORT);

    totalbytes = 0;
    gettimeofday(&start, NULL);

    while (1)
    {
        if ((numbytes = recv(sockfd, buf, BUFSIZE, 0)) == -1)
        {
            perror("recv");
            exit(1);
        }

        totalbytes += numbytes;

        gettimeofday(&end, NULL);
        elapsedtime = (double)((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));

        if (elapsedtime >= 10000000)
        {
            printf("Average throughput: %f bytes/sec\n", (totalbytes / elapsedtime) * 1000000);
            totalbytes = 0;
            gettimeofday(&start, NULL);
        }
    }

    close(sockfd);

    return 0;
}