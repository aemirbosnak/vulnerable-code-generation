//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_HOSTS 10
#define TIMEOUT 5

struct host_info {
    char *hostname;
    struct sockaddr_in addr;
};

int ping(struct host_info *host) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7);
    inet_pton(AF_INET, host->hostname, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        if (errno == ECONNREFUSED) {
            printf("%s is down\n", host->hostname);
        } else {
            perror("connect");
        }
        close(sock);
        return -1;
    }

    close(sock);
    printf("%s is up\n", host->hostname);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }

    struct host_info hosts[MAX_HOSTS];
    int num_hosts = 0;

    hosts[num_hosts].hostname = argv[1];
    hosts[num_hosts].addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &hosts[num_hosts].addr.sin_addr);
    num_hosts++;

    for (int i = 2; i < argc; i++) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Maximum number of hosts reached\n");
            break;
        }

        hosts[num_hosts].hostname = argv[i];
        hosts[num_hosts].addr.sin_family = AF_INET;
        inet_pton(AF_INET, argv[i], &hosts[num_hosts].addr.sin_addr);
        num_hosts++;
    }

    for (int i = 0; i < num_hosts; i++) {
        ping(&hosts[i]);
    }

    return 0;
}