//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <time.h>

#define DELAY 1
#define CPU_COUNT 4
#define HISTORY_COUNT 10

typedef struct {
    float usage;
    time_t timestamp;
} CPUSnapshot;

void displayUsage(CPUSnapshot history[], int count) {
    printf("\nCPU Usage History (last %d records):\n", count);
    printf("Time\t\tUsage(%%)\n");
    for (int i = 0; i < count; i++) {
        if (history[i].timestamp != 0) {
            char buffer[30];
            strftime(buffer, 30, "%H:%M:%S", localtime(&history[i].timestamp));
            printf("%s\t%.2f\n", buffer, history[i].usage);
        }
    }
}

float readCPUUsage() {
    FILE *file;
    unsigned long idle_time, total_time;
    static unsigned long prev_idle = 0;
    static unsigned long prev_total = 0;
    unsigned long curr_idle, curr_total;

    file = fopen("/proc/stat", "r");
    if (!file) {
        fprintf(stderr, "Could not open /proc/stat\n");
        exit(1);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer) - 1, file);
    fclose(file);

    sscanf(buffer, "cpu %*s %*s %*s %lu %lu", &idle_time, &total_time);
    curr_idle = idle_time;
    curr_total = idle_time + total_time;

    float cpu_usage = 100.0 * (1.0 - (float)(curr_idle - prev_idle) / (curr_total - prev_total));

    prev_idle = curr_idle;
    prev_total = curr_total;

    return cpu_usage;
}

int main() {
    CPUSnapshot history[HISTORY_COUNT] = {0};
    int index = 0;
    
    printf("=== CPU Usage Monitor ===\n");
    printf("Press Ctrl+C to stop.\n");

    while (1) {
        float usage = readCPUUsage();
        time_t now = time(NULL);

        history[index].usage = usage;
        history[index].timestamp = now;
        index = (index + 1) % HISTORY_COUNT;

        displayUsage(history, HISTORY_COUNT);
        sleep(DELAY);
    }

    return 0;
}