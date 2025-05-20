//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/time.h>

#define MAX_PROCESSES 1024

struct process {
    int pid;
    char name[16];
    int rss;
};

int main() {
    int num_processes = 0;
    struct process *processes = malloc(MAX_PROCESSES * sizeof(struct process));
    if (processes == NULL) {
        printf("Error: Could not allocate memory for process list.\n");
        return 1;
    }
    memset(processes, 0, MAX_PROCESSES * sizeof(struct process));

    FILE *fp;
    char line[1024];
    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status.\n");
        return 1;
    }
    while (fgets(line, 1024, fp)!= NULL) {
        if (strstr(line, "VmRSS")!= NULL) {
            int rss;
            sscanf(line, "VmRSS: %d kB", &rss);
            processes[num_processes].pid = getpid();
            strncpy(processes[num_processes].name, "RAM Monitor", 16);
            processes[num_processes].rss = rss;
            num_processes++;
        }
    }
    fclose(fp);

    while (1) {
        sleep(1);
        int total_rss = 0;
        for (int i = 0; i < num_processes; i++) {
            int pid = processes[i].pid;
            char path[16];
            snprintf(path, 16, "/proc/%d", pid);
            struct statvfs stvfs;
            if (statvfs(path, &stvfs) == 0) {
                total_rss += processes[i].rss;
            }
        }
        printf("Total RAM usage: %d kB\n", total_rss);
    }
    return 0;
}