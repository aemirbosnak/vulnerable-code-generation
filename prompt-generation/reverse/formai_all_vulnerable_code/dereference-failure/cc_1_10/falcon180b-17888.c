//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

struct port_info {
    int port;
    char *ip;
};

void *scan_ports(void *arg) {
    struct port_info *info = (struct port_info*) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;

    if(sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(info->port);
    if(inet_pton(AF_INET, info->ip, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    int res = connect(sock, (struct sockaddr*) &addr, sizeof(addr));
    if(res == -1) {
        if(errno == ECONNREFUSED) {
            printf("Port %d on %s is closed\n", info->port, info->ip);
        } else if(errno == ETIMEDOUT) {
            printf("Port %d on %s is filtered\n", info->port, info->ip);
        } else {
            perror("connect");
        }
        close(sock);
        return NULL;
    }

    close(sock);
    printf("Port %d on %s is open\n", info->port, info->ip);
    return NULL;
}

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    while(num_threads < MAX_THREADS && port <= MAX_PORTS) {
        struct port_info info;
        info.port = port;
        info.ip = ip;
        pthread_create(&threads[num_threads], NULL, scan_ports, &info);
        num_threads++;
        port++;
    }

    for(int i=0; i<num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}