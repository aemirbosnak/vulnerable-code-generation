//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    char* name;
    int priority;
    int period;
    int burst_time;
    int remaining_burst_time;
    int start_time;
    int end_time;
} Task;

void* task_runner(void* arg) {
    Task* task = (Task*) arg;

    int time_quantum = 3;
    int current_time = 0;

    while (current_time < task->end_time) {
        if (task->remaining_burst_time > time_quantum) {
            task->remaining_burst_time -= time_quantum;
            current_time += time_quantum;
        } else {
            task->remaining_burst_time = 0;
            current_time += task->remaining_burst_time;
        }

        printf("Task %d (%s) is running from %d to %d\n", task->id, task->name, task->start_time, task->end_time);
        fflush(stdout);

        sleep(1);
    }

    pthread_exit(0);
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter the details for task %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    int current_time = 0;

    while (current_time < 100) {
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].start_time == current_time && tasks[i].remaining_burst_time > 0) {
                pthread_t thread_id;
                pthread_create(&thread_id, NULL, task_runner, &tasks[i]);
            }
        }

        current_time++;

        sleep(1);
    }

    return 0;
}