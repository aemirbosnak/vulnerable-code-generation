//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define PING_COUNT 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Function prototypes
int create_socket();
void fill_packet(struct ping_packet *packet, int seq);
void send_ping(int sockfd, struct sockaddr_in *addr);
void receive_ping(int sockfd);
unsigned short calculate_checksum(void *b, int len);
void ping(const char *ip_address);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = create_socket();
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, ip_address, &addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < PING_COUNT; i++) {
        send_ping(sockfd, &addr);
        receive_ping(sockfd);
        sleep(1);
    }

    close(sockfd);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void fill_packet(struct ping_packet *packet, int seq) {
    packet->hdr.type = ICMP_ECHO;
    packet->hdr.un.echo.id = getpid();
    packet->hdr.un.echo.sequence = seq;
    packet->hdr.checksum = 0;
    memset(packet->msg, 0, sizeof(packet->msg));
    snprintf(packet->msg, sizeof(packet->msg), "Ping message %d", seq);
    packet->hdr.checksum = calculate_checksum(packet, sizeof(struct ping_packet));
}

void send_ping(int sockfd, struct sockaddr_in *addr) {
    struct ping_packet packet;
    fill_packet(&packet, getpid());
    
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("Send failed");
    } else {
        printf("Ping sent: seq=%d\n", packet.hdr.un.echo.sequence);
    }
}

void receive_ping(int sockfd) {
    struct sockaddr_in reply_addr;
    socklen_t addr_len = sizeof(reply_addr);
    struct ping_packet packet;
    fd_set read_fds;
    struct timeval timeout;

    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    int rv = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
    
    if (rv == -1) {
        perror("Select error");
        return;
    } else if (rv == 0) {
        printf("Request timed out.\n");
        return;
    }

    if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&reply_addr, &addr_len) <= 0) {
        perror("Recvfrom failed");
        return;
    }

    if (packet.hdr.type == ICMP_ECHOREPLY) {
        printf("Received reply from %s: seq=%d\n", inet_ntoa(reply_addr.sin_addr), packet.hdr.un.echo.sequence);
    }
}

unsigned short calculate_checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}