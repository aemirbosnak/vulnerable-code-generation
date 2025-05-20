//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct host_info {
    char *hostname;
    int port;
};

int is_valid_port(int port) {
    if (port <= 0 || port > 65535) {
        return 0;
    }
    return 1;
}

void *scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(host->port);
    if (inet_pton(AF_INET, host->hostname, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(sock);
        return NULL;
    }
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Port %d is closed\n", host->port);
        close(sock);
        return NULL;
    } else {
        printf("Port %d is open\n", host->port);
        close(sock);
        return NULL;
    }
}

int main() {
    int num_threads = 0;
    struct host_info *hosts = NULL;
    char input_buffer[BUFFER_SIZE];
    while (fgets(input_buffer, BUFFER_SIZE, stdin)!= NULL) {
        char *token = strtok(input_buffer, ":");
        if (token == NULL) {
            continue;
        }
        char *hostname = token;
        token = strtok(NULL, ":");
        if (token == NULL) {
            printf("Invalid input: %s\n", input_buffer);
            continue;
        }
        int port = atoi(token);
        if (!is_valid_port(port)) {
            printf("Invalid port: %d\n", port);
            continue;
        }
        struct host_info *new_host = (struct host_info *) malloc(sizeof(struct host_info));
        if (new_host == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        new_host->hostname = strdup(hostname);
        new_host->port = port;
        hosts = realloc(hosts, sizeof(struct host_info) * ++num_threads);
        hosts[num_threads - 1] = *new_host;
        free(new_host);
    }
    pthread_t threads[MAX_THREADS];
    int rc;
    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, hosts + i);
        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            exit(1);
        }
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}