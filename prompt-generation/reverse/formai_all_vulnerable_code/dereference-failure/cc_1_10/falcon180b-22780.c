//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_SAMPLES 100

// Struct to hold CPU usage data
typedef struct {
    int cpu_percent;
    int timestamp;
} cpu_usage_t;

// Function to get the current CPU usage
void get_cpu_usage(cpu_usage_t *usage) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    // Open /proc/stat file
    fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    // Read the first line (CPU statistics)
    if (fgets(line, sizeof(line), fp) == NULL) {
        printf("Error reading /proc/stat\n");
        exit(1);
    }

    // Parse the line to get the CPU usage
    token = strtok(line, " ");
    while (token!= NULL) {
        if (i == 2) {
            // Convert the CPU usage string to an integer
            usage->cpu_percent = atoi(token);
            break;
        }
        i++;
        token = strtok(NULL, " ");
    }

    // Get the current timestamp
    struct timeval tv;
    gettimeofday(&tv, NULL);
    usage->timestamp = tv.tv_sec;

    // Close the file
    fclose(fp);
}

// Function to print the CPU usage history
void print_cpu_usage_history(cpu_usage_t *history, int num_samples) {
    int i;

    for (i = 0; i < num_samples; i++) {
        printf("%d: %d%%\n", history[i].timestamp, history[i].cpu_percent);
    }
}

// Function to monitor CPU usage
void monitor_cpu_usage(int interval_ms, int num_samples) {
    cpu_usage_t history[MAX_SAMPLES];
    int i = 0;
    int num_samples_taken = 0;

    while (num_samples_taken < num_samples) {
        get_cpu_usage(&history[i]);
        i = (i + 1) % MAX_SAMPLES;
        num_samples_taken++;

        usleep(interval_ms * 1000);
    }

    print_cpu_usage_history(history, num_samples);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <interval_ms> <num_samples>\n", argv[0]);
        return 1;
    }

    int interval_ms = atoi(argv[1]);
    int num_samples = atoi(argv[2]);

    monitor_cpu_usage(interval_ms, num_samples);

    return 0;
}