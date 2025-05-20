//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PACKET_SIZE 1024
#define TIMEOUT 10

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[PACKET_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    while (1) {
        if (recv(sockfd, buffer, PACKET_SIZE, 0) < 0) {
            perror("recv() failed");
            return 1;
        }

        printf("Received packet: %s\n", buffer);

        // Check if the packet contains a QoS header
        if (strstr(buffer, "QoS")) {
            // Extract the QoS value from the packet
            char *qos_value = strstr(buffer, "QoS");
            qos_value += 3;

            // Print the QoS value
            printf("QoS value: %s\n", qos_value);

            // Check if the QoS value is within the acceptable range
            if (atoi(qos_value) < 1 || atoi(qos_value) > 5) {
                printf("Invalid QoS value: %s\n", qos_value);
            } else {
                printf("Valid QoS value: %s\n", qos_value);
            }
        } else {
            printf("No QoS header found in packet\n");
        }
    }

    return 0;
}