//FormAI DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define PACKET_SIZE 64
#define MAX_TRIES 3

long long current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL);
}

int ping(const char* host) {
    struct hostent* hostinfo = gethostbyname(host);
    if (!hostinfo) {
        printf("Unknown host %s\n", host);
        return -1;
    }
    int fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (fd < 0) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr*) hostinfo->h_addr);

    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);
    packet[0] = 8;  // ICMP_ECHO
    packet[1] = 0;  // ICMP_ECHOREPLY
    packet[2] = 0;
    packet[3] = 0;
    packet[4] = 0;
    packet[5] = 0;
    packet[6] = 0;
    packet[7] = 0;
    packet[8] = 0;
    packet[9] = 0;
    packet[10] = 0;
    packet[11] = 0;
    packet[12] = 0;
    packet[13] = 0;
    packet[14] = 0;
    packet[15] = 0;
    long long send_time, recv_time;
    int tries = 0;
    do {
        send_time = current_time();
        if (sendto(fd, packet, PACKET_SIZE, 0, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
            printf("Error: %s\n", strerror(errno));
            return -1;
        }
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(fd, &fds);
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        if (select(fd+1, &fds, NULL, NULL, &tv) > 0) {
            char buf[PACKET_SIZE];
            memset(buf, 0, PACKET_SIZE);
            struct sockaddr_in from;
            socklen_t fromlen = sizeof(from);
            if (recvfrom(fd, buf, PACKET_SIZE, 0, (struct sockaddr*) &from, &fromlen) < 0) {
                printf("Error: %s\n", strerror(errno));
                return -1;
            }
            recv_time = current_time();
            long long elapsed = recv_time - send_time;
            printf("Response from %s: time=%lldms\n", host, elapsed);
            return elapsed;
        } else {
            printf("Request timed out for %s\n", host);
            tries++;
        }
    } while (tries < MAX_TRIES);
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return -1;
    }
    int elapsed = ping(argv[1]);
    if (elapsed >= 0 && elapsed <= 100) {
        printf("Yay! %s is super quick!\n", argv[1]);
    } else if (elapsed > 100 && elapsed <= 200) {
        printf("Great news, %s is responding in a snap!\n", argv[1]);
    } else if (elapsed > 200 && elapsed <= 500) {
        printf("Not bad, %s is fairly quick.\n", argv[1]);
    } else if (elapsed > 500 && elapsed <= 1000) {
        printf("Uh oh, %s seems a bit slow...\n", argv[1]);
    } else if (elapsed > 1000) {
        printf("Oh no, %s is taking forever to respond!\n", argv[1]);
    } else {
        printf("Unknown response time for %s\n", argv[1]);
    }
    return 0;
}