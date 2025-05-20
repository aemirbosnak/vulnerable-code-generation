//FormAI DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME 20
#define MAX_DESCRIPTION 1000

typedef struct {
    char name[MAX_NAME];
    char description[MAX_DESCRIPTION];
    time_t deadline;
    int priority; 
} Task;

Task tasks[MAX_TASKS];

int num_tasks = 0;

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return;
    }
    printf("Enter task name: ");
    scanf("%s", tasks[num_tasks].name);
    printf("Enter task description: ");
    getchar(); // clear input buffer
    fgets(tasks[num_tasks].description, MAX_DESCRIPTION, stdin);
    tasks[num_tasks].description[strcspn(tasks[num_tasks].description, "\n")] = 0; // remove trailing newline
    printf("Enter task deadline (in Unix timestamp format): ");
    scanf("%ld", &tasks[num_tasks].deadline);
    printf("Enter task priority (1-10): ");
    scanf("%d", &tasks[num_tasks].priority);
    printf("Task added successfully.\n");
    num_tasks++;
}

void list_tasks() {
    if (num_tasks == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("Task list:\n");
    for (int i = 0; i < num_tasks; i++) {
        time_t t = tasks[i].deadline;
        struct tm *tm_info = localtime(&t);
        char deadline_str[26];
        strftime(deadline_str, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s (priority %d) - %s (deadline: %s)\n", tasks[i].name, tasks[i].priority, tasks[i].description, deadline_str);
    }
}

void delete_task() {
    if (num_tasks == 0) {
        printf("No tasks available to delete.\n");
        return;
    }
    printf("Enter task name to delete: ");
    char task_name[MAX_NAME];
    scanf("%s", task_name);
    int found_task = 0;
    for (int i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, task_name) == 0) {
            found_task = 1;
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j+1];
            }
            num_tasks--;
            printf("Task deleted successfully.\n");
            break;
        }
    }
    if (!found_task) {
        printf("Task not found.\n");
    }
}

int compare_tasks(const void *a, const void *b) {
    Task *task1 = (Task *) a;
    Task *task2 = (Task *) b;
    if (task1->priority < task2->priority) {
        return 1;
    } else if (task1->priority > task2->priority) {
        return -1;
    } else {
        return 0;
    }
}

void sort_tasks_by_priority() {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);
    printf("Tasks sorted by priority.\n");
}

int main() {
    int choice = -1;
    while (choice != 0) {
        printf("What would you like to do?\n");
        printf("1. Add task\n");
        printf("2. List tasks\n");
        printf("3. Delete task\n");
        printf("4. Sort tasks by priority\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                sort_tasks_by_priority();
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}