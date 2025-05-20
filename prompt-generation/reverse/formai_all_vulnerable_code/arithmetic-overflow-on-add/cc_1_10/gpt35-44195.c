//FormAI DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 20

typedef struct {
    char name[MAX_TASK_NAME]; // Task name
    int priority; // Task priority (1 - high, 2 - medium, 3 - low)
    time_t next_run; // Timestamp of next scheduled run
    void (*function)(); // Pointer to the function that performs the task
} task_t;

task_t task_list[MAX_TASKS]; // List of tasks

int num_tasks = 0; // Number of tasks in the list

// Function to add a new task to the list
void add_task(char name[], int priority, int interval, void (*function)()) {
    if(num_tasks < MAX_TASKS) {
        strncpy(task_list[num_tasks].name, name, MAX_TASK_NAME);
        task_list[num_tasks].priority = priority;
        task_list[num_tasks].next_run = time(NULL) + interval;
        task_list[num_tasks].function = function;
        num_tasks++;
    } else {
        printf("Error: Maximum number of tasks reached.\n");
    }
}

// Function to remove a task from the list
void remove_task(char name[]) {
    for(int i = 0; i < num_tasks; i++) {
        if(strcmp(task_list[i].name, name) == 0) {
            for(int j = i; j < num_tasks - 1; j++) {
                task_list[j] = task_list[j+1];
            }
            num_tasks--;
            printf("Task removed: %s\n", name);
            return;
        }
    }
    printf("Error: Task not found.\n");
}

// Function to run the task scheduler
void run_scheduler() {
    while(1) {
        // Find the highest priority task that is ready to run
        int highest_priority = 4;
        int index = -1;
        for(int i = 0; i < num_tasks; i++) {
            if(task_list[i].next_run <= time(NULL)) {
                if(task_list[i].priority < highest_priority) {
                    highest_priority = task_list[i].priority;
                    index = i;
                }
            }
        }
        // If a task was found, run it
        if(index != -1) {
            printf("Running task: %s\n", task_list[index].name);
            task_list[index].function();
            task_list[index].next_run = time(NULL) + 60; // Reschedule task for 1 minute from now
        }
        
        // Sleep for 1 second
        sleep(1);
    }
}

// Example tasks
void task1() {
    printf("Task 1 executed.\n");
}

void task2() {
    printf("Task 2 executed.\n");
}

// Main function
int main() {
    // Add example tasks
    add_task("Task 1", 2, 5, task1); // Run every 5 seconds, medium priority
    add_task("Task 2", 1, 10, task2); // Run every 10 seconds, high priority
    
    // Start the scheduler
    run_scheduler();
    
    return 0;
}