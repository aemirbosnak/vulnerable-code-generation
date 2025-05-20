//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
// This is a task scheduler program in C
// written in a Dennis Ritchie style

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10 // maximum number of tasks
#define MAX_NAME_LENGTH 20 // maximum length of task name

// structure for a task
typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t deadline;
    void (*function)();
} task;

// array of tasks
task tasks[MAX_TASKS];

// function to add a task to the array
void add_task(char name[], time_t deadline, void (*function)()) {
    // find the next available index in the array
    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].name[0] == '\0') {
            break;
        }
    }
    
    // add the task to the array
    if (i < MAX_TASKS) {
        // set the name and deadline of the task
        int j;
        for (j = 0; j < MAX_NAME_LENGTH && name[j] != '\0'; j++) {
            tasks[i].name[j] = name[j];
        }
        tasks[i].name[j] = '\0';
        tasks[i].deadline = deadline;
        tasks[i].function = function;
        printf("Task added: %s\n", name);
    } else {
        printf("Error: Maximum number of tasks reached!\n");
    }
}

// function to remove a task from the array
void remove_task(int index) {
    // check if the index is valid
    if (index < 0 || index >= MAX_TASKS || tasks[index].name[0] == '\0') {
        printf("Error: Invalid index!\n");
    } else {
        printf("Task removed: %s\n", tasks[index].name);
        // remove the task from the array
        tasks[index].name[0] = '\0';
        tasks[index].deadline = 0;
        tasks[index].function = NULL;
    }
}

// function to execute a task
void execute_task(int index) {
    // check if the index is valid
    if (index < 0 || index >= MAX_TASKS || tasks[index].name[0] == '\0') {
        printf("Error: Invalid index!\n");
    } else {
        tasks[index].function();
        printf("Task completed: %s\n", tasks[index].name);
        // remove the task from the array
        tasks[index].name[0] = '\0';
        tasks[index].deadline = 0;
        tasks[index].function = NULL;
    }
}

// function to print the list of tasks
void print_tasks() {
    printf("Tasks:\n");
    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].name[0] != '\0') {
            printf("%d. %s (deadline: %ld)\n", i, tasks[i].name, tasks[i].deadline);
        }
    }
}

// main function
int main() {
    // initialize the array of tasks
    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        tasks[i].name[0] = '\0';
        tasks[i].deadline = 0;
        tasks[i].function = NULL;
    }
    
    // add some tasks
    add_task("Task 1", time(NULL) + 5, NULL);
    add_task("Task 2", time(NULL) + 10, NULL);
    add_task("Task 3", time(NULL) + 15, NULL);
    add_task("Task 4", time(NULL) + 20, NULL);
    print_tasks();
    
    // remove a task
    remove_task(1);
    print_tasks();
    
    // execute a task
    execute_task(2);
    print_tasks();
    
    return 0;
}