//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a task
typedef struct task {
    int id;             // Unique ID for the task
    char *name;          // Name of the task
    int priority;        // Priority of the task (higher is better)
    time_t scheduled_time;// Time when the task is scheduled to run
    int remaining_time;  // Remaining time to complete the task
} task;

// Function to create a new task
task *create_task(int id, char *name, int priority, time_t scheduled_time, int remaining_time) {
    task *new_task = malloc(sizeof(task));
    new_task->id = id;
    new_task->name = name;
    new_task->priority = priority;
    new_task->scheduled_time = scheduled_time;
    new_task->remaining_time = remaining_time;
    return new_task;
}

// Function to print a task
void print_task(task *t) {
    printf("Task ID: %d\n", t->id);
    printf("Task name: %s\n", t->name);
    printf("Task priority: %d\n", t->priority);
    printf("Task scheduled time: %s", ctime(&t->scheduled_time));
    printf("Task remaining time: %d\n", t->remaining_time);
}

// Function to compare two tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    task *task1 = (task *)a;
    task *task2 = (task *)b;
    return task2->priority - task1->priority;
}

// Main function
int main() {
    // Create an array of tasks
    task *tasks[] = {
        create_task(1, "Task 1", 10, time(NULL) + 60, 10),
        create_task(2, "Task 2", 5, time(NULL) + 120, 20),
        create_task(3, "Task 3", 15, time(NULL) + 180, 30),
        create_task(4, "Task 4", 7, time(NULL) + 240, 40),
        create_task(5, "Task 5", 2, time(NULL) + 300, 50),
    };

    // Sort the tasks based on their priority
    qsort(tasks, sizeof(tasks) / sizeof(task *), sizeof(task *), compare_tasks);

    // Print the sorted tasks
    for (int i = 0; i < sizeof(tasks) / sizeof(task *); i++) {
        print_task(tasks[i]);
    }

    return 0;
}