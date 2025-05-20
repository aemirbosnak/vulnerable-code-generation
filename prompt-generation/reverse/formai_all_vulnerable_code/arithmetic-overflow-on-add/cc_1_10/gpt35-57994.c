//FormAI DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_SIZE     64
#define TIMEOUT_SEC     1
#define MAX_ATTEMPTS    5

typedef struct Pinger {
    struct sockaddr_in server_addr;
    int sock;
    int ttl;
    int seqno;
    char packet[PACKET_SIZE];
    int max_attempts;
    int time;
    bool running;
} Pinger;

unsigned short calculate_checksum(void* buf, int len);
void create_packet(void* buf, int seqno);
bool receive_packet(int sock, struct sockaddr_in* server_addr, unsigned short send_seqno, int timeout);

unsigned short calculate_checksum(void* buf, int len) {
    unsigned short* ptr = (unsigned short*)buf;
    unsigned long sum = 0;

    for (int i = 0; i < len / 2; i++) {
        sum += ptr[i];
    }

    if (len % 2) {
        sum += (unsigned char) ((unsigned char*)buf)[len - 1];
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    return (unsigned short) ~sum;
}

void create_packet(void* buf, int seqno) {
    memset(buf, 0, PACKET_SIZE);

    struct timeval tv;
    gettimeofday(&tv, NULL);

    char* ptr = (char*)buf;
    ptr[0] = 8;         // Type
    ptr[1] = 0;         // Code
    *((unsigned short*) (ptr + 2)) = 0;      // Checksum (initially zero)
    *((unsigned short*) (ptr + 4)) = htons(seqno);
    *((unsigned long*) (ptr + 8)) = tv.tv_sec * 1000000 + tv.tv_usec;
    *((unsigned short*) (ptr + 16)) = calculate_checksum(buf, PACKET_SIZE);
}

bool receive_packet(int sock, struct sockaddr_in* server_addr, unsigned short send_seqno, int timeout) {
    char buf[PACKET_SIZE];
    socklen_t server_len = sizeof(*server_addr);

    struct timeval tv;
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    int n = select(sock + 1, &readfds, NULL, NULL, &tv);
    if (n > 0) {
        n = recvfrom(sock, buf, PACKET_SIZE, 0, (struct sockaddr*) server_addr, &server_len);
        if (n >= PACKET_SIZE) {
            unsigned short* ptr = (unsigned short*)buf;
            if (ptr[0] != 0) {
                return false;
            }
            if (ptr[5] != htons(send_seqno)) {
                return false;
            }

            unsigned long send_time = *((unsigned long*) (buf + 8));
            struct timeval tv;
            gettimeofday(&tv, NULL);
            unsigned long elapsed = (tv.tv_sec * 1000000 + tv.tv_usec) - send_time;
            printf("Reply from %s: bytes=%d time=%ldms\n", inet_ntoa(server_addr->sin_addr), n, elapsed / 1000);

            return true;
        }
    }

    printf("Request timed out\n");
    return false;
}

void ping(Pinger* pinger) {
    int seqno = 0;
    pinger->running = true;

    while (pinger->running) {
        pinger->seqno++;

        create_packet(pinger->packet, seqno);

        int ret = sendto(pinger->sock, pinger->packet, PACKET_SIZE, 0, (struct sockaddr*) &(pinger->server_addr), sizeof(pinger->server_addr));
        if (ret < 0) {
            printf("Error sending packet %d\n", seqno);
        } else {
            int attempts = 0;
            do {
                if (receive_packet(pinger->sock, &(pinger->server_addr), seqno, TIMEOUT_SEC)) {
                    pinger->time++;
                    break;
                }
                attempts++;
            } while (attempts < pinger->max_attempts);

            if (attempts == pinger->max_attempts) {
                printf("Ping request %d timed out\n", seqno);
            }
        }

        sleep(1);
    }

    close(pinger->sock);
}

Pinger* create_pinger(char* ip, int ttl, int max_attempts) {
    Pinger* pinger = (Pinger*) malloc(sizeof(Pinger));
    if (!pinger) {
        printf("Error: malloc() failed\n");
        exit(EXIT_FAILURE);
    }

    pinger->seqno = 0;
    pinger->sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    pinger->ttl = ttl;
    pinger->max_attempts = max_attempts;
    pinger->time = 0;
    pinger->running = false;

    if (setsockopt(pinger->sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        printf("Error: setsockopt() failed\n");
        exit(EXIT_FAILURE);
    }

    pinger->server_addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, ip, &(pinger->server_addr.sin_addr)) <= 0) {
        printf("Invalid address: %s\n", ip);
        exit(EXIT_FAILURE);
    }

    return pinger;
}

int main() {
    Pinger* pinger = create_pinger("8.8.8.8", 64, MAX_ATTEMPTS);

    ping(pinger);

    return 0;
}