//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

void display_cpu_usage(float usage) {
    printf("CPU Usage: %.2f%%\n", usage);
}

float calculate_cpu_usage() {
    FILE *fp;
    char line[128];
    long total_user, total_user_nice, total_sys, total_idle, total_iowait, total_steal;
    long total;

    // Fetching the CPU stats
    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        perror("Error reading /proc/stat");
        return -1.0;
    }

    // Read the first line which contains CPU statistics
    fgets(line, sizeof(line), fp);
    fclose(fp);

    // Parsing the line for relevant values
    sscanf(line, "cpu %ld %ld %ld %ld %ld %ld", 
           &total_user, &total_user_nice, &total_sys, 
           &total_idle, &total_iowait, &total_steal);
    
    total = total_user + total_user_nice + total_sys + total_idle + total_iowait + total_steal;

    // Calculate usage
    long busy_time = total - total_idle; // Total busy time
    float usage = 100.0 * ((float)busy_time / (float)total);

    return usage;
}

void display_header() {
    printf("==================================================\n");
    printf("                CPU Usage Monitor                  \n");
    printf("                Peaceful Monitoring                 \n");
    printf("==================================================\n");
}

int main() {
    struct sysinfo sys_info;
    float cpu_usage;
    time_t current_time;

    display_header();

    while (1) {
        cpu_usage = calculate_cpu_usage();
        if (cpu_usage < 0) return 1; // Error occured

        current_time = time(NULL);
        // Display the timestamp and CPU usage
        printf("[%s] ", ctime(&current_time));
        display_cpu_usage(cpu_usage);

        // Sleep for 1 second before repeating
        sleep(1);
    }

    return 0;
}