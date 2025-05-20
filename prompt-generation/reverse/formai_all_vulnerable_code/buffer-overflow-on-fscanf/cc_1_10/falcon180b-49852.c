//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

// Process structure
typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
} Process;

// Function to get all running processes
void get_processes(Process* processes) {
    char command[100];
    sprintf(command, "ps -e | awk '{print $1,$NF}'");
    FILE* fp = popen(command, "r");
    if (!fp) {
        printf("Error: Failed to get processes.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%d %s", &processes[count].pid, processes[count].name)!= EOF) {
        count++;
        if (count == MAX_PROCESSES) {
            printf("Warning: Maximum number of processes reached.\n");
            break;
        }
    }

    pclose(fp);
}

// Function to display processes in a funny style
void display_processes(Process* processes, int count) {
    printf("Here are some processes running on your system:\n");
    for (int i = 0; i < count; i++) {
        printf("- PID %d: %s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;

    get_processes(processes);
    display_processes(processes, count);

    return 0;
}