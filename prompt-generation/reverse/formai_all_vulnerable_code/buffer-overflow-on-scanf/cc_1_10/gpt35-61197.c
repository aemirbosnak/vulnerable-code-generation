//FormAI DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} task;

int n;
task tasks[100];

void swap(task *a, task *b) {
    task temp = *a;
    *a = *b;
    *b = temp;
}

void sort_tasks_by_priority() {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(tasks[j].priority > tasks[i].priority) {
                swap(&tasks[j], &tasks[i]);
            }
        }
    }
}

void execute_task(task t) {
    printf("Executing task %d with priority %d...\n", t.id, t.priority);
    sleep(t.burst_time);
    printf("Task %d completed execution.\n", t.id);
    t.completion_time = time(NULL);
    t.turnaround_time = t.completion_time - t.arrival_time;
    t.waiting_time = t.turnaround_time - t.burst_time;
}

void schedule_tasks() {
    sort_tasks_by_priority();
    for(int i=0; i<n; i++) {
        execute_task(tasks[i]);
    }
}

int main() {
    printf("Enter the number of tasks to schedule: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter the arrival time for task %d: ", i+1);
        scanf("%d", &tasks[i].arrival_time);
        printf("Enter the burst time for task %d: ", i+1);
        scanf("%d", &tasks[i].burst_time);
        printf("Enter the priority (higher is better) for task %d: ", i+1);
        scanf("%d", &tasks[i].priority);
        tasks[i].id = i+1;
    }
    printf("Scheduling tasks...\n");
    schedule_tasks();
    printf("Task scheduling complete.\n");
    // calculate average waiting time and turnaround time
    int total_waiting_time = 0, total_turnaround_time = 0;
    for(int i=0; i<n; i++) {
        total_waiting_time += tasks[i].waiting_time;
        total_turnaround_time += tasks[i].turnaround_time;
    }
    printf("Average waiting time: %lf\n", (double)total_waiting_time / n);
    printf("Average turnaround time: %lf\n", (double)total_turnaround_time / n);
    return 0;
}