//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 100
#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s <server> <filename>\n", argv[0]);
        exit(1);
    }
    
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char recv_buffer[MAX_LINE];
    FILE *fp;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if ((inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)) <= 0)
    {
        perror("ERROR, could not resolve server address");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    fp = fopen(argv[2], "wb");
    if (fp == NULL)
    {
        perror("ERROR opening file");
        exit(1);
    }

    if (send(sockfd, argv[2], strlen(argv[2]), 0) < 0)
    {
        perror("ERROR sending file name");
        exit(1);
    }

    if (send(sockfd, "START\r\n", 7, 0) < 0)
    {
        perror("ERROR sending start command");
        exit(1);
    }

    while (n = recv(sockfd, recv_buffer, MAX_LINE, 0))
    {
        if (n <= 0)
        {
            perror("ERROR receiving data");
            exit(1);
        }
        fwrite(recv_buffer, 1, n, fp);
    }

    if (send(sockfd, "STOP\r\n", 7, 0) < 0)
    {
        perror("ERROR sending stop command");
        exit(1);
    }

    close(sockfd);
    fclose(fp);
    return 0;
}