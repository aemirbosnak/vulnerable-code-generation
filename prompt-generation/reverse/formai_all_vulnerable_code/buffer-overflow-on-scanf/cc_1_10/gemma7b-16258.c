//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024

int main()
{
    char hostname[256];
    int sockfd, err, i, packets_sent = 0, packets_received = 0;
    struct sockaddr_in servaddr;
    struct ping_packet
    {
        char data[MAX_PACKET_SIZE];
        int seq_num;
    } packet;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(3));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(65535);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    packet.seq_num = 0;
    for (i = 0; i < 10; i++)
    {
        packet.data[0] = i + 1;
        sendto(sockfd, packet.data, MAX_PACKET_SIZE, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        packets_sent++;

        packet.seq_num++;
        recvfrom(sockfd, packet.data, MAX_PACKET_SIZE, 0, (struct sockaddr *)&servaddr, NULL);
        packets_received++;
    }

    printf("Number of packets sent: %d\n", packets_sent);
    printf("Number of packets received: %d\n", packets_received);
    printf("Packet loss: %.2f%%\n", (packets_sent - packets_received) * 100.0 / packets_sent);

    close(sockfd);

    return 0;
}