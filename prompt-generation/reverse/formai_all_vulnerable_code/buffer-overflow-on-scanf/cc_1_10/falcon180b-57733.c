//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_LEN 100
#define NUM_THREADS 4

struct thread_data {
    int thread_id;
    char iface[MAX_LEN];
};

void *thread_func(void *arg) {
    struct thread_data *data = arg;
    char cmd[MAX_LEN];
    FILE *fp;
    char line[MAX_LEN];
    int i;

    sprintf(cmd, "iw dev %s info | grep signal", data->iface);
    fp = popen(cmd, "r");

    if (fp == NULL) {
        printf("Error: Failed to execute command\n");
        return NULL;
    }

    while (fgets(line, MAX_LEN, fp)!= NULL) {
        if (strstr(line, "signal")!= NULL) {
            sscanf(line, "signal: %d", &i);
            printf("Thread %d: Signal strength: %d\n", data->thread_id, i);
        }
    }

    pclose(fp);
    return NULL;
}

int main() {
    char iface[MAX_LEN];
    pthread_t threads[NUM_THREADS];
    struct thread_data data[NUM_THREADS];
    int i;

    printf("Enter interface name: ");
    scanf("%s", iface);

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i;
        strcpy(data[i].iface, iface);
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}