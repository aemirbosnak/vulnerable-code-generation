//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <time.h>

#define MAX_PROCESSES 64 // The maximum number of processes to display

// Structure to hold process information
typedef struct {
    int pid;
    char name[256];
    double cpu_usage;
} ProcessInfo;

// Function to get CPU usage
double get_cpu_usage() {
    FILE *fp;
    unsigned long long total_user, total_user_nice, total_system, total_idle, total_iowait, total;
    unsigned long long total_1, total_2;
    unsigned long long idle_1, idle_2;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return -1;
    }
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu",
           &total_user, &total_user_nice, &total_system,
           &total_idle, &total_iowait, &total, &total);

    fclose(fp);

    total_1 = total_user + total_user_nice + total_system + total_idle + total_iowait;
    idle_1 = total_idle;

    sleep(1); // Wait for 1 second to get the next measurement

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return -1;
    }
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu",
           &total_user, &total_user_nice, &total_system,
           &total_idle, &total_iowait, &total, &total);

    fclose(fp);

    total_2 = total_user + total_user_nice + total_system + total_idle + total_iowait;
    idle_2 = total_idle;

    double total_cpu = (double)(total_2 - total_1);
    double idle_cpu = (double)(idle_2 - idle_1);
    
    return ((total_cpu - idle_cpu) / total_cpu) * 100; // CPU usage in percentage
}

// Function to get information of processes
void get_process_info(ProcessInfo *processes, int *count) {
    FILE *fp;
    char buffer[256];
    *count = 0;
    
    for (int i = 1; i <= MAX_PROCESSES; i++) {
        snprintf(buffer, sizeof(buffer), "/proc/%d/stat", i);
        fp = fopen(buffer, "r");
        if (fp) {
            int pid;
            char name[256];
            unsigned long utime, stime;
            fscanf(fp, "%d %s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu %lu", &pid, name, &utime, &stime);
            processes[*count].pid = pid;
            strncpy(processes[*count].name, name + 1, sizeof(processes[*count].name) - 2); // Strip parentheses
            processes[*count].name[strlen(processes[*count].name) - 1] = '\0'; // Remove last )
            processes[*count].cpu_usage = (utime + stime) / (double)sysconf(_SC_CLK_TCK); // CPU time is divided by clock ticks
            (*count)++;
            fclose(fp);
        }
    }
}

// Function to display process usage in ASCII Art style
void display_usage(ProcessInfo *processes, int count, double cpu_usage) {
    printf("\n");
    printf("          \033[1;32mCPU USAGE MONITOR\033[0m\n");
    printf("           ┌───────────────────────────────────────────────┐\n");
    printf("           │ Current CPU Usage: \033[1;36m%.2f%%\033[0m                │\n", cpu_usage);
    printf("           ├─────────┬─────────────┬─────────────┬──────────┤\n");
    printf("           │  PID    │   Process   │ CPU Time   │  Usage % │\n");
    printf("           ├─────────┼─────────────┼─────────────┼──────────┤\n");
    
    for (int i = 0; i < count; i++) {
        printf("           │  %-6d │ %-11s │ %-11.2f │ %-6.2f %│\n", 
               processes[i].pid, processes[i].name, processes[i].cpu_usage, processes[i].cpu_usage);
    }
    printf("           └─────────┴─────────────┴─────────────┴──────────┘\n");
}

// Signal handler to gracefully exit the program
void handle_sigint(int sig) {
    printf("\n\nExiting CPU Monitor. Goodbye!\n");
    exit(0);
}

int main(void) {
    signal(SIGINT, handle_sigint); // Handle Ctrl+C to exit

    ProcessInfo processes[MAX_PROCESSES];
    int count = 0;
    
    while (1) {
        double cpu_usage = get_cpu_usage();
        if (cpu_usage < 0) {
            fprintf(stderr, "Error getting CPU usage.\n");
            return 1;
        }
        get_process_info(processes, &count);
        display_usage(processes, count, cpu_usage);
        
        usleep(1000000); // Refresh every second
        printf("\033[H\033[J"); // Clear screen
    }

    return 0;
}