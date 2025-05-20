//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct {
    int id;
    int priority;
    int duration;
    time_t start_time;
} Task;

typedef struct {
    int count;
    Task tasks[MAX_TASKS];
} TaskList;

TaskList task_list = {0};

void add_task(int priority, int duration) {
    Task task;
    task.id = task_list.count + 1;
    task.priority = priority;
    task.duration = duration;
    task.start_time = time(NULL);
    task_list.tasks[task_list.count++] = task;
    printf("Task %d added to the task list.\n", task.id);
}

void run_task(Task task) {
    printf("Running task %d for %d seconds...\n", task.id, task.duration);
    int remaining_time = task.duration;
    while (remaining_time > 0) {
        time_t current_time = time(NULL);
        remaining_time = task.duration - (current_time - task.start_time);
    }
    printf("Task %d completed.\n", task.id);
}

void run_tasks() {
    while (task_list.count > 0) {
        Task highest_priority_task = task_list.tasks[0];
        int highest_priority_index = 0;
        for (int i = 1; i < task_list.count; i++) {
            if (task_list.tasks[i].priority > highest_priority_task.priority) {
                highest_priority_task = task_list.tasks[i];
                highest_priority_index = i;
            }
        }
        run_task(highest_priority_task);
        for (int i = highest_priority_index + 1; i < task_list.count; i++) {
            task_list.tasks[i-1] = task_list.tasks[i];
        }
        task_list.count--;
    }
}

int main() {
    srand(time(NULL));
    int num_tasks = rand() % MAX_TASKS + 1;
    for (int i = 0; i < num_tasks; i++) {
        int priority = rand() % MAX_PRIORITY + 1;
        int duration = rand() % 10 + 1;
        add_task(priority, duration);
    }
    run_tasks();
    printf("All tasks completed.\n");
    return 0;
}