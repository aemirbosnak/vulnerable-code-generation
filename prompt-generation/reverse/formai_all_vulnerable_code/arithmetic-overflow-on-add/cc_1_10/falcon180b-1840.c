//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct task {
    int id;
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void add_task(Task tasks[], int *num_tasks) {
    printf("Enter task ID: ");
    scanf("%d", &tasks[*num_tasks].id);
    printf("Enter task name: ");
    scanf("%s", tasks[*num_tasks].name);
    printf("Enter task priority: ");
    scanf("%d", &tasks[*num_tasks].priority);
    printf("Enter task burst time: ");
    scanf("%d", &tasks[*num_tasks].burst_time);
    (*num_tasks)++;
}

void display_tasks(Task tasks[], int num_tasks) {
    printf("\nTask ID\tTask Name\tPriority\tBurst Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t%d\t%d\n", tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].burst_time);
    }
}

void execute_tasks(Task tasks[], int num_tasks) {
    int completed_tasks = 0;
    while (completed_tasks < num_tasks) {
        int min_burst_time = tasks[0].burst_time;
        int min_index = 0;
        for (int i = 1; i < num_tasks; i++) {
            if (tasks[i].burst_time < min_burst_time) {
                min_burst_time = tasks[i].burst_time;
                min_index = i;
            }
        }
        if (min_burst_time > 0) {
            tasks[min_index].burst_time -= 1;
            completed_tasks++;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        add_task(tasks, &num_tasks);
    }

    display_tasks(tasks, num_tasks);

    execute_tasks(tasks, num_tasks);

    return 0;
}