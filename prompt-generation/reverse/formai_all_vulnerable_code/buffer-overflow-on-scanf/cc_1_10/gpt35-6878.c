//FormAI DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

typedef struct Task {
    char name[MAX_NAME_LENGTH];
    int priority;
    int time_remaining;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: task list is full\n");
        return;
    }
    Task new_task;
    printf("Enter task name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", new_task.name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &new_task.priority);
    printf("Enter task time remaining (in minutes): ");
    scanf("%d", &new_task.time_remaining);
    tasks[num_tasks++] = new_task;
    printf("Task added successfully\n");
}

void list_tasks() {
    if (num_tasks == 0) {
        printf("No tasks in list\n");
        return;
    }
    printf("Task List:\n");
    printf("Name\tPriority\tTime Remaining\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].time_remaining);
    }
}

void run_next_task() {
    if (num_tasks == 0) {
        printf("Error: no tasks in list\n");
        return;
    }
    int highest_priority = 0;
    int next_task_index = 0;
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].priority > highest_priority) {
            highest_priority = tasks[i].priority;
            next_task_index = i;
        }
    }
    printf("Running task %s\n", tasks[next_task_index].name);
    tasks[next_task_index].time_remaining = 0;
    for (int i = next_task_index; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    num_tasks--;
}

int main() {
    int option;
    do {
        printf("\nTask Scheduler\n");
        printf("1. Add task\n");
        printf("2. List tasks\n");
        printf("3. Run next task\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_task();
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                run_next_task();
                break;
            case 4:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid option, try again\n");
                break;
        }
    } while (option != 4);

    return 0;
}