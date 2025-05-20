//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to print the task status
void printStatus(int taskStatus) {
    switch (taskStatus) {
        case 1:
            printf("Task is in progress.\n");
            break;
        case 2:
            printf("Task is completed.\n");
            break;
        case 3:
            printf("Task is cancelled.\n");
            break;
        case 4:
            printf("Task is on hold.\n");
            break;
        default:
            printf("Invalid task status.\n");
    }
}

// Function to schedule tasks
void scheduleTask(int taskStatus) {
    srand(time(0));
    int shape = rand() % 5;

    switch (shape) {
        case 1:
            printf("Task is in progress.\n");
            break;
        case 2:
            printf("Task is completed.\n");
            break;
        case 3:
            printf("Task is cancelled.\n");
            break;
        case 4:
            printf("Task is on hold.\n");
            break;
        default:
            printf("Invalid task status.\n");
    }
}

// Main function
int main() {
    int taskStatus;

    // Prompt user to input task status
    printf("Enter the task status (1 - In Progress, 2 - Completed, 3 - Cancelled, 4 - On Hold): ");
    scanf("%d", &taskStatus);

    // Schedule the task
    scheduleTask(taskStatus);

    // Print the task status
    printStatus(taskStatus);

    return 0;
}