//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

struct hostent *host;
struct sockaddr_in server;
int sockfd;
char buffer[MAX];

void scan(char *ip) {
    int port = 1;
    while (port <= 1024) {
        if (connect(sockfd, (struct sockaddr*)&server, sizeof(server))!= 0) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Port %d is open\n", port);
        }
        close(sockfd);
        port++;
    }
}

int main() {
    char ip[16];
    printf("Enter the IP address to scan: ");
    scanf("%s", ip);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(0);
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Scanning...\n");
    scan(ip);

    close(sockfd);
    return 0;
}