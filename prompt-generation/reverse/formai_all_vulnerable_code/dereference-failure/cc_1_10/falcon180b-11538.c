//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct process {
    char name[20];
    int pid;
    int ram_usage;
} Process;

int get_process_info(Process *processes, int count, int *total_ram_usage) {
    FILE *fp;
    char line[256];
    char *token;
    int i = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_PROCESSES) {
            break;
        }

        token = strtok(line, ":");
        strcpy(processes[i].name, token);

        token = strtok(NULL, ":");
        processes[i].pid = atoi(token);

        token = strtok(NULL, ":");
        processes[i].ram_usage = atoi(token);

        i++;
    }

    fclose(fp);

    *total_ram_usage = 0;

    for (int j = 0; j < i; j++) {
        *total_ram_usage += processes[j].ram_usage;
    }

    return i;
}

void print_process_info(Process *processes, int count) {
    printf("Process ID\tProcess Name\tRAM Usage\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d KB\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int total_ram_usage;
    int process_count;

    process_count = get_process_info(processes, MAX_PROCESSES, &total_ram_usage);

    printf("Total RAM usage by all processes: %d KB\n", total_ram_usage);

    print_process_info(processes, process_count);

    return 0;
}