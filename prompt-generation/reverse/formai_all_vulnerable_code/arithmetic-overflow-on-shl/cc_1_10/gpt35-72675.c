//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <server_ip> <file_name>\n", argv[0]);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("Socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connect");
        exit(1);
    }

    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);

    recv(sock, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "USER anonymous\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "PASS anonymous\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "TYPE I\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "PASV\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    int h1, h2, h3, h4, p1, p2;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\r\n", &h1, &h2, &h3, &h4, &p1, &p2);

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons((p1 << 8) + p2);
    data_addr.sin_addr.s_addr = inet_addr(argv[1]);

    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr)) < 0)
    {
        perror("Connect");
        exit(1);
    }

    sprintf(buffer, "RETR %s\r\n", argv[2]);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    FILE *fp = fopen(argv[2], "wb");
    if(fp == NULL)
    {
        perror("fopen");
        exit(1);
    }

    int size;
    while((size = recv(data_sock, buffer, BUF_SIZE, 0)) > 0)
    {
        fwrite(buffer, 1, size, fp);
    }

    close(data_sock);
    fclose(fp);

    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUF_SIZE, 0);
    printf("%s", buffer);

    close(sock);

    return 0;
}