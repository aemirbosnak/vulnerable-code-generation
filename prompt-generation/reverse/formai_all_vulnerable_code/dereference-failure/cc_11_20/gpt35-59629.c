//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PACKET_SIZE 64
#define MAX_PACKETS 4
#define TIMEOUT 1

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    int sockfd, rc;
    struct sockaddr_in addr;
    struct hostent *host;
    char packet[PACKET_SIZE];
    int connections = 0;
    int timeouts = 0;
    int i;

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0)
    {
        printf("Failed to create socket\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Could not resolve host %s\n", argv[1]);
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
    addr.sin_port = htons(0);

    for (i = 0; i < MAX_PACKETS; i++)
    {
        memset(&packet, 0, PACKET_SIZE);
        packet[0] = 8;
        packet[1] = 0;
        packet[2] = 0;
        packet[3] = 0;
        packet[4] = 0;
        packet[5] = 0;
        packet[6] = 0;
        packet[7] = 0;
        packet[8] = i + 1;
        packet[9] = 0;
        packet[10] = 0;
        packet[11] = 0;
        packet[12] = 'K';
        packet[13] = 'T';
        packet[14] = 'P';
        packet[15] = '!';

        rc = sendto(sockfd, packet, PACKET_SIZE, 0,
                    (struct sockaddr *)&addr, sizeof(addr));
        if (rc < 0)
        {
            printf("Failed to send packet %d\n", i + 1);
            continue;
        }

        connections++;

        fd_set read_fds;
        struct timeval tv;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        int num_fds = select(sockfd + 1, &read_fds, NULL, NULL, &tv);

        if (num_fds < 0)
        {
            printf("Error in select()\n");
            break;
        }
        else if (num_fds == 0)
        {
            timeouts++;
            printf("Packet %d timed out\n", i + 1);
        }
        else
        {
            char recv_packet[PACKET_SIZE];
            int recv_len = recvfrom(sockfd, recv_packet, PACKET_SIZE, 0, NULL, NULL);
            if (recv_len < 0)
            {
                printf("Error in recvfrom()\n");
                break;
            }

            if (recv_len >= 16 && recv_packet[8] == packet[8])
            {
                printf("Received response for packet %d\n", i + 1);
            }
            else
            {
                printf("Received invalid response for packet %d\n", i + 1);
            }
        }
    }

    printf("%d packets sent, %d packets received, %d packets timed out\n", MAX_PACKETS, connections - timeouts, timeouts);

    close(sockfd);

    return 0;
}