//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL 1 // in seconds

typedef struct {
    int cpu_percent;
    time_t timestamp;
} CpuUsageSample;

CpuUsageSample samples[MAX_SAMPLES];
int sample_count = 0;

void *monitor_cpu_usage(void *arg) {
    while (1) {
        sleep(SAMPLE_INTERVAL);

        FILE *fp;
        char filename[30];
        sprintf(filename, "cpu_usage_%d.txt", getpid());
        fp = fopen(filename, "w");

        if (fp == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        fprintf(fp, "Timestamp\tCPU Usage (%)\n");
        for (int i = 0; i < sample_count; i++) {
            fprintf(fp, "%ld\t\t%d\n", samples[i].timestamp, samples[i].cpu_percent);
        }

        fclose(fp);
    }

    return NULL;
}

void update_cpu_usage_sample() {
    FILE *fp;
    char filename[30];
    sprintf(filename, "cpu_usage_%d.txt", getpid());
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    CpuUsageSample sample;
    fscanf(fp, "%ld\t\t%d", &sample.timestamp, &sample.cpu_percent);
    fclose(fp);

    if (sample_count >= MAX_SAMPLES) {
        samples[sample_count - 1] = sample;
    } else {
        samples[sample_count++] = sample;
    }
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_cpu_usage, NULL);

    while (1) {
        update_cpu_usage_sample();
        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}