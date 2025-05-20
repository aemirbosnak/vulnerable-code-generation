//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

// Task structure
typedef struct {
    char task_name[20];
    int task_priority;
    int task_duration;
    int task_arrival_time;
    int task_completion_time;
    int task_status;
} Task;

// Task scheduling algorithm
void schedule_tasks(Task tasks[], int num_tasks) {
    int i, j, current_time = 0;
    Task task_queue[MAX_TASKS];
    int task_queue_size = 0;

    // Initialize task queue
    for (i = 0; i < num_tasks; i++) {
        task_queue[task_queue_size++] = tasks[i];
    }

    // Sort task queue by arrival time
    for (i = 0; i < task_queue_size - 1; i++) {
        for (j = i + 1; j < task_queue_size; j++) {
            if (task_queue[i].task_arrival_time > task_queue[j].task_arrival_time) {
                Task temp = task_queue[i];
                task_queue[i] = task_queue[j];
                task_queue[j] = temp;
            }
        }
    }

    // Execute tasks
    while (task_queue_size > 0) {
        current_time = task_queue[0].task_arrival_time;
        while (current_time < task_queue[0].task_completion_time) {
            task_queue[0].task_status = 1;
            printf("%s started at %d\n", task_queue[0].task_name, current_time);
            current_time += task_queue[0].task_duration;
        }
        printf("%s completed at %d\n", task_queue[0].task_name, current_time);
        task_queue_size--;
    }
}

int main() {
    Task tasks[] = {
        {"Task 1", 1, 10, 0, 20, 0},
        {"Task 2", 2, 15, 5, 35, 0},
        {"Task 3", 3, 20, 10, 60, 0},
        {"Task 4", 4, 5, 20, 25, 0},
        {"Task 5", 5, 30, 30, 80, 0}
    };
    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    schedule_tasks(tasks, num_tasks);

    return 0;
}