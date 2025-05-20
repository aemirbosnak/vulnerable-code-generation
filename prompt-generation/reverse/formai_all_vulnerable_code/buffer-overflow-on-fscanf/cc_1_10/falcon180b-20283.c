//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 100

struct process {
    int pid;
    char name[MAX_PROCESS_NAME];
    int cpu_time;
    int start_time;
    int end_time;
};

int compare_processes(const void *a, const void *b) {
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;

    if (p1->cpu_time > p2->cpu_time) {
        return -1;
    } else if (p1->cpu_time < p2->cpu_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int i, j, k, n;
    FILE *fp;
    char filename[50] = "processes.txt";
    struct process processes[MAX_PROCESSES];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fscanf(fp, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(fp, "%d %s %d %d %d", &processes[i].pid, processes[i].name, &processes[i].cpu_time, &processes[i].start_time, &processes[i].end_time);
    }

    fclose(fp);

    qsort(processes, n, sizeof(struct process), compare_processes);

    printf("Process ID\tProcess Name\tCPU Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].cpu_time);
    }

    return 0;
}