//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    char name[20];
    int priority;
    int period;
    int deadline;
    int burst_time;
    int remaining_time;
};

void execute_task(void* arg) {
    struct task* task = (struct task*) arg;
    int i;

    for (i = 0; i < task->burst_time; i++) {
        printf("%s is executing...\n", task->name);
        fflush(stdout);
        sleep(1);
    }

    task->remaining_time = task->period;
}

int compare_tasks(const void* a, const void* b) {
    struct task* task1 = (struct task*) a;
    struct task* task2 = (struct task*) b;

    if (task1->priority > task2->priority)
        return -1;
    else if (task1->priority < task2->priority)
        return 1;
    else
        return 0;
}

int main() {
    int i, j;
    struct task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter the tasks:\n");
    for (i = 0; i < num_tasks; i++) {
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
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_tasks);

    for (i = 0; i < num_tasks; i++) {
        tasks[i].remaining_time = tasks[i].period;
    }

    printf("Tasks sorted by priority:\n");
    for (i = 0; i < num_tasks; i++) {
        printf("%s\n", tasks[i].name);
    }

    for (i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, execute_task, (void*) &tasks[i]);
    }

    for (i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}