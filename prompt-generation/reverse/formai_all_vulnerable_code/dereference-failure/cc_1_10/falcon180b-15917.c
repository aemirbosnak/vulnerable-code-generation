//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: real-life
// This program demonstrates a simple process viewer in C.
// It uses the ps command to get a list of running processes,
// then displays their PID, name, and CPU usage.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 100
#define MAX_NAME_LENGTH 80

typedef struct {
    int pid;
    char name[MAX_NAME_LENGTH];
    float cpu_usage;
} Process;

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    int count = 0;
    Process processes[MAX_PROCESSES];

    // Open the ps command and read its output
    fp = popen("ps aux", "r");
    if (fp == NULL) {
        printf("Error: Failed to run ps command.\n");
        exit(1);
    }

    // Parse the ps output and store process info in an array
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_PROCESSES) {
            printf("Warning: Reached maximum number of processes.\n");
            break;
        }

        // Extract process ID, name, and CPU usage from the line
        token = strtok(line, " ");
        processes[count].pid = atoi(token);
        token = strtok(NULL, " ");
        strncpy(processes[count].name, token, MAX_NAME_LENGTH);
        processes[count].name[MAX_NAME_LENGTH - 1] = '\0';
        token = strtok(NULL, " ");
        processes[count].cpu_usage = atof(token);

        // Move to the next line
        count++;
    }

    // Close the ps command
    pclose(fp);

    // Print the process info
    printf("PID\tName\tCPU Usage\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }

    return 0;
}