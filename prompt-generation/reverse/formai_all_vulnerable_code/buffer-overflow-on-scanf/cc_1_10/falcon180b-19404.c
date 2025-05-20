//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_TASKS 10

typedef struct {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void execute_task(Task *task) {
    printf("Executing task %s...\n", task->name);
    sleep(task->burst_time);
}

void schedule_tasks(Task tasks[], int num_tasks) {
    int i, j;
    for (i = 0; i < num_tasks; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("Scheduling tasks:\n");
    for (i = 0; i < num_tasks; i++) {
        printf("Task %s has priority %d\n", tasks[i].name, tasks[i].priority);
    }

    for (i = 0; i < num_tasks; i++) {
        execute_task(&tasks[i]);
    }
}

void main() {
    int i, num_tasks;
    Task tasks[MAX_TASKS];

    printf("Enter the number of tasks (max %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (i = 0; i < num_tasks; i++) {
        printf("Enter task %d name: ", i + 1);
        scanf("%s", tasks[i].name);
        printf("Enter task %d priority: ", i + 1);
        scanf("%d", &tasks[i].priority);
        printf("Enter task %d burst time: ", i + 1);
        scanf("%d", &tasks[i].burst_time);
    }

    schedule_tasks(tasks, num_tasks);
}