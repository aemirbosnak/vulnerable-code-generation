//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <time.h>

// Function to calculate CPU usage
void calculate_cpu_usage(double *prev_cpu_usage, double *prev_idle_time) {
    FILE *file;
    char line[128];
    double user_time, nice_time, system_time, idle_time, iowait_time, irq_time, softirq_time, total_time;

    // Open the /proc/stat file to read CPU stats
    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to read /proc/stat");
        exit(EXIT_FAILURE);
    }
  
    // Read the first line, which contains CPU information
    if (fgets(line, sizeof(line), file) == NULL) {
        perror("Failed to read line from /proc/stat");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // Parse the values from the line
    sscanf(line, "cpu %lf %lf %lf %lf %lf %lf %lf %lf", 
           &user_time, &nice_time, &system_time, 
           &idle_time, &iowait_time, &irq_time, 
           &softirq_time);

    // Calculate total idle time
    total_time = user_time + nice_time + system_time + idle_time + iowait_time + irq_time + softirq_time;

    // Calculate CPU usage since last check
    double current_idle_time = idle_time + iowait_time;
    *prev_cpu_usage = 100 * ((total_time - (*prev_cpu_usage)) / total_time);
    *prev_idle_time = current_idle_time;
}

// Function to display the CPU usage in an artistic style
void display_cpu_usage() {
    double prev_cpu_usage = 0, prev_idle_time = 0;

    printf("     ██████╗ ██╗   ██╗██╗     ██╗   ██╗    ███████╗██╗   ██╗██╗   ██╗\n"); 
    printf("     ██╔══██╗██║   ██║██║     ██║   ██║    ██╔════╝██║   ██║██║   ██║\n");
    printf("     ██████╔╝██║   ██║██║     ██║   ██║    █████╗  ██║   ██║██║   ██║\n");
    printf("     ██╔═══╝ ██║   ██║██║     ██║   ██║    ██╔══╝  ██║   ██║██║   ██║\n");
    printf("     ██║     ╚██████╔╝███████╗╚██████╔╝    ███████╗╚██████╔╝╚██████╔╝\n"); 
    printf("     ╚═╝      ╚═════╝ ╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝  ╚═════╝ \n");
    printf("                     CPU Usage Monitor                      \n\n");

    while (1) {
        // Calculate CPU usage
        calculate_cpu_usage(&prev_cpu_usage, &prev_idle_time);

        // Print the CPU usage
        printf("\rCurrent CPU Usage: %.2f%%   ", prev_cpu_usage);
        fflush(stdout);
        usleep(1000000); // Sleep for 1 second
    }
}

int main() {
    display_cpu_usage();
    return 0;
}