//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
    char *name;
    unsigned int interval;
    time_t start_time;
    time_t next_run_time;
} Task;

typedef struct TaskScheduler {
    Task *tasks;
    unsigned int num_tasks;
    unsigned int current_index;
} TaskScheduler;

TaskScheduler *create_task_scheduler(unsigned int num_tasks) {
    TaskScheduler *scheduler = malloc(sizeof(TaskScheduler));
    
    scheduler->tasks = malloc(num_tasks * sizeof(Task));
    
    scheduler->num_tasks = num_tasks;
    
    scheduler->current_index = 0;
    
    return scheduler;
}

void free_task_scheduler(TaskScheduler *scheduler) {
    for (unsigned int i = 0; i < scheduler->num_tasks; i++) {
        free(scheduler->tasks[i].name);
    }
    
    free(scheduler->tasks);
    
    free(scheduler);
}

void add_task(TaskScheduler *scheduler, Task task) {
    scheduler->tasks[scheduler->num_tasks] = task;
    
    scheduler->num_tasks++;
}

void run_next_task(TaskScheduler *scheduler) {
    if (scheduler->current_index >= scheduler->num_tasks) {
        scheduler->current_index = 0;
    }
    
    Task *task = &scheduler->tasks[scheduler->current_index];
    
    if (time(NULL) >= task->next_run_time) {
        printf("Running task %s\n", task->name);
        
        task->next_run_time = time(NULL) + task->interval;
    }
    
    scheduler->current_index++;
}

int main() {
    TaskScheduler *scheduler = create_task_scheduler(3);
    
    Task task1 = {"Task 1", 1, time(NULL), time(NULL) + 1};
    Task task2 = {"Task 2", 3, time(NULL), time(NULL) + 3};
    Task task3 = {"Task 3", 5, time(NULL), time(NULL) + 5};
    
    add_task(scheduler, task1);
    add_task(scheduler, task2);
    add_task(scheduler, task3);
    
    while (1) {
        run_next_task(scheduler);
        
        sleep(1);
    }
    
    free_task_scheduler(scheduler);
    
    return 0;
}