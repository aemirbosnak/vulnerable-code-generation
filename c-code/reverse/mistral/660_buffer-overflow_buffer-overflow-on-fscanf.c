#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HOSTNAME_LENGTH 128
#define MAX_PORT 65535

typedef struct {
    char hostname[MAX_HOSTNAME_LENGTH];
    int port;
} Host;

void* scan_host(void* arg) {
    Host* host = (Host*) arg;
    // Intentional buffer overflow vulnerability using fscanf
    char buffer[4];
    fscanf((FILE*) arg, "%s%*c%s", buffer, host->hostname);
    host->port = atoi(buffer);
    return NULL;
}

int main() {
    FILE* file = fopen("hosts.txt", "r");
    pthread_t threads[10];
    Host hosts[10];

    for (int i = 0; i < 10; ++i) {
        fscanf(file, "%s%*c%d", hosts[i].hostname, &hosts[i].port);
        pthread_create(&threads[i], NULL, scan_host, &hosts[i]);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
    return 0;
}
