//FormAI DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define ICMP_ECHO_REQUEST       8 /* Echo Request (RFC 792) */
#define MAX_HOPS                64 /* Max value for IP TTL */
#define IP_HEADER_LENGTH        20 /* Min Size of IP header */
#define ICMP_HEADER_LENGTH      8 /* Size of ICMP header without data */
#define MAX_WAIT_TIME           5 /* Max time in seconds waiting for a reply */
#define MAX_PACKET_SIZE         4096 /* Max size of an IP packet */

/* ICMP header structure without data*/
struct icmp_header {
    uint8_t type;           /* ICMP message type */
    uint8_t code;           /* ICMP message code */
    uint16_t checksum;      /* ICMP message checksum */
    uint16_t id;            /* ICMP message id */
    uint16_t sequence;      /* ICMP message sequence */
};

/* IP header structure */
struct ip_header {
    uint8_t     protocol;   /* Higher-layer protocol */
    uint8_t     ttl;        /* Time to Live (TTL) */
    uint16_t    id;         /* Unique identifier */
    uint16_t    offset;     /* Fragment offset field */
    uint16_t    checksum;   /* IP header checksum */
    struct in_addr  source; /* Source address */
    struct in_addr  dest;   /* Destination address */
};

int main(int argc, char **argv) {
    int sockfd, ttl = 1, num_sent = 0, num_replies = 0, seq = 0;
    char hostname[NI_MAXHOST];
    struct timeval tv;
    struct hostent *host;
    struct sockaddr_in addr, source_addr;
    struct ip_header *ip_hdr;
    struct icmp_header *icmp_hdr;
    char packet[MAX_PACKET_SIZE], buffer[MAX_PACKET_SIZE];
    ssize_t packet_size, bytes_received;
    socklen_t addrlen = sizeof(struct sockaddr_in);

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    /* Set up socket */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    /* Set socket options */
    int optval = 1;
    if(setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    /* Get host IP from hostname */
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Cannot resolve hostname %s\n", argv[1]);
        exit(1);
    }

    /* Set up destination address */
    memset(&addr, 0, sizeof(struct sockaddr_in));
    memcpy(&addr.sin_addr, host->h_addr_list[0], sizeof(struct in_addr));
    addr.sin_family = AF_INET;

    /* Get hostname from IP address */
    if(getnameinfo((struct sockaddr *)&addr, sizeof(struct sockaddr_in),
        hostname, NI_MAXHOST, NULL, 0, 0) != 0) {
        printf("Unable to resolve address %s\n", inet_ntoa(addr.sin_addr));
        exit(1);
    }

    /* Initialize packet */
    memset(packet, 0, MAX_PACKET_SIZE);
    icmp_hdr = (struct icmp_header *) packet;
    icmp_hdr->type = ICMP_ECHO_REQUEST;
    icmp_hdr->id = getpid() & 0xFFFF;

    packet_size = ICMP_HEADER_LENGTH + sizeof(struct timeval) + 4;
    gettimeofday((struct timeval *)(packet+ICMP_HEADER_LENGTH), NULL);
    icmp_hdr->checksum = 0;
    icmp_hdr->sequence = seq++;

    /* Send packet */
    if(sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)&addr,
        sizeof(struct sockaddr_in)) < 0) {
            perror("sendto");
            exit(1);
    }
    num_sent++;

    /* Set timeout for select */
    tv.tv_sec = MAX_WAIT_TIME;
    tv.tv_usec = 0;

    while (ttl < MAX_HOPS) {
        /* Set up select */
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        /* Set TTL */
        if(setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
            perror("setsockopt");
            exit(1);
        }

        /* Print traceroute output */
        printf("%d ", ttl);
        if(inet_ntop(AF_INET, &addr.sin_addr, buffer, sizeof(buffer)) == NULL) {
            perror("inet_ntop");
            exit(1);
        }
        printf("%s ", buffer);

        /* Mark start time for round-trip time */
        struct timespec start_time, end_time;
        clock_gettime(CLOCK_REALTIME, &start_time);

        /* Send packet */
        if(sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)&addr,
            sizeof(struct sockaddr_in)) < 0) {
                perror("sendto");
                exit(1);
        }
        num_sent++;

        /* Wait for packet or timeout */
        int ready = select(sockfd+1, &readfds, NULL, NULL, &tv);
        if(ready == -1) {
            perror("select");
            exit(1);
        } else if(ready == 0) { /* Timeout */
            printf("*\n");
        } else { /* Packet received */
            bytes_received = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0,
                (struct sockaddr *)&source_addr, &addrlen);

            if(bytes_received < 0) {
                perror("recvfrom");
                exit(1);
            }

            /* Extract IP header */
            ip_hdr = (struct ip_header *) buffer;

            /* Make sure it is an ICMP packet */
            if((ip_hdr->protocol == IPPROTO_ICMP) && (ip_hdr->source.s_addr == addr.sin_addr.s_addr)) {
                /* Extract ICMP header */
                icmp_hdr = (struct icmp_header *)(buffer + IP_HEADER_LENGTH);

                /* Check if it is an echo reply */
                if(icmp_hdr->type == ICMP_ECHOREPLY) {
                    /* Mark end time for round-trip time */
                    clock_gettime(CLOCK_REALTIME, &end_time);
                    double rtt = (double) (end_time.tv_sec - start_time.tv_sec) +
                        (double) (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

                    /* Increment number of replies */
                    num_replies++;

                    /* Print output */
                    printf("%.03f ms\n", rtt*1000);

                    /* Check if we have reached our destination */
                    if(ip_hdr->dest.s_addr == addr.sin_addr.s_addr) {
                        printf("Reached %s in %d hops\n", hostname, ttl);
                        exit(0);
                    }
                }
            }
        }

        /* Increment TTL */
        ttl++;

        /* Reset select timeout */
        tv.tv_sec = MAX_WAIT_TIME;
        tv.tv_usec = 0;
    }

    printf("Unable to reach %s in %d hops\n", hostname, MAX_HOPS);
    exit(1);
}