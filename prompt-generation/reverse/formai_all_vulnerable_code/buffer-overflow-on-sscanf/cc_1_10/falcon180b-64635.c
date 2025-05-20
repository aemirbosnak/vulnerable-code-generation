//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memory_usage;
};

int get_process_memory_usage(int pid) {
    FILE *fp;
    char filename[20];
    int memory_usage = 0;

    sprintf(filename, "/proc/%d/status", pid);
    fp = fopen(filename, "r");

    if (fp!= NULL) {
        char line[100];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (strstr(line, "VmSize:")!= NULL) {
                sscanf(line, "VmSize: %*s %d kB", &memory_usage);
                break;
            }
        }
        fclose(fp);
    }

    return memory_usage;
}

void print_processes(struct process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%s (PID: %d) is using %d KB of memory.\n", processes[i].name, processes[i].pid, processes[i].memory_usage);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *fp;
    char filename[20];
    char line[100];

    sprintf(filename, "/proc/self/status");
    fp = fopen(filename, "r");

    if (fp!= NULL) {
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (strstr(line, "Name:")!= NULL) {
                sscanf(line, "Name: %s", processes[num_processes].name);
            } else if (strstr(line, "Pid:")!= NULL) {
                sscanf(line, "Pid: %d", &processes[num_processes].pid);
            }
        }
        fclose(fp);
    }

    num_processes++;

    for (int i = 0; i < num_processes; i++) {
        processes[i].memory_usage = get_process_memory_usage(processes[i].pid);
    }

    print_processes(processes, num_processes);

    return 0;
}