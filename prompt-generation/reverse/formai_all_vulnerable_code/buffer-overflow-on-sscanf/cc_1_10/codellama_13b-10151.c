//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10

struct process_info {
    char name[20];
    int pid;
};

void get_process_info(struct process_info *processes, int num_processes) {
    int i;
    FILE *fp;
    char line[256];

    fp = popen("ps -ef", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (i = 0; i < num_processes; i++) {
        fgets(line, 256, fp);
        sscanf(line, "%s %d", processes[i].name, &processes[i].pid);
    }

    pclose(fp);
}

void print_process_info(struct process_info *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%s: %d\n", processes[i].name, processes[i].pid);
    }
}

int main() {
    struct process_info processes[MAX_PROCESSES];
    int num_processes = 0;

    get_process_info(processes, MAX_PROCESSES);
    num_processes = MAX_PROCESSES;
    print_process_info(processes, num_processes);

    return 0;
}