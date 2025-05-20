//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape sequence to clear screen
}

void get_cpu_usage(double *cpu_usage) {
    FILE *fp;
    char buffer[MAX_LINE_LENGTH];
    long total_user, total_user_nice, total_system, total_idle, total_iowait;
    long total_steal, total_irq, total_softirq, total;
    static long prev_total_idle = 0, prev_total = 0;

    // Read the /proc/stat file
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line that starts with "cpu"
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
               &total_user, &total_user_nice, &total_system, 
               &total_idle, &total_iowait, &total_steal, 
               &total_irq, &total_softirq);
        
        // Total time and idle time
        total = total_user + total_user_nice + total_system + 
                total_idle + total_iowait + total_steal + 
                total_irq + total_softirq;

        long total_idle_time = total_idle + total_iowait;

        if (prev_total > 0) {
            long total_diff = total - prev_total;
            long idle_diff = total_idle_time - prev_total_idle;

            *cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;
        } else {
            *cpu_usage = 0.0; // Initial state
        }

        prev_total_idle = total_idle_time;
        prev_total = total;
    }
    
    fclose(fp);
}

void print_usage(double cpu_usage) {
    clear_screen();
    time_t current_time = time(NULL);
    char *time_str = ctime(&current_time);

    // Display current time
    printf("CPU Usage Monitor\n");
    printf("Current Time: %s", time_str);
    printf("=====================================\n");
    printf("Current CPU Usage: %.2f%%\n", cpu_usage);
    printf("=====================================\n");
}

int main() {
    double cpu_usage;

    // Monitor CPU usage indefinitely
    while (1) {
        get_cpu_usage(&cpu_usage);
        print_usage(cpu_usage);
        usleep(1000000); // Update every second
    }

    return 0;
}