//FormAI DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define PACKETSIZE     64
#define MAXTRIES       3
#define TIMEOUT        1000

int main(int argc, char *argv[])
{
    struct hostent *host;
    struct sockaddr_in addr;
    int sock, addr_len, n, i, j, cnt = 0;
    int alive = 0, avg = 0, minrtt = 99999, maxrtt = 0;
    struct icmp *icmp;
    char packet[PACKETSIZE], recvpacket[PACKETSIZE];
    socklen_t fromlen;
    struct timeval tvrecv, tvsend, tvinterval, tvout;

    if (argc != 2)
    {
        printf("Usage: %s [target]\n", argv[0]);
        exit(1);
    }

    // try to resolve address
    if ((host = gethostbyname(argv[1])) == NULL)
    {
        printf("Cannot resolve host.\n");
        exit(1);
    }

    // fill in address structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // create socket
    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket");
        exit(1);
    }

    printf("Ping %s...\n", inet_ntoa(addr.sin_addr));

    // prepare icmp packet
    icmp = (struct icmp *) packet;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_id = getpid() & 0xFFFF;
    icmp->icmp_seq = 0;
    memset(packet + sizeof(struct icmp), 0xa5, PACKETSIZE - sizeof(struct icmp));

    // prepare out time
    tvout.tv_sec = TIMEOUT / 1000;
    tvout.tv_usec = (TIMEOUT % 1000) * 1000;

    // main loop to send icmp packets and receive response
    while (cnt < MAXTRIES)
    {
        // send icmp packet
        if (sendto(sock, packet, PACKETSIZE, 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        {
            perror("sendto");
            exit(1);
        }

        // get time of sending
        gettimeofday(&tvsend, NULL);

        // set up time interval for select
        tvinterval.tv_sec = 0;
        tvinterval.tv_usec = 1000000;

        // select for timeout
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);

        if (select(sock + 1, &readfds, NULL, NULL, &tvinterval) <= 0)
        {
            printf("Timeout for icmp_seq %d\n", cnt);
        }
        else
        {
            // receive icmp packet
            fromlen = sizeof(addr);

            if ((n = recvfrom(sock, recvpacket, sizeof(recvpacket), 0, (struct sockaddr *)&addr, &fromlen)) < 0)
            {
                perror("recvfrom");
                exit(1);
            }

            // get time of response
            gettimeofday(&tvrecv, NULL);

            // calculate round-trip time
            int rtt = (tvrecv.tv_sec - tvsend.tv_sec) * 1000 + (tvrecv.tv_usec - tvsend.tv_usec) / 1000;

            // update stats
            alive++;
            avg += rtt;

            if (minrtt > rtt) minrtt = rtt;
            if (maxrtt < rtt) maxrtt = rtt;

            // print result
            printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.1f ms\n", n, inet_ntoa(addr.sin_addr), cnt, 
                ntohs(addr.sin_port), (float)rtt);

            usleep(1000000 - (tvrecv.tv_usec - tvsend.tv_usec)); // wait for 1s
        }

        cnt++;
    }

    // close socket
    close(sock);

    // print statistics
    printf("--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %dms\n", MAXTRIES, alive, 
        (MAXTRIES - alive) * 100 / MAXTRIES, TIMEOUT * MAXTRIES);

    if (alive > 0)
    {
        printf("rtt min/avg/max = %.1f/%.1f/%.1f ms\n", (float)minrtt, (float)avg/alive, (float)maxrtt);
    }

    return 0;
}