//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    int memory_usage;
} Process;

int main() {
    FILE* fp;
    char line[1024];
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    int total_memory_usage = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            sscanf(line, "VmSize: %d kB", &processes[num_processes].memory_usage);
            num_processes++;
        }
    }

    fclose(fp);

    if (num_processes == 0) {
        printf("No processes found.\n");
        return 0;
    }

    printf("Process\t\tMemory Usage (KB)\n");
    printf("------------------------------------------------------\n");

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(processes[0].name, line + 6);
        } else if (strncmp(line, "Pid:", 4) == 0) {
            sscanf(line, "Pid: %d", &processes[0].pid);
        }
    }

    fclose(fp);

    for (int i = 0; i < num_processes; i++) {
        printf("%s\t\t%d\n", processes[i].name, processes[i].memory_usage);
        total_memory_usage += processes[i].memory_usage;
    }

    printf("\nTotal memory usage: %d KB\n", total_memory_usage);

    return 0;
}