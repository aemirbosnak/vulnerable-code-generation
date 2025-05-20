//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <time.h>

#define BUFSIZE 1024

/* Structure to hold the packet headers */
struct pkt {
    struct iphdr ip_h;
    struct tcphdr tcp_h;
    char payload[BUFSIZE - sizeof(struct iphdr) - sizeof(struct tcphdr)];
};

/* Function to calculate the checksum of the packet */
unsigned short checksum(unsigned short *ptr, int nbytes)
{
    register long sum;
    unsigned short oddbyte;
    register short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1) {
        oddbyte = 0;
        *((u_char*)&oddbyte) = *(u_char*)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (short)~sum;

    return(answer);
}

int main()
{
    int sockfd, optval = 1;
    struct sockaddr_in addr;
    struct pkt pktbuf;
    socklen_t addrlen = sizeof(addr);
    char ipdest[16], iplocal[16];
    unsigned short destport, localport;
    int count, timeout, delay;

    /* Get the destination IP address and port */
    printf("Enter the destination IP address: ");
    scanf("%s", ipdest);
    printf("Enter the destination port: ");
    scanf("%hu", &destport);

    /* Get the local IP address and port */
    printf("Enter the local IP address: ");
    scanf("%s", iplocal);
    printf("Enter the local port: ");
    scanf("%hu", &localport);

    /* Get the packet count, timeout and delay values */
    printf("Enter the packet count: ");
    scanf("%d", &count);
    printf("Enter the timeout value in seconds: ");
    scanf("%d", &timeout);
    printf("Enter the delay value in milliseconds: ");
    scanf("%d", &delay);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    /* Set the IP_HDRINCL flag to include the IP header in the packet */
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    /* Set the destination address */
    addr.sin_family = AF_INET;
    addr.sin_port = htons(destport);
    addr.sin_addr.s_addr = inet_addr(ipdest);

    /* Initialize the packet */
    memset(&pktbuf, 0, sizeof(pktbuf));
    pktbuf.ip_h.ihl = 5;
    pktbuf.ip_h.version = 4;
    pktbuf.ip_h.tos = 0;
    pktbuf.ip_h.id = htons(54321);
    pktbuf.ip_h.frag_off = htons(0);
    pktbuf.ip_h.ttl = 255;
    pktbuf.ip_h.protocol = IPPROTO_TCP;
    pktbuf.ip_h.saddr = inet_addr(iplocal);
    pktbuf.ip_h.daddr = inet_addr(ipdest);
    pktbuf.tcp_h.source = htons(localport);
    pktbuf.tcp_h.dest = htons(destport);
    pktbuf.tcp_h.seq = htonl(1);
    pktbuf.tcp_h.doff = 5;
    pktbuf.tcp_h.fin = 0;
    pktbuf.tcp_h.syn = 1;
    pktbuf.tcp_h.rst = 0;
    pktbuf.tcp_h.psh = 0;
    pktbuf.tcp_h.ack = 0;
    pktbuf.tcp_h.urg = 0;
    pktbuf.tcp_h.window = htons(5840);
    pktbuf.tcp_h.check = 0;
    pktbuf.tcp_h.urg_ptr = 0;

    /* Loop to send the packets */
    for (int i = 0; i < count; i++) {
        /* Calculate the TCP checksum */
        pktbuf.tcp_h.check = checksum((unsigned short *)&pktbuf, sizeof(pktbuf));

        /* Send the packet */
        if (sendto(sockfd, &pktbuf, sizeof(pktbuf), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("sendto");
            exit(1);
        }

        /* Delay for a specified amount of time */
        usleep(delay * 1000);
    }

    /* Wait for a specified amount of time to receive the response */
    printf("Waiting for response...\n");
    sleep(timeout);

    /* Check for any response */
    if (recvfrom(sockfd, &pktbuf, sizeof(pktbuf), 0, (struct sockaddr *)&addr, &addrlen) >= 0) {
        printf("Response received!\n");
    } else {
        printf("No response received!\n");
    }

    /* Close the socket */
    close(sockfd);

    return 0;
}