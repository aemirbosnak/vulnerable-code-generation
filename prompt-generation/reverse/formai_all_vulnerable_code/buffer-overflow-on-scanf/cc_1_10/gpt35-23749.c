//FormAI DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20
#define TIME_LIMIT 10

typedef struct Task {
    char name[MAX_NAME_LENGTH];
    int priority;
    int time_required;
} Task;

void read_tasks(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter details of task %d:\n", i+1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority (1-10): ");
        scanf("%d", &tasks[i].priority);
        printf("Time required (in seconds): ");
        scanf("%d", &tasks[i].time_required);
    }
}

void print_tasks(Task tasks[], int num_tasks) {
    printf("List of tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. Name: %s; Priority: %d; Time Required: %d seconds\n", i+1, tasks[i].name, tasks[i].priority, tasks[i].time_required);
    }
}

void execute_task(Task task) {
    printf("Executing task %s...\n", task.name);
    time_t start_time, end_time;
    time(&start_time);
    while (difftime(time(&end_time), start_time) < task.time_required) {
        // Busy wait until the required time has elapsed
    }
    printf("Task %s executed successfully!\n", task.name);
}

void execute_tasks(Task tasks[], int num_tasks) {
    int remaining_time = TIME_LIMIT;
    while (remaining_time > 0 && num_tasks > 0) {
        int max_priority = -1;
        int max_priority_index = -1;
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].priority > max_priority) {
                max_priority = tasks[i].priority;
                max_priority_index = i;
            }
        }
        if (max_priority_index != -1) {
            Task current_task = tasks[max_priority_index];
            if (current_task.time_required <= remaining_time) {
                execute_task(current_task);
                remaining_time -= current_task.time_required;
                // Remove the completed task from the array
                for (int i = max_priority_index; i < num_tasks-1; i++) {
                    tasks[i] = tasks[i+1];
                }
                num_tasks--;
            } else {
                printf("Not enough time to execute task %s! Skipping...\n", current_task.name);
                break;
            }
        } else {
            break;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks;
    printf("Enter the number of tasks (up to %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);
    read_tasks(tasks, num_tasks);
    print_tasks(tasks, num_tasks);
    execute_tasks(tasks, num_tasks);
    return 0;
}