//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[20];
    int pid;
    int status;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    FILE *fp;
    char line[100];
    char *token;

    // Open the process status file
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat.\n");
        exit(1);
    }

    // Read the number of processes
    fgets(line, 100, fp);
    sscanf(line, "cpu %d %d %d %d", &processes[num_processes].pid, &processes[num_processes].pid, &processes[num_processes].pid, &processes[num_processes].pid);
    num_processes++;

    // Read each process
    while (fgets(line, 100, fp)!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            break;
        }

        token = strtok(line, " ");
        strcpy(processes[num_processes].name, token);
        sscanf(token, "%d", &processes[num_processes].pid);
        processes[num_processes].status = 1;
        num_processes++;
    }

    fclose(fp);

    // Print the process list
    printf("Process List:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s (%d)\n", processes[i].name, processes[i].pid);
    }

    return 0;
}