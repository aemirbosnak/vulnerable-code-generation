//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PORTS 65535

int main()
{
    int port_number;
    char host_name[256];
    int sockfd, err;
    struct sockaddr_in serv_addr;

    printf("Enter host name: ");
    scanf("%s", host_name);

    printf("Enter port number: ");
    scanf("%d", &port_number);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port_number));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_number);
    serv_addr.sin_addr.s_addr = inet_addr(host_name);

    err = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (err < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connection established!\n");

    // Send and receive messages
    char message[1024];
    printf("Enter message: ");
    scanf("%s", message);

    send(sockfd, message, sizeof(message), 0);

    recv(sockfd, message, sizeof(message), 0);

    printf("Received message: %s\n", message);

    close(sockfd);

    return 0;
}