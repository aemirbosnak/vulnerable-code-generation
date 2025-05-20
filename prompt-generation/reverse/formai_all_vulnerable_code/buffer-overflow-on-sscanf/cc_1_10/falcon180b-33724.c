//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

struct process {
    char name[50];
    int pid;
    int memory;
};

void get_processes(struct process* processes) {
    FILE* fp;
    char line[100];
    int count = 0;

    fp = popen("ps -x -o \"pid= %%p,comm= %%c,rsz= %%mem\"", "r");

    if (fp == NULL) {
        printf("Error: Failed to run ps command\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_PROCESSES) {
            break;
        }

        sscanf(line, "%s %d %d", processes[count].name, &processes[count].pid, &processes[count].memory);
        count++;
    }

    pclose(fp);
}

void sort_processes(struct process* processes) {
    int i, j;
    struct process temp;

    for (i = 0; i < MAX_PROCESSES - 1; i++) {
        for (j = i + 1; j < MAX_PROCESSES; j++) {
            if (processes[j].memory > processes[i].memory) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void print_processes(struct process* processes) {
    int i;

    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("%-10s %5d %10d KB\n", processes[i].name, processes[i].pid, processes[i].memory);
    }
}

int main(int argc, char* argv[]) {
    struct process processes[MAX_PROCESSES];

    get_processes(processes);
    sort_processes(processes);
    print_processes(processes);

    return 0;
}