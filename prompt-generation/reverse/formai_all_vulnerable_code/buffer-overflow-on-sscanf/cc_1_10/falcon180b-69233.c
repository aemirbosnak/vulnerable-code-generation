//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[16];
    long int rss;
} Process;

void getProcesses(Process *processes, int *numProcesses) {
    FILE *fp;
    char line[1024];
    int count = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "VmRSS:", 7) == 0) {
            sscanf(line, "VmRSS: %ld kB", &processes[count].rss);
        } else if (strncmp(line, "Name:", 5) == 0) {
            strncpy(processes[count].name, line + 6, sizeof(processes[count].name) - 1);
            processes[count].name[sizeof(processes[count].name) - 1] = '\0';
        }
    }

    fclose(fp);

    *numProcesses = count + 1;
}

int main() {
    Process processes[MAX_PROCESSES];
    int numProcesses;

    getProcesses(processes, &numProcesses);

    printf("Process ID\tName\t\tRSS\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%s\t%ld kB\n", processes[i].pid, processes[i].name, processes[i].rss);
    }

    return 0;
}