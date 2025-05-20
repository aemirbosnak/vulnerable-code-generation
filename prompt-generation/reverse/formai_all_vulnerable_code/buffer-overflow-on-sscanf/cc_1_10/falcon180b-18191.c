//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

typedef struct {
    char name[64];
    int pid;
    int ram_usage;
} Process;

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int total_ram_usage = 0;
    char line[4096];
    char name[64];
    int pid;
    int ram_usage;
    FILE *fp;

    // Get list of running processes
    fp = fopen("/proc/self/task/", "r");
    if (fp == NULL) {
        printf("Error: failed to open /proc/self/task/\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "%d %s\n", &pid, name) == 2) {
            strcpy(processes[num_processes].name, name);
            processes[num_processes].pid = pid;
            processes[num_processes].ram_usage = 0;
            num_processes++;
        }
    }

    fclose(fp);

    // Get RAM usage for each process
    while (1) {
        for (int i = 0; i < num_processes; i++) {
            snprintf(line, sizeof(line), "/proc/%d/statm", processes[i].pid);
            fp = fopen(line, "r");
            if (fp == NULL) {
                printf("Error: failed to open %s\n", line);
                exit(1);
            }

            if (fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %d", &ram_usage) == 1) {
                processes[i].ram_usage = ram_usage;
                total_ram_usage += ram_usage;
            }

            fclose(fp);
        }

        usleep(100000); // Sleep for 100ms
    }

    return 0;
}