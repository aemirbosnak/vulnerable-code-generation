//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_HEIGHT 20
#define WIDTH 50

void display_usage(float usage);
void clear_screen();
void print_bar(float usage);
float get_cpu_usage();

int main() {
    // Loop to continuously monitor CPU usage
    while (1) {
        float cpu_usage = get_cpu_usage();

        clear_screen();
        display_usage(cpu_usage);

        // Sleep for a second before updating
        sleep(1);
    }
    return 0;
}

// Function to calculate CPU usage based on /proc/stat data
float get_cpu_usage() {
    FILE *fp;
    char buffer[256];
    unsigned long idle_time, total_time, user_time, nice_time, system_time, iowait_time, irq_time, softirq_time, steal_time;
    unsigned long prev_idle_time = 0, prev_total_time = 0;

    // Read the first line of /proc/stat
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to read /proc/stat");
        return -1;
    }

    fscanf(fp, "%s %lu %lu %lu %lu %lu %lu %lu %lu %lu",
           buffer, &user_time, &nice_time, &system_time, &idle_time, &iowait_time, &irq_time, &softirq_time, &steal_time);

    // Calculate total and idle time
    total_time = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time + steal_time;
    idle_time += iowait_time;

    // Calculate CPU usage
    unsigned long total_delta = total_time - prev_total_time;
    unsigned long idle_delta = idle_time - prev_idle_time;

    prev_total_time = total_time;
    prev_idle_time = idle_time;

    float cpu_usage = 100.0 * (1.0 - (float)idle_delta / (float)total_delta);
    
    fclose(fp);
    return cpu_usage;
}

// Function to clear the console screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to display the CPU usage in a graphical manner
void display_usage(float usage) {
    printf("\n\nCurrent CPU Usage: %.2f%%\n", usage);
    printf("Usage Bar: |");
    print_bar(usage);
    printf("|\n\n");
}

// Function to print a bar graph based on CPU usage
void print_bar(float usage) {
    int filled_length = (int)(usage / 100.0 * WIDTH);
    for (int i = 0; i < filled_length; i++) {
        printf("#");
    }
    for (int i = filled_length; i < WIDTH; i++) {
        printf("-");
    }
}