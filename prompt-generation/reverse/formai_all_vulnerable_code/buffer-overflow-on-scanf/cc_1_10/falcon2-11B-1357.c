//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_IP 1000
#define MAX_LEN 100

int main() {
    int sockfd, portno, addrlen;
    struct sockaddr_in serv_addr;

    char hostname[MAX_LEN];
    char buf[MAX_LEN];

    int count = 0;

    printf("Please enter the hostname you want to scan: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Could not connect to server\n");
        exit(1);
    }

    printf("Scanning host %s for port %d\n", hostname, PORT);

    for (portno = 0; portno < MAX_IP; portno++) {
        if (portno == PORT) {
            printf("Port %d is open\n", portno);
            break;
        }

        if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
            printf("Port %d is closed\n", portno);
        } else {
            printf("Port %d is open\n", portno);
            break;
        }
    }

    printf("Scan complete\n");
    close(sockfd);
    return 0;
}