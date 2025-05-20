//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 100

struct process {
    pid_t pid;
    char name[256];
    int state;
    int ppid;
    time_t start_time;
};

int compare_processes(const void *a, const void *b) {
    struct process *process_a = (struct process *)a;
    struct process *process_b = (struct process *)b;

    return strcmp(process_a->name, process_b->name);
}

int main(int argc, char **argv) {
    // Get the list of processes
    FILE *f = fopen("/proc", "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read the list of processes into an array
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    while (fscanf(f, "%d %s %d %d %d %d %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
                  &processes[num_processes].pid,
                  processes[num_processes].name,
                  &processes[num_processes].state,
                  &processes[num_processes].ppid,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time,
                  &processes[num_processes].start_time) != EOF) {
        num_processes++;
    }
    fclose(f);

    // Sort the list of processes by name
    qsort(processes, num_processes, sizeof(struct process), compare_processes);

    // Print the list of processes
    for (int i = 0; i < num_processes; i++) {
        printf("%d %s\n", processes[i].pid, processes[i].name);
    }

    return 0;
}