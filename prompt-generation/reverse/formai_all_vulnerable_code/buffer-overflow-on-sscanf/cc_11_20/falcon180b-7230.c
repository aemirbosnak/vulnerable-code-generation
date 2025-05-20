//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 50

typedef struct {
    char name[MAX_PROCESS_NAME];
    int pid;
    int memory_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    char input_buffer[1024];

    while (1) {
        memset(input_buffer, 0, sizeof(input_buffer));
        fgets(input_buffer, sizeof(input_buffer), stdin);

        if (strncmp(input_buffer, "list", 4) == 0) {
            printf("Process Name\tPID\tMemory Usage\n");
            for (int i = 0; i < num_processes; i++) {
                printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].memory_usage);
            }
        } else if (strncmp(input_buffer, "add", 3) == 0) {
            char process_name[MAX_PROCESS_NAME];
            int pid;
            int memory_usage;

            sscanf(input_buffer, "add %s %d %d", process_name, &pid, &memory_usage);

            for (int i = 0; i < num_processes; i++) {
                if (strcmp(processes[i].name, process_name) == 0) {
                    printf("Process already exists.\n");
                    break;
                }
            }

            if (num_processes >= MAX_PROCESSES) {
                printf("Maximum number of processes reached.\n");
            } else {
                strcpy(processes[num_processes].name, process_name);
                processes[num_processes].pid = pid;
                processes[num_processes].memory_usage = memory_usage;
                num_processes++;
            }
        } else if (strncmp(input_buffer, "remove", 6) == 0) {
            char process_name[MAX_PROCESS_NAME];

            sscanf(input_buffer, "remove %s", process_name);

            for (int i = 0; i < num_processes; i++) {
                if (strcmp(processes[i].name, process_name) == 0) {
                    processes[i] = processes[num_processes - 1];
                    num_processes--;
                    break;
                }
            }
        } else if (strncmp(input_buffer, "exit", 4) == 0) {
            break;
        }
    }

    return 0;
}