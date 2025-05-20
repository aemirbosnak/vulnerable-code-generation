//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
// Example C Task Scheduler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int task_id;
    int execution_time;
    time_t last_execution;
} Task;

Task tasks[MAX_TASKS];

void add_task(int task_id, int execution_time) {
    Task new_task = {task_id, execution_time, time(NULL)};
    
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].task_id == 0) {
            tasks[i] = new_task;
            printf("Task %d added to the scheduler.\n", task_id);
            return;
        }
    }
    
    printf("Could not add task %d. Task scheduler is full.\n", task_id);
}

void remove_task(int task_id) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].task_id == task_id) {
            tasks[i].task_id = 0;
            tasks[i].execution_time = 0;
            tasks[i].last_execution = 0;
            printf("Task %d removed from the scheduler.\n", task_id);
            return;
        }
    }
    
    printf("Could not remove task %d. Task not found in the scheduler.\n", task_id);
}

void execute_task(int index) {
    if (time(NULL) < tasks[index].last_execution + tasks[index].execution_time) {
        printf("Task %d cannot be executed yet.\n", tasks[index].task_id);
    } else {
        printf("Executing task %d...\n", tasks[index].task_id);
        tasks[index].last_execution = time(NULL);
    }
}

void run_scheduler() {
    int num_tasks = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].task_id != 0) {
            num_tasks++;
        }
    }
    printf("Running task scheduler with %d tasks...\n", num_tasks);
    while (1) {
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].task_id != 0) {
                execute_task(i);
            }
        }
    }
}

int main() {
    add_task(1, 5); // Add task with ID 1 and 5 second execution time
    add_task(2, 10); // Add task with ID 2 and 10 second execution time
    add_task(3, 15); // Add task with ID 3 and 15 second execution time
    run_scheduler(); // Run the task scheduler
    return 0;
}