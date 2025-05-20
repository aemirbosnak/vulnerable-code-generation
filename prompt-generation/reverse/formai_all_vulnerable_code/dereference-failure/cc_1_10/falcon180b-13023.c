//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define MAX_PROCESSES 1024

typedef struct process {
    int pid;
    char name[16];
    int memory;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void update_processes() {
    FILE *file;
    char line[1024];
    char *token;
    int i;

    file = popen("ps axo pid,comm,%mem", "r");

    if (file == NULL) {
        printf("Error: Failed to run 'ps' command.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, " ");
        processes[num_processes].pid = atoi(token);
        strncpy(processes[num_processes].name, strtok(NULL, " "), 15);
        processes[num_processes].memory = atoi(strtok(NULL, " "));
        num_processes++;
    }

    pclose(file);
}

void sort_processes() {
    int i, j;
    Process temp;

    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[j].memory > processes[i].memory) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void print_processes() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-5d %-15s %-10d%%\n", processes[i].pid, processes[i].name, processes[i].memory);
    }
}

int main() {
    int i;

    update_processes();
    sort_processes();

    printf("PID\tName\tMemory Usage (%)\n");
    print_processes();

    return 0;
}