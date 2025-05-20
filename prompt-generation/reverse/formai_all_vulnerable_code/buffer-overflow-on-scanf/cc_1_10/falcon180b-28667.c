//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <time.h>

#define NUM_TASKS 5
#define STACK_SIZE 8192

struct task {
    int task_id;
    char task_name[20];
    int priority;
    int time_slice;
    int total_time;
    int remaining_time;
    int start_time;
    int end_time;
    int burst_time[10];
    int waiting_time;
    int turnaround_time;
};

void execute_task(int task_id) {
    printf("Executing task %d\n", task_id);
    sleep(1);
}

int main() {
    int i;
    struct task tasks[NUM_TASKS];

    for (i = 0; i < NUM_TASKS; i++) {
        printf("Enter task name for task %d: ", i+1);
        scanf("%s", tasks[i].task_name);
        printf("Enter priority for task %s: ", tasks[i].task_name);
        scanf("%d", &tasks[i].priority);
        printf("Enter time slice for task %s: ", tasks[i].task_name);
        scanf("%d", &tasks[i].time_slice);
        printf("Enter total time for task %s: ", tasks[i].task_name);
        scanf("%d", &tasks[i].total_time);
        tasks[i].remaining_time = tasks[i].total_time;
        tasks[i].start_time = time(NULL);
        tasks[i].end_time = tasks[i].start_time + tasks[i].total_time;
        tasks[i].burst_time[0] = tasks[i].time_slice;
    }

    int quantum = 2;
    int current_task = 0;
    int completed_tasks = 0;

    while (completed_tasks < NUM_TASKS) {
        if (tasks[current_task].remaining_time > quantum) {
            tasks[current_task].remaining_time -= quantum;
            execute_task(current_task+1);
        } else {
            tasks[current_task].remaining_time = 0;
            completed_tasks++;
            current_task = (current_task+1) % NUM_TASKS;
        }
    }

    printf("All tasks completed.\n");

    return 0;
}