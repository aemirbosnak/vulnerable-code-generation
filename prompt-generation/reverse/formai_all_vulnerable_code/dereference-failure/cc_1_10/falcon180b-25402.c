//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 80

typedef struct {
    char name[MAX_LINE_LENGTH];
    int pid;
    int mem_usage;
} process_t;

int compare_processes(const void *a, const void *b) {
    const process_t *p1 = a;
    const process_t *p2 = b;

    if (p1->mem_usage > p2->mem_usage) {
        return -1;
    } else if (p1->mem_usage < p2->mem_usage) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    char *saveptr;
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok_r(line, ":", &saveptr);
        if (token!= NULL) {
            if (strcmp(token, "VmSize:") == 0) {
                processes[num_processes].mem_usage = atoi(strtok_r(NULL, " ", &saveptr)) * 1024;
                strncpy(processes[num_processes].name, "RAM Monitor", MAX_LINE_LENGTH);
                processes[num_processes].pid = getpid();
                num_processes++;
            }
        }
    }

    fclose(fp);

    qsort(processes, num_processes, sizeof(process_t), compare_processes);

    printf("RAM Usage Monitor:\n");
    printf("-------------------\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-20s %-10d KB\n", processes[i].name, processes[i].mem_usage);
    }

    return 0;
}