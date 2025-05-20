//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int completed;
} process;

int compare_processes(const void *a, const void *b) {
    process *p1 = (process *) a;
    process *p2 = (process *) b;
    return p1->arrival_time - p2->arrival_time;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process *processes = (process *) malloc(n * sizeof(process));

    for (int i = 0; i < n; i++) {
        processes[i].name = (char *) malloc(100 * sizeof(char));
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
    }

    qsort(processes, n, sizeof(process), compare_processes);

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        int next_process = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].completed == 0) {
                if (next_process == -1 || processes[i].priority < processes[next_process].priority) {
                    next_process = i;
                }
            }
        }

        if (next_process == -1) {
            current_time++;
            continue;
        }

        processes[next_process].remaining_time--;
        current_time++;

        if (processes[next_process].remaining_time == 0) {
            processes[next_process].completed = 1;
            completed_processes++;
        }
    }

    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].arrival_time + processes[i].burst_time);
    }

    return 0;
}