//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 64
#define MAX_HOPS 30

uint16_t calculate_checksum(uint16_t *addr, int len);

int main(int argc, char *argv[])
{
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    char host[BUFFER_SIZE];
    scanf("%s", host);

    struct hostent *h = gethostbyname(host);
    if (h == NULL)
    {
        printf("Error: Cannot resolve %s\n", host);
        return EXIT_FAILURE;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = *((struct in_addr *)h->h_addr);

    char reverse_hostname[BUFFER_SIZE];
    if (getnameinfo((struct sockaddr *)&dest_addr, sizeof(dest_addr),
                    reverse_hostname, BUFFER_SIZE, NULL, 0, NI_NAMEREQD) == 0)
    {
        printf("PING %s (%s) 56(84) bytes of data.\n",
               h->h_name, reverse_hostname);
    }
    else
    {
        printf("PING %s (%s) 56(84) bytes of data.\n",
               h->h_name, inet_ntoa(dest_addr.sin_addr));
    }

    for (int ttl = 1; ttl <= MAX_HOPS; ttl++)
    {
        if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int)) < 0)
        {
            perror("setsockopt");
            return EXIT_FAILURE;
        }

        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv)) < 0)
        {
            perror("setsockopt");
            return EXIT_FAILURE;
        }

        char recv_buffer[BUFFER_SIZE];
        memset(recv_buffer, 0, sizeof(recv_buffer));

        struct icmphdr icmp_header;
        icmp_header.type = ICMP_ECHO;
        icmp_header.code = 0;
        icmp_header.un.echo.id = getpid();
        icmp_header.un.echo.sequence = ttl;
        icmp_header.checksum = 0;
        icmp_header.checksum = calculate_checksum((uint16_t *)&icmp_header, sizeof(icmp_header));

        struct timeval start_time;
        gettimeofday(&start_time, NULL);

        ssize_t bytes_sent = sendto(sockfd, &icmp_header, sizeof(icmp_header), 0,
                                    (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (bytes_sent < 0)
        {
            perror("sendto");
            return EXIT_FAILURE;
        }

        struct sockaddr_in recv_addr;
        socklen_t recv_addr_len = sizeof(recv_addr);
        ssize_t bytes_received = recvfrom(sockfd, recv_buffer, sizeof(recv_buffer), 0,
                                          (struct sockaddr *)&recv_addr, &recv_addr_len);

        if (bytes_received < 0)
        {
            printf("%d * *\n", ttl);
            continue;
        }

        struct timeval end_time;
        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
        elapsed_time += (end_time.tv_usec - start_time.tv_usec) / 1000.0;

        struct icmphdr *received_icmp_hdr = (struct icmphdr *)recv_buffer;
        if (received_icmp_hdr->type == ICMP_TIME_EXCEEDED)
        {
            struct iphdr *received_ip_hdr = (struct iphdr *)(recv_buffer + sizeof(struct icmphdr));
            uint8_t *received_icmp_data = (uint8_t *)(recv_buffer + sizeof(struct icmphdr) + sizeof(struct iphdr));

            struct sockaddr_in received_addr;
            memset(&received_addr, 0, sizeof(received_addr));
            received_addr.sin_family = AF_INET;
            received_addr.sin_addr = *((struct in_addr *)&received_ip_hdr->saddr);

            char received_reverse_host[BUFFER_SIZE];
            if (getnameinfo((struct sockaddr *)&received_addr, sizeof(received_addr),
                            received_reverse_host, BUFFER_SIZE, NULL, 0, NI_NAMEREQD) == 0)
            {
                printf("%d  %s (%s)  %.1f ms\n", ttl, received_reverse_host,
                       inet_ntoa(received_addr.sin_addr), elapsed_time);
            }
            else
            {
                printf("%d  %s  (%s)  %.1f ms\n", ttl, inet_ntoa(received_addr.sin_addr),
                       inet_ntoa(received_addr.sin_addr), elapsed_time);
            }
        }
        else if (received_icmp_hdr->type == ICMP_ECHOREPLY)
        {
            printf("%d  %s  %.1f ms\n", ttl, host, elapsed_time);
            break;
        }
        else
        {
            printf("%d  Received unknown ICMP packet type %d\n", ttl, received_icmp_hdr->type);
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}

uint16_t calculate_checksum(uint16_t *addr, int len)
{
    uint32_t checksum = 0;
    while (len > 1)
    {
        checksum += *addr++;
        len -= 2;
    }
    if (len == 1)
    {
        checksum += *(uint8_t *)addr;
    }
    checksum = (checksum >> 16) + (checksum & 0xffff);
    checksum += (checksum >> 16);
    return ~checksum;
}