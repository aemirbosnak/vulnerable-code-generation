//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n;
        socklen_t len;
        struct sockaddr_in cliaddr;

        len = sizeof(cliaddr);

        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &cliaddr, &len);
        buffer[n] = '\0';

        // calculate network quality of service (QoS) metrics
        int latency = rand() % 50 + 1; // simulate random latency in milliseconds
        int jitter = rand() % 20 + 1; // simulate random jitter in milliseconds
        int packet_loss = rand() % 10 + 1; // simulate random packet loss rate in percentage

        // create response message with QoS metrics
        char response[MAXLINE];
        snprintf(response, MAXLINE, "Latency: %dms\nJitter: %dms\nPacket Loss: %d%%\n", latency, jitter, packet_loss);
        
        // send QoS metrics to client
        sendto(sockfd, (const char *)response, strlen(response), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
        printf("QoS metrics sent to client.\n");
    }

    close(sockfd);
    return 0;
}