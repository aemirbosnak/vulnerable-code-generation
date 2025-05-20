//FormAI DATASET v1.0 Category: Network Ping Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define PING_WAIT_TIME 2

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    struct hostent *host;
    struct sockaddr_in ping_addr;
    int socket_fd, seq_no = 0, packets_sent = 0, packets_received = 0, ttl = 64;
    char packet[PACKET_SIZE];

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("[ERROR] Unknown Host: %s\n", argv[1]);
        exit(1);
    }

    memset(&ping_addr, 0, sizeof(ping_addr));
    ping_addr.sin_family = AF_INET;
    memcpy(&ping_addr.sin_addr, host->h_addr_list[0], host->h_length);

    if ((socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1) {
        printf("[ERROR] Socket Creation Failed\n");
        exit(1);
    }

    while (1) {
        ++seq_no;
        packets_sent++;

        memset(&packet, 0, sizeof(packet));
        struct icmp *icmp_hdr = (struct icmp *) packet;
        icmp_hdr->icmp_type = ICMP_ECHO;
        icmp_hdr->icmp_code = 0;
        icmp_hdr->icmp_id = getpid() & 0xffff;
        icmp_hdr->icmp_seq = seq_no;
        gettimeofday((struct timeval *) icmp_hdr->icmp_data, NULL);
        unsigned short checksum = 0;
        for (int i = 0; i < PACKET_SIZE; i += 2)
            checksum += *(unsigned short *) (packet + i);
        icmp_hdr->icmp_cksum = ~(checksum + (checksum >> 16));

        if (setsockopt(socket_fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) != 0) {
            printf("[WARN] Setting TTL Failed\n");
        }

        struct timeval start, stop, timeout;
        timeout.tv_sec = PING_WAIT_TIME;
        timeout.tv_usec = 0;

        if (sendto(socket_fd, packet, sizeof(packet), 0, (struct sockaddr *) &ping_addr, sizeof(ping_addr)) == -1) {
            printf("[ERROR] Sending ICMP Packet Failed\n");
            continue;
        }

        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(socket_fd, &read_set);
        int activity = select(socket_fd + 1, &read_set, NULL, NULL, &timeout);

        if (activity < 0) {
            printf("[WARN] Select Error Occurred\n");
        } else if (activity == 0) {
            printf("[WARN] Request Timed Out for seq %d\n", seq_no);
        } else {
            char recv_buf[PACKET_SIZE];
            memset(&recv_buf, 0, sizeof(recv_buf));
            struct sockaddr_in from_addr;
            socklen_t addr_len = sizeof(from_addr);
            ssize_t packet_len = recvfrom(socket_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *) &from_addr,
                                          &addr_len);

            if (packet_len < 0) {
                printf("[ERROR] Packet Receive Failed!\n");
                continue;
            }

            struct iphdr *iphdr_ptr = (struct iphdr *) recv_buf;
            struct icmp *icmp_ptr = (struct icmp *) (recv_buf + (iphdr_ptr->ihl << 2));
            if (icmp_ptr->icmp_type == ICMP_ECHOREPLY && icmp_ptr->icmp_id == getpid()) {
                gettimeofday(&stop, NULL);
                long double rtt = (stop.tv_sec - ((struct timeval *) icmp_ptr->icmp_data)->tv_sec) * 1000000;
                rtt += stop.tv_usec - ((struct timeval *) icmp_ptr->icmp_data)->tv_usec;
                rtt /= 1000;
                printf("[INFO] Reply from %s: icmp_seq=%d ttl=%d time=%.3Lf ms\n",
                       inet_ntoa(from_addr.sin_addr), icmp_ptr->icmp_seq, iphdr_ptr->ttl, rtt);
                packets_received++;
            }
        }

        sleep(1);
    }

    float packet_loss = (float) (packets_sent - packets_received) / packets_sent * 100.0;
    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n", packets_sent, packets_received, packet_loss);
    close(socket_fd);
    return 0;
}