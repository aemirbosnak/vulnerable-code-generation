//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 20

struct process {
    char name[MAX_PROCESS_NAME];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int priority;
    int quantum;
    int remaining_time;
};

void *runner(void *param) {
    struct process *process = (struct process *) param;

    printf("Running process %s with burst time %d\n", process->name, process->burst_time);
    usleep(process->burst_time * 1000);

    return NULL;
}

int main() {
    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    struct process processes[MAX_PROCESSES];

    for (int i = 0; i < num_processes; i++) {
        printf("Enter process name: ");
        scanf("%s", processes[i].name);

        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);

        printf("Enter priority: ");
        scanf("%d", &processes[i].priority);

        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].quantum = 0;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &processes[0].quantum);

    for (int i = 0; i < num_processes; i++) {
        int j;
        for (j = 0; j < num_processes - 1 && processes[j].priority <= processes[j + 1].priority; j++);

        while (j > 0) {
            struct process temp = processes[j];
            processes[j] = processes[j - 1];
            processes[j - 1] = temp;
            j--;
        }
    }

    printf("Processes sorted by priority:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s (%d)\n", processes[i].name, processes[i].priority);
    }

    for (int i = 0; i < num_processes; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, runner, (void *) &processes[i]);
    }

    return 0;
}