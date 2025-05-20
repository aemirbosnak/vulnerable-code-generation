//FormAI DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    char description[50];
    int priority;
    int time_to_complete;
    time_t deadline;
    bool completed;
} Task;

typedef struct TaskScheduler {
    Task tasks[MAX_TASKS];
    int num_tasks;
} TaskScheduler;

void add_task(TaskScheduler *scheduler, Task task) {
    if (scheduler->num_tasks < MAX_TASKS) {
        scheduler->tasks[scheduler->num_tasks] = task;
        scheduler->num_tasks++;
    }
}

void remove_task(TaskScheduler *scheduler, int task_id) {
    for (int i = 0; i < scheduler->num_tasks; i++) {
        if (scheduler->tasks[i].id == task_id) {
            for (int j = i; j < scheduler->num_tasks - 1; j++) {
                scheduler->tasks[j] = scheduler->tasks[j+1];
            }
            scheduler->num_tasks--;
            break;
        }
    }
}

void print_tasks(TaskScheduler *scheduler) {
    printf("ID | DESCRIPTION | PRIORITY | TIME TO COMPLETE | DEADLINE   | COMPLETED\n");
    for (int i = 0; i < scheduler->num_tasks; i++) {
        printf("%2d | %-10s | %8d | %15d | %s | %s\n", 
                scheduler->tasks[i].id, 
                scheduler->tasks[i].description, 
                scheduler->tasks[i].priority, 
                scheduler->tasks[i].time_to_complete,
                ctime(&scheduler->tasks[i].deadline), 
                scheduler->tasks[i].completed ? "true" : "false");
    }
}

void run_task(Task *task) {
    printf("Running task: %s\n", task->description);
    task->completed = true;
}

int main() {
    srand(time(NULL));
    TaskScheduler scheduler = {0};
    
    // Configure tasks
    Task task1 = {1, "Clean kitchen", 2, 60 * 30, time(NULL) + 60 * 60 * 24, false};
    Task task2 = {2, "Do laundry", 1, 60 * 60, time(NULL) + 60 * 60 * 24 * 2, false};
    Task task3 = {3, "Buy groceries", 3, 60 * 45, time(NULL) + 60 * 60 * 24 * 3, false};
    
    // Add tasks to scheduler
    add_task(&scheduler, task1);
    add_task(&scheduler, task2);
    add_task(&scheduler, task3);
    
    // Print tasks
    print_tasks(&scheduler);
    
    // Execute tasks
    for (int i = 0; i < scheduler.num_tasks; i++) {
        printf("\n");
        run_task(&scheduler.tasks[i]);
        printf("\n");
    }
    
    // Remove completed tasks
    for (int i = 0; i < scheduler.num_tasks; i++) {
        if (scheduler.tasks[i].completed) {
            remove_task(&scheduler, scheduler.tasks[i].id);
        }
    }
    
    // Print updated tasks
    printf("Updated tasks:\n");
    print_tasks(&scheduler);
    
    return 0;
}