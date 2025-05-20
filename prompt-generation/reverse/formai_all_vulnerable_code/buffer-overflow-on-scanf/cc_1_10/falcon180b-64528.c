//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char *message = "PING";
    int addrlen = sizeof(cli_addr);

    if (argc < 3) {
        printf("Usage: %s <IP Address> <No. of Packets>\n", argv[0]);
        exit(0);
    }

    if (strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s <IP Address> <No. of Packets>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (SA *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter the number of packets to send: ");
    scanf("%d", &sd);

    for (i = 0; i < sd; i++) {
        send(sockfd, message, strlen(message), 0);
        usleep(100000);
    }

    close(sockfd);

    return 0;
}