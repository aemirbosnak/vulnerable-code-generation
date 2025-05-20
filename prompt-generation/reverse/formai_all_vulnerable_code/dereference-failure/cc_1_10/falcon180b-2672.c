//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int n;
    char filename[50];
    FILE *fp;
    char mode[10];

    if (argc!= 4)
    {
        printf("Usage:./ftp_client <server_ip> <port_number> <filename>\n");
        exit(0);
    }

    strcpy(filename, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error: Unable to create socket.\n");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error: Unable to connect to server.\n");
        exit(0);
    }

    printf("Connected to server.\n");

    sprintf(buffer, "STOR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);

    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        exit(0);
    }

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0)
    {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);
    printf("File transfer complete.\n");

    close(sockfd);
    exit(0);
}