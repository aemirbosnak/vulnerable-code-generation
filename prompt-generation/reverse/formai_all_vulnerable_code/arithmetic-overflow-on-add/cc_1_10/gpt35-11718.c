//FormAI DATASET v1.0 Category: Network Ping Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_SIZE 4096

/* Simple checksum function used for the ICMP packet */
unsigned short checksum(void *b, int len)
{   
   unsigned short *buf = b;
   unsigned int sum=0;
   unsigned short result;

   for ( sum = 0; len > 1; len -= 2 )
       sum += *buf++;
   if ( len == 1 )
       sum += *(unsigned char*)buf;
   sum = (sum >> 16) + (sum & 0xFFFF);
   sum += (sum >> 16);
   result = ~sum;
   return result;
}

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in addr_ping, addr_recv;
    char buffer[PACKET_SIZE];
    struct icmp *icmp_packet;
    int sent_seq_num = 0, received_seq_num = 0, bytes_received = 0;
    socklen_t sockaddr_len = sizeof(addr_recv);
    struct timeval tv_begin, tv_end, tv_interval;

    if(argc < 2)
    {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        exit(0);
    }

    /* Create a socket for sending and receiving ICMP packets */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0)
    {
        printf("Unable to create socket.\n");
        exit(1);
    }

    /* Initialize the destination IP address and ICMP packet information */
    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &addr_ping.sin_addr);
    icmp_packet = (struct icmp*) buffer;
    icmp_packet->icmp_type = ICMP_ECHO;
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_id = getpid();

    /* Continuously send and receive ICMP packets */
    printf("Pinging %s...\n", argv[1]);
    while(1)
    {
        /* Set the ICMP packet sequence number and fill the data payload */
        sent_seq_num++;
        icmp_packet->icmp_seq = sent_seq_num;
        memset(icmp_packet->icmp_data, 0xa5, sizeof(buffer) - sizeof(struct icmp));

        /* Calculate the ICMP packet checksum */
        icmp_packet->icmp_cksum = checksum(icmp_packet, sizeof(struct icmp));

        /* Record the time that the ICMP packet is being sent */
        gettimeofday(&tv_begin, NULL);

        /* Send the ICMP packet to the destination IP address */
        if(sendto(sockfd, buffer, sizeof(struct icmp), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) < 0)
        {
            printf("Error in sendto.\n");
            continue;
        }

        /* Attempt to receive an ICMP packet from the destination IP address */
        memset(buffer, 0, sizeof(buffer));
        if((bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr_recv, &sockaddr_len)) < 0)
        {
            printf("Error in recvfrom.\n");
            continue;
        }

        /* Record the time that the ICMP packet is being received */
        gettimeofday(&tv_end, NULL);

        /* Calculate the round-trip time and print the results */
        timersub(&tv_end, &tv_begin, &tv_interval);
        printf("%d bytes from %s: icmp_seq=%d time=%ld.%06ldms\n", bytes_received, inet_ntoa(addr_recv.sin_addr), icmp_packet->icmp_seq, tv_interval.tv_sec * 1000 + tv_interval.tv_usec / 1000, tv_interval.tv_usec % 1000);

        /* Check if the received ICMP packet matches the one that we sent */
        received_seq_num = ((struct icmp*) buffer)->icmp_seq;
        if(received_seq_num != sent_seq_num)
        {
            printf("Received sequence number does not match sent sequence number.\n");
            continue;
        }

        /* Sleep for one second before sending the next ICMP packet */
        sleep(1);
    }

    return 0;
}