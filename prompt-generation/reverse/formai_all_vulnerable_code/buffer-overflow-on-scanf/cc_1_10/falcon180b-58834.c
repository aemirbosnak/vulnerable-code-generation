//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_TASKS 100

typedef struct {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_TASKS];
int num_processes = 0;

void *runner(void *arg) {
    int i = *(int *) arg;
    Process *p = &processes[i];

    printf("Process %d started\n", p->id);
    sleep(p->burst_time);
    printf("Process %d completed\n", p->id);

    return NULL;
}

int main() {
    int i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        printf("Enter process %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &processes[i].id);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    for (i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < num_processes; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].priority > processes[j].priority) {
                int temp = processes[i].priority;
                processes[i].priority = processes[j].priority;
                processes[j].priority = temp;
            }
        }
    }

    int quantum = 2;
    int current_time = 0;
    int completed_processes = 0;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    while (completed_processes < num_processes) {
        int i = 0;
        while (i < num_processes && processes[i].burst_time > current_time) {
            i++;
        }

        if (i == num_processes) {
            current_time += quantum;
            continue;
        }

        int j = i;
        while (j < num_processes && processes[j].burst_time <= current_time) {
            if (processes[j].waiting_time > 0) {
                current_time += processes[j].waiting_time;
                processes[j].waiting_time = 0;
            } else {
                pthread_t thread_id;
                pthread_create(&thread_id, NULL, runner, &j);
                current_time += processes[j].burst_time;
                processes[j].turnaround_time = current_time - processes[j].burst_time - processes[j].waiting_time;
                total_turnaround_time += processes[j].turnaround_time;
                total_waiting_time += processes[j].waiting_time;
                completed_processes++;
            }
            j++;
        }
    }

    printf("\nAverage turnaround time: %.2f\n", (float) total_turnaround_time / num_processes);
    printf("Average waiting time: %.2f\n", (float) total_waiting_time / num_processes);

    return 0;
}