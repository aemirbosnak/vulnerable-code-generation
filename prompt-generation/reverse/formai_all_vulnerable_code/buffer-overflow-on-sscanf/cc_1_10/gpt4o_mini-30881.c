//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define SLEEP_TIME 1

void get_cpu_usage(double *idle, double *total) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    double user, nice, system, idle_time, iowait, irq, softirq, steal, guest, guest_nice;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "cpu %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
               &user, &nice, &system, &idle_time, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        
        *idle = idle_time + iowait;
        *total = user + nice + system + *idle + irq + softirq + steal + guest + guest_nice;
    }

    fclose(file);
}

void print_cpu_usage(double prev_idle, double prev_total, double curr_idle, double curr_total) {
    double idle_delta = curr_idle - prev_idle;
    double total_delta = curr_total - prev_total;

    if (total_delta == 0) {
        return; // To avoid division by zero
    }

    double cpu_usage = 100.0 * (1.0 - (idle_delta / total_delta));

    printf("\n🎉 CPU Usage: %.2f%% 🎉\n", cpu_usage);
}

int main() {
    double prev_idle = 0.0, prev_total = 0.0;
    double curr_idle = 0.0, curr_total = 0.0;

    printf("☀️ Welcome to the Happy CPU Usage Monitor! ☀️\n");
    printf("🚀 Let's see how your CPU is doing! 🚀\n");

    while (1) {
        get_cpu_usage(&curr_idle, &curr_total);

        if (prev_total != 0.0) {
            print_cpu_usage(prev_idle, prev_total, curr_idle, curr_total);
        }

        prev_idle = curr_idle;
        prev_total = curr_total;

        printf("😊 Checking again in %d seconds... 😊\n", SLEEP_TIME);
        sleep(SLEEP_TIME);
    }

    return 0;
}