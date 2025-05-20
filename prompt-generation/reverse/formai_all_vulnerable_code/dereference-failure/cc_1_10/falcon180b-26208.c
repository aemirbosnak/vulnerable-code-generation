//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[1024];

    if(argc < 3)
    {
        printf("Usage:./pop3_client <server_ip> <port_number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Error in socket creation\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to POP3 server\n");

    while(1)
    {
        bzero(buffer, sizeof(buffer));
        printf("Enter command: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        if(!strcmp(buffer, "QUIT"))
        {
            printf("Exiting...\n");
            break;
        }

        bzero(buffer, sizeof(buffer));
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("Server response: %s", buffer);
    }

    close(sockfd);

    return 0;
}