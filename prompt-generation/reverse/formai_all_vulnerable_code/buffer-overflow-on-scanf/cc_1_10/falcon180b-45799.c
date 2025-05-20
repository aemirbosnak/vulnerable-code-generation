//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TIME 100

// Struct to represent a task
typedef struct {
    int id;
    int start_time;
    int end_time;
    int duration;
    int priority;
} Task;

// Function to compare tasks based on their start times
int compare_tasks(const void *a, const void *b) {
    Task *task1 = (Task *)a;
    Task *task2 = (Task *)b;
    return (task1->start_time - task2->start_time);
}

// Function to schedule tasks using round-robin scheduling
void schedule_tasks(Task *tasks, int num_tasks) {
    int current_time = 0;
    int completed_tasks = 0;
    int task_index = 0;

    // Sort tasks based on their start times
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    // Schedule tasks using round-robin scheduling
    while (completed_tasks < num_tasks) {
        // Execute the task with the smallest start time
        Task *current_task = &tasks[task_index];
        if (current_time >= current_task->start_time && current_time < current_task->end_time) {
            printf("Executing task %d at time %d\n", current_task->id, current_time);
            completed_tasks++;
        }

        // Update the current time
        current_time++;

        // Move to the next task
        task_index++;
        if (task_index == num_tasks) {
            task_index = 0;
        }
    }
}

// Function to generate random tasks
void generate_tasks(Task *tasks, int num_tasks) {
    srand(time(NULL));

    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i + 1;
        tasks[i].start_time = rand() % MAX_TIME;
        tasks[i].end_time = tasks[i].start_time + rand() % MAX_TIME;
        tasks[i].duration = tasks[i].end_time - tasks[i].start_time;
        tasks[i].priority = rand() % 10;
    }
}

// Main function
int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    Task tasks[MAX_TASKS];
    generate_tasks(tasks, num_tasks);

    schedule_tasks(tasks, num_tasks);

    return 0;
}