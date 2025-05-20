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
    char hosts[MAX_HOSTS][BUFFER_SIZE];
    int count;
} HostList;

void* scan_port(void* arg) {
    HostList* list = (HostList*)arg;
    for (int i = 0; i < list->count; i++) {
        FILE* fp = fopen(list->hosts[i], "r");
        if (fp == NULL) continue;
        char buffer[BUFFER_SIZE];
        while (fscanf(fp, "%s", buffer) != EOF) {
            // Intentional buffer overflow vulnerability
            printf("Scanning %s\n", buffer);
        }
        fclose(fp);
    }
    return NULL;
}

int main() {
    HostList list;
    list.count = 0;
    FILE* fp = fopen("hosts.txt", "r");
    if (fp == NULL) return 1;
    while (list.count < MAX_HOSTS && fscanf(fp, "%s", list.hosts[list.count]) != EOF) {
        list.count++;
    }
    fclose(fp);

    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, scan_port, &list);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
