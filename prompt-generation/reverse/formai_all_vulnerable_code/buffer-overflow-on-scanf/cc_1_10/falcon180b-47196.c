//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct network_info {
    char name[20];
    char ip[16];
    int signal_strength;
};

void *scan_thread(void *arg) {
    struct network_info *info = (struct network_info *) arg;
    FILE *fp;
    char cmd[50];

    sprintf(cmd, "iwlist %s scan", info->name);

    fp = popen(cmd, "r");

    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        return NULL;
    }

    while (fgets(info->ip, sizeof(info->ip), fp)!= NULL) {
        if (strstr(info->ip, "ESSID")) {
            sscanf(info->ip, "ESSID:\"%[^\"]\"", info->name);
        } else if (strstr(info->ip, "Quality")) {
            sscanf(info->ip, "Quality=%d/100", &info->signal_strength);
        }
    }

    pclose(fp);

    return NULL;
}

int main() {
    int i, num_threads;
    pthread_t threads[MAX_THREADS];
    struct network_info networks[MAX_THREADS];

    printf("Enter the number of wireless networks to scan: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter the name of wireless network %d: ", i + 1);
        scanf("%s", networks[i].name);

        pthread_create(&threads[i], NULL, scan_thread, &networks[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}