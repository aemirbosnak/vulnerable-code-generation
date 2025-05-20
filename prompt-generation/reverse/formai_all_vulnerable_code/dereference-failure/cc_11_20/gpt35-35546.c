//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PROCS 2048
#define BUF_SIZE 1024

struct Process {
    char name[256];
    int pid;
    char state;
    int memory;
};

struct Process processes[MAX_PROCS];

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[BUF_SIZE];

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    int i = 0;
    // Iterate through all the entries in the directory
    while ((ent = readdir(dir)) != NULL && i < MAX_PROCS) {
        // Only process directories with numeric names
        if (isdigit(*ent->d_name)) {
            // Construct the path to the process status file
            snprintf(path, BUF_SIZE, "/proc/%s/status", ent->d_name);

            // Open the status file
            FILE *f = fopen(path, "r");
            if (f == NULL) {
                // Ignore processes that have since terminated
                continue;
            }

            // Parse the name and state from the status file
            char line[BUF_SIZE];
            while (fgets(line, BUF_SIZE, f) != NULL) {
                if (strncmp(line, "Name:", 5) == 0) {
                    strncpy(processes[i].name, line + 6, 255);
                    processes[i].name[255] = '\0';
                } else if (strncmp(line, "State:", 6) == 0) {
                    processes[i].state = *(line + 7);
                } else if (strncmp(line, "VmRSS:", 6) == 0) {
                    // Parse the memory usage (in kilobytes)
                    int value;
                    sscanf(line + 7, "%d", &value);
                    processes[i].memory = value;
                }
            }

            // Close the status file
            fclose(f);

            // Save the process ID
            processes[i].pid = atoi(ent->d_name);

            ++i;
        }
    }

    // Close the directory
    closedir(dir);

    // Sort the processes by memory usage (descending)
    int num_procs = i;
    for (i = 0; i < num_procs; ++i) {
        int max_index = i;
        for (int j = i + 1; j < num_procs; ++j) {
            if (processes[j].memory > processes[max_index].memory) {
                max_index = j;
            }
        }
        struct Process temp = processes[i];
        processes[i] = processes[max_index];
        processes[max_index] = temp;
    }

    // Output the process list
    printf(" PID  STATE  MEMORY  NAME\n");
    printf("----  -----  ------  ----\n");
    for (i = 0; i < num_procs; ++i) {
        printf("%4d  %c      %5dKB  %s", processes[i].pid, processes[i].state, processes[i].memory, processes[i].name);
    }

    return 0;
}