//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 4096

void print_header() {
    printf("\n------------------------------------------------------------\n");
    printf("   Welcome to the C Network Quality of Service (QoS) monitor\n");
    printf("------------------------------------------------------------\n\n");
}

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char packet[MAX_PACKET_SIZE];
    struct timeval start, end;
    double elapsed_time;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR: Could not open socket\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("ERROR: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server successfully!\n\n");
    print_header();

    while (1) {
        printf("Sending packet to server...");
        bzero(packet, MAX_PACKET_SIZE);
        gettimeofday(&start, NULL);
        n = send(sockfd, packet, MAX_PACKET_SIZE, 0);
        if (n < 0) {
            printf("ERROR: Could not send packet\n");
            exit(1);
        }
        gettimeofday(&end, NULL);
        elapsed_time = ((end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0);
        printf("Packet sent! Response time: %lf ms \n", elapsed_time);
        sleep(1);
    }

    close(sockfd);
    return 0;
}