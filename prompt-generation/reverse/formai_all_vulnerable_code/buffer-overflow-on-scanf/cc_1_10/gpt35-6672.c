//FormAI DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

// Structure to hold task information
struct task {
    int id;
    char name[20];
    time_t start_time;
    int interval;
};

// Global variables
int num_tasks = 0;
struct task task_list[MAX_TASKS];
int task_counter = 0;

// Signal handler for SIGINT, prints all the running tasks and exits the program
void sigint_handler(int sig) {
    printf("Received SIGINT, exiting...\n");
    printf("Printing all the running tasks:\n");
    for(int i=0; i<num_tasks; i++) {
        printf("Task ID: %d, Name: %s, Start Time: %ld, Interval: %d\n", task_list[i].id, task_list[i].name, task_list[i].start_time, task_list[i].interval);
    }
    exit(0);
}

// Function to add a new task
void add_task(char name[], int interval) {
    if(num_tasks >= MAX_TASKS) {
        printf("Task limit reached. Unable to add new task.\n");
        return;
    }
    struct task new_task;
    new_task.id = task_counter++;
    strcpy(new_task.name, name);
    new_task.start_time = time(NULL);
    new_task.interval = interval;
    task_list[num_tasks++] = new_task;
    printf("Task added successfully.\n");
}

// Function to remove a task
void remove_task(int id) {
    int index = -1;
    for(int i=0; i<num_tasks; i++) {
        if(task_list[i].id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Unable to find task with ID %d\n", id);
        return;
    }
    for(int i=index; i<num_tasks-1; i++) {
        task_list[i] = task_list[i+1];
    }
    num_tasks--;
    printf("Task removed successfully.\n");
}

// Function to display all the tasks
void display_tasks() {
    printf("Total tasks: %d\n", num_tasks);
    for(int i=0; i<num_tasks; i++) {
        printf("Task ID: %d, Name: %s, Start Time: %ld, Interval: %d\n", task_list[i].id, task_list[i].name, task_list[i].start_time, task_list[i].interval);
    }
}

// Main function
int main() {
    // Install signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    // Main loop
    while(1) {
        // Display menu
        printf("\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Read user input
        int choice;
        scanf("%d", &choice);

        // Perform action based on user input
        switch(choice) {
            case 1: {
                // Add new task
                char name[20];
                int interval;
                printf("Enter task name: ");
                scanf("%s", name);
                printf("Enter task interval in seconds: ");
                scanf("%d", &interval);
                add_task(name, interval);
                break;
            }
            case 2: {
                // Remove task
                int id;
                printf("Enter task ID to remove: ");
                scanf("%d", &id);
                remove_task(id);
                break;
            }
            case 3: {
                // Display all tasks
                display_tasks();
                break;
            }
            case 4: {
                // Exit program
                printf("Exiting program...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }

        // Sleep for 1 second
        sleep(1);

        // Check if any tasks need to be executed
        for(int i=0; i<num_tasks; i++) {
            time_t current_time = time(NULL);
            double elapsed = difftime(current_time, task_list[i].start_time);
            if(elapsed >= task_list[i].interval) {
                printf("Executing task: %s\n", task_list[i].name);
                task_list[i].start_time = current_time;
            }
        }
    }
    return 0;
}