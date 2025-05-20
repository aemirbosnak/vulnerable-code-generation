//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    void (*func)(void); // function pointer to the task function
    int interval; // time in seconds between task executions
    time_t lastExecution; // timestamp of the last execution
} Task;

Task tasks[MAX_TASKS]; // array of tasks
int taskCount = 0; // current number of tasks

// function to add a task
bool addTask(void (*func)(void), int interval) {
    if (taskCount >= MAX_TASKS) {
        return false; // can't add more tasks
    }
    tasks[taskCount].func = func;
    tasks[taskCount].interval = interval;
    tasks[taskCount].lastExecution = time(NULL);
    taskCount++;
    return true;
}

// function to run all tasks that are due for execution
void runDueTasks() {
    time_t now = time(NULL);
    for (int i = 0; i < taskCount; i++) {
        Task *task = &tasks[i];
        if ((now - task->lastExecution) >= task->interval) {
            task->func();
            task->lastExecution = now;
        }
    }
}

// example task functions
void printMessage() {
    printf("Hello, world!\n");
}

void printTime() {
    time_t now = time(NULL);
    printf("Current time: %s", ctime(&now));
}

int main() {
    // add some tasks
    addTask(printMessage, 2); // print "Hello, world!" every 2 seconds
    addTask(printTime, 5); // print current time every 5 seconds
    // run the tasks in a loop
    while (true) {
        runDueTasks();
        // add a small delay to reduce CPU usage
        usleep(100000);
    }
    return 0;
}