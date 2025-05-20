//FormAI DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Task {
    char name[100];
    time_t scheduledTime;
    void (*functionPointer)(void);
} Task;

void printHello() {
    printf("\nHello there!\n");
}

void printGoodbye() {
    printf("\nGoodbye!\n");
}

void executeTask(Task task) {
    printf("Executing task '%s'\n", task.name);
    task.functionPointer();
}

void addTask(Task* taskList, int* taskCount, Task taskToAdd) {
    taskList[*taskCount] = taskToAdd;
    (*taskCount)++;
    printf("Task added!\n");
}

Task* removeTask(Task* taskList, int* taskCount, int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove >= *taskCount) {
        printf("Invalid index!\n");
        return NULL;
    }
    
    Task* removedTask = malloc(sizeof(Task));
    memcpy(removedTask, &taskList[indexToRemove], sizeof(Task));
    
    for (int i = indexToRemove; i < *taskCount - 1; i++) {
        taskList[i] = taskList[i+1];
    }
    
    (*taskCount)--;
    printf("Task removed!\n");
    
    return removedTask;
}

void printTaskList(Task* taskList, int taskCount) {
    printf("Current Task List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i+1, taskList[i].name);
    }
}

int main() {
    Task taskList[10];
    int taskCount = 0;

    Task helloTask = {"Say Hello", time(NULL) + 2, &printHello};
    Task goodbyeTask = {"Say Goodbye", time(NULL) + 10, &printGoodbye};
    
    printf("Adding Tasks...\n");
    addTask(taskList, &taskCount, helloTask);
    addTask(taskList, &taskCount, goodbyeTask);
    printTaskList(taskList, taskCount);
    
    printf("\n");
    
    while (taskCount > 0) {
        for (int i = 0; i < taskCount; i++) {
            Task currentTask = taskList[i];
            if (currentTask.scheduledTime <= time(NULL)) {
                executeTask(currentTask);
                removeTask(taskList, &taskCount, i);
            }
        }
        
        printf("\nCurrent Task List:\n");
        printTaskList(taskList, taskCount);
        printf("\n");
        
        // Add random task every 5 seconds
        if (time(NULL) % 5 == 0) {
            Task randomTask;
            sprintf(randomTask.name, "Random Task %d", taskCount + 1);
            randomTask.scheduledTime = time(NULL) + rand() % 10 + 1;
            randomTask.functionPointer = taskCount % 2 == 0 ? &printHello : &printGoodbye;
            addTask(taskList, &taskCount, randomTask);
        }
        
        // Sleep for 1 second
        sleep(1);
    }
    
    printf("All tasks completed!\n");

    return 0;
}