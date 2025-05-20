//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void get_memory_usage() {
    FILE *fp;
    char buffer[256];

    printf("\nMemory Usage:\n");
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        // Display only the first five lines of memory info
        if (strncmp(buffer, "MemTotal", 8) == 0 ||
            strncmp(buffer, "MemFree", 7) == 0 ||
            strncmp(buffer, "Buffers", 7) == 0 ||
            strncmp(buffer, "Cached", 6) == 0 ||
            strncmp(buffer, "SwapTotal", 9) == 0) {
            printf("%s", buffer);
        }
    }
    fclose(fp);
}

void get_cpu_load() {
    FILE *fp;
    double load[3];
    
    printf("\nCPU Load (last 1, 5, 15 mins):\n");
    fp = fopen("/proc/loadavg", "r");
    if (fp == NULL) {
        perror("Error opening /proc/loadavg");
        return;
    }

    fscanf(fp, "%lf %lf %lf", &load[0], &load[1], &load[2]);
    printf("1 min: %.2f, 5 min: %.2f, 15 min: %.2f\n", load[0], load[1], load[2]);
    fclose(fp);
}

void get_disk_space() {
    FILE *fp;
    char buffer[256];

    printf("\nDisk Space Usage:\n");
    fp = popen("df -h", "r");
    if (fp == NULL) {
        perror("Error executing df command");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    pclose(fp);
}

int main() {
    printf("System Administration Tool\n");
    printf("===========================\n");

    get_memory_usage();
    get_cpu_load();
    get_disk_space();

    return 0;
}