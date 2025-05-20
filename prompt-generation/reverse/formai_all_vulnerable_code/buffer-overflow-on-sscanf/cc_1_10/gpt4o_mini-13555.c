//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clear_screen() {
    // Clear the screen using ANSI escape codes
    printf("\033[H\033[J");
}

float get_cpu_usage() {
    FILE *fp;
    char buffer[1024];
    unsigned long long idle_time, total_time;
    unsigned long long prev_idle_time = 0, prev_total_time = 0;

    // Open the /proc/stat file to read CPU stats
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open /proc/stat\n");
        return -1.0;
    }

    // Read the first line to get CPU times
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Tokenize the line to extract CPU times
    unsigned long long user_time, nice_time, system_time;
    sscanf(buffer, "cpu %llu %llu %llu %llu", &user_time, &nice_time, &system_time, &idle_time);

    total_time = user_time + nice_time + system_time + idle_time;
    float cpu_usage = 1.0 - ((float)idle_time - (float)prev_idle_time) / (total_time - prev_total_time);
    
    prev_idle_time = idle_time;
    prev_total_time = total_time;

    return cpu_usage * 100.0; // Return as percentage
}

void display_cpu_usage(float usage) {
    clear_screen();
    printf("======================================\n");
    printf("           CPU Usage Monitor          \n");
    printf("======================================\n");
    printf("Current CPU Usage: %.2f%%\n", usage);
    printf("Breathe in... and out...\n");
    printf("Take a moment to appreciate the flow of life.\n");
    printf("======================================\n");
}

int main() {
    // Main loop to monitor CPU usage
    while (1) {
        float cpu_usage = get_cpu_usage();
        if (cpu_usage < 0) {
            fprintf(stderr, "Failed to get CPU usage\n");
            break; // Exit if there's an error
        }
        
        display_cpu_usage(cpu_usage);
        sleep(1); // Sleep for 1 second before the next check
    }
    return 0;
}