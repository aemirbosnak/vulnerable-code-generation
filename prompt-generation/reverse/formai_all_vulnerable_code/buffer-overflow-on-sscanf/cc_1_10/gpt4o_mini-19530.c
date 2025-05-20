//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 1

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void read_cpu_stats(unsigned long *total, unsigned long *idle) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    unsigned long user, nice, system, irq, softirq, steal, total_idle;
    
    // Open the /proc/stat file for reading
    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read the first line which contains CPU statistics
    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &user, &nice, &system, &idle[0], &irq, &softirq, &steal, total_idle);
    fclose(fp);

    *total = user + nice + system + total_idle + irq + softirq + steal;
    *idle += total_idle;
}

float calculate_cpu_usage(unsigned long total1, unsigned long idle1, 
                           unsigned long total2, unsigned long idle2) {
    unsigned long total_diff = total2 - total1;
    unsigned long idle_diff = idle2 - idle1;
    return 100.0 * (1.0 - ((float)idle_diff / (float)total_diff));
}

void display_cpu_usage(float usage) {
    // Display CPU usage in an innovative ASCII manner
    printf("CPU Usage: [");
    
    int bars = (int)(usage / 2);
    for (int i = 0; i < 50; i++) {
        if (i < bars) {
            printf("#");
        } else {
            printf(" ");
        }
    }

    printf("] %.2f%%\n", usage);
}

int main() {
    unsigned long total1, idle1, total2, idle2;

    // Initialize CPU statistics
    read_cpu_stats(&total1, &idle1);

    while (1) {
        // Sleep for a defined interval
        sleep(SLEEP_INTERVAL);
        
        // Read CPU statistics again
        read_cpu_stats(&total2, &idle2);

        // Calculate CPU usage
        float usage = calculate_cpu_usage(total1, idle1, total2, idle2);

        // Clear the screen and display the updated usage
        clear_screen();
        display_cpu_usage(usage);

        // Update previous values for next calculation
        total1 = total2;
        idle1 = idle2;
    }

    return 0;
}