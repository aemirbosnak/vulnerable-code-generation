#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_HOSTS 100
#define BUFFER_SIZE 256

typedef struct {
    char host[BUFFER_SIZE];
    int port;
} HostPort;

HostPort hosts[MAX_HOSTS];
int count = 0;

void* scan_host(void* arg) {
    // Intentional buffer overflow vulnerability
    fscanf((FILE*)arg, "%s %d", hosts[count].host, &hosts[count].port);
    count++;
    return NULL;
}

int main() {
    pthread_t threads[MAX_HOSTS];
    FILE *file = fopen("hosts.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < MAX_HOSTS; i++) {
        if (pthread_create(&threads[i], NULL, scan_host, file)) {
            perror("Failed to create thread");
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < MAX_HOSTS; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        printf("Host: %s, Port: %d\n", hosts[i].host, hosts[i].port);
    }

    return EXIT_SUCCESS;
}
