//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100 // maximum tasks that can be scheduled
#define MAX_TASK_NAME_LENGTH 20 // maximum length of task names

typedef struct {
    char task_name[MAX_TASK_NAME_LENGTH];
    int priority;
    int duration;
} Task;

void schedule_task(Task tasks[], int num_tasks);

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks, i;

    printf("Enter the number of tasks to be scheduled: ");
    scanf("%d", &num_tasks);

    // get input for each task
    for (i = 0; i < num_tasks; i++) {
        printf("Enter task name, priority, and duration (in seconds) for task %d:\n", i+1);
        scanf("%s %d %d", tasks[i].task_name, &tasks[i].priority, &tasks[i].duration);
    }

    // schedule tasks
    schedule_task(tasks, num_tasks);

    return 0;
}

void schedule_task(Task tasks[], int num_tasks) {
    int i, j;
    int current_time = 0; // seconds since scheduler started running
    int remaining_time[MAX_TASKS] = {0}; // remaining time for each task

    srand(time(NULL)); // seed random number generator

    // initialize remaining_time array
    for (i = 0; i < num_tasks; i++) {
        remaining_time[i] = tasks[i].duration;
    }

    while (1) {
        int highest_priority_task_index = -1;
        int highest_priority = -1;

        // find task with highest priority that has remaining time
        for (i = 0; i < num_tasks; i++) {
            if (remaining_time[i] > 0 && tasks[i].priority > highest_priority) {
                highest_priority = tasks[i].priority;
                highest_priority_task_index = i;
            }
        }

        if (highest_priority_task_index == -1) {
            printf("\nAll tasks completed!\n");
            break;
        }

        // simulate task execution for a random amount of time between 1 and 5 seconds
        int execution_time = rand() % 5 + 1;

        // update remaining time for the task
        remaining_time[highest_priority_task_index] -= execution_time;

        // update current time
        current_time += execution_time;

        printf("\nTask '%s' with priority %d started at %d seconds and will run for %d seconds.", 
            tasks[highest_priority_task_index].task_name, tasks[highest_priority_task_index].priority, 
            current_time - execution_time, execution_time);

        // check if task has completed
        if (remaining_time[highest_priority_task_index] == 0) {
            printf("\nTask '%s' with priority %d completed at %d seconds.", 
                tasks[highest_priority_task_index].task_name, tasks[highest_priority_task_index].priority, current_time);
        }
    }
}