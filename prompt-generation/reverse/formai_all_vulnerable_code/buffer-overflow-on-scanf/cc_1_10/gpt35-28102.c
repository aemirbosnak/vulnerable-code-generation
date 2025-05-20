//FormAI DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// Structure to store task details
struct Task {
    int id;
    int priority;
    int time;
    char desc[50];
};

// Function to add a new task
void addTask(struct Task *tasks, int *numTasks) {
    printf("\nAdding a new task to the list...\n");
    struct Task newTask;

    printf("Enter task ID: ");
    scanf("%d", &newTask.id);

    printf("Enter task priority (1-10): ");
    scanf("%d", &newTask.priority);

    printf("Enter estimated time to complete task (in minutes): ");
    scanf("%d", &newTask.time);

    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.desc);

    tasks[*numTasks] = newTask;
    (*numTasks)++;

    printf("Task added successfully!\n");
}

// Function to display all tasks
void displayTasks(struct Task *tasks, int numTasks) {
    printf("\nCurrent List of Tasks:\n");
    printf("ID\tPriority\tTime (in mins)\tDescription\n");
    for(int i=0;i<numTasks;i++) {
        printf("%d\t%d\t\t%d\t\t%s\n", tasks[i].id, tasks[i].priority, tasks[i].time, tasks[i].desc);
    }
}

// Function to remove a task based on ID
void removeTask(struct Task *tasks, int *numTasks, int taskID) {
    int i;
    bool taskFound = false;
    for(i=0;i<*numTasks;i++) {
        if(tasks[i].id == taskID) {
            taskFound = true;
            break;
        }
    }

    if(taskFound) {
        printf("\nRemoving task with ID %d\n", taskID);
        for(int j=i;j<*numTasks-1;j++) {
            tasks[j] = tasks[j+1];
        }
        (*numTasks)--;
        printf("Task removed successfully!\n");
    } else {
        printf("\nTask with ID %d not found!\n", taskID);
    }
}

// The actual scheduling function - this will run the tasks based on priority
void schedule(struct Task *tasks, int numTasks) {
    // Selection sort the array of tasks based on priority
    for(int i=0;i<numTasks-1;i++) {
        int maxIndex = i;
        for(int j=i+1;j<numTasks;j++) {
            if(tasks[j].priority > tasks[maxIndex].priority) {
                maxIndex = j;
            }
        }
        struct Task temp = tasks[i];
        tasks[i] = tasks[maxIndex];
        tasks[maxIndex] = temp;
    }

    printf("Starting task scheduler...\n");

    for(int i=0;i<numTasks;i++) {
        printf("\nRunning task %d...\n", tasks[i].id);
        printf("Task description: %s\n", tasks[i].desc);
        printf("Estimated time to complete task: %d minutes\n", tasks[i].time);
        printf("Task completed successfully!\n");
    }

    printf("\nAll tasks completed!\n");
}

int main() {
    struct Task tasks[100];
    int numTasks = 0;

    printf("\n####### Welcome to the Task Scheduler #######\n");

    while(true) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new task\n");
        printf("2. View all tasks\n");
        printf("3. Remove a task\n");
        printf("4. Schedule tasks\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addTask(tasks, &numTasks);
                break;

            case 2:
                displayTasks(tasks, numTasks);
                break;

            case 3: {
                int taskID;
                printf("\nEnter the ID of the task you want to remove: ");
                scanf("%d", &taskID);
                removeTask(tasks, &numTasks, taskID);
                break;
            }

            case 4:
                if(numTasks <= 0) {
                    printf("\nNothing to schedule! Please add some tasks first.\n");
                } else {
                    schedule(tasks, numTasks);
                }
                break;

            case 5:
                printf("\nThank you for using Task Scheduler! Exiting...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}