//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

#define PACKET_SIZE 64

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <IP Address/Domain Name>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    int status;
    char ipstr[INET6_ADDRSTRLEN];
    struct timeval tv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(status));
        return 2;
    }

    void *addr;
    char *ipver;

    if (res->ai_family == AF_INET) {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
        addr = &(ipv4->sin_addr);
        ipver = "IPv4";
    } else {
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)res->ai_addr;
        addr = &(ipv6->sin6_addr);
        ipver = "IPv6";
    }

    inet_ntop(res->ai_family, addr, ipstr, sizeof ipstr);
    printf("Pinging %s [%s] with %d bytes of data:\n\n", argv[1], ipstr, PACKET_SIZE);

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (sock < 0) {
        printf("Unable to create socket\n");
        return 3;
    }

    struct sockaddr_storage destination_addr;
    memcpy(&destination_addr, res->ai_addr, res->ai_addrlen);

    int sequence_no = 0;
    int i;
    int sent_count = 0;
    int recv_count = 0;
    int time_sum = 0;

    for(i = 0; i < 4; i++) {
        sequence_no++;
        char message[PACKET_SIZE];
        memset(message, 'a', PACKET_SIZE);

        ssize_t bytes_sent = sendto(sock, message, PACKET_SIZE, 0, (struct sockaddr *)&destination_addr, res->ai_addrlen);

        if (bytes_sent < 0) {
            printf("Unable to send message\n");
            continue;
        }

        sent_count++;

        tv.tv_sec = 1;
        tv.tv_usec = 0;
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        int select_status = select(sock+1, &readfds, NULL, NULL, &tv);
        if (select_status == -1) {
            printf("Select error\n");
            continue;
        } else if (select_status == 0) {
            printf("Request timed out for sequence number %d\n\n", sequence_no);
            continue;
        }

        char buffer[PACKET_SIZE];
        struct sockaddr_storage src_addr;
        socklen_t src_addr_len = sizeof(src_addr);
        ssize_t bytes_recv = recvfrom(sock, buffer, PACKET_SIZE, 0, (struct sockaddr *)&src_addr, &src_addr_len);
        if (bytes_recv < 0) {
            printf("Error in receiving message\n");
            continue;
        }

        recv_count++;
        struct timeval *timestamp = (struct timeval *) buffer;
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        int time_diff = (int) (current_time.tv_usec - timestamp->tv_usec);

        printf("Reply from %s: bytes=%d time=%dms TTL=255\n", ipstr, bytes_recv, time_diff);
        printf("\n");

        time_sum += time_diff;
    }

    if(sent_count != recv_count) {
        printf("Ping failed: %d packets sent, %d packets received\n", sent_count, recv_count);
        return 4;
    }

    int avg_time = time_sum / recv_count;

    printf("Ping statistics for %s:\n Packets: Sent = %d, Received = %d, Lost = %d (%.1f%% loss),\nApproximate round trip times in milli-seconds:\n Minimum = %dms, Maximum = %dms, Average = %dms\n",
        argv[1], sent_count, recv_count, sent_count - recv_count, ((sent_count - recv_count) * 100.0 / sent_count),
        avg_time, avg_time, avg_time);

    close(sock);
    freeaddrinfo(res);
    return 0;
}