//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int priority;
    int period;
    int deadline;
    int burst;
    int quantum;
    int remaining_time;
} Task;

void *run_task(void *arg) {
    Task *task = (Task *) arg;
    int quantum = task->quantum;
    int remaining_time = task->remaining_time;
    while (remaining_time > quantum) {
        printf("Running task %s with remaining time %d\n", task->name, remaining_time);
        fflush(stdout);
        sleep(quantum);
        remaining_time -= quantum;
    }
    printf("Task %s completed\n", task->name);
    fflush(stdout);
    pthread_exit(0);
}

int compare_tasks(const void *a, const void *b) {
    Task *task1 = (Task *) a;
    Task *task2 = (Task *) b;
    if (task1->priority < task2->priority) {
        return -1;
    } else if (task1->priority > task2->priority) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    Task tasks[n];
    printf("Enter the task details:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d:\n", i+1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
        printf("Deadline: ");
        scanf("%d", &tasks[i].deadline);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst);
        printf("Quantum: ");
        scanf("%d", &tasks[i].quantum);
    }
    qsort(tasks, n, sizeof(Task), compare_tasks);
    for (int i = 0; i < n; i++) {
        printf("Task %d: %s\n", i+1, tasks[i].name);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, run_task, (void *) &tasks[i]);
    }
    return 0;
}