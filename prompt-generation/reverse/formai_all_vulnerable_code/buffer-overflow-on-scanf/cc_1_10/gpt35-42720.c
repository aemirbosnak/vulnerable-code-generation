//FormAI DATASET v1.0 Category: Task Scheduler ; Style: detailed
// This is a task scheduler program that simulates a simple to-do list
// It allows the user to add tasks with a priority level and due date
// The program then sorts the tasks by priority level and due date
// It displays the next task to be completed based on those factors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about each task
typedef struct task_struct {
    char task_name[50];
    int priority_level;
    int due_date;
} Task;

// Define a function to compare tasks by priority level and due date (used for sorting)
int compare_tasks(const void* a, const void* b) {
    Task task1 = *(Task*)a;
    Task task2 = *(Task*)b;
    if (task1.priority_level != task2.priority_level) {
        return task1.priority_level - task2.priority_level;
    } else {
        return task1.due_date - task2.due_date;
    }
}

int main() {
    int i, n;
    printf("Welcome to the task scheduler!\n\n");
    printf("How many tasks would you like to add? ");
    scanf("%d", &n);
    Task *task_list = (Task*)malloc(n * sizeof(Task));

    // Prompt the user to add tasks and their information
    for (i=0; i<n; i++) {
        printf("Enter task name: ");
        scanf("%s", task_list[i].task_name);
        printf("Enter task priority level (1-5): ");
        scanf("%d", &task_list[i].priority_level);
        printf("Enter task due date (days from now): ");
        scanf("%d", &task_list[i].due_date);
    }

    // Sort the task list based on priority level and due date
    qsort(task_list, n, sizeof(Task), compare_tasks);

    // Display the next task to be completed
    printf("\nNext task to be completed:\n");
    printf("Task name: %s\n", task_list[0].task_name);
    printf("Priority level: %d\n", task_list[0].priority_level);
    printf("Due date: %d days from now\n", task_list[0].due_date);
    free(task_list);
    return 0;
}