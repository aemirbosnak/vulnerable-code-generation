//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define MAX_HOSTS 100
#define TIMEOUT 5

typedef struct {
    char *hostname;
    struct in_addr ip;
} host_t;

void print_hosts(host_t *hosts, int count) {
    printf("Hosts:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", hosts[i].hostname, inet_ntoa(hosts[i].ip));
    }
}

void scan_ports(host_t *hosts, int count) {
    int sock;
    struct sockaddr_in addr;
    int opt = 1;
    char buffer[1024];

    for (int i = 0; i < count; i++) {
        printf("Scanning %s...\n", hosts[i].hostname);

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket");
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(22);
        addr.sin_addr.s_addr = hosts[i].ip.s_addr;

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            printf("Port 22 is closed.\n");
        } else {
            printf("Port 22 is open.\n");
        }

        close(sock);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s domain\n", argv[0]);
        return 1;
    }

    char *domain = argv[1];
    int count = 0;
    host_t hosts[MAX_HOSTS];

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(domain, NULL, &hints, &res)!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    for (struct addrinfo *ai = res; ai!= NULL; ai = ai->ai_next) {
        if (count >= MAX_HOSTS) {
            printf("Too many hosts.\n");
            break;
        }

        hosts[count].hostname = strdup(domain);
        hosts[count].ip = ((struct sockaddr_in *)ai->ai_addr)->sin_addr;
        count++;
    }

    freeaddrinfo(res);

    printf("Scanning %d hosts...\n", count);
    scan_ports(hosts, count);

    return 0;
}