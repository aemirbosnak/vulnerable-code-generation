//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_HOSTS 100
#define MAX_PORTS 100
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in addr;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int port;
    int status;
} host_t;

void *scan_hosts(void *arg) {
    host_t *hosts = (host_t *) arg;
    int i = 0;
    while (i < MAX_HOSTS) {
        hosts[i].addr.sin_family = AF_INET;
        hosts[i].addr.sin_port = htons(hosts[i].port);
        inet_pton(AF_INET, hosts[i].host, &hosts[i].addr.sin_addr);
        i++;
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <IP address/hostname> <start port> <end port>\n", argv[0]);
        exit(1);
    }

    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int num_hosts = end_port - start_port + 1;
    if (num_hosts > MAX_HOSTS) {
        printf("Error: Maximum number of hosts exceeded.\n");
        exit(1);
    }

    host_t hosts[num_hosts];
    for (int i = 0; i < num_hosts; i++) {
        hosts[i].port = start_port + i;
        strcpy(hosts[i].host, ip_addr);
    }

    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    for (int i = 0; i < num_hosts; i++) {
        pthread_create(&threads[num_threads], NULL, scan_hosts, &hosts[i]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scan completed.\n");
    return 0;
}