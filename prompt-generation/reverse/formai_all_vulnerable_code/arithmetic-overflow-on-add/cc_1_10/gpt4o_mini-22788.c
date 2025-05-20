//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct Task {
    char name[TASK_NAME_LENGTH];
    time_t execute_at;
    void (*function)(void);
} Task;

typedef struct Scheduler {
    Task tasks[MAX_TASKS];
    int task_count;
} Scheduler;

void greet() {
    printf("🎉 It's time to say hello! Hello World! 🎉\n");
}

void countdown() {
    printf("⏰ Countdown initiated! ⏰\n");
    for(int i = 5; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("🚀 Countdown complete! 🚀\n");
}

void create_task(Scheduler *scheduler, const char *name, time_t execute_at, void (*function)(void)) {
    if (scheduler->task_count < MAX_TASKS) {
        Task new_task;
        strncpy(new_task.name, name, TASK_NAME_LENGTH);
        new_task.execute_at = execute_at;
        new_task.function = function;
        scheduler->tasks[scheduler->task_count] = new_task;
        scheduler->task_count++;
        printf("Task '%s' scheduled to execute at %s\n", name, ctime(&execute_at));
    } else {
        printf("🚫 Scheduler is full! Unable to schedule '%s'. 🚫\n", name);
    }
}

void run_tasks(Scheduler *scheduler) {
    time_t now;
    while (scheduler->task_count > 0) {
        now = time(NULL);
        for (int i = 0; i < scheduler->task_count; i++) {
            if (scheduler->tasks[i].execute_at <= now) {
                scheduler->tasks[i].function();
                printf("Task '%s' executed.\n", scheduler->tasks[i].name);
                // Shift tasks down in the array
                for (int j = i; j < scheduler->task_count - 1; j++) {
                    scheduler->tasks[j] = scheduler->tasks[j + 1];
                }
                scheduler->task_count--;
                i--; // Adjust index due to shifting
            }
        }
        sleep(1); // Wait for a second before checking
    }
}

int main() {
    Scheduler scheduler = { .task_count = 0 };

    // Scheduling some tasks
    time_t now = time(NULL);
    create_task(&scheduler, "Greet Task", now + 2, greet);
    create_task(&scheduler, "Countdown Task", now + 5, countdown);
    create_task(&scheduler, "Second Greet", now + 10, greet);

    // Run all scheduled tasks
    printf("🕒 Starting Scheduler... 🕒\n");
    run_tasks(&scheduler);

    printf("All tasks complete! 🎊 Scheduler shutting down... 🎊\n");
    return 0;
}