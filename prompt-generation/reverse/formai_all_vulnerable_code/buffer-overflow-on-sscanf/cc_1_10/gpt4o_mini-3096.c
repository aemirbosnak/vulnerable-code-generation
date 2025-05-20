//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define LINE_LENGTH 256

typedef struct {
    int pid;
    char name[100];
    long rss; // Resident Set Size
} ProcessInfo;

void clear_screen() {
    printf("\033[H\033[J");
}

void get_memory_usage(ProcessInfo processes[], int *process_count) {
    FILE *fp = fopen("/proc/meminfo", "r");
    char line[LINE_LENGTH];
    long mem_total = 0, mem_available = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "MemTotal: %ld kB", &mem_total) == 1) {
            continue;
        }
        if (sscanf(line, "MemAvailable: %ld kB", &mem_available) == 1) {
            continue;
        }
    }
    fclose(fp);

    *process_count = 0;
    FILE *proc_fp = fopen("/proc/stat", "r");
    while (fgets(line, sizeof(line), proc_fp) != NULL) {
        if (sscanf(line, "processes %d", &processes[*process_count].pid) == 1) {
            strcpy(processes[*process_count].name, "System Processes");
            processes[*process_count].rss = -1; // System process placeholder
            (*process_count)++;
        }
        if (*process_count >= MAX_PROCESSES) {
            break;
        }
    }
    fclose(proc_fp);
}

void get_process_details(ProcessInfo processes[], int process_count) {
    FILE *fp;
    char line[LINE_LENGTH];
    
    for (int i = 0; i < process_count; i++) {
        snprintf(line, LINE_LENGTH, "/proc/%d/stat", processes[i].pid);
        fp = fopen(line, "r");
        
        if (fp) {
            int pid;
            char comm[256];
            char state;
            long utime, stime, cutime, cstime, session;
            unsigned long vsize;
            long rss;

            fscanf(fp, "%d %s %c %d %d %d %d %d %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
                   &pid, comm, &state, &utime, &stime, &cutime, &cstime,
                   &session, &vsize, &rss);
            strcpy(processes[i].name, comm);
            processes[i].rss = rss;
            fclose(fp);
        } else {
            processes[i].rss = -1; // Not accessible
        }
    }
}

void display_memory_usage(ProcessInfo processes[], int process_count) {
    clear_screen();
    printf("PID\tProcess Name\t\tRSS (KB)\n");
    printf("------------------------------------------\n");
    
    for (int i = 0; i < process_count; i++) {
        if (processes[i].rss != -1) {
            printf("%d\t%-20s\t%ld\n", processes[i].pid, processes[i].name, processes[i].rss);
        }
    }
    printf("\nPress Ctrl+C to exit...\n");
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count = 0;

    while (1) {
        get_memory_usage(processes, &process_count);
        get_process_details(processes, process_count);
        display_memory_usage(processes, process_count);
        sleep(2); // Refresh every 2 seconds
    }

    return 0;
}