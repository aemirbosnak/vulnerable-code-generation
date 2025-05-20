//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    char host[256];
    int sockfd, n, port = 53, timeout = 2;
    struct sockaddr_in srv_addr;
    struct ping_packet
    {
        char data[1024];
        int seq_num;
    } ping_packet;

    printf("Enter the host name: ");
    scanf("%s", host);

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    srv_addr.sin_addr.s_addr = inet_addr(host);

    ping_packet.seq_num = 1;
    n = sendto(sockfd, ping_packet.data, sizeof(ping_packet), 0, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

    if (n < 0)
    {
        perror("Error sending ping packet");
        exit(1);
    }

    ping_packet.seq_num = 2;
    n = sendto(sockfd, ping_packet.data, sizeof(ping_packet), 0, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

    if (n < 0)
    {
        perror("Error sending ping packet");
        exit(1);
    }

    // Wait for the ping reply
    n = recvfrom(sockfd, ping_packet.data, sizeof(ping_packet), 0, (struct sockaddr *)&srv_addr, NULL);

    if (n < 0)
    {
        perror("Error receiving ping reply");
        exit(1);
    }

    // Print the ping reply
    printf("Ping reply from %s: %d bytes, sequence number %d\n", host, n, ping_packet.seq_num);

    close(sockfd);

    return 0;
}