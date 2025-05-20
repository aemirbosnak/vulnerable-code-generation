//FormAI DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TASK_COUNT 5

typedef struct {
    int id; // identifier
    int interval; // time interval in seconds
    time_t last_exec_time; // last execution time
    bool active; // flag if task is active
} Task;

Task tasks[TASK_COUNT]; // an array of tasks

// initializes the array of tasks with random values
void init_tasks() {
    for(int i=0; i<TASK_COUNT; i++) {
        tasks[i].id = i;
        tasks[i].interval = rand() % 10 + 1; // random interval between 1 and 10 seconds
        tasks[i].last_exec_time = time(NULL);
        tasks[i].active = true;
    }
}

// execute a task
void execute_task(Task * t) {
    printf("Executing task %d\n", t->id);
    t->last_exec_time = time(NULL);
}

// check if a task should be executed
bool should_execute(Task * t) {
    time_t now = time(NULL);
    return t->active && (now - t->last_exec_time) >= t->interval;
}

int main() {
    init_tasks();

    // main loop
    while(true) {
        // check if any tasks should be executed and do so
        for(int i=0; i<TASK_COUNT; i++) {
            Task * t = &tasks[i];
            if(should_execute(t)) {
                execute_task(t);
            }
        }

        // wait 1 second before checking again
        sleep(1);
    }

    return 0;
}