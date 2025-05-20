//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

struct Task {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void add_task(struct Task tasks[], int *num_tasks) {
    printf("Enter task name: ");
    scanf("%s", tasks[*num_tasks].name);
    printf("Enter task priority: ");
    scanf("%d", &tasks[*num_tasks].priority);
    printf("Enter task burst time: ");
    scanf("%d", &tasks[*num_tasks].burst_time);
    (*num_tasks)++;
}

int compare_priority(const void *a, const void *b) {
    struct Task *task_a = (struct Task *)a;
    struct Task *task_b = (struct Task *)b;

    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

void execute_task(struct Task tasks[], int num_tasks, int current_time) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].burst_time > current_time) {
            tasks[i].burst_time -= current_time;
            break;
        } else {
            tasks[i].burst_time = 0;
            tasks[i].waiting_time += current_time - tasks[i].burst_time;
            tasks[i].turnaround_time += current_time - tasks[i].waiting_time;
        }
    }
}

void print_tasks(struct Task tasks[], int num_tasks) {
    printf("Task Name\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

int main() {
    int num_tasks = 0;
    struct Task tasks[MAX_TASKS];

    add_task(tasks, &num_tasks);
    add_task(tasks, &num_tasks);
    add_task(tasks, &num_tasks);

    qsort(tasks, num_tasks, sizeof(struct Task), compare_priority);

    int current_time = 0;
    while (current_time < 100) {
        execute_task(tasks, num_tasks, current_time);
        current_time += 1;
    }

    print_tasks(tasks, num_tasks);

    return 0;
}