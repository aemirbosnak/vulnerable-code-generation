//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>

#define MAX_PROCESSES 1024
#define MAX_NAME_LEN 256
#define CPU_USAGE_FILE "/proc/stat"
#define REFRESH_INTERVAL 1

// Structure to hold CPU usage statistics
typedef struct {
    char name[MAX_NAME_LEN];
    double usage;
    bool is_monitored;
} ProcessInfo;

ProcessInfo processes[MAX_PROCESSES];
int process_count = 0;
bool running = true;

// Signal handler to gracefully terminate the program
void handle_sigint(int sig) {
    running = false;
}

// Function to read the CPU usage from /proc/stat
void get_cpu_usage(double *cpu_info) {
    FILE *fp = fopen(CPU_USAGE_FILE, "r");
    if (!fp) {
        fprintf(stderr, "Error opening %s\n", CPU_USAGE_FILE);
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Parse CPU info from the line
    sscanf(buffer, "cpu  %lf %lf %lf %lf %lf %lf %lf %lf",
           &cpu_info[0], &cpu_info[1], &cpu_info[2], &cpu_info[3],
           &cpu_info[4], &cpu_info[5], &cpu_info[6], &cpu_info[7]);
}

// Calculate CPU usage percentage
double calculate_cpu_usage(double *prev_info, double *current_info) {
    double total_prev = 0.0;
    double total_current = 0.0;
    
    for (int i = 0; i < 8; i++) {
        total_prev += prev_info[i];
        total_current += current_info[i];
    }
    
    double cpu_usage = (total_current - total_prev) / total_current * 100.0;
    return cpu_usage;
}

void monitor_cpu_usage() {
    double prev_cpu_info[8] = {0}, current_cpu_info[8] = {0};

    while (running) {
        sleep(REFRESH_INTERVAL);
        
        get_cpu_usage(current_cpu_info);
        
        double cpu_usage = calculate_cpu_usage(prev_cpu_info, current_cpu_info);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        
        // Store current CPU info for the next iteration
        memcpy(prev_cpu_info, current_cpu_info, sizeof(prev_cpu_info));
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Set up the signal handler to allow graceful exit
    signal(SIGINT, handle_sigint);

    printf("Starting the CPU Usage Monitor...\n");
    
    monitor_cpu_usage();
    
    printf("Exiting CPU Usage Monitor. Goodbye!\n");
    return 0;
}