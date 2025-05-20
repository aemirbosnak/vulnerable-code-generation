//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024

typedef struct {
    pid_t pid;
    char name[16];
    int cpu_percent;
} Process;

void read_process_info(int fd, Process *process) {
    char line[1024];
    while (fgets(line, sizeof(line), fd)!= NULL) {
        if (sscanf(line, "%d %s %d", &process->pid, process->name, &process->cpu_percent) == 3) {
            break;
        }
    }
}

void print_processes(Process *processes, int num_processes) {
    printf("PID\tName\tCPU%\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].cpu_percent);
    }
}

void main() {
    int fd;
    char path[64];
    snprintf(path, sizeof(path), "/proc/%d/stat", getpid());
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error opening %s\n", path);
        exit(EXIT_FAILURE);
    }

    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    while (num_processes < MAX_PROCESSES) {
        read_process_info(fd, &processes[num_processes]);
        num_processes++;
    }

    close(fd);
    print_processes(processes, num_processes);
}