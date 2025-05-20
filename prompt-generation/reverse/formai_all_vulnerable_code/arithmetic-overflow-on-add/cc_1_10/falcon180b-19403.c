//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

// Task structure
typedef struct {
    char name[20];
    int priority;
    int duration;
    int start_time;
    int end_time;
} Task;

// Function to compare tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    Task *task_a = (Task *) a;
    Task *task_b = (Task *) b;

    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

// Function to execute tasks
void execute_tasks(Task *tasks, int num_tasks) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("Executing task %s with priority %d\n", tasks[i].name, tasks[i].priority);
        sleep(tasks[i].duration);
    }
}

// Function to schedule tasks
void schedule_tasks(Task *tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("Scheduling task %s with priority %d\n", tasks[i].name, tasks[i].priority);
        tasks[i].start_time = tasks[i - 1].end_time;
        tasks[i].end_time = tasks[i].start_time + tasks[i].duration;
    }
}

int main() {
    // Initialize tasks
    Task tasks[MAX_TASKS] = {{ "Task 1", 1, 2, 0, 0 },
                             { "Task 2", 2, 3, 0, 0 },
                             { "Task 3", 3, 1, 0, 0 }};

    int num_tasks = 3;

    // Schedule tasks
    schedule_tasks(tasks, num_tasks);

    // Execute tasks
    execute_tasks(tasks, num_tasks);

    return 0;
}