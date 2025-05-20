//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PROCESS_ID_LENGTH 10

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    char id[MAX_PROCESS_ID_LENGTH];
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tNAME\tID\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%s\n", processes[i].pid, processes[i].name, processes[i].id);
    }
}

int get_processes(Process *processes, int max_processes) {
    FILE *fp;
    char filename[MAX_COMMAND_LENGTH] = "/proc/self/task";
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/task\n");
        return -1;
    }

    while (count < max_processes && fscanf(fp, "%d %s %s", &processes[count].pid, processes[count].name, processes[count].id)!= EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

int main(int argc, char *argv[]) {
    Process processes[MAX_PROCESSES];
    int num_processes = get_processes(processes, MAX_PROCESSES);

    if (num_processes < 0) {
        return -1;
    }

    print_processes(processes, num_processes);

    return 0;
}