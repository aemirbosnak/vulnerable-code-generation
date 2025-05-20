//FormAI DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10 // maximum number of tasks that can be scheduled
#define MAX_TASK_LENGTH 50 // maximum length of each task
#define MAX_PRIORITY 10 // maximum priority level of tasks
#define TIME_INTERVAL 1 // time interval for executing tasks (in seconds)

int numTasks = 0; // number of tasks currently scheduled

/* Data structure to represent a task */
typedef struct task {
    char description[MAX_TASK_LENGTH]; // task description
    int priority; // task priority
    int timeLeft; // time left until task can be executed
} Task;

Task tasks[MAX_TASKS]; // array to hold all scheduled tasks

/* Function to add a task to the list of scheduled tasks
   Returns 0 if task was added successfully, -1 otherwise */
int addTask(char *description, int priority) {
    if (numTasks == MAX_TASKS) {
        printf("Cannot add task: maximum number of tasks reached\n");
        return -1;
    }
    Task newTask;
    strncpy(newTask.description, description, MAX_TASK_LENGTH);
    newTask.priority = priority;
    newTask.timeLeft = (priority-1) * TIME_INTERVAL;
    tasks[numTasks] = newTask;
    numTasks++;
    return 0;
}

/* Function to remove a task from the list of scheduled tasks
   Returns 0 if task was removed successfully, -1 otherwise */
int removeTask(int taskNum) {
    if (taskNum >= numTasks || taskNum < 0) {
        printf("Invalid task number\n");
        return -1;
    }
    for (int i = taskNum; i < numTasks-1; i++) {
        tasks[i] = tasks[i+1];
    }
    numTasks--;
    return 0;
}

/* Function to print out all scheduled tasks */
void printTasks() {
    if (numTasks == 0) {
        printf("No tasks currently scheduled\n");
        return;
    }
    printf("Scheduled Tasks:\n");
    printf("%-4s%-20s%s\n", "Num", "Description", "Priority");
    for (int i = 0; i < numTasks; i++) {
        printf("%-4d%-20s%d\n", i, tasks[i].description, tasks[i].priority);
    }
}

/* Function to execute the next task with the highest priority */
void executeNextTask() {
    if (numTasks == 0) {
        printf("No tasks currently scheduled\n");
        return;
    }
    int maxPriority = 0;
    int maxPriorityIndex = -1;
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].priority > maxPriority && tasks[i].timeLeft == 0) {
            maxPriority = tasks[i].priority;
            maxPriorityIndex = i;
        }
    }
    if (maxPriorityIndex == -1) {
        printf("No tasks available to execute\n");
        return;
    }
    printf("Executing task: %s\n", tasks[maxPriorityIndex].description);
    removeTask(maxPriorityIndex);
}

/* Function to update the time left until each task can be executed */
void updateTimeLeft() {
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].timeLeft > 0) {
            tasks[i].timeLeft -= TIME_INTERVAL;
        }
    }
}

int main() {
    printf("Welcome to Brave Task Scheduler!\n");

    while (1) {
        printf("\nAvailable Options:\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Print Tasks\n");
        printf("4. Execute Next Task\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char description[MAX_TASK_LENGTH];
                printf("Please enter task description: ");
                scanf("%s", description);
                int priority;
                printf("Please enter task priority (1-10): ");
                scanf("%d", &priority);
                if (addTask(description, priority) == 0) {
                    printf("Task added successfully!\n");
                }
                break;
            }
            case 2: {
                int taskNum;
                printf("Please enter task number to remove: ");
                scanf("%d", &taskNum);
                if (removeTask(taskNum) == 0) {
                    printf("Task removed successfully!\n");
                }
                break;
            }
            case 3: {
                printTasks();
                break;
            }
            case 4: {
                executeNextTask();
                break;
            }
            case 5: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice, please try again\n");
                break;
            }
        }

        updateTimeLeft();
    }

    return 0;
}