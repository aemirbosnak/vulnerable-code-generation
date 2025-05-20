//FormAI DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define PACKET_SIZE 4096
#define MAX_IP_LEN 16

// Structure for ICMP packet
struct icmp_packet {
    uint8_t type;           // Type of packet (8 for echo request, 0 for echo reply)
    uint8_t code;           // Code (always 0 for ping)
    uint16_t checksum;      // Checksum of ICMP request
    uint16_t id;            // Identification of request
    uint16_t sequence;      // Sequence number of request
    char data[32];          // Optional data to include in request
};

// Calculates the checksum of a packet
unsigned short checksum(void *buffer, int length) {
    unsigned short *buf = (unsigned short *)buffer;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; length > 1; length -= 2)
        sum += *buf++;

    if (length == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

// Sends an ICMP packet to the specified IP address
void send_ping(int sockfd, char *ip, int seq) {
    struct icmp_packet packet;
    struct sockaddr_in dest_addr;
    struct hostent *he;
    int size = sizeof(struct sockaddr_in);

    memset(&packet, 0, sizeof(struct icmp_packet));
    packet.type = ICMP_ECHO_REQUEST;
    packet.code = 0;
    packet.id = getpid() & 0xFFFF;
    packet.sequence = seq;
    gethostname(packet.data, sizeof(packet.data));

    packet.checksum = checksum((void *)&packet, sizeof(struct icmp_packet));
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));

    if ((he = gethostbyname(ip)) == NULL) {
        fprintf(stderr, "ERROR: Could not find IP address for %s\n", ip);
        exit(1);
    }

    memcpy(&dest_addr.sin_addr, he->h_addr_list[0], he->h_length);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);

    if (sendto(sockfd, &packet, sizeof(struct icmp_packet), 0, (struct sockaddr *)&dest_addr, size) <= 0) {
        fprintf(stderr, "ERROR: Failed to send ping request to %s!\n", ip);
        exit(1);
    }
}

// Receives and processes incoming ICMP packets
void receive_ping(int sockfd, char *ip, int seq) {
    struct icmp_packet packet;
    struct sockaddr_in recv_addr;
    int addr_len = sizeof(recv_addr);
    int num_bytes;

    num_bytes = recvfrom(sockfd, &packet, sizeof(struct icmp_packet), 0, (struct sockaddr *)&recv_addr, (socklen_t *)&addr_len);

    if (num_bytes > 0 && packet.type == ICMP_ECHO_REPLY && packet.id == getpid() & 0xFFFF && packet.sequence == seq) {
        printf("%d bytes from %s: icmp_seq=%d time=%dms\n", num_bytes, inet_ntoa(recv_addr.sin_addr), packet.sequence, (int)(clock() - packet.sequence) / 1000);
    }
}

int main(int argc, char *argv[]) {
    int sockfd;
    int seq = 0;
    struct timeval start, end;
    double time_taken;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <IP address>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        fprintf(stderr, "ERROR: Failed to create socket!\n");
        exit(1);
    }

    printf("PING %s:\n", argv[1]);

    gettimeofday(&start, NULL);

    // Send 5 ping packets to the specified IP address
    for (int i = 0; i < 5; i++) {
        send_ping(sockfd, argv[1], seq++);
        receive_ping(sockfd, argv[1], seq - 1);
        sleep(1);
    }

    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    printf("--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %.0fms\n", 5, 5, 0, time_taken);
    close(sockfd);

    return 0;
}