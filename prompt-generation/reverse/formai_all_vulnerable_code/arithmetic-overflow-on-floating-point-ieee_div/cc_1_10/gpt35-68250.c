//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_PROCESS_NAME_LENGTH 256

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage;
} process_info;

process_info* get_running_processes();
void print_running_processes(process_info* running_processes);
void update_cpu_usage(process_info* process);
float calculate_percentage_usage(long long int elapsed_time, long long int total_time);
void calculate_total_cpu_info(long long int* total_time, long long int* idle_time);

int main() {
    process_info* running_processes = get_running_processes();
    while(1) {
        usleep(500000);
        system("clear");
        print_running_processes(running_processes);
    }
    free(running_processes);
    return 0;
}

process_info* get_running_processes() {
    // Get total CPU time
    long long int total_time1, idle_time1;
    calculate_total_cpu_info(&total_time1, &idle_time1);
    // Sleep for 1 second
    usleep(1000000);
    // Get CPU time again
    long long int total_time2, idle_time2;
    calculate_total_cpu_info(&total_time2, &idle_time2);
    // Calculate CPU time difference to get elapsed time
    long long int elapsed_time = total_time2 - total_time1;
    // Calculate total number of processes currently running
    int max_processes = get_nprocs();
    process_info* running_processes = (process_info*) malloc(sizeof(process_info) * max_processes);
    // Get CPU usage of each process
    int process_count = 0;
    for(int pid = 1; pid < 32768; pid++) {
        char stat_filename[MAX_PROCESS_NAME_LENGTH];
        sprintf(stat_filename, "/proc/%d/stat", pid);
        FILE *file = fopen(stat_filename, "r");
        if(file) {
            char name[MAX_PROCESS_NAME_LENGTH];
            fscanf(file, "%d (%[^)])", &pid, name);
            process_info pi = {pid, name, 0.0};
            update_cpu_usage(&pi);
            if(pi.cpu_usage > 0.0) {
                running_processes[process_count++] = pi;
            }
            fclose(file);
        }
    }
    running_processes = (process_info*) realloc(running_processes, sizeof(process_info) * process_count);
    return running_processes;
}

void print_running_processes(process_info* running_processes) {
    long long int total_time, idle_time;
    calculate_total_cpu_info(&total_time, &idle_time);
    float total_cpu_usage = 100 - calculate_percentage_usage(idle_time, total_time);
    printf("%-6s %-30s %-10s\n", "PID", "Name", "% CPU Usage");
    printf("%-6s %-30s %-10s\n", "---", "----", "-----------");
    for(int i = 0; i < sizeof(running_processes); i++) {
        printf("%-6d %-30s %-10.1f\n", running_processes[i].pid, running_processes[i].name, running_processes[i].cpu_usage);
    }
    printf("\nTotal CPU Usage: %.1f%%\n", total_cpu_usage);
}

void update_cpu_usage(process_info* process) {
    char stat_filename[MAX_PROCESS_NAME_LENGTH];
    sprintf(stat_filename, "/proc/%d/stat", process->pid);
    FILE *file = fopen(stat_filename, "r");
    if(file) {
        long long int utime, stime;
        fscanf(file, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %llu %llu", &utime, &stime);
        long long int updated_total_time, updated_idle_time;
        calculate_total_cpu_info(&updated_total_time, &updated_idle_time);
        process->cpu_usage = calculate_percentage_usage((utime + stime), (updated_total_time - updated_idle_time)) / get_nprocs();
        fclose(file);
    }
}

float calculate_percentage_usage(long long int elapsed_time, long long int total_time) {
    return (((float)elapsed_time / (float)total_time) * 100);
}

void calculate_total_cpu_info(long long int* total_time, long long int* idle_time) {
    FILE *file = fopen("/proc/stat", "r");
    if(file) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "cpu %llu %*u %llu %*u %*u %*u %*u %*u %*u", total_time, idle_time);
        fclose(file);
    }
}