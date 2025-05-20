//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the structure for a task
typedef struct {
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

// Function to compare tasks based on priority
int compare(const void *a, const void *b) {
    Task taskA = *((Task *) a);
    Task taskB = *((Task *) b);

    if (taskA.priority > taskB.priority)
        return -1;
    else if (taskA.priority < taskB.priority)
        return 1;
    else
        return 0;
}

// Function to execute a task
void execute_task(Task task) {
    printf("Executing task %s with priority %d\n", task.name, task.priority);
    sleep(task.burst_time);
}

// Function to schedule tasks using Round Robin scheduling algorithm
void round_robin_scheduling(Task tasks[], int num_tasks) {
    int current_task = 0;
    int completed_tasks = 0;

    qsort(tasks, num_tasks, sizeof(Task), compare);

    while (completed_tasks < num_tasks) {
        execute_task(tasks[current_task]);
        completed_tasks++;

        if (current_task == num_tasks - 1)
            current_task = 0;
        else
            current_task++;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    printf("Enter the details of the tasks:\n");

    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    round_robin_scheduling(tasks, num_tasks);

    return 0;
}