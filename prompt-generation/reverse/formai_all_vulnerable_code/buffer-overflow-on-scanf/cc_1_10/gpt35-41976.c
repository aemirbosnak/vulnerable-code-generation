//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_LENGTH 50

typedef struct Task {
    int id;
    char description[MAX_TASK_LENGTH];
    int duration;
    int priority;
    bool completed;
} Task;

typedef struct TaskScheduler {
    Task tasks[MAX_TASKS];
    int numTasks;
} TaskScheduler;

// Helper function to generate random task information
Task generateTask(int id) {
    Task task;
    task.id = id;
    snprintf(task.description, MAX_TASK_LENGTH, "Task %d", id);
    task.duration = rand() % 5 + 1; // Random duration between 1 and 5 seconds
    task.priority = rand() % 10; // Random priority between 0 and 9
    task.completed = false;
    return task;
}

// Helper function to print task information
void printTask(Task task) {
    printf("ID: %d, Description: %s, Duration: %d, Priority: %d, Completed: %s\n", 
           task.id, task.description, task.duration, task.priority, task.completed ? "true" : "false");
}

// Adds a task to the task scheduler
void addTask(TaskScheduler* scheduler) {
    if (scheduler->numTasks < MAX_TASKS) {
        Task task = generateTask(scheduler->numTasks);
        scheduler->tasks[scheduler->numTasks++] = task;
        printf("Task added successfully!\n");
    } else {
        printf("Unable to add task, task scheduler is already full.\n");
    }
}

// Removes a task from the task scheduler
void removeTask(TaskScheduler* scheduler) {
    int id;
    printf("Enter the ID of the task to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < scheduler->numTasks; i++) {
        if (scheduler->tasks[i].id == id) {
            for (int j = i+1; j < scheduler->numTasks; j++) {
                scheduler->tasks[j-1] = scheduler->tasks[j];
            }
            scheduler->numTasks--;
            printf("Task removed successfully!\n");
            return;
        }
    }
    printf("No task with ID %d found.\n", id);
}

// Marks a task as completed
void completeTask(TaskScheduler* scheduler) {
    int id;
    printf("Enter the ID of the task to mark as completed: ");
    scanf("%d", &id);
    for (int i = 0; i < scheduler->numTasks; i++) {
        if (scheduler->tasks[i].id == id) {
            scheduler->tasks[i].completed = true;
            printf("Task marked as completed!\n");
            return;
        }
    }
    printf("No task with ID %d found.\n", id);
}

// Prints a list of all the tasks in the task scheduler
void listTasks(TaskScheduler* scheduler) {
    printf("Task List:\n");
    for (int i = 0; i < scheduler->numTasks; i++) {
        printTask(scheduler->tasks[i]);
    }
}

int main() {
    TaskScheduler scheduler = {0};
    srand(time(NULL)); // Initialize random number generator with current time

    printf("Welcome to the Multiplayer Task Scheduler!\n\n");

    char choice;
    do {
        printf("MENU:\n");
        printf("1. Add task\n");
        printf("2. Remove task\n");
        printf("3. Mark task as completed\n");
        printf("4. List tasks\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addTask(&scheduler);
                break;
            case '2':
                removeTask(&scheduler);
                break;
            case '3':
                completeTask(&scheduler);
                break;
            case '4':
                listTasks(&scheduler);
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '5');

    return 0;
}