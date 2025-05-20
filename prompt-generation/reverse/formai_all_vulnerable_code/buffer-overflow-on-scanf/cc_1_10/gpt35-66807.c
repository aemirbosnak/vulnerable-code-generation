//FormAI DATASET v1.0 Category: Task Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_LEN 100

struct task {
    int id;
    char description[MAX_TASK_LEN];
    time_t deadline;
};

struct task tasks[MAX_TASKS];
int task_count = 0;

void add_task(char* description, time_t deadline) {
    if (task_count >= MAX_TASKS) {
        printf("Maximum number of tasks added\n");
    } else {
        struct task new_task;
        new_task.id = task_count + 1;
        strcpy(new_task.description, description);
        new_task.deadline = deadline;
        tasks[task_count] = new_task;
        task_count++;
        printf("Task added successfully!\n\n");
    }
}

void remove_task(int id) {
    int i, found = 0;
    for (i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (i = id-1; i < task_count; i++) {
            tasks[i] = tasks[i+1];
        }
        task_count--;
        printf("Task removed successfully!\n\n");
    } else {
        printf("Task with ID %d not found!\n\n", id);
    }
}

void print_tasks() {
    printf("Task List:\n");
    int i;
    for (i = 0; i < task_count; i++) {
        printf("%d. %s (Deadline: %s)", tasks[i].id, tasks[i].description, asctime(localtime(&tasks[i].deadline)));
    }
    printf("\n");
}

void execute_tasks() {
    printf("Executing Tasks:\n");
    int i;
    for (i = 0; i < task_count; i++) {
        if (tasks[i].deadline > time(NULL)) {
            printf("%d. %s\n", tasks[i].id, tasks[i].description);
        }
    }
    printf("\n");
}

int main() {
    int choice, id;
    char description[MAX_TASK_LEN];
    time_t deadline;
    do {
        printf("Task Scheduler - Main Menu\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Print Task List\n");
        printf("4. Execute Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]", description);
                printf("Enter deadline (YYYY-MM-DD HH:MM:SS): ");
                scanf(" %ld", &deadline);
                add_task(description, deadline);
                break;
            case 2:
                printf("Enter task ID to remove: ");
                scanf("%d", &id);
                remove_task(id);
                break;
            case 3:
                print_tasks();
                break;
            case 4:
                execute_tasks();
                break;
            case 5:
                printf("Exiting Task Scheduler...");
                break;
            default:
                printf("Invalid choice! Try again.\n\n");
        }
    } while (choice != 5);
    return 0;
}