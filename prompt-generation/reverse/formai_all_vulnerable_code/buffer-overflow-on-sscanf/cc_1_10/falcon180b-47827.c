//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 100
#define MAX_THREADS 10

struct host_info {
    char *hostname;
    int port;
};

void *scan_port(void *arg) {
    struct host_info *host_info = (struct host_info *) arg;
    int sock;
    char buffer[1024];
    int bytes_received;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(host_info->port);
    inet_pton(AF_INET, host_info->hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Host %s:%d is down\n", host_info->hostname, host_info->port);
        close(sock);
        return NULL;
    }

    printf("Host %s:%d is up\n", host_info->hostname, host_info->port);
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port_range>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *port_range = argv[2];

    int min_port, max_port;
    sscanf(port_range, "%d-%d", &min_port, &max_port);

    if (min_port > max_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    int num_hosts = 1;
    struct host_info *hosts = malloc(sizeof(struct host_info));
    hosts[0].hostname = strdup(hostname);
    hosts[0].port = min_port;

    pthread_t threads[MAX_THREADS];
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        if (i < num_hosts) {
            pthread_create(&threads[i], NULL, scan_port, &hosts[i]);
        } else {
            break;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(hosts);
    return 0;
}