//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_PROCESSES 1024

void *cpu_monitor(void *arg);

typedef struct {
    int pid;
    char name[256];
    double cpu_usage;
} ProcessInfo;

ProcessInfo process_list[MAX_PROCESSES];
int process_count = 0;

void signal_handler(int sig) {
    printf("\nExiting CPU usage monitor...\n");
    exit(0);
}

void get_process_info() {
    char buffer[256];
    process_count = 0;
    FILE *fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // CPU data starts from the second line
    int total_user, total_nice, total_system, total_idle;
    sscanf(buffer, "cpu %d %d %d %d", &total_user, &total_nice, &total_system, &total_idle);
    
    int total_time = total_user + total_nice + total_system + total_idle;

    printf("Total CPU Time: %d\n", total_time);

    fp = fopen("/proc/self/stat", "r");
    if (fp == NULL) {
        perror("Unable to open /proc/self/stat");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (process_count >= MAX_PROCESSES) break;
        
        int pid;
        unsigned long utime, stime, cutime, cstime;

        sscanf(buffer, "%d %s %*s %*d %*d %*d %*d %*d %*d %*d %*d %lu %lu %lu %lu", 
                &pid, process_list[process_count].name, &utime, &stime, &cutime, &cstime);
        
        // Calculate CPU usage
        int total_process_time = utime + stime + cutime + cstime;
        process_list[process_count].pid = pid;
        process_list[process_count].cpu_usage = (double)total_process_time / total_time * 100.0;
        process_count++;
    }

    fclose(fp);
}

void display_cpu_usage() {
    printf("\nCPU Usage for Processes:\n");
    printf("%-10s %-25s %s\n", "PID", "Process Name", "CPU Usage (%)");
    for (int i = 0; i < process_count; i++) {
        printf("%-10d %-25s %.2f\n", process_list[i].pid, process_list[i].name, process_list[i].cpu_usage);
    }
}

void *cpu_monitor(void *arg) {
    while (1) {
        get_process_info();
        display_cpu_usage();
        sleep(2); // Update every 2 seconds
    }
}

int main() {
    signal(SIGINT, signal_handler);

    pthread_t monitor_thread;

    if (pthread_create(&monitor_thread, NULL, cpu_monitor, NULL) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    // Join the thread (will wait for it to finish)
    pthread_join(monitor_thread, NULL);

    return 0;
}