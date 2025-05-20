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
    int duration;
    int start_time;
    int end_time;
} Task;

// Function to compare the priorities of two tasks
int compare_tasks(const void *a, const void *b) {
    const Task *task1 = a;
    const Task *task2 = b;
    if (task1->priority > task2->priority) {
        return -1;
    } else if (task1->priority < task2->priority) {
        return 1;
    } else {
        return 0;
    }
}

// Function to schedule the tasks using the Round Robin scheduling algorithm
void schedule_tasks() {
    int i, j, current_time = 0;
    Task tasks[MAX_TASKS];
    
    // Read the tasks from the user
    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &i);
    for (j = 0; j < i; j++) {
        printf("Enter the name of task %d: ", j + 1);
        scanf("%s", tasks[j].name);
        printf("Enter the priority of task %d (1 to %d): ", j + 1, i);
        scanf("%d", &tasks[j].priority);
        printf("Enter the duration of task %d in seconds: ", j + 1);
        scanf("%d", &tasks[j].duration);
    }
    
    // Sort the tasks based on their priorities
    qsort(tasks, i, sizeof(Task), compare_tasks);
    
    // Schedule the tasks using the Round Robin scheduling algorithm
    while (current_time < (i - 1) * tasks[0].duration) {
        for (j = 0; j < i; j++) {
            if (current_time >= tasks[j].start_time && current_time < tasks[j].end_time) {
                printf("%s is executing from %d to %d\n", tasks[j].name, current_time, current_time + tasks[j].duration);
            }
        }
        current_time += tasks[0].duration;
    }
}

int main() {
    schedule_tasks();
    return 0;
}