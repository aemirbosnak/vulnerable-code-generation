//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 1000

struct process {
    int pid;
    char name[32];
    int cpu_usage;
};

int get_process_info(struct process *processes, int num_processes) {
    FILE *proc_file;
    char line[1024];
    char *token;
    int i = 0;

    proc_file = fopen("/proc/stat", "r");
    if (proc_file == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), proc_file)!= NULL) {
        if (sscanf(line, "cpu %d %*s %*s %*s %*s", &processes[i].cpu_usage) == 1) {
            token = strtok(line, " ");
            sscanf(token, "%d", &processes[i].pid);
            i++;
        }
    }

    fclose(proc_file);

    return i;
}

void print_process_info(struct process *processes, int num_processes) {
    printf("Process ID\tName\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t\t%d\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    num_processes = get_process_info(processes, MAX_PROCESSES);

    print_process_info(processes, num_processes);

    return 0;
}