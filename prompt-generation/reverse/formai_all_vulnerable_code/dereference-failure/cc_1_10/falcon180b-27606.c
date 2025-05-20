//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == 0)
    {
        error_handling("Error: Socket creation failed");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(port_number);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error_handling("Error: Connection failed");
    }

    while(1)
    {
        char buffer[BUFFER_SIZE];
        memset(buffer, '\0', BUFFER_SIZE);

        if(recv(sockfd, buffer, BUFFER_SIZE, 0) <= 0)
        {
            error_handling("Error: Data received is empty");
        }

        printf("Received data: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}

void error_handling(char *message)
{
    perror(message);
    exit(1);
}