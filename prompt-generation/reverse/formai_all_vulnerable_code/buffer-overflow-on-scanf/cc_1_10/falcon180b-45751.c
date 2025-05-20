//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_HOSTS 10
#define MAX_THREADS 10
#define TIMEOUT 3

struct host {
    char *ip;
    char *name;
    int port;
};

void *ping_host(void *arg) {
    struct host *host = (struct host *) arg;
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(host->port);
    inet_pton(AF_INET, host->ip, &servaddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (ret == -1) {
        printf("%s is not reachable\n", host->name);
        close(sockfd);
        return NULL;
    }

    send(sockfd, "PING", strlen("PING"), 0);
    ret = recv(sockfd, buffer, sizeof(buffer), 0);
    if (ret <= 0) {
        printf("%s did not respond to PING\n", host->name);
        close(sockfd);
        return NULL;
    }

    printf("%s is alive\n", host->name);
    close(sockfd);
    return NULL;
}

int main() {
    int i, ret;
    pthread_t threads[MAX_THREADS];
    struct host hosts[MAX_HOSTS];

    printf("Enter number of hosts to ping: ");
    scanf("%d", &i);

    for (int j = 0; j < i; j++) {
        printf("Enter IP address of host %d: ", j + 1);
        scanf("%s", hosts[j].ip);

        printf("Enter name of host %d: ", j + 1);
        scanf("%s", hosts[j].name);

        printf("Enter port number of host %d: ", j + 1);
        scanf("%d", &hosts[j].port);
    }

    for (int j = 0; j < i; j++) {
        ret = pthread_create(&threads[j], NULL, ping_host, &hosts[j]);
        if (ret!= 0) {
            printf("Error creating thread for host %s\n", hosts[j].name);
            exit(1);
        }
    }

    for (int j = 0; j < i; j++) {
        ret = pthread_join(threads[j], NULL);
        if (ret!= 0) {
            printf("Error joining thread for host %s\n", hosts[j].name);
            exit(1);
        }
    }

    return 0;
}