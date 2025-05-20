//FormAI DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5 // Max number of tasks that can be scheduled

// Struct to hold information about each task
struct Task {
    int id;
    char name[20];
    int priority;
    int time;
    int completed;
};

int main() {
    printf("Welcome to the Curious Task Scheduler!\n");

    // Random seed based on current time
    srand(time(NULL));

    // Array to hold all tasks
    struct Task tasks[MAX_TASKS];

    int num_tasks = 0; // Current number of tasks

    // Loop until user decides to quit
    while (1) {
        // Print options
        printf("\nWhat do you want to do?\n");
        printf("1. Add a task\n");
        printf("2. View scheduled tasks\n");
        printf("3. Mark a task as completed\n");
        printf("4. Quit\n");

        // Get user choice
        int choice = -1;
        while (choice < 1 || choice > 4) {
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar(); // Consume newline character
        }

        // Handle user choice
        switch (choice) {
            case 1: // Add a task
                printf("\nAdding a task...\n");

                // Check if there's space for another task
                if (num_tasks == MAX_TASKS) {
                    printf("Sorry, the task scheduler is full!\n");
                } else {
                    // Get user input for task information
                    printf("Enter task name (max. 20 chars): ");
                    fgets(tasks[num_tasks].name, 20, stdin);
                    tasks[num_tasks].name[strcspn(tasks[num_tasks].name, "\n")] = '\0'; // Remove newline character

                    printf("Enter task priority (1-5): ");
                    scanf("%d", &tasks[num_tasks].priority);
                    getchar(); // Consume newline character

                    printf("Enter task time (in minutes): ");
                    scanf("%d", &tasks[num_tasks].time);
                    getchar(); // Consume newline character

                    // Generate random ID number
                    tasks[num_tasks].id = rand() % 100000;
                    printf("Task ID: %d\n", tasks[num_tasks].id);

                    // Mark task as not completed
                    tasks[num_tasks].completed = 0;
                    printf("Task added successfully!\n");

                    // Increment number of tasks
                    num_tasks++;
                }

                break;

            case 2: // View scheduled tasks
                printf("\nScheduled tasks:\n");
                
                // Print header row
                printf("%-6s%-20s%-10s%-10s%s\n", "ID", "Name", "Priority", "Time", "Completed");

                // Print task information for each task
                for (int i = 0; i < num_tasks; i++) {
                    printf("%-6d%-20s%-10d%-10d%s\n", tasks[i].id, tasks[i].name, tasks[i].priority, tasks[i].time, tasks[i].completed ? "Yes" : "No");
                }

                break;

            case 3: // Mark a task as completed
                printf("\nMarking a task as completed...\n");

                // Get user input for task ID to mark as completed
                printf("Enter task ID to mark as completed (enter 0 to cancel): ");
                int id_to_complete;
                scanf("%d", &id_to_complete);
                getchar(); // Consume newline character

                if (id_to_complete == 0) {
                    printf("Cancelled.\n");
                } else {
                    // Find the task with the given ID
                    int task_index = -1;
                    for (int i = 0; i < num_tasks; i++) {
                        if (tasks[i].id == id_to_complete) {
                            task_index = i;
                            break;
                        }
                    }

                    if (task_index == -1) { // Task not found
                        printf("Task not found!\n");
                    } else if (tasks[task_index].completed) { // Task already completed
                        printf("Task already marked as completed!\n");
                    } else { // Mark task as completed
                        tasks[task_index].completed = 1;
                        printf("Task marked as completed!\n");
                    }
                }

                break;

            case 4: // Quit
                printf("\nQuitting Curious Task Scheduler...\n");
                exit(0);

            default: // Invalid choice (should never happen)
                printf("Oops! Something went wrong.\n");
                break;
        }
    }

    return 0;
}