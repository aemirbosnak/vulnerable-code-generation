//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[MAX_LINE_LENGTH];
    int pid;
} process_t;

int main() {
    char proc_file[MAX_LINE_LENGTH];
    FILE *proc_fp;
    char line[MAX_LINE_LENGTH];
    process_t *processes = malloc(MAX_PROCESSES * sizeof(process_t));
    int num_processes = 0;

    sprintf(proc_file, "/proc/");

    proc_fp = fopen(proc_file, "r");

    if (proc_fp == NULL) {
        printf("Error: Could not open /proc directory.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, proc_fp)!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: Maximum number of processes reached.\n");
            break;
        }

        if (line[0]!= '.') {
            int i = 0;
            while (line[i]!= '\t' && line[i]!= '\n') {
                processes[num_processes].name[i] = line[i];
                i++;
            }
            processes[num_processes].name[i] = '\0';
            processes[num_processes].pid = atoi(line + i + 1);
            num_processes++;
        }
    }

    fclose(proc_fp);

    printf("Process ID\tProcess Name\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }

    free(processes);

    return 0;
}