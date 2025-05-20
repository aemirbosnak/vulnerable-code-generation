//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_ATTEMPTS 4

typedef struct {
    struct icmphdr header;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} ping_packet;

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *) buf;
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *target) {
    struct sockaddr_in addr_con;
    int sock_fd;
    ping_packet packet;
    struct timeval timeout;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    int ping_rc;
    char ip[INET_ADDRSTRLEN];
    time_t start, end;
    double time_elapsed;

    addr_con.sin_family = AF_INET;
    addr_con.sin_port = htons(0);
    addr_con.sin_addr.s_addr = inet_addr(target);

    sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock_fd < 0) {
        perror("Socket creation failed");
        return;
    }

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    if (setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("Setting socket options failed");
        return;
    }

    printf("Pinging %s...\n", target);
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.header.type = ICMP_ECHO;
        packet.header.un.echo.id = getpid();
        packet.header.un.echo.sequence = i;
        packet.header.checksum = checksum(&packet, sizeof(packet));

        start = time(NULL);
        ping_rc = sendto(sock_fd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr_con, sizeof(addr_con));
        if (ping_rc <= 0) {
            printf("Ping %d failed: %s\n", i + 1, strerror(errno));
            continue;
        }

        ping_rc = recvfrom(sock_fd, &packet, sizeof(packet), 0, (struct sockaddr*)&r_addr, &addr_len);
        end = time(NULL);
        time_elapsed = difftime(end, start) * 1000; // Convert to milliseconds
        
        if (ping_rc > 0) {
            if (packet.header.type == 0) {
                inet_ntop(AF_INET, &(r_addr.sin_addr), ip, INET_ADDRSTRLEN);
                printf("Ping %d: Reply from %s: bytes=%d time=%.2f ms\n", i + 1, ip, ping_rc, time_elapsed);
            }
        } else {
            printf("Ping %d timed out.\n", i + 1);
        }
        sleep(1);
    }

    close(sock_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP or hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}