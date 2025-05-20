//FormAI DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 20

// Struct to hold task info
struct Task {
    char name[MAX_NAME_LEN];
    time_t time;
};

// Array to hold tasks
struct Task tasks[MAX_TASKS];

// Number of tasks currently scheduled
int taskCount = 0;

// Function to add a task to the schedule
void addTask(char* name, time_t time) {
    // Check if there are already too many tasks
    if (taskCount == MAX_TASKS) {
        printf("Sorry, you can't add any more tasks to the scheduler.\n");
        return;
    }
    
    // Create new task
    struct Task newTask;
    strcpy(newTask.name, name);
    newTask.time = time;
    
    // Add new task to array
    tasks[taskCount] = newTask;
    taskCount++;
    
    printf("Task \"%s\" scheduled for %s", name, ctime(&time));
}

// Function to remove all tasks at a certain time
void removeTasks(time_t time) {
    int removedCount = 0;
    
    // Loop through all tasks
    for (int i = 0; i < taskCount; i++) {
        // Check if task time matches given time
        if (tasks[i].time == time) {
            // Shift remaining tasks down to fill gap
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j+1];
            }
            taskCount--;
            removedCount++;
        }
    }
    
    printf("%d task%s removed from the schedule.\n", removedCount, (removedCount == 1) ? "" : "s");
}

// Main function
int main() {
    // Set up some example tasks
    addTask("Buy milk", time(NULL) + 10);
    addTask("Call mom", time(NULL) + 20);
    addTask("Finish project", time(NULL) + 30);
    addTask("Take a nap", time(NULL) + 40);
    addTask("Watch a movie", time(NULL) + 50);
    
    // Remove tasks at a certain time
    removeTasks(time(NULL) + 30);
    
    // Print remaining tasks
    printf("\nRemaining tasks:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. \"%s\" at %s", i+1, tasks[i].name, ctime(&tasks[i].time));
    }
    
    return 0;
}