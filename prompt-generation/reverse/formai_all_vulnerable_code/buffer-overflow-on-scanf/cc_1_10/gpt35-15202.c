//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

/*
    A unique CPU scheduling algorithm that sorts processes based on their process ID and burst time.
    The algorithm selects the process that has the lowest process ID and burst time, and executes it.
    If there is a tie in burst time, the process with the lowest process ID is selected.
*/

struct Process {
    int pid; // process ID
    int burst_time; // CPU burst time
};

void sort(struct Process* procs, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (procs[i].burst_time > procs[j].burst_time || (procs[i].burst_time == procs[j].burst_time && procs[i].pid > procs[j].pid)) {
                // swap processes
                struct Process temp = procs[i];
                procs[i] = procs[j];
                procs[j] = temp;
            }
        }
    }
}

int main() {
    int n; // number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // allocate memory for array of processes
    struct Process* procs = (struct Process*)malloc(n * sizeof(struct Process));

    // get process ID and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter the process ID and burst time for process %d: ", i+1);
        scanf("%d%d", &procs[i].pid, &procs[i].burst_time);
    }

    // sort the processes
    sort(procs, n);

    // execute the processes
    for (int i = 0; i < n; i++) {
        printf("Executing process %d with burst time %d\n", procs[i].pid, procs[i].burst_time);
    }

    // free memory
    free(procs);

    return 0;
}