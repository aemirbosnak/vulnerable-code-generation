//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX_HOSTS 100
#define MAX_THREADS 10

struct host_info {
    char name[20];
    int port;
    struct in_addr ip;
};

int host_count = 0;
struct host_info hosts[MAX_HOSTS];
pthread_t threads[MAX_THREADS];

void *scan_host(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in dest;

    strcpy(dest.sin_zero, "");
    dest.sin_family = AF_INET;
    dest.sin_port = htons((unsigned short) *(int *) arg);
    dest.sin_addr.s_addr = inet_addr((char *) ((struct host_info *) arg)->name);

    if (connect(sock, (struct sockaddr *) &dest, sizeof(dest)) == 0) {
        ((struct host_info *) arg)->port = ntohs(dest.sin_port);
        inet_ntop(AF_INET, &dest.sin_addr, &((struct host_info *) arg)->ip, sizeof(((struct host_info *) arg)->ip));
    } else {
        ((struct host_info *) arg)->port = 0;
    }

    close(sock);
    return NULL;
}

int main() {
    FILE *fp;
    char line[100];

    fp = fopen("hosts.txt", "r");

    while (fscanf(fp, "%s", line)!= EOF) {
        if (host_count >= MAX_HOSTS) {
            printf("Maximum hosts reached\n");
            break;
        }

        strcpy(hosts[host_count].name, line);
        hosts[host_count++].port = 0;
    }

    fclose(fp);

    for (int i = 0; i < host_count; i++) {
        pthread_create(&threads[i], NULL, scan_host, &hosts[i]);
    }

    for (int i = 0; i < host_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Host\tIP\tPort\n");

    for (int i = 0; i < host_count; i++) {
        printf("%s\t", hosts[i].name);
        inet_ntop(AF_INET, &hosts[i].ip, line, sizeof(line));
        printf("%s\t%d\n", line, hosts[i].port);
    }

    return 0;
}