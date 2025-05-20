//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

struct task {
    int id;
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void add_task(struct task tasks[], int *size) {
    printf("Enter task ID: ");
    scanf("%d", &tasks[*size].id);

    printf("Enter task name: ");
    scanf("%s", tasks[*size].name);

    printf("Enter task priority (1-10): ");
    scanf("%d", &tasks[*size].priority);

    printf("Enter task burst time: ");
    scanf("%d", &tasks[*size].burst_time);

    (*size)++;
}

void print_tasks(struct task tasks[], int size) {
    printf("Task ID\tTask Name\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

void execute_tasks(struct task tasks[], int size) {
    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < size) {
        int min_burst_time = tasks[0].burst_time;
        int min_index = 0;

        for (int i = 1; i < size; i++) {
            if (tasks[i].burst_time < min_burst_time) {
                min_burst_time = tasks[i].burst_time;
                min_index = i;
            }
        }

        if (current_time >= min_burst_time) {
            tasks[min_index].turnaround_time = current_time - tasks[min_index].waiting_time + tasks[min_index].burst_time;
            tasks[min_index].waiting_time = 0;
            completed_tasks++;
        } else {
            tasks[min_index].waiting_time += current_time;
            current_time += tasks[min_index].burst_time;
        }
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int size = 0;

    add_task(tasks, &size);
    add_task(tasks, &size);
    add_task(tasks, &size);

    print_tasks(tasks, size);

    execute_tasks(tasks, size);

    return 0;
}