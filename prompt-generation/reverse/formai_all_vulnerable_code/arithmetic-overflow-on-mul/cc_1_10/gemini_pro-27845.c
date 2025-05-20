//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define ICMP_HDR_SIZE sizeof(struct icmphdr)
#define ICMP6_HDR_SIZE sizeof(struct icmp6_hdr)
#define IP6_HDR_SIZE sizeof(struct ip6_hdr)
#define PAYLOAD_SIZE  16

struct results {
    unsigned int sent;
    unsigned int lost;
    unsigned int min_rtt;
    unsigned int max_rtt;
    unsigned int total_rtt;
};

static struct results r = {0};
static int sock;
static char buffer[ICMP6_HDR_SIZE + IP6_HDR_SIZE + PAYLOAD_SIZE];
static const char *payload = "abcdefghijklmnop"; // just for testing

static int make_sock(int af)
{
    int s = socket(af, SOCK_RAW, IPPROTO_ICMP);
    int on = 1;

    if (s < 0)
        return s;

    setsockopt(s, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
    return s;
}

static struct sockaddr_in6 *make_addr(const char *addr)
{
    struct sockaddr_in6 *sin6;
    int err;

    sin6 = calloc(1, sizeof(*sin6));
    if (!sin6)
        return NULL;

    sin6->sin6_family = AF_INET6;
    err = inet_pton(AF_INET6, addr, &sin6->sin6_addr);
    if (err <= 0) {
        free(sin6);
        return NULL;
    }
    return sin6;
}

static int send_packet(const struct sockaddr_in6 *dst, int size)
{
    struct iovec iov;
    struct msghdr msg;
    int n;

    memset(&iov, 0, sizeof(iov));
    iov.iov_base = buffer;
    iov.iov_len = size;

    memset(&msg, 0, sizeof(msg));
    msg.msg_name = dst;
    msg.msg_namelen = sizeof(*dst);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    n = sendmsg(sock, &msg, 0);
    if (n < 0) {
        perror("sendmsg");
        return -1;
    }
    return n;
}

static int get_packet(const struct sockaddr_in6 *dst)
{
    struct iovec iov;
    struct msghdr msg;
    struct timeval now;
    int n;

    while (1) {
        memset(&iov, 0, sizeof(iov));
        iov.iov_base = buffer;
        iov.iov_len = sizeof(buffer);

        memset(&msg, 0, sizeof(msg));
        msg.msg_name = dst;
        msg.msg_namelen = sizeof(*dst);
        msg.msg_iov = &iov;
        msg.msg_iovlen = 1;

        n = recvmsg(sock, &msg, 0);
        if (n < 0) {
            perror("recvmsg");
            return -1;
        }

        gettimeofday(&now, NULL);
        return (now.tv_sec * 1000000) + now.tv_usec;
    }
}

static int ping_host(const char *addr)
{
    struct sockaddr_in6 *dst;
    unsigned int i, t;

    dst = make_addr(addr);
    if (!dst)
        return -1;

    r.sent = 0;
    r.lost = 0;
    r.min_rtt = 0;
    r.max_rtt = 0;
    r.total_rtt = 0;

    memset(buffer, 0, sizeof(buffer));
    for (i = 0; i < PAYLOAD_SIZE; i++)
        memcpy(buffer + ICMP6_HDR_SIZE + IP6_HDR_SIZE + i, payload + i, 1);

    for (i = 0; i < 10; i++) {
        r.sent++;

        if (send_packet(dst, IP6_HDR_SIZE + ICMP6_HDR_SIZE + PAYLOAD_SIZE) < 0)
            r.lost++;
        else {
            t = get_packet(dst);
            if (t < 0)
                r.lost++;
            else if (!r.sent)
                r.min_rtt = r.max_rtt = t - (1399999 - r.sent);
            else {
                if (t - (1399999 - r.sent) < r.min_rtt)
                    r.min_rtt = t - (1399999 - r.sent);
                if (t - (1399999 - r.sent) > r.max_rtt)
                    r.max_rtt = t - (1399999 - r.sent);
                r.total_rtt += t - (1399999 - r.sent);
            }
        }

        usleep(100000);
    }

    free(dst);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <ip-addr>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sock = make_sock(AF_INET6);
    if (sock < 0) {
        perror("make_sock");
        return EXIT_FAILURE;
    }

    if (ping_host(argv[1]) < 0) {
        perror("ping_host");
        return EXIT_FAILURE;
    }

    printf("sent: %u\n", r.sent);
    printf("lost: %u\n", r.lost);
    printf("min_rtt: %u\n", r.min_rtt);
    printf("max_rtt: %u\n", r.max_rtt);
    printf("avg_rtt: %u\n", r.total_rtt / (r.sent - r.lost));

    close(sock);
    return EXIT_SUCCESS;
}