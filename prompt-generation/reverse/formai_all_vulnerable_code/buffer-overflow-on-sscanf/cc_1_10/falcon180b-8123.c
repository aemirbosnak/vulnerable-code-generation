//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100

struct process {
    char name[50];
    int pid;
    int cpu_usage;
    int mem_usage;
};

int get_processes(struct process *processes) {
    int count = 0;
    char *line = NULL;
    size_t len = 0;
    FILE *file = popen("ps -eo comm=,pid=,%cpu=,%mem=", "r");

    if (file == NULL) {
        printf("Error: Failed to execute ps command.\n");
        return -1;
    }

    while ((getline(&line, &len, file))!= -1) {
        if (count >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached.\n");
            break;
        }

        sscanf(line, "%s %d %d %d", processes[count].name, &processes[count].pid, &processes[count].cpu_usage, &processes[count].mem_usage);
        count++;
    }

    pclose(file);
    return count;
}

void display_processes(struct process *processes, int count) {
    printf("\nProcess ID\tProcess Name\tCPU Usage\tMemory Usage\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d%%\t\t%d%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage, processes[i].mem_usage);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int count = get_processes(processes);

    if (count > 0) {
        display_processes(processes, count);
    } else {
        printf("No processes running.\n");
    }

    return 0;
}