//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>

void display_cpu_usage() {
    FILE *fp;
    char buffer[128];
    double idle_time, total_time;

    fp = popen("grep 'cpu ' /proc/stat", "r");
    if (fp == NULL) {
        perror("popen");
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %lf %lf %lf %lf", &total_time, &idle_time, &total_time, &total_time);
    
    total_time += idle_time;
    double cpu_usage = (total_time - idle_time) / total_time * 100;

    printf("Current CPU Usage: %.2f%%\n", cpu_usage);
    pclose(fp);
}

void display_memory_usage() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        long total_memory = info.totalram / (1024 * 1024);
        long free_memory = info.freeram / (1024 * 1024);
        long used_memory = total_memory - free_memory;
        
        printf("Total Memory: %ld MB\n", total_memory);
        printf("Used Memory: %ld MB\n", used_memory);
        printf("Free Memory: %ld MB\n", free_memory);
    } else {
        perror("sysinfo");
    }
}

void display_processes() {
    FILE *fp;
    char cmd[256];

    printf("\nCurrent Running Processes:\n");
    printf("%-10s %-20s %-10s\n", "PID", "User", "Command");

    // Using `ps` command to list processes
    fp = popen("ps -eo pid,user,cmd --sort=-%mem | head -n 10", "r");
    if (fp == NULL) {
        perror("popen");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    pclose(fp);
}

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting gracefully...\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);

    while (1) {
        printf("\n--- System Monitoring ---\n");
        display_cpu_usage();
        display_memory_usage();
        display_processes();
        
        // Wait for a while before refreshing
        printf("\nRefreshing in 5 seconds...\n");
        sleep(5);
    }

    return 0;
}