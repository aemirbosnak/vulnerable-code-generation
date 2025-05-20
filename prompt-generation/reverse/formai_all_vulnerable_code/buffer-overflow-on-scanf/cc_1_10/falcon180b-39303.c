//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void execute_task(Task *task) {
    printf("Executing task %d (%s) with priority %d\n", task->id, task->name, task->priority);
    fflush(stdout);
    sleep(task->burst_time);
}

void schedule_tasks(Task *tasks, int num_tasks) {
    int i, j, completed_tasks = 0;
    Task *current_task;

    for (i = 0; i < num_tasks; i++) {
        current_task = &tasks[i];
        printf("Task %d (%s) arrived with priority %d and burst time %d\n", current_task->id, current_task->name, current_task->priority, current_task->burst_time);
        fflush(stdout);

        // Find the appropriate position to insert the task
        for (j = 0; j < completed_tasks; j++) {
            if (tasks[j].priority > current_task->priority) {
                break;
            }
        }

        // Shift tasks to the right
        for (int k = completed_tasks; k > j; k--) {
            tasks[k] = tasks[k-1];
        }

        // Insert the new task
        tasks[j] = *current_task;

        // Execute the task
        execute_task(current_task);

        // Update the completed tasks count
        completed_tasks++;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter the number of tasks (up to %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    printf("Enter the task details:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    schedule_tasks(tasks, num_tasks);

    return 0;
}