//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define MAX_PROCESSES 100

typedef struct process {
    char name[16];
    int pid;
    int memory_usage;
} Process;

Process processes[MAX_PROCESSES];

int num_processes = 0;

int get_process_index(int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            return i;
        }
    }
    return -1;
}

void add_process(const char* name, int pid) {
    if (num_processes >= MAX_PROCESSES) {
        return;
    }

    Process* process = &processes[num_processes];
    strncpy(process->name, name, sizeof(process->name));
    process->pid = pid;
    process->memory_usage = 0;
    num_processes++;
}

void update_process_memory_usage(int pid, int memory_usage) {
    int index = get_process_index(pid);
    if (index == -1) {
        return;
    }

    processes[index].memory_usage = memory_usage;
}

int main() {
    setbuf(stdout, NULL);

    char command[1024];
    while (true) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        char* token = strtok(command, " ");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "list") == 0) {
            for (int i = 0; i < num_processes; i++) {
                printf("%d: %s (%d KB)\n", processes[i].pid, processes[i].name, processes[i].memory_usage / 1024);
            }
        } else if (strcmp(token, "add") == 0) {
            char name[16];
            int pid;
            sscanf(command, "add %s %d", name, &pid);
            add_process(name, pid);
        } else if (strcmp(token, "update") == 0) {
            int pid, memory_usage;
            sscanf(command, "update %d %d", &pid, &memory_usage);
            update_process_memory_usage(pid, memory_usage);
        }
    }

    return 0;
}