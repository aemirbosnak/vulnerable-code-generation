//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define MAX_PROCESSES 256

typedef struct {
    pid_t pid;
    char name[256];
    long ram_usage; // in KB
} ProcessInfo;

void fetch_processes(ProcessInfo *processes, int *count) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
  
    char line[256];
    long total_memory = 0;
    long free_memory = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) continue;
        if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) continue;
    }
  
    fclose(fp);
  
    FILE *proc_fp = fopen("/proc/stat", "r");
    if (!proc_fp) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    int process_count = 0;
  
    for (int pid = 1; pid < MAX_PROCESSES && process_count < MAX_PROCESSES; pid++) {
        char filepath[256], cmdline[256];
        snprintf(filepath, sizeof(filepath), "/proc/%d/stat", pid);
        snprintf(cmdline, sizeof(cmdline), "/proc/%d/cmdline", pid);
      
        if (access(filepath, F_OK) == 0) {
            ProcessInfo p_info;
            p_info.pid = pid;
            
            FILE *cmd_fp = fopen(cmdline, "r");
            if (cmd_fp) {
                if (fgets(p_info.name, sizeof(p_info.name), cmd_fp)) {
                    // Remove newline character
                    size_t len = strlen(p_info.name);
                    if (len > 0 && p_info.name[len - 1] == '\n') {
                        p_info.name[len - 1] = '\0';
                    }
                }
                fclose(cmd_fp);
            } else {
                strcpy(p_info.name, "Unknown");
            }

            FILE *stat_fp = fopen(filepath, "r");
            if (stat_fp) {
                long utime, stime, cutime, cstime, vsize, rss;
                fscanf(stat_fp, "%*d %*s %*s %*s %*s %*s %*s %*s %ld %ld %ld %ld %ld %ld", 
                      &utime, &stime, &cutime, &cstime, &vsize, &rss);
                p_info.ram_usage = rss * 4; // Convert pages to KB
                fclose(stat_fp);
            } else {
                p_info.ram_usage = 0;
            }
          
            processes[process_count++] = p_info;
        }
    }
  
    *count = process_count;
}

void display_memory_info(ProcessInfo *processes, int count, long total_memory, long free_memory) {
    printf("\nTotal Memory: %ld kB\nFree Memory: %ld kB\n", total_memory, free_memory);
    printf("| PID | Command                          | RAM Usage (KB) |\n");
    printf("---------------------------------------------------------\n");
  
    for (int i = 0; i < count; i++) {
        printf("| %-4d | %-30s | %-15ld |\n", 
               processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
    printf("---------------------------------------------------------\n");
}

int main() {
    
    struct sysinfo si;
    if (sysinfo(&si) != 0) {
        perror("sysinfo");
        return EXIT_FAILURE;
    }
    
    long total_memory = si.totalram / 1024;
    long free_memory = si.freeram / 1024;

    ProcessInfo processes[MAX_PROCESSES];
    int process_count = 0;
    
    while (1) {
        fetch_processes(processes, &process_count);
        display_memory_info(processes, process_count, total_memory, free_memory);
        
        printf("Refresh in 5 seconds...\n");
        sleep(5);
    }
    
    return 0;
}