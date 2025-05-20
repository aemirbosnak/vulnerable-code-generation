//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_SIZE 100
#define MAX_PORT_SIZE 6
#define MAX_DATA_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_number = argv[2];

    int sockfd, newsockfd, portno, addrlen, clientlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_DATA_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &serv_addr.sin_addr);
    portno = atoi(port_number);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    listen(sockfd, 5);

    addrlen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            return 1;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_DATA_SIZE);
            ssize_t bytes_received = recv(newsockfd, buffer, MAX_DATA_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Error receiving data\n");
                close(newsockfd);
                break;
            }

            printf("Received data: %s\n", buffer);

            ssize_t bytes_sent = send(newsockfd, buffer, strlen(buffer), 0);
            if (bytes_sent <= 0) {
                printf("Error sending data\n");
                close(newsockfd);
                break;
            }
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}