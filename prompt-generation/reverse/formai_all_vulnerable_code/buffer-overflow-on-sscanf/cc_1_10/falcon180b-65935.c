//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define INTERVAL 5 // seconds

struct cpu_usage {
    float user;
    float system;
    float idle;
};

// Function to get CPU usage
void get_cpu_usage(struct cpu_usage *usage) {
    FILE *fp;
    char line[1024];
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Cannot open /proc/stat\n");
        exit(1);
    }
    fgets(line, sizeof(line), fp);
    fclose(fp);

    sscanf(line, "cpu %f %f %f", &usage->user, &usage->system, &usage->idle);
}

// Function to print CPU usage
void print_cpu_usage(struct cpu_usage usage) {
    printf("CPU Usage:\n");
    printf("User: %.2f%%\n", usage.user);
    printf("System: %.2f%%\n", usage.system);
    printf("Idle: %.2f%%\n", usage.idle);
}

// Function to run in a separate thread
void *monitor_cpu_usage(void *arg) {
    struct cpu_usage usage;
    while (1) {
        get_cpu_usage(&usage);
        print_cpu_usage(usage);
        sleep(INTERVAL);
    }
    return NULL;
}

// Main function
int main() {
    pthread_t thread_id;
    int ret;

    ret = pthread_create(&thread_id, NULL, monitor_cpu_usage, NULL);
    if (ret!= 0) {
        printf("Error: Unable to create thread, %d\n", ret);
        exit(1);
    }

    printf("Press Ctrl+C to exit...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}