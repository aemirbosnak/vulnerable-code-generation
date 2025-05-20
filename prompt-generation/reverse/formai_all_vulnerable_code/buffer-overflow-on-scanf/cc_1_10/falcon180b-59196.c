//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

#define MAX_TASKS 10

typedef struct {
    int task_id;
    int priority;
    int execution_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Task;

void *execute_task(void *arg) {
    Task task = *((Task *) arg);
    printf("Executing task %d with priority %d\n", task.task_id, task.priority);
    sleep(task.execution_time);
    printf("Task %d completed with turnaround time %d\n", task.task_id, task.turnaround_time);
}

int compare_priority(const void *a, const void *b) {
    Task task1 = *((Task *) a);
    Task task2 = *((Task *) b);
    return (task1.priority - task2.priority);
}

int main() {
    int i, j;
    Task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];

    printf("Enter task details:\n");
    for(i=0; i<MAX_TASKS; i++) {
        printf("Task %d:\n", i+1);
        printf("Enter task ID: ");
        scanf("%d", &tasks[i].task_id);
        printf("Enter priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Enter execution time: ");
        scanf("%d", &tasks[i].execution_time);
    }

    qsort(tasks, MAX_TASKS, sizeof(Task), compare_priority);

    for(i=0; i<MAX_TASKS; i++) {
        tasks[i].waiting_time = 0;
        tasks[i].turnaround_time = tasks[i].execution_time;
    }

    for(i=0; i<MAX_TASKS; i++) {
        pthread_create(&threads[i], NULL, execute_task, (void *)&tasks[i]);
        printf("Task %d started\n", tasks[i].task_id);
    }

    for(i=0; i<MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}