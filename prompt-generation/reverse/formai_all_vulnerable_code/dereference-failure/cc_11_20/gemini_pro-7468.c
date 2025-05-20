//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_MAX_PACKET_SIZE 65535
#define PING_TIMEOUT_SEC 1
#define PING_TIMEOUT_USEC 0
#define PING_PACKET_SIZE 64
#define PING_NUM_PACKETS 4

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence;
    char data[PING_PACKET_SIZE - 8];
} IcmpPacket;

int main(int argc, char **argv) {
    // Check args
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set socket options
    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Resolve hostname
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Create ping packet
    IcmpPacket ping;
    ping.type = ICMP_ECHO_REQUEST;
    ping.code = 0;
    ping.checksum = 0;
    ping.identifier = getpid();
    ping.sequence = 1;
    for (int i = 0; i < PING_PACKET_SIZE - 8; i++) {
        ping.data[i] = 0;
    }

    // Send ping packet
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr *) host->h_addr;
    ssize_t sent = sendto(sockfd, &ping, sizeof(ping), 0, (struct sockaddr *) &addr, sizeof(addr));
    if (sent == -1) {
        perror("sendto");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive ping reply
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);
    struct timeval timeout = {PING_TIMEOUT_SEC, PING_TIMEOUT_USEC};
    int nfds = select(sockfd + 1, &fds, NULL, NULL, &timeout);
    if (nfds == -1) {
        perror("select");
        close(sockfd);
        return EXIT_FAILURE;
    } else if (nfds == 0) {
        fprintf(stderr, "Timeout\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    if (FD_ISSET(sockfd, &fds)) {
        IcmpPacket reply;
        ssize_t received = recvfrom(sockfd, &reply, sizeof(reply), 0, (struct sockaddr *) &from, &fromlen);
        if (received == -1) {
            perror("recvfrom");
            close(sockfd);
            return EXIT_FAILURE;
        } else if (reply.type == ICMP_ECHO_REPLY && reply.identifier == getpid() && reply.sequence == 1) {
            // Print ping reply
            printf("Reply from %s: time=%ldms\n", inet_ntoa(from.sin_addr), (clock() - reply.data[0]) / (CLOCKS_PER_SEC / 1000));
        } else {
            fprintf(stderr, "Received unexpected packet\n");
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}