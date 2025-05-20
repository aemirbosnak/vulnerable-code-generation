//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// A structure to store information about a process
typedef struct process {
    pid_t pid;
    char *name;
    char *state;
    int ppid;
    int priority;
    int start_time;
} process;

// A function to compare two processes based on their start time
int compare_processes(const void *a, const void *b) {
    const process *p1 = (const process *)a;
    const process *p2 = (const process *)b;

    return p1->start_time - p2->start_time;
}

int main() {
    // Get a list of all processes
    FILE *fp = popen("ps -eo pid,comm,state,ppid,pri,lstart", "r");
    if (fp == NULL) {
        perror("popen");
        return EXIT_FAILURE;
    }

    // Read the header line
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        pclose(fp);
        return EXIT_FAILURE;
    }

    // Read the process information
    int num_processes = 0;
    process *processes = NULL;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line
        pid_t pid;
        char *name;
        char *state;
        int ppid;
        int priority;
        int start_time;
        if (sscanf(line, "%d %s %s %d %d %d", &pid, &name, &state, &ppid, &priority, &start_time) != 6) {
            fprintf(stderr, "Error parsing line: %s", line);
            continue;
        }

        // Store the process information
        processes = realloc(processes, (num_processes + 1) * sizeof(process));
        processes[num_processes].pid = pid;
        processes[num_processes].name = strdup(name);
        processes[num_processes].state = strdup(state);
        processes[num_processes].ppid = ppid;
        processes[num_processes].priority = priority;
        processes[num_processes].start_time = start_time;

        num_processes++;
    }

    // Sort the processes by start time
    qsort(processes, num_processes, sizeof(process), compare_processes);

   
    for (int i = 0; i < num_processes; i++) {
      printf("--------------------------\n");
      printf("Process ID: %d\n", processes[i].pid);
      printf("Process Name: %s\n", processes[i].name);
      printf("Process State: %s\n", processes[i].state);
      printf("Parent Process ID: %d\n", processes[i].ppid);
      printf("Process Priority: %d\n", processes[i].priority);
      printf("Process Start Time: %d\n", processes[i].start_time);
    }
    
    // Clean up
    for (int i = 0; i < num_processes; i++) {
        free(processes[i].name);
        free(processes[i].state);
    }
    free(processes);
    pclose(fp);

    return EXIT_SUCCESS;
}