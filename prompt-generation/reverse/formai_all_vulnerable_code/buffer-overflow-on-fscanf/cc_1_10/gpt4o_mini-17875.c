//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_system_uptime() {
    FILE *fp;
    unsigned long uptime;
    fp = fopen("/proc/uptime", "r");
    if (fp == NULL) {
        perror("Failed to open uptime file");
        return;
    }
    fscanf(fp, "%lu", &uptime);
    fclose(fp);
    printf("System uptime is: %lu seconds\n", uptime);
}

void get_memory_usage() {
    FILE *fp;
    long total_memory = 0;
    long free_memory = 0;
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open meminfo file");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) || sscanf(line, "MemFree: %ld kB", &free_memory)) {
            continue;
        }
    }
    
    fclose(fp);
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
}

void list_running_processes() {
    FILE *fp;
    struct {
        int pid;
        char comm[256];
        char state[4];
    } process;

    printf("\nPID\tCOMMAND\t\tSTATE\n");
    printf("------------------------------------\n");

    for (int pid = 1; pid <= 30000; pid++) {
        char filename[32], line[256];
        snprintf(filename, sizeof(filename), "/proc/%d/stat", pid);
        fp = fopen(filename, "r");

        if (fp) {
            fscanf(fp, "%d %s %s", &process.pid, process.comm, process.state);
            printf("%d\t%s\t%s\n", process.pid, process.comm, process.state);
            fclose(fp);
        }
    }
}

int main() {
    printf("Welcome to the Curious System Monitor!\n");
    printf("Let's uncover some secrets of your Linux system...\n\n");
    
    get_system_uptime();
    get_memory_usage();
    list_running_processes();
    
    printf("\nThank you for using the Curious System Monitor. Until next time!\n");
    
    return 0;
}