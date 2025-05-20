//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MAX_PROCESSES 1024

typedef struct {
    pid_t pid;
    char name[16];
    int memory;
} Process;

int num_processes = 0;
Process *processes = NULL;

int compare_processes(const void *a, const void *b) {
    return ((*(Process*)a).memory - (*(Process*)b).memory);
}

void update_processes() {
    FILE *fp;
    char line[1024];
    char name[16];
    pid_t pid;
    int memory;

    fp = fopen("/proc/self/status", "r");
    if (!fp) {
        printf("Error: Failed to open /proc/self/status\n");
        return;
    }

    num_processes = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "VmSize:\t%d kB", &memory) == 1) {
            sscanf(line, "Name:\t%15s", name);
            pid = getpid();

            processes = realloc(processes, sizeof(Process) * ++num_processes);
            processes[num_processes - 1].pid = pid;
            strncpy(processes[num_processes - 1].name, name, sizeof(processes[num_processes - 1].name));
            processes[num_processes - 1].memory = memory;
        }
    }

    fclose(fp);
    qsort(processes, num_processes, sizeof(Process), compare_processes);
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-10d %-16s %6d kB\n", processes[i].pid, processes[i].name, processes[i].memory);
    }
}

int main() {
    update_processes();
    print_processes();

    return 0;
}