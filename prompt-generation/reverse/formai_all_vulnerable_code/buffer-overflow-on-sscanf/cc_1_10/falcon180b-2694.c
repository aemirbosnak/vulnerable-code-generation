//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    char name[16];
    int ram_usage;
};

void update_processes() {
    FILE *fp;
    char filename[32];
    char line[64];
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    sprintf(filename, "/proc/self/status");
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening /proc/self/status\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "VmSize: %d kB", &processes[num_processes].ram_usage) == 1) {
            num_processes++;
        }
    }

    fclose(fp);

    if (num_processes == 0) {
        printf("No processes found\n");
        return;
    }

    sprintf(filename, "/proc/%d/status", getpid());
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening /proc/%d/status\n", getpid());
        return;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "Name: %15s", processes[num_processes - 1].name) == 1) {
            break;
        }
    }

    fclose(fp);

    printf("Process ID\tName\tRAM Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

int main() {
    while (1) {
        update_processes();
        sleep(5);
    }

    return 0;
}