//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 32

typedef struct task {
    char name[MAX_NAME_LENGTH];
    int priority;
    time_t scheduled_time;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int priority, time_t scheduled_time) {
    if (num_tasks < MAX_TASKS) {
        strcpy(tasks[num_tasks].name, name);
        tasks[num_tasks].priority = priority;
        tasks[num_tasks].scheduled_time = scheduled_time;
        num_tasks++;
    } else {
        printf("Error: Task list is full\n");
    }
}

void remove_task(char *name) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            tasks[i] = tasks[num_tasks - 1];
            num_tasks--;
        }
    }
}

void print_tasks() {
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("%s (%d) scheduled for %s\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].scheduled_time));
    }
}

int main() {
    // Add some tasks to the list
    add_task("Task 1", 1, time(NULL) + 60);
    add_task("Task 2", 2, time(NULL) + 120);
    add_task("Task 3", 3, time(NULL) + 180);

    // Print the list of tasks
    print_tasks();

    // Remove a task from the list
    remove_task("Task 2");

    // Print the list of tasks again
    print_tasks();

    return 0;
}