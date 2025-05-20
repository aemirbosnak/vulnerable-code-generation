//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a struct for a task
typedef struct Task {
    char* name;
    int id;
    time_t start_time;
    time_t end_time;
} Task;

// Define a struct for a scheduled task
typedef struct ScheduledTask {
    Task* task;
    time_t scheduled_time;
    int priority;
} ScheduledTask;

// Define global variables
ScheduledTask** tasks;
int num_tasks = 0;

// Function to create a new Task
Task* create_task(char* name) {
    Task* new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->id = num_tasks++;
    return new_task;
}

// Function to schedule a task
void schedule_task(Task* task, int priority, time_t scheduled_time) {
    ScheduledTask* new_scheduled_task = malloc(sizeof(ScheduledTask));
    new_scheduled_task->task = task;
    new_scheduled_task->priority = priority;
    new_scheduled_task->scheduled_time = scheduled_time;
    
    // Find the correct index to insert the new scheduled task
    int index = num_tasks;
    for (int i = 0; i < num_tasks; i++) {
        if (difftime(tasks[i]->scheduled_time, scheduled_time) > 0) {
            index = i;
            break;
        }
    }
    
    // Shift all tasks after the new task to the right
    for (int i = num_tasks; i > index; i--) {
        tasks[i] = tasks[i-1];
    }
    
    // Insert the new task into the array
    tasks[index] = new_scheduled_task;
    num_tasks++;
}

// Function to print a task
void print_task(Task* task) {
    printf("Task #%d -- %s\n", task->id, task->name);
}

// Function to print a scheduled task
void print_scheduled_task(ScheduledTask* scheduled_task) {
    printf("Scheduled Task -- Priority: %d, Scheduled Time: %s", scheduled_task->priority, asctime(localtime(&scheduled_task->scheduled_time)));
    print_task(scheduled_task->task);
}

// Function to execute a task
void execute_task(Task* task) {
    printf("Executing Task #%d -- %s\n", task->id, task->name);
    task->start_time = time(NULL);
    task->end_time = task->start_time + rand() % 10 + 1;
    
    // Wait for the task to complete
    while (difftime(time(NULL), task->end_time) < 0) {}
    
    printf("Task #%d Complete\n", task->id);
}

// Function to execute all scheduled tasks
void execute_scheduled_tasks() {
    // Loop through all scheduled tasks
    for (int i = 0; i < num_tasks; i++) {
        ScheduledTask* scheduled_task = tasks[i];
        
        // Check if the scheduled time has already passed
        if (difftime(time(NULL), scheduled_task->scheduled_time) >= 0) {
            execute_task(scheduled_task->task);
            free(scheduled_task);
            num_tasks--;
            
            // Shift all tasks after the executed task to the left
            for (int j = i; j < num_tasks; j++) {
                tasks[j] = tasks[j+1];
            }
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Allocate memory for the scheduled tasks array
    tasks = malloc(sizeof(ScheduledTask*) * 10);
    
    // Create some tasks
    Task* task1 = create_task("Do laundry");
    Task* task2 = create_task("Buy groceries");
    Task* task3 = create_task("Clean room");
    Task* task4 = create_task("Study for exam");
    Task* task5 = create_task("Go for a run");
    
    // Schedule the tasks
    schedule_task(task1, 3, time(NULL) + 5);
    schedule_task(task2, 2, time(NULL) + 10);
    schedule_task(task3, 4, time(NULL) + 20);
    schedule_task(task4, 1, time(NULL) + 15);
    schedule_task(task5, 5, time(NULL) + 30);
    
    // Execute the scheduled tasks
    printf("Executing Scheduled Tasks...\n");
    while (num_tasks > 0) {
        execute_scheduled_tasks();
    }
    
    // Free memory for the scheduled tasks array
    free(tasks);
    
    return 0;
}