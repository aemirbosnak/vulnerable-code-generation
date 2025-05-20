//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct task {
    int id;
    int priority;
    int execution_time;
    int waiting_time;
    int turnaround_time;
} Task;

void execute_task(Task *task) {
    printf("Executing task %d with priority %d\n", task->id, task->priority);
    sleep(task->execution_time);
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter task IDs and priorities:\n");
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i + 1;
        printf("Task %d priority: ", tasks[i].id);
        scanf("%d", &tasks[i].priority);
    }

    printf("Enter task execution times:\n");
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].execution_time = rand() % 10 + 1;
        printf("Task %d execution time: %d\n", tasks[i].id, tasks[i].execution_time);
    }

    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        int min_priority = MAX_PRIORITY;
        int min_index = -1;

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].priority <= min_priority && tasks[i].waiting_time == 0) {
                min_priority = tasks[i].priority;
                min_index = i;
            }
        }

        if (min_index!= -1) {
            tasks[min_index].waiting_time = 0;
            tasks[min_index].turnaround_time = current_time - tasks[min_index].waiting_time;
            execute_task(&tasks[min_index]);
            completed_tasks++;
        } else {
            current_time++;
        }
    }

    return 0;
}