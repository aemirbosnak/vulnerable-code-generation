//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <stdbool.h>

#define SAMPLE_INTERVAL 1
#define BUFFER_SIZE 256

void clear_screen() {
    // ANSI escape codes to clear the screen
    printf("\033[H\033[J");
}

void display_cpu_usage(float usage) {
    // Show the CPU usage in a futuristic style
    printf("\n");
    printf("=========================================\n");
    printf("            CPU USAGE MONITOR          \n");
    printf("=========================================\n");
    printf("|             %.2f%%                   |\n", usage);
    printf("=========================================\n");
    printf("\n");
}

float get_cpu_usage() {
    // Initialization variables
    static long prev_total = 0, prev_idle = 0;
    long total = 0, idle = 0;
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    // Open the CPU stats
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return -1;
    }

    // Read the first line which contains CPU metrics
    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    // Parse the CPU stats
    long user, nice, system, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld", 
           &user, &nice, &system, &iowait, 
           &irq, &softirq, &steal, &guest, &guest_nice);
    
    total = user + nice + system + iowait + irq + softirq + steal;
    idle = iowait + guest + guest_nice;

    // Calculate CPU usage percentage
    long total_diff = total - prev_total;
    long idle_diff = idle - prev_idle;
    float cpu_usage = 0.0;

    if (total_diff > 0) {
        cpu_usage = (1.0 - (float)idle_diff / total_diff) * 100.0;
    }

    prev_total = total;
    prev_idle = idle;

    return cpu_usage;
}

void futuristic_loading_animation(int duration) {
    const char* loading_chars = "|/-\\";
    for (int i = 0; i < duration; i++) {
        printf("\rLoading CPU usage %c", loading_chars[i % 4]);
        fflush(stdout);
        usleep(250000); // Sleep for 250 milliseconds
    }
    printf("\r");
}

int main() {
    bool run_monitor = true;

    printf("Welcome to the Futuristic CPU Usage Monitor!\n");
    printf("Press Ctrl+C to exit at any time.\n");

    while (run_monitor) {
        // Clear the screen for every iteration
        clear_screen();
        
        // Run animation while getting CPU usage
        futuristic_loading_animation(SAMPLE_INTERVAL);

        // Get and display the CPU usage
        float cpu_usage = get_cpu_usage();
        if (cpu_usage >= 0) {
            display_cpu_usage(cpu_usage);
        }
        
        // Sleep for the specified sample interval
        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}