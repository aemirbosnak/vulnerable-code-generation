//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char hostname[256];
    int sockfd, ping_size, i, j, k;
    struct sockaddr_in server_addr;
    struct ping_packet
    {
        unsigned short packet_id;
        unsigned int seq_num;
        char data[1024];
    } ping_packet;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    ping_size = sizeof(ping_packet);

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(5));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(65432);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    for (i = 0; i < 10; i++)
    {
        ping_packet.packet_id = i;
        ping_packet.seq_num = i;
        strcpy(ping_packet.data, "This is a ping packet.");

        sendto(sockfd, &ping_packet, ping_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        for (j = 0; j < 10; j++)
        {
            recvfrom(sockfd, &ping_packet, ping_size, 0, (struct sockaddr *)&server_addr, NULL);

            if (ping_packet.packet_id == i)
            {
                printf("Received ping packet from %s with seq num %d.\n", hostname, ping_packet.seq_num);
            }
        }
    }

    close(sockfd);

    return 0;
}