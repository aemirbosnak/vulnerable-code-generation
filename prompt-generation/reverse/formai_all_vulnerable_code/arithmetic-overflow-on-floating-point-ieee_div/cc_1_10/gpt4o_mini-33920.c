//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <signal.h>

#define MAX_SIZE 200
#define REFRESH_INTERVAL 2

volatile sig_atomic_t keep_running = 1;

void intHandler(int dummy) {
    keep_running = 0;
}

void displayMemoryUsage(struct sysinfo *info) {
    printf("\033[H\033[J"); // Clear screen
    printf("Memory Usage Monitor\n");
    printf("----------------------\n");
    printf("Total RAM: %lu MB\n", info->totalram / (1024 * 1024));
    printf("Free RAM: %lu MB\n", info->freeram / (1024 * 1024));
    printf("Used RAM: %lu MB\n", (info->totalram - info->freeram) / (1024 * 1024));
    printf("Memory Usage Percentage: %.2f%%\n",
           ((double)(info->totalram - info->freeram) / info->totalram) * 100);
    printf("----------------------\n\n");
}

void recordMemoryUsage(struct sysinfo *info, FILE *logfile) {
    if (logfile != NULL) {
        fprintf(logfile, "Total RAM: %lu MB\n", info->totalram / (1024 * 1024));
        fprintf(logfile, "Free RAM: %lu MB\n", info->freeram / (1024 * 1024));
        fprintf(logfile, "Used RAM: %lu MB\n", (info->totalram - info->freeram) / (1024 * 1024));
        fprintf(logfile, "Memory Usage Percentage: %.2f%%\n",
                ((double)(info->totalram - info->freeram) / info->totalram) * 100);
        fprintf(logfile, "----------------------\n");
    }
}

int main() {
    struct sysinfo info;
    FILE *logfile = fopen("memory_usage.log", "w");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return EXIT_FAILURE;
    }

    signal(SIGINT, intHandler);

    printf("Starting RAM Usage Monitor...\n");
    printf("Press Ctrl+C to stop.\n\n");

    while (keep_running) {
        if (sysinfo(&info) == 0) {
            displayMemoryUsage(&info);
            recordMemoryUsage(&info, logfile);
        } else {
            perror("sysinfo failed");
            break;
        }
        sleep(REFRESH_INTERVAL);
    }

    fclose(logfile);
    printf("Stopping RAM Usage Monitor. Log saved to memory_usage.log\n");
    return EXIT_SUCCESS;
}