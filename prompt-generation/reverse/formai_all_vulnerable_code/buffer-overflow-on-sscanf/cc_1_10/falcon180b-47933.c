//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define BUFFER_SIZE 1024

typedef struct process {
    int pid;
    char name[20];
    int status;
} Process;

int main() {
    int num_processes = 0;
    Process *processes = malloc(MAX_PROCESSES * sizeof(Process));

    if (processes == NULL) {
        printf("Error: Could not allocate memory for process list.\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    FILE *file = popen("ps -ax", "r");

    if (file == NULL) {
        printf("Error: Could not open process list.\n");
        free(processes);
        return 1;
    }

    while (getline(&line, &len, file)!= -1) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached.\n");
            free(processes);
            free(line);
            pclose(file);
            return 1;
        }

        Process *current_process = &processes[num_processes];

        sscanf(line, "%d %s %d", &current_process->pid, current_process->name, &current_process->status);
        num_processes++;
    }

    free(line);
    pclose(file);

    printf("Process list:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s (%d)\n", processes[i].pid, processes[i].name, processes[i].status);
    }

    free(processes);
    return 0;
}