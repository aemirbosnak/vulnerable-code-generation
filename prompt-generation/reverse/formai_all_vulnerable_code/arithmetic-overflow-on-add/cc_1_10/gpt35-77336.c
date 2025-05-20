//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100 // Max tasks in the scheduler
#define MAX_NAME_LENGTH 50 // Max length of task name

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t time; // Time in seconds
    void (*task)(void); // Function pointer to task
} TASK;

TASK tasks[MAX_TASKS]; // Array of tasks
int numTasks = 0; // Current number of tasks
 
void AddTask(char name[], time_t time, void (*task)(void))
{
    if (numTasks >= MAX_TASKS) {
        printf("Cannot add more tasks!");
        return;
    }
 
    // Create a new task
    TASK newTask;
    strncpy(newTask.name, name, MAX_NAME_LENGTH);
    newTask.time = time;
    newTask.task = task;
 
    tasks[numTasks++] = newTask;
}
 
void RunScheduler()
{
    while (1) {
        for (int i = 0; i < numTasks; i++) {
            // If it's time to run this task
            if (time(NULL) >= tasks[i].time) {
                printf("Running task: %s\n", tasks[i].name);
                tasks[i].task();
                tasks[i].time = time(NULL) + 60; // Run again in a minute
            }
        }
 
        // Sleep for 1 second to avoid busy waiting
        sleep(1);
    }
}

// Example tasks
void Task1()
{
    printf("Task 1\n");
}

void Task2()
{
    printf("Task 2\n");
}

int main()
{
    AddTask("Task 1", time(NULL) + 10, Task1);
    AddTask("Task 2", time(NULL) + 15, Task2);
    RunScheduler();
 
    return 0;
}