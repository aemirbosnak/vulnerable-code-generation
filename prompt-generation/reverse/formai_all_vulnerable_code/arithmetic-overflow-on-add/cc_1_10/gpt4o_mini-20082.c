//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct {
    void (*taskFunc)(void);
    time_t scheduledTime;
} Task;

int compareTasks(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    return (taskA->scheduledTime - taskB->scheduledTime);
}

void taskA(void) {
    printf("Executing Task A: Hello from Task A! Time: %ld\n", time(NULL));
}

void taskB(void) {
    printf("Executing Task B: Hello from Task B! Time: %ld\n", time(NULL));
}

void taskC(void) {
    printf("Executing Task C: Hello from Task C! Time: %ld\n", time(NULL));
}

void scheduleTask(Task *tasks, int *taskCount, void (*taskFunc)(void), time_t when) {
    if (*taskCount < MAX_TASKS) {
        tasks[*taskCount].taskFunc = taskFunc;
        tasks[*taskCount].scheduledTime = when;
        (*taskCount)++;
        qsort(tasks, *taskCount, sizeof(Task), compareTasks);
    } else {
        printf("Task limit reached. Cannot schedule new task.\n");
    }
}

void runTasks(Task *tasks, int taskCount) {
    time_t currentTime;
    
    while (taskCount > 0) {
        currentTime = time(NULL);
        for (int i = 0; i < taskCount; i++) {
            if (difftime(currentTime, tasks[i].scheduledTime) >= 0) {
                tasks[i].taskFunc();
                // Shift remaining tasks down the array
                for (int j = i; j < taskCount - 1; j++) {
                    tasks[j] = tasks[j + 1];
                }
                taskCount--;
                i--; // Stay at current index to check new task in this slot
            }
        }
        sleep(1); // Sleep to avoid busy looping
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    
    // Schedule tasks at specific times
    time_t now = time(NULL);
    scheduleTask(tasks, &taskCount, taskA, now + 5); // Task A: Run after 5 seconds
    scheduleTask(tasks, &taskCount, taskB, now + 10); // Task B: Run after 10 seconds
    scheduleTask(tasks, &taskCount, taskC, now + 15); // Task C: Run after 15 seconds

    printf("Scheduled tasks. Waiting for them to execute...\n");
    runTasks(tasks, taskCount);

    printf("All tasks executed. Exiting program.\n");
    return 0;
}