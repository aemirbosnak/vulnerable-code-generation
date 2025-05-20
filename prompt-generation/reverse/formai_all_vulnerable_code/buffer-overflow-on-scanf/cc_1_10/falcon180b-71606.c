//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTS 1000
#define MAX_THREADS 10

typedef struct {
    char ip[16];
    int port;
} host_t;

void *scan_host(void *arg) {
    host_t *host = (host_t *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Failed to create socket for %s:%d - %s\n", host->ip, host->port, strerror(errno));
        return NULL;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(host->port);
    inet_pton(AF_INET, host->ip, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        close(sock);
        printf("Connection failed for %s:%d\n", host->ip, host->port);
        return NULL;
    }

    close(sock);
    printf("Connection successful for %s:%d\n", host->ip, host->port);
    return NULL;
}

int main() {
    int num_hosts = 0;
    host_t hosts[MAX_HOSTS];

    printf("Enter the number of hosts to scan (max %d): ", MAX_HOSTS);
    scanf("%d", &num_hosts);

    printf("Enter the hosts (IP:port):\n");
    for (int i = 0; i < num_hosts; i++) {
        scanf("%s:%d", hosts[i].ip, &hosts[i].port);
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int i = 0; i < num_hosts; i++) {
        if (thread_count >= MAX_THREADS) {
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;
        }

        pthread_create(&threads[thread_count], NULL, scan_host, &hosts[i]);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}