//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: calm
// TaskScheduler.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

// Task structure
typedef struct {
    char name[20];
    time_t start_time;
    time_t end_time;
} Task;

// Scheduler structure
typedef struct {
    Task tasks[MAX_TASKS];
    int num_tasks;
} Scheduler;

// Function prototypes
void addTask(Scheduler* scheduler, const char* name, time_t start_time, time_t end_time);
void scheduleTasks(Scheduler* scheduler);
void printTasks(Scheduler* scheduler);

// Function definitions
void addTask(Scheduler* scheduler, const char* name, time_t start_time, time_t end_time) {
    Task task;
    strcpy(task.name, name);
    task.start_time = start_time;
    task.end_time = end_time;
    scheduler->tasks[scheduler->num_tasks++] = task;
}

void scheduleTasks(Scheduler* scheduler) {
    int i;
    for (i = 0; i < scheduler->num_tasks; i++) {
        printf("Scheduling task %s from %s to %s\n", scheduler->tasks[i].name, ctime(&scheduler->tasks[i].start_time), ctime(&scheduler->tasks[i].end_time));
    }
}

void printTasks(Scheduler* scheduler) {
    int i;
    for (i = 0; i < scheduler->num_tasks; i++) {
        printf("Task %s from %s to %s\n", scheduler->tasks[i].name, ctime(&scheduler->tasks[i].start_time), ctime(&scheduler->tasks[i].end_time));
    }
}

int main() {
    Scheduler scheduler;
    scheduler.num_tasks = 0;

    addTask(&scheduler, "Task 1", time(NULL), time(NULL) + 3600);
    addTask(&scheduler, "Task 2", time(NULL) + 1800, time(NULL) + 5400);
    addTask(&scheduler, "Task 3", time(NULL) + 3600, time(NULL) + 7200);

    scheduleTasks(&scheduler);
    printTasks(&scheduler);

    return 0;
}