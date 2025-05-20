//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int numTasks = 5;
    int* taskArray = (int*)malloc(numTasks * sizeof(int));
    for (int i = 0; i < numTasks; i++) {
        taskArray[i] = rand() % 100;
    }

    int numProcesses = 2;
    int* processArray = (int*)malloc(numProcesses * sizeof(int));
    for (int i = 0; i < numProcesses; i++) {
        processArray[i] = rand() % 100;
    }

    printf("Task Array: ");
    for (int i = 0; i < numTasks; i++) {
        printf("%d ", taskArray[i]);
    }
    printf("\n");

    printf("Process Array: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d ", processArray[i]);
    }
    printf("\n");

    int* taskSchedules = (int*)malloc(numTasks * sizeof(int));
    for (int i = 0; i < numTasks; i++) {
        taskSchedules[i] = 0;
    }

    int* processSchedules = (int*)malloc(numProcesses * sizeof(int));
    for (int i = 0; i < numProcesses; i++) {
        processSchedules[i] = 0;
    }

    for (int i = 0; i < numTasks; i++) {
        if (taskArray[i] < processArray[0]) {
            taskSchedules[i] = 1;
        } else if (taskArray[i] < processArray[1]) {
            taskSchedules[i] = 2;
        } else {
            taskSchedules[i] = 0;
        }
    }

    for (int i = 0; i < numProcesses; i++) {
        if (processArray[i] < taskArray[0]) {
            processSchedules[i] = 1;
        } else if (processArray[i] < taskArray[1]) {
            processSchedules[i] = 2;
        } else {
            processSchedules[i] = 0;
        }
    }

    printf("Task Schedules: ");
    for (int i = 0; i < numTasks; i++) {
        printf("%d ", taskSchedules[i]);
    }
    printf("\n");

    printf("Process Schedules: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d ", processSchedules[i]);
    }
    printf("\n");

    return 0;
}