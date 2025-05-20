//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void taskA();
void taskB();
void taskC();

int main() {
    printf("Initializing task scheduler...\n");
    printf("Loading tasks...\n");

    int task1Interval = 3; // task A repeats every 3 seconds
    int task2Interval = 5; // task B repeats every 5 seconds
    int task3Interval = 10; // task C repeats every 10 seconds

    printf("Task A: Repeating every %d seconds\n", task1Interval);
    printf("Task B: Repeating every %d seconds\n", task2Interval);
    printf("Task C: Repeating every %d seconds\n", task3Interval);
    printf("\n");

    time_t currentTime;
    time_t task1LastRun; // Last time task A was run
    time_t task2LastRun; // Last time task B was run
    time_t task3LastRun; // Last time task C was run

    task1LastRun = time(NULL);
    task2LastRun = time(NULL);
    task3LastRun = time(NULL);

    while (1) { // Carry on with forever
        currentTime = time(NULL);

        if(currentTime - task1LastRun >= task1Interval) { // If task A needs to run
            taskA();
            task1LastRun = currentTime;
        }

        if(currentTime - task2LastRun >= task2Interval) { // If task B needs to run
            taskB();
            task2LastRun = currentTime;
        }

        if(currentTime - task3LastRun >= task3Interval) { // If task C needs to run
            taskC();
            task3LastRun = currentTime;
        }

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}

void taskA() {
    printf("Task A: Running...\n");
    // Add task A functionality here
}

void taskB() {
    printf("Task B: Running...\n");
    // Add task B functionality here
}

void taskC() {
    printf("Task C: Running...\n");
    // Add task C functionality here
}