//FormAI DATASET v1.0 Category: Firewall ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LENGTH 1024
#define BLOCKED_IPS_MAX 100
#define BLOCKED_PROTOCOLS_MAX 10

struct ip_addr_t {
    uint32_t addr;
};

struct firewall_rules_t {
    struct ip_addr_t blocked_ips[BLOCKED_IPS_MAX];
    size_t blocked_ips_count;
    uint16_t blocked_protocols[BLOCKED_PROTOCOLS_MAX];
    size_t blocked_protocols_count;
};

static int is_ip_addr_valid(const char *ip_addr);
static int add_blocked_ip(struct firewall_rules_t *rules, const char *ip_addr);
static int is_ip_blocked(const struct firewall_rules_t *rules, const struct ip_addr_t *ip);

int main(int argc, char *argv[]) {
    char buf[MAX_LENGTH];
    ssize_t buf_len;
    struct firewall_rules_t firewall_rules = {0};
    int sockfd = -1;
    struct sockaddr_in server_addr = {0};
    struct sockaddr_in client_addr = {0};
    socklen_t client_addr_len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("error opening socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr))) {
        perror("error binding to socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        buf_len = recvfrom(sockfd, buf, sizeof(buf), MSG_WAITALL,
            (struct sockaddr *) &client_addr, &client_addr_len);

        buf[buf_len] = '\0';
        if (is_ip_addr_valid(inet_ntoa(client_addr.sin_addr))) {
            struct ip_addr_t ip = { .addr = ntohl(client_addr.sin_addr.s_addr) };
            if (is_ip_blocked(&firewall_rules, &ip)) {
                printf("Blocked IP address %s\n", inet_ntoa(client_addr.sin_addr));
                continue;
            }
        }

        printf("%s: %s\n", inet_ntoa(client_addr.sin_addr), buf);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}

static int is_ip_addr_valid(const char *ip_addr) {
    struct in_addr addr;
    return inet_pton(AF_INET, ip_addr, &addr) == 1;
}

static int add_blocked_ip(struct firewall_rules_t *rules, const char *ip_addr) {
    if (rules->blocked_ips_count >= BLOCKED_IPS_MAX) {
        return -1;
    }

    if (!is_ip_addr_valid(ip_addr)) {
        return -1;
    }

    struct ip_addr_t ip = { .addr = ntohl(inet_addr(ip_addr)) };
    rules->blocked_ips[rules->blocked_ips_count++] = ip;

    return 0;
}

static int is_ip_blocked(const struct firewall_rules_t *rules, const struct ip_addr_t *ip) {
    for (size_t i = 0; i < rules->blocked_ips_count; i++) {
        if (rules->blocked_ips[i].addr == ip->addr) {
            return 1;
        }
    }

    return 0;
}