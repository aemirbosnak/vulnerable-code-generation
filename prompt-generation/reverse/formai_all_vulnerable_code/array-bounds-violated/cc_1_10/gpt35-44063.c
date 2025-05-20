//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_PACKET_SIZE 1024

int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_PACKET_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed.\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("255.255.255.255");

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Binding failed.\n");
        return 1;
    }

    printf("Scanning for wireless networks...\n");
    printf("--------------------------------\n");

    int i = 0;
    while (i < 10) {
        int n;
        socklen_t len = sizeof(servaddr);
        n = recvfrom(sockfd, (char*)buffer, MAX_PACKET_SIZE, MSG_WAITALL, (struct sockaddr*)&servaddr, &len);
        buffer[n] = '\0';

        printf("Network %d: %s\n", i+1, buffer);

        i++;
    }

    close(sockfd);
    return 0;
}