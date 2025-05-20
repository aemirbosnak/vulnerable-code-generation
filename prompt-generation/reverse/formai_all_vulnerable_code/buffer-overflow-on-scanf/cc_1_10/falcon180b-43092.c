//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_TASKS 10

typedef struct task {
    int id;
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void execute_task(Task *task) {
    printf("Executing task %d: %s\n", task->id, task->name);
    printf("Burst time: %d\n", task->burst_time);
    printf("Waiting time: %d\n", task->waiting_time);
    printf("Turnaround time: %d\n", task->turnaround_time);
}

int compare_priority(const void *a, const void *b) {
    Task *task1 = (Task *)a;
    Task *task2 = (Task *)b;
    return task1->priority - task2->priority;
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks, i;

    printf("Enter the number of tasks (up to %d):\n", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (i = 0; i < num_tasks; i++) {
        printf("Enter task %d information:\n", i+1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    printf("\nTask ID\tTask Name\tPriority\tBurst Time\n");
    for (i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t%d\t%d\n", tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].burst_time);
    }

    return 0;
}