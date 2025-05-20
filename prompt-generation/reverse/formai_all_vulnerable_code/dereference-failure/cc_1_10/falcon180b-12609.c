//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX 65535

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sock, val = 1, port, i = 0;
    struct sockaddr_in serv_addr;
    char *ip = argv[1];
    char *output_file = argv[2];

    if(argc!= 3)
    {
        printf("Usage: %s <IP Address> <Output File>\n", argv[0]);
        exit(0);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1)
        error("socket failed");

    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &val, sizeof(val)))
    {
        error("setsockopt");
    }

    if(setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val)))
    {
        error("setsockopt");
    }

    if(setsockopt(sock, SOL_SOCKET, SO_LINGER, &val, sizeof(val)))
    {
        error("setsockopt");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(1);

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
    {
        close(sock);
        error("connect");
    }

    printf("Connected to %s on port 1\n", inet_ntoa(serv_addr.sin_addr));

    FILE *fp;

    fp = fopen(output_file, "w");

    if(fp == NULL)
    {
        printf("Cannot create file\n");
        exit(0);
    }

    for(port = 1; port <= MAX; port++)
    {
        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(ip);
        serv_addr.sin_port = htons(port);

        if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == 0)
        {
            fprintf(fp, "Port %d is open\n", port);
        }
        else
        {
            fprintf(fp, "Port %d is closed\n", port);
        }

        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    fclose(fp);

    return 0;
}