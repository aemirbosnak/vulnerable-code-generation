//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

struct process {
    int pid;
    char name[16];
    int ram_usage;
};

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    char command[32];
    FILE *fp;

    // Read the list of running processes
    fp = popen("ps -e -o pid= -o comm=", "r");
    if (fp == NULL) {
        printf("Error: Failed to read process list.\n");
        return 1;
    }

    // Parse the process list
    while (fscanf(fp, "%d %s", &processes[num_processes].pid, processes[num_processes].name)!= EOF) {
        num_processes++;
        if (num_processes >= MAX_PROCESSES) {
            break;
        }
    }

    // Close the process list
    pclose(fp);

    // Initialize RAM usage to zero
    for (int i = 0; i < num_processes; i++) {
        processes[i].ram_usage = 0;
    }

    // Monitor RAM usage
    while (1) {
        for (int i = 0; i < num_processes; i++) {
            sprintf(command, "cat /proc/%d/statm | awk '{print $2}'", processes[i].pid);
            fp = popen(command, "r");
            if (fp!= NULL) {
                fscanf(fp, "%d", &processes[i].ram_usage);
                pclose(fp);
            }
        }

        // Print RAM usage
        printf("\nRAM usage (KB):\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%s: %d\n", processes[i].name, processes[i].ram_usage);
        }

        // Wait for 5 seconds before updating again
        sleep(5);
    }

    return 0;
}