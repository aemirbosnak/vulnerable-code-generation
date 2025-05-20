//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_PKT_SIZE 1024

int main() {
    int sockfd, count = 0;
    struct sockaddr_in addr;
    char buffer[MAX_PKT_SIZE + 1];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sockfd < 0) {
        printf("Error while creating socket\n");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);

    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error while binding socket\n");
        close(sockfd);
        exit(1);
    }

    printf("Packet monitoring started...\n");

    while(1) {
        int bytes_received = recv(sockfd, buffer, MAX_PKT_SIZE, 0);
        if(bytes_received < 0) {
            printf("Error while receiving packets\n");
            close(sockfd);
            exit(1);
        } else {
            buffer[bytes_received] = '\0';
            printf("Packet %d:\n", ++count);
            printf("Received %d bytes of data\n", bytes_received);

            time_t rawtime;
            struct tm * timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);

            printf("Arrival time (local): %s", asctime(timeinfo));
            printf("Packet content:\n\n%s\n", buffer);
        }
    }

    close(sockfd);

    return 0;
}