//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 256
#define SLEEP_TIME 1

void get_cpu_usage(double *usage) {
    FILE *fp;
    char buffer[MAX_LEN];
    long total_user, total_user_nice, total_system, total_idle, total_iowait, total_steal;
    long total, idle;

    // Open /proc/stat to get CPU stats
    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(1);
    }

    // Read the first line which contains CPU statistics
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    sscanf(buffer + 5, "%ld %ld %ld %ld %ld %ld", 
           &total_user, &total_user_nice, 
           &total_system, &total_idle, 
           &total_iowait, &total_steal);
    
    // Calculate total and idle time
    total = total_user + total_user_nice + total_system + total_idle + total_iowait + total_steal;
    idle = total_idle;

    // Calculate CPU usage percentage
    static long prev_total = 0, prev_idle = 0;
    long total_diff = total - prev_total;
    long idle_diff = idle - prev_idle;

    *usage = (double)(total_diff - idle_diff) / total_diff * 100;

    // Update previous values
    prev_total = total;
    prev_idle = idle;
}

void print_cpu_usage() {
    double usage;

    while (1) {
        get_cpu_usage(&usage);
        printf("\rCPU Usage: [");
        
        int bar_length = 50 * (usage / 100.0); // Progress bar length
        for (int i = 0; i < 50; i++) {
            if (i < bar_length) {
                printf("█");
            } else {
                printf(" ");
            }
        }

        printf("] %.2f%%", usage);
        fflush(stdout);
        sleep(SLEEP_TIME);
    }
}

int main() {
    printf("\n");
    printf("=====================================\n");
    printf("   WELCOME TO CPU USAGE MONITOR!   \n");
    printf("   Let’s keep an eye on that CPU!   \n");
    printf("=====================================\n");
    printf("   Monitoring CPU usage every %d seconds...\n\n", SLEEP_TIME);
    
    print_cpu_usage();

    return 0;
}