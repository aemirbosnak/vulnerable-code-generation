//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int memory;
} process_t;

void get_process_info(process_t *processes, int count) {
    FILE *fp;
    char line[50];
    int i = 0;

    fp = popen("ps -eo 'pid,comm,vsz'", "r");

    if (fp == NULL) {
        printf("Error: Failed to execute ps command.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= count) {
            printf("Error: Too many processes.\n");
            exit(1);
        }

        sscanf(line, "%d %s %d", &processes[i].pid, processes[i].name, &processes[i].memory);
        i++;
    }

    pclose(fp);
}

void sort_processes(process_t *processes, int count) {
    int i, j;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (processes[j].memory > processes[i].memory) {
                process_t temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void print_processes(process_t *processes, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%-20s %10d %10d\n", processes[i].name, processes[i].pid, processes[i].memory);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count;

    printf("Enter the number of processes to monitor: ");
    scanf("%d", &count);

    if (count > MAX_PROCESSES || count <= 0) {
        printf("Error: Invalid number of processes.\n");
        exit(1);
    }

    get_process_info(processes, count);
    sort_processes(processes, count);
    print_processes(processes, count);

    return 0;
}