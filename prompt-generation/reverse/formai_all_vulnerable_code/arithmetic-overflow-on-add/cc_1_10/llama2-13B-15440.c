//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_DESCRIPTION_LENGTH 50

typedef struct task {
    char name[20];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t due_date;
} task_t;

typedef struct schedule {
    task_t tasks[MAX_TASKS];
    int num_tasks;
} schedule_t;

void add_task(schedule_t *schedule, char *name, char *description, time_t due_date);
void print_schedule(schedule_t *schedule);
void run_scheduler(schedule_t *schedule);

schedule_t *create_schedule() {
    schedule_t *schedule = malloc(sizeof(schedule_t));
    schedule->num_tasks = 0;
    return schedule;
}

int main() {
    schedule_t *schedule = create_schedule();

    // Add some tasks
    add_task(schedule, "Buy milk", "Don't forget to buy milk on your way home", time(0) + 30 * 60);
    add_task(schedule, "Walk the dog", "Take Fido for a walk before you head to work", time(0) + 2 * 60);
    add_task(schedule, "Meet with boss", "Schedule a meeting with your boss to discuss the new project", time(0) + 1 * 60);

    // Print the schedule
    print_schedule(schedule);

    // Run the scheduler
    run_scheduler(schedule);

    return 0;
}

void add_task(schedule_t *schedule, char *name, char *description, time_t due_date) {
    task_t *task = malloc(sizeof(task_t));
    strcpy(task->name, name);
    strcpy(task->description, description);
    task->due_date = due_date;
    schedule->tasks[schedule->num_tasks++] = *task;
}

void print_schedule(schedule_t *schedule) {
    printf("Your schedule for today:\n");
    for (int i = 0; i < schedule->num_tasks; i++) {
        printf("  %-20s: %s (due at %s)\n", schedule->tasks[i].name, schedule->tasks[i].description, ctime(&schedule->tasks[i].due_date));
    }
}

void run_scheduler(schedule_t *schedule) {
    for (int i = 0; i < schedule->num_tasks; i++) {
        if (time(0) >= schedule->tasks[i].due_date) {
            printf("Task %d (%s) is due now!\n", i, schedule->tasks[i].name);
        }
    }
}