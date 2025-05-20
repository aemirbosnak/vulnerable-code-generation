//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 25
#define MAX 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buf[MAX];
    char recv_buf[MAX];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(argc < 3)
    {
        printf("Error: Invalid number of arguments\n");
        close(sockfd);
        exit(1);
    }

    strcpy(send_buf, "HELO ");
    strcat(send_buf, argv[1]);
    strcat(send_buf, "\r\n");

    send(sockfd, send_buf, strlen(send_buf), 0);

    while(1)
    {
        memset(recv_buf, 0, MAX);
        n = recv(sockfd, recv_buf, MAX, 0);

        if(n <= 0)
        {
            printf("Server disconnected\n");
            close(sockfd);
            exit(1);
        }

        printf("Received: %s", recv_buf);
    }

    close(sockfd);
    return 0;
}