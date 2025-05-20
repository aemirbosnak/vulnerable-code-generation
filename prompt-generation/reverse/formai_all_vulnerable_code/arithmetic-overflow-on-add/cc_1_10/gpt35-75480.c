//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define ICMP_HEADER_SIZE 8
#define IP_HEADER_SIZE 20
#define BUFFER_MAX_SIZE 1024
#define MAX_TRIES 4
#define PORT_NUM 0
#define TIME_OUT 1

typedef struct _IcmpPacket {
    u_int8_t type;
    u_int8_t code;
    u_int16_t checksum;
    u_int16_t id;
    u_int16_t sequenceNumber;
    struct timeval timeStamp;
} IcmpPacket;

int sendIcmpEchoRequest(int sockfd, const struct sockaddr_in* destAddr, int sequenceNumber)
{
    IcmpPacket packet;
    packet.type = ICMP_ECHO_REQUEST;
    packet.code = 0;
    packet.checksum = 0;
    packet.id = getpid() & 0xFFFF;
    packet.sequenceNumber = sequenceNumber & 0xFFFF;
    gettimeofday(&packet.timeStamp, NULL);

    int packetSize = ICMP_HEADER_SIZE;
    if (sendto(sockfd, &packet, packetSize, 0, (struct sockaddr*)destAddr, sizeof(*destAddr)) == -1) {
        fprintf(stderr, "Error encountered while sending ICMP packet.\n");
        return -1;
    }
    return 0;
}

int receiveIcmpEchoReply(int sockfd, const struct sockaddr_in* expectedAddr, int sequenceNumber, struct timeval* nowPtr)
{
    char buffer[BUFFER_MAX_SIZE];
    socklen_t addrLen = sizeof(struct sockaddr_in);
    struct sockaddr_in senderAddr;
    bzero(&senderAddr, sizeof(senderAddr));
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&senderAddr, &addrLen) < 1) {
        fprintf(stderr, "Error while receiving ICMP packet.\n");
        return -1;
    }

    // Verify that packet is ICMP_ECHO_REPLY
    IcmpPacket* repPacket = (IcmpPacket*)buffer;
    if (repPacket->type != ICMP_ECHO_REPLY || repPacket->id != (getpid() & 0xFFFF) || repPacket->sequenceNumber != (sequenceNumber & 0xFFFF)) {
        fprintf(stderr, "Received packet is an erroneous ICMP packet.\n");
        return -1;
    }

    // Check that sender address is what was expected
    if (memcmp(&senderAddr.sin_addr, &expectedAddr->sin_addr, sizeof(struct in_addr)) != 0) {
        fprintf(stderr, "Sender address does not match expected address.\n");
        return -1;
    }

    // Calculate round-trip time
    struct timeval timeStamp;
    gettimeofday(&timeStamp, NULL);
    long elapsedTimeUsec = (timeStamp.tv_sec - repPacket->timeStamp.tv_sec) * 1000000 + (timeStamp.tv_usec - repPacket->timeStamp.tv_usec);
    printf("%d Bytes from %s: icmp_seq=%d ttl=%d time=%ld ms\n",
           ICMP_HEADER_SIZE, inet_ntoa(senderAddr.sin_addr), sequenceNumber, repPacket->code, elapsedTimeUsec / 1000);
    nowPtr->tv_sec = timeStamp.tv_sec;
    nowPtr->tv_usec = timeStamp.tv_usec;

    return 0;
}

unsigned short calculateIcmpChecksum(const void* buffer, int size)
{
    unsigned long sum = 0;
    const unsigned short* ptr = buffer;
    while (size > 1) {
        sum += *ptr++;
        size -= 2;
    }
    if (size == 1) {
        sum += *(unsigned char*)ptr;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum = sum + (sum >> 16);
    return ~sum;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s dstAddr\n", argv[0]);
        return -1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        fprintf(stderr, "Error encountered while creating socket.\n");
        return -1;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIME_OUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        fprintf(stderr, "Error encountered while setting socket timeout.\n");
        return -1;
    }

    // Configure destination address
    struct sockaddr_in destAddr;
    bzero(&destAddr, sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &destAddr.sin_addr) == 0) {
        fprintf(stderr, "Invalid destination IP address.\n");
        return -1;
    }

    // Perform ping test
    for (int i = 0; i < MAX_TRIES; i++) {
        struct timeval now;
        if (sendIcmpEchoRequest(sockfd, &destAddr, i + 1) == -1)
            continue;
        if (receiveIcmpEchoReply(sockfd, &destAddr, i + 1, &now) == -1)
            continue;
        sleep(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}