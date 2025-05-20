//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_COUNT 3 // Number of tasks to be scheduled

typedef struct task {
    int id; // Task ID
    int duration; // Task duration in seconds
    int start_time; // Task start time in seconds
} Task;

int get_current_time() {
    return (int) time(NULL);
}

void wait_for_seconds(int seconds) {
    int start_time = get_current_time();
    while ((get_current_time() - start_time) < seconds);
}

void run_task(Task* task) {
    task->start_time = get_current_time();
    printf("Task %d started.\n", task->id);
    wait_for_seconds(task->duration);
    printf("Task %d completed in %d seconds.\n", task->id, task->duration);
}

int get_random_number_between(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void schedule_tasks(Task* tasks, int task_count) {
    int i;
    for (i = 0; i < task_count; i++) {
        int delay = get_random_number_between(1, 5); // Random delay between 1 and 5 seconds
        wait_for_seconds(delay);
        run_task(&tasks[i]);
    }
}

int main() {
    srand(get_current_time()); // Seed random number generator with the current time

    Task tasks[TASK_COUNT];

    int i;
    for (i = 0; i < TASK_COUNT; i++) {
        tasks[i].id = i + 1;
        tasks[i].duration = get_random_number_between(5, 10); // Random duration between 5 and 10 seconds
    }

    schedule_tasks(tasks, TASK_COUNT);

    return 0;
}