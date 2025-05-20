//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
/*
 * Ada Lovelace-style C Task Scheduler Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of tasks in the scheduler
#define MAX_TASKS 10

// Define the task structure
struct Task {
    int id;
    char description[50];
    int priority;
    int duration;
    time_t start_time;
    time_t end_time;
};

// Define the scheduler structure
struct Scheduler {
    struct Task tasks[MAX_TASKS];
    int num_tasks;
};

// Initialize the scheduler
struct Scheduler scheduler;

// Define the function to add a task to the scheduler
void add_task(int id, char* description, int priority, int duration) {
    // If the scheduler is full, do not add the task
    if (scheduler.num_tasks >= MAX_TASKS) {
        printf("Scheduler is full!\n");
        return;
    }
    
    // Add the task to the scheduler
    struct Task task = {id, description, priority, duration, time(NULL)};
    scheduler.tasks[scheduler.num_tasks] = task;
    scheduler.num_tasks++;
    
    printf("Added task %d: %s\n", id, description);
}

// Define the function to remove a task from the scheduler
void remove_task(int id) {
    // Find the task with the given id
    int i;
    for (i = 0; i < scheduler.num_tasks; i++) {
        if (scheduler.tasks[i].id == id) {
            break;
        }
    }
    
    // If the task is not found, do not remove anything
    if (i == scheduler.num_tasks) {
        printf("Task %d not found!\n", id);
        return;
    }
    
    // Remove the task from the scheduler
    for (; i < scheduler.num_tasks - 1; i++) {
        scheduler.tasks[i] = scheduler.tasks[i+1];
    }
    scheduler.num_tasks--;
    
    printf("Removed task %d\n", id);
}

// Define the function to print all tasks in the scheduler
void print_tasks() {
    printf("Tasks in scheduler:\n");
    printf("id  description                         priority  duration  start_time             end_time\n");
    printf("------------------------------------------------------------------------------------------\n");
    
    int i;
    for (i = 0; i < scheduler.num_tasks; i++) {
        struct Task task = scheduler.tasks[i];
        printf("%-4d%-35s%-10d%-10d%-24ld%-24ld\n", task.id, task.description, task.priority, task.duration, task.start_time, task.end_time);
    }
}

// Define the function to run the scheduler
void run_scheduler() {
    // Sort the tasks by priority
    int i, j;
    for (i = 0; i < scheduler.num_tasks - 1; i++) {
        for (j = i + 1; j < scheduler.num_tasks; j++) {
            if (scheduler.tasks[i].priority < scheduler.tasks[j].priority) {
                struct Task temp = scheduler.tasks[i];
                scheduler.tasks[i] = scheduler.tasks[j];
                scheduler.tasks[j] = temp;
            }
        }
    }
    
    // Run each task in order of priority
    for (i = 0; i < scheduler.num_tasks; i++) {
        struct Task* task = &scheduler.tasks[i];
        task->start_time = time(NULL);
        printf("Running task %d: %s\n", task->id, task->description);
        
        // Simulate running the task
        int count;
        for (count = 0; count < task->duration; count++) {
            // Do nothing
        }
        
        task->end_time = time(NULL);
        printf("Task %d completed in %d seconds\n", task->id, (int)(task->end_time - task->start_time));
    }
}

int main() {
    // Initialize the scheduler
    scheduler.num_tasks = 0;
    
    // Add some tasks to the scheduler
    add_task(1, "Calculate pi", 3, 10);
    add_task(2, "Sort a list", 2, 7);
    add_task(3, "Encrypt a message", 1, 5);
    add_task(4, "Search a database", 4, 15);
    
    // Print the tasks in the scheduler
    print_tasks();
    
    // Run the scheduler
    run_scheduler();
    
    // Remove a task from the scheduler
    remove_task(2);
    
    // Print the tasks in the scheduler again
    print_tasks();
    
    return 0;
}