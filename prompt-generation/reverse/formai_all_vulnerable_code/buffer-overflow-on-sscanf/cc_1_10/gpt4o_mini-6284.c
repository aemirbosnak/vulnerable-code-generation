//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define CPU_INFO_FILE "/proc/stat"
#define BUFFER_SIZE 256

void get_cpu_usage(double *cpu_usage) {
    FILE *file = fopen(CPU_INFO_FILE, "r");
    if (!file) {
        perror("Failed to open " CPU_INFO_FILE);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char cpu[5];
        long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

        sscanf(buffer, "%s %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", cpu, &user,
               &nice, &system, &idle, &iowait, &irq, &softirq, &steal,
               &guest, &guest_nice);

        long total_idle = idle + iowait;
        long total_non_idle = user + nice + system + irq + softirq + steal;
        long total = total_idle + total_non_idle;

        double usage = ((double)total_non_idle / total) * 100.0;

        *cpu_usage = usage;
    }
    fclose(file);
}

void print_usage(double cpu_usage) {
    printf("\rCurrent CPU Usage: %.2f%%   ", cpu_usage);
    fflush(stdout);
}

void display_heading() {
    printf("==========================================\n");
    printf("          CPU Usage Monitor               \n");
    printf("==========================================\n");
    printf("Press Ctrl+C to exit...\n");
    printf("==========================================\n");
}

int main() {
    double cpu_usage = 0.0;
    display_heading();

    while (1) {
        get_cpu_usage(&cpu_usage);
        print_usage(cpu_usage);
        usleep(500000); // Sleep for half a second
    }

    return 0;
}