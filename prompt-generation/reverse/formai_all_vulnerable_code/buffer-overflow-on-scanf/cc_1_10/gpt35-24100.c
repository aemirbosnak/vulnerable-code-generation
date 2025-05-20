//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 20
#define TASK_NAME_LEN 30

// A task structure to store the name, priority and time for each task
typedef struct Task {
    char name[TASK_NAME_LEN];
    int priority;
    int time;
} Task;

// Forward declarations of functions
void addTask(Task task, Task taskList[], int* numTasks);
void removeTask(int index, Task taskList[], int* numTasks);
void printTasks(Task taskList[], int numTasks);
void scheduleTasks(Task taskList[], int numTasks);

int main() {
    Task taskList[MAX_TASKS]; // An array of Task structures to store all the tasks
    int numTasks = 0; // Counter to keep track of the number of tasks currently in the list
    char command[10]; // A string to store user input
    Task newTask; // A temporary task structure to store user input

    printf("Welcome to the Cyberpunk Task Scheduler!\n");
    printf("Type 'help' for a list of available commands.\n\n");

    // Main command loop
    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Task name: ");
            scanf("%s", newTask.name);
            printf("Task priority (1-10): ");
            scanf("%d", &newTask.priority);
            printf("Task time (minutes): ");
            scanf("%d", &newTask.time);

            // Add the task to the list and print out the task list
            addTask(newTask, taskList, &numTasks);
            printf("Tasks:\n");
            printTasks(taskList, numTasks);
        }
        else if (strcmp(command, "remove") == 0) {
            int index;
            printf("Task index: ");
            scanf("%d", &index);

            // Remove the task at the given index and print out the task list
            removeTask(index, taskList, &numTasks);
            printf("Tasks:\n");
            printTasks(taskList, numTasks);
        }
        else if (strcmp(command, "list") == 0) {
            // Print out the task list
            printf("Tasks:\n");
            printTasks(taskList, numTasks);
        }
        else if (strcmp(command, "schedule") == 0) {
            // Schedule the tasks and print out the resulting schedule
            scheduleTasks(taskList, numTasks);
        }
        else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("  add - Add a new task to the list\n");
            printf("  remove - Remove a task from the list\n");
            printf("  list - List all tasks in the list\n");
            printf("  schedule - Schedule the tasks\n");
            printf("  help - Display this help message\n");
            printf("  quit - Quit the program\n");
        }
        else if (strcmp(command, "quit") == 0) {
            // Quit the program
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Unknown command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}

// Function to add a task to the list
void addTask(Task task, Task taskList[], int* numTasks) {
    if (*numTasks < MAX_TASKS) {
        taskList[*numTasks] = task;
        *numTasks += 1;
    }
    else {
        printf("Task list is full. Cannot add task.\n");
    }
}

// Function to remove a task from the list
void removeTask(int index, Task taskList[], int* numTasks) {
    if (index >= 0 && index < *numTasks) {
        // Shift all tasks after the removed task back by one index
        for (int i = index; i < *numTasks - 1; i++) {
            taskList[i] = taskList[i+1];
        }
        *numTasks -= 1;
    }
    else {
        printf("Invalid task index. Cannot remove task.\n");
    }
}

// Function to print out all the tasks in the list
void printTasks(Task taskList[], int numTasks) {
    if (numTasks == 0) {
        printf("No tasks in the list.\n");
        return;
    }

    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s - Priority: %d, Time: %d minutes\n",
            i, taskList[i].name, taskList[i].priority, taskList[i].time);
    }
}

// Function to schedule the tasks based on their priority and time
void scheduleTasks(Task taskList[], int numTasks) {
    if (numTasks == 0) {
        printf("No tasks to schedule.\n");
        return;
    }

    int totalMinutes = 0; // Total time required to complete all tasks
    for (int i = 0; i < numTasks; i++) {
        totalMinutes += taskList[i].time;
    }

    // Generate a random starting time between 9am and 9pm
    srand(time(NULL));
    int startHour = rand() % 12 + 9; // 9am to 8pm
    int startMinute = rand() % 60;

    // Calculate the end time based on the starting time and total task time
    int endHour = startHour + (totalMinutes / 60);
    int endMinute = startMinute + (totalMinutes % 60);
    if (endMinute >= 60) {
        endHour += 1;
        endMinute -= 60;
    }
    if (endHour > 12) {
        endHour -= 12;
    }

    // Print out the schedule
    printf("Schedule:\n");
    printf("Start time: %02d:%02d %s\n", startHour > 12 ? startHour-12 : startHour,
        startMinute, startHour >= 12 ? "pm" : "am");
    printf("End time: %02d:%02d %s\n", endHour > 12 ? endHour-12 : endHour,
        endMinute, endHour >= 12 ? "pm" : "am");

    // Sort the task list based on priority (highest first)
    for (int i = 0; i < numTasks-1; i++) {
        for (int j = i+1; j < numTasks; j++) {
            if (taskList[j].priority > taskList[i].priority) {
                Task temp = taskList[i];
                taskList[i] = taskList[j];
                taskList[j] = temp;
            }
        }
    }

    // Print out the sorted task list
    printf("Tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s - Priority: %d, Time: %d minutes\n",
            i, taskList[i].name, taskList[i].priority, taskList[i].time);
    }
}