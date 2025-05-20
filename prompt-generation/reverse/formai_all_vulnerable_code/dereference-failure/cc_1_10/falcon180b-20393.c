//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 256

typedef struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
} process_t;

void read_processes(process_t processes[MAX_PROCESSES]) {
    char proc_file[MAX_PROCESS_NAME_LENGTH];
    sprintf(proc_file, "/proc/%d/cmdline", getpid());

    FILE *fp = fopen(proc_file, "r");
    if (fp == NULL) {
        printf("Error opening %s\n", proc_file);
        exit(1);
    }

    char buffer[MAX_PROCESS_NAME_LENGTH];
    fgets(buffer, MAX_PROCESS_NAME_LENGTH, fp);
    strcpy(processes[0].name, buffer);

    int count = 1;
    while (count < MAX_PROCESSES) {
        sprintf(proc_file, "/proc/%d/cmdline", count);

        FILE *fp = fopen(proc_file, "r");
        if (fp == NULL) {
            printf("Error opening %s\n", proc_file);
            exit(1);
        }

        char buffer[MAX_PROCESS_NAME_LENGTH];
        fgets(buffer, MAX_PROCESS_NAME_LENGTH, fp);
        strcpy(processes[count].name, buffer);

        fclose(fp);
        count++;
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    read_processes(processes);

    printf("Process Name\tPID\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%s\t%d\n", processes[i].name, processes[i].pid);
    }

    return 0;
}