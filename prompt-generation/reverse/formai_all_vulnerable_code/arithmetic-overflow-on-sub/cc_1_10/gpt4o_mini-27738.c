//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

void print_memory_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    long totalRAM = memInfo.totalram;
    long freeRAM = memInfo.freeram;
    long usedRAM = totalRAM - freeRAM;

    // Convert to MB
    totalRAM = totalRAM / (1024 * 1024);
    freeRAM = freeRAM / (1024 * 1024);
    usedRAM = usedRAM / (1024 * 1024);

    printf("Total RAM: %ld MB\n", totalRAM);
    printf("Used RAM: %ld MB\n", usedRAM);
    printf("Free RAM: %ld MB\n", freeRAM);
}

void print_memory_stats() {
    FILE *fp;
    char buffer[256];
    char *token;

    printf("Memory statistics:\n");
    fp = popen("free -h", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

void monitor_memory_usage(int interval) {
    while (1) {
        printf("\n--- Memory Usage Monitor ---\n");
        print_memory_usage();
        print_memory_stats();
        printf("\nNext check in %d seconds...\n", interval);
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // Default interval of 5 seconds

    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Interval must be a positive integer. Defaulting to 5 seconds.\n");
            interval = 5;
        }
    }

    printf("Starting memory usage monitor with interval: %d seconds.\n", interval);
    monitor_memory_usage(interval);
    
    return 0;
}