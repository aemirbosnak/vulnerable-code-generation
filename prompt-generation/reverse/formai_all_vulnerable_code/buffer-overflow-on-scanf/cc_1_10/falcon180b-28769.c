//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_HOSTS 100
#define BUFFER_SIZE 1024

struct host_info {
    char *hostname;
    int port;
};

void *ping_host(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sockfd, ret;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host->hostname, &server_addr.sin_addr);
    server_addr.sin_port = htons(host->port);

    ret = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to %s:%d: %s\n", host->hostname, host->port, strerror(errno));
        close(sockfd);
        return NULL;
    }

    send(sockfd, "PING", strlen("PING"), 0);
    ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (ret <= 0) {
        printf("Error receiving response from %s:%d\n", host->hostname, host->port);
        close(sockfd);
        return NULL;
    }

    printf("Response from %s:%d: %s\n", host->hostname, host->port, buffer);
    close(sockfd);

    return NULL;
}

int main() {
    int num_hosts, num_threads;
    struct host_info hosts[MAX_HOSTS];
    pthread_t threads[MAX_THREADS];

    printf("Enter number of hosts to ping: ");
    scanf("%d", &num_hosts);

    for (int i = 0; i < num_hosts; i++) {
        printf("Enter hostname and port (e.g. google.com:80): ");
        char input[BUFFER_SIZE];
        scanf("%s", input);
        char *token = strtok(input, ":");
        hosts[i].hostname = token;
        hosts[i].port = atoi(strtok(NULL, ":"));
    }

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_hosts; i++) {
        pthread_create(&threads[i], NULL, ping_host, &hosts[i]);
    }

    for (int i = 0; i < num_hosts; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}