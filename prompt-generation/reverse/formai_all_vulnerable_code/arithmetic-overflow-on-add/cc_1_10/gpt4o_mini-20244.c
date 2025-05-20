//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef enum {
    TASK_ONE_SHOT,
    TASK_REPEATING
} TaskType;

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t start_time;
    int interval; // in seconds for repeating tasks
    TaskType type;
    void (*task_function)(void);
    int is_scheduled;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void greet() {
    printf("Greetings, Citizen! The Time Management Core is now online.\n");
}

void farewell() {
    printf("Farewell, Citizen! The Time Management Core is shutting down.\n");
}

void add_task(const char *name, time_t start_time, int interval, TaskType type, void (*task_function)(void)) {
    if(task_count >= MAX_TASKS) {
        printf("Task limit reached! Unable to add task: %s\n", name);
        return;
    }
    strncpy(task_list[task_count].name, name, TASK_NAME_LENGTH);
    task_list[task_count].start_time = start_time;
    task_list[task_count].interval = interval;
    task_list[task_count].type = type;
    task_list[task_count].task_function = task_function;
    task_list[task_count].is_scheduled = 1;
    task_count++;
    printf("Task '%s' added.\n", name);
}

void execute_task(Task *t) {
    printf("Executing task: %s.\n", t->name);
    t->task_function();
}

void *run_scheduler(void *arg) {
    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < task_count; i++) {
            if (task_list[i].is_scheduled && (task_list[i].type == TASK_ONE_SHOT && current_time >= task_list[i].start_time)) {
                execute_task(&task_list[i]);
                task_list[i].is_scheduled = 0; // remove the task after execution
            } 
            else if (task_list[i].is_scheduled && task_list[i].type == TASK_REPEATING && current_time >= task_list[i].start_time) {
                execute_task(&task_list[i]);
                task_list[i].start_time += task_list[i].interval; // reschedule to the next interval
            }
        }
        sleep(1); // check every second
    }
    return NULL;
}

void example_task() {
    printf("Running example task...\n");
}

int main() {
    greet();

    // Schedule tasks
    time_t current_time = time(NULL);
    add_task("One Shot Task", current_time + 5, 0, TASK_ONE_SHOT, example_task);
    add_task("Repeating Task", current_time + 3, 5, TASK_REPEATING, example_task);

    // Run the task scheduler
    run_scheduler(NULL);

    farewell();
    return 0;
}