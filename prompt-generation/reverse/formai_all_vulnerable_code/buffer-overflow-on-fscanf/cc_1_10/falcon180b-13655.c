//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROC_FILE "/proc/self/stat"

typedef struct {
    int cpu_percent;
    int pid;
} Process;

void get_cpu_percent(Process* proc) {
    FILE* file = fopen(PROC_FILE, "r");
    char buffer[1024];
    if (file) {
        fscanf(file, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d", &proc->cpu_percent);
        fclose(file);
    }
}

void print_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("PID: %d, CPU usage: %.2f%%\n", processes[i].pid, processes[i].cpu_percent);
    }
}

int main() {
    int num_processes = 0;
    Process* processes = NULL;

    FILE* file = fopen(PROC_FILE, "r");
    char buffer[1024];
    if (file) {
        while (fscanf(file, "%d", &num_processes)!= EOF) {
            processes = realloc(processes, num_processes * sizeof(Process));
            for (int i = 0; i < num_processes; i++) {
                get_cpu_percent(&processes[i]);
            }
        }
        fclose(file);
    } else {
        perror("Error opening file");
        exit(1);
    }

    print_processes(processes, num_processes);

    free(processes);
    return 0;
}