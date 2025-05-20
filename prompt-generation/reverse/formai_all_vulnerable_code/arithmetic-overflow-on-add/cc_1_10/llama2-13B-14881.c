//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_DESCRIPTION_LEN 50

// Structure to hold a task
typedef struct {
    char name[50];   // Task name
    char description[50];  // Task description
    time_t due_time;  // Time the task is due
    time_t created_time;  // Time the task was created
} task_t;

// Global variable to store the list of tasks
task_t tasks[MAX_TASKS];
int num_tasks = 0;

// Function to add a new task
void add_task(char *name, char *description, time_t due_time) {
    task_t new_task;
    strcpy(new_task.name, name);
    strcpy(new_task.description, description);
    new_task.due_time = due_time;
    new_task.created_time = time(NULL);
    if (num_tasks >= MAX_TASKS) {
        printf("Oops! The task list is full! Sorry, I can't add any more tasks:\n");
        return;
    }
    tasks[num_tasks++] = new_task;
    printf("New task added: %s (due at %s)\n", new_task.name, ctime(&new_task.due_time));
}

// Function to print all tasks
void print_tasks() {
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("%d. %s (due at %s)\n", i + 1, tasks[i].name, ctime(&tasks[i].due_time));
    }
}

// Function to check if a task is overdue
int is_overdue(time_t current_time) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (current_time >= tasks[i].due_time) {
            return 1;  // Task is overdue
        }
    }
    return 0;  // No tasks are overdue
}

int main() {
    // Add some tasks
    add_task("Buy milk", "Don't forget to buy milk today!", time(NULL) + 30 * 60);  // 30 minutes from now
    add_task("Call mom", "Call your mom to wish her a happy birthday!", time(NULL) + 2 * 60 * 60);  // 2 hours from now
    add_task("Meet John", "Meet John at the park at 3 PM", time(NULL) + 3 * 60 * 60);  // 3 hours from now

    // Print all tasks
    print_tasks();

    // Check if any tasks are overdue
    time_t current_time = time(NULL);
    if (is_overdue(current_time)) {
        printf("Oops! You have overdue tasks!\n");
    } else {
        printf("All tasks are on time!\n");
    }

    return 0;
}