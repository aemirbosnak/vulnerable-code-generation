//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void executeTask(Task* task) {
    printf("Executing task %s with burst time %d\n", task->name, task->burst_time);
    fflush(stdout);
    sleep(task->burst_time);
}

int comparePriority(const void* a, const void* b) {
    Task* task1 = *(Task**)a;
    Task* task2 = *(Task**)b;
    return task2->priority - task1->priority;
}

int main() {
    Task tasks[MAX_TASKS];
    int numTasks = 0;
    int i;

    // Read input from user
    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &numTasks);
    for(i = 0; i < numTasks; i++) {
        printf("Enter task name, priority, and burst time for task %d: ", i+1);
        scanf("%s %d %d", tasks[i].name, &tasks[i].priority, &tasks[i].burst_time);
        tasks[i].waiting_time = 0;
        tasks[i].turnaround_time = 0;
    }

    // Sort tasks by priority
    qsort(tasks, numTasks, sizeof(Task), comparePriority);

    // Execute tasks
    for(i = 0; i < numTasks; i++) {
        executeTask(&tasks[i]);
    }

    // Calculate waiting and turnaround times
    for(i = 0; i < numTasks; i++) {
        tasks[i].waiting_time = tasks[i].turnaround_time - tasks[i].burst_time;
        tasks[i].turnaround_time = tasks[i].waiting_time + tasks[i].burst_time;
    }

    // Print task statistics
    printf("\nTask Statistics:\n");
    for(i = 0; i < numTasks; i++) {
        printf("Task %s: Priority %d, Burst Time %d, Waiting Time %d, Turnaround Time %d\n", tasks[i].name, tasks[i].priority, tasks[i].burst_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }

    return 0;
}