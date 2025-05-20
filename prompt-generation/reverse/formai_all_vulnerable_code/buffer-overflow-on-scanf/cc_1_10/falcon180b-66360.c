//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct host_info {
    char ip[16];
    char hostname[256];
    int port;
};

void *scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(host->port);
    inet_pton(AF_INET, host->ip, &server_addr.sin_addr);

    int result = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    if (result == -1) {
        printf("Port %d is closed\n", host->port);
    } else {
        printf("Port %d is open\n", host->port);
    }

    close(sock);
    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads to use (max %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    char ip[16];
    printf("Enter the IP address to scan: ");
    scanf("%s", ip);

    int start_port, end_port;
    printf("Enter the start and end port numbers (e.g. 80 90): ");
    scanf("%d %d", &start_port, &end_port);

    pthread_t threads[MAX_THREADS];
    struct host_info hosts[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        hosts[i].port = start_port + i;
        sprintf(hosts[i].ip, "%s", ip);
        gethostname(hosts[i].hostname, sizeof(hosts[i].hostname));

        pthread_create(&threads[i], NULL, scan_port, &hosts[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}