//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 20

typedef void (*TaskFunction)(void);

typedef struct {
    char name[TASK_NAME_LENGTH];
    TaskFunction function;
    int delay;
    int execution_time;
    int is_scheduled;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void task_one() {
    printf("😃 Task One: Water the plants! 🌱\n");
}

void task_two() {
    printf("🎉 Task Two: Cook a delicious meal! 🍳\n");
}

void task_three() {
    printf("📚 Task Three: Read a fascinating book! 📖\n");
}

void add_task(const char* name, TaskFunction function, int delay) {
    if (task_count >= MAX_TASKS) {
        printf("😢 Maximum task limit reached!\n");
        return;
    }
    
    strncpy(tasks[task_count].name, name, TASK_NAME_LENGTH - 1);
    tasks[task_count].function = function;
    tasks[task_count].delay = delay;
    tasks[task_count].is_scheduled = 1;
    
    task_count++;
    printf("🎊 Task '%s' added with a delay of %d seconds! 🎉\n", name, delay);
}

void execute_tasks() {
    time_t start_time = time(NULL);
    while (1) {
        int executed_any = 0;
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].is_scheduled) {
                tasks[i].execution_time = start_time + tasks[i].delay;

                if (time(NULL) >= tasks[i].execution_time) {
                    tasks[i].function();
                    tasks[i].is_scheduled = 0; // Mark as executed
                    executed_any = 1;
                }
            }
        }
        
        if (!executed_any) {
            printf("🌈 Waiting for tasks to execute...\n");
            sleep(1);
        }
        
        // If all tasks are done, exit the loop.
        int all_done = 1;
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].is_scheduled) {
                all_done = 0;
                break;
            }
        }
        
        if (all_done) {
            printf("🎉 All tasks completed successfully! 🎉\n");
            break;
        }
    }
}

void signal_handler(int signum) {
    printf("\n🤗 Scheduler paused. Press Ctrl+C to exit or any other key to resume.\n");
    getchar(); // Wait for input
    printf("😊 Resuming Scheduler...\n");
}

int main() {
    signal(SIGINT, signal_handler); // Setting up a signal handler

    add_task("Water Plants", task_one, 3);
    add_task("Cook Meal", task_two, 5);
    add_task("Read Book", task_three, 7);

    printf("\n🚀 Starting the Task Scheduler! ✨\n");
    execute_tasks();

    return 0;
}