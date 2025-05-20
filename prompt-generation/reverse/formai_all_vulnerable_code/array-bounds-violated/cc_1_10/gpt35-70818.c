//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PORT 8888
#define MAXLINE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr, clientaddr;
    char buffer[MAXLINE];
    time_t ticks;
    char client_ipv4[INET_ADDRSTRLEN];

    // create socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // bind socket to server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        unsigned int len = sizeof(clientaddr);
        int n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&clientaddr, &len);
        if (n < 0) {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        // get client IP address
        inet_ntop(AF_INET, &(clientaddr.sin_addr), client_ipv4, INET_ADDRSTRLEN);

        buffer[n] = '\0';
        printf("Received packet from %s:%d\n", client_ipv4, ntohs(clientaddr.sin_port));
        printf("Message: %s\n", buffer);

        // send response to client
        ticks = time(NULL);
        snprintf(buffer, sizeof(buffer), "%.24s\r\n", ctime(&ticks));
        sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&clientaddr, len);
        printf("Response sent to %s:%d\n", client_ipv4, ntohs(clientaddr.sin_port));
    }

    close(sockfd);
    return 0;
}