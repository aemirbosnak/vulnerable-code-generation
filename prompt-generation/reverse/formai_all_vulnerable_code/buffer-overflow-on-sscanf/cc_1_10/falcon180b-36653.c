//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_PROCESSES 50

typedef struct {
    pid_t pid;
    char name[20];
    float cpu_usage;
    float mem_usage;
} process;

void get_processes(process* procs, int* num_procs) {
    FILE* fp;
    char line[1024];
    char name[20];
    pid_t pid;
    float cpu_usage = 0.0;
    float mem_usage = 0.0;
    int i = 0;

    *num_procs = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "cpu %d %s %f %f", &pid, name, &cpu_usage, &mem_usage) == 4) {
            procs[*num_procs].pid = pid;
            strncpy(procs[*num_procs].name, name, sizeof(procs[*num_procs].name));
            procs[*num_procs].cpu_usage = cpu_usage;
            procs[*num_procs].mem_usage = mem_usage;
            (*num_procs)++;
        }
    }

    fclose(fp);
}

void print_processes(process* procs, int num_procs) {
    int i;

    printf("PID\tName\tCPU%\tMEM%\n");
    for (i = 0; i < num_procs; i++) {
        printf("%d\t%s\t%.2f\t%.2f\n", procs[i].pid, procs[i].name, procs[i].cpu_usage, procs[i].mem_usage);
    }
}

int main() {
    process procs[MAX_PROCESSES];
    int num_procs = 0;

    get_processes(procs, &num_procs);
    print_processes(procs, num_procs);

    return 0;
}