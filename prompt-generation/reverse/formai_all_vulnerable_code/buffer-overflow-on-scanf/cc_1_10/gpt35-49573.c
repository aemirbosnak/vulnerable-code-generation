//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME 50
#define MAX_DESC_LENGTH 100

typedef struct task {
    char name[MAX_TASK_NAME];
    char description[MAX_DESC_LENGTH];
    int priority;
    int minutes;
} Task;

void add_task(Task tasks[], int *count) {
    if (*count >= MAX_TASKS) {
        printf("\nYou have reached the maximum number of tasks!\n");
        return;
    }

    printf("\nEnter task name: ");
    scanf("%s", tasks[*count].name);

    printf("Enter task description: ");
    scanf("%s", tasks[*count].description);

    printf("Enter task priority (1-10): ");
    scanf("%d", &tasks[*count].priority);

    printf("Enter task duration in minutes: ");
    scanf("%d", &tasks[*count].minutes);

    printf("\nTask added successfully!\n");
    (*count)++;
}

void remove_task(Task tasks[], int *count) {
    char name[MAX_TASK_NAME];
    int i, j;

    printf("\nEnter task name to delete: ");
    scanf("%s", name);

    for (i = 0; i < *count; i++) {
        if (strcmp(name, tasks[i].name) == 0) {
            (*count)--;
            for (j = i; j < *count; j++) {
                tasks[j] = tasks[j+1];
            }
            printf("\nTask deleted successfully!\n");
            return;
        }
    }

    printf("\nTask not found!\n");
}

void display_tasks(Task tasks[], int count) {
    int i;

    printf("\n%-20s %-20s %-10s %-10s\n", "Task", "Description", "Priority", "Duration");
    for (i = 0; i < count; i++) {
        printf("%-20s %-20s %-10d %-10d\n", tasks[i].name, tasks[i].description, tasks[i].priority, tasks[i].minutes);
    }
}

void execute_tasks(Task tasks[], int count) {
    int i;

    printf("\nExecuting tasks...\n");
    for (i = 0; i < count; i++) {
        printf("\nTask: %s\n", tasks[i].name);
        printf("Description: %s\n", tasks[i].description);
        printf("Priority: %d\n", tasks[i].priority);
        printf("Duration: %d minutes\n", tasks[i].minutes);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int count = 0;
    int choice;

    do {
        printf("\nTask Scheduler\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Execute Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task(tasks, &count);
                break;
            case 2:
                remove_task(tasks, &count);
                break;
            case 3:
                display_tasks(tasks, count);
                break;
            case 4:
                execute_tasks(tasks, count);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    } while(1);

    return 0;
}