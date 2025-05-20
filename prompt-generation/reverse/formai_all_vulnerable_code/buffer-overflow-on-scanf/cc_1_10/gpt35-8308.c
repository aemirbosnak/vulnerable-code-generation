//FormAI DATASET v1.0 Category: Task Scheduler ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_TASKS 10 // Maximum number of tasks
#define MAX_NAME_LENGTH 20 // Maximum name length for a task

/* Structure to store task information */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    int frequency;
    int iterations; 
} Task;

/* Function Prototypes */
void addTask(Task[], int);
void displayTasks(Task[], int);
void runScheduler(Task[], int);
void executeTask(Task[], int);

/* Main function */
int main() {
    Task taskList[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while(1) {
        printf("\n\n\t Task Scheduler \n\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Run Scheduler\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addTask(taskList, taskCount);
                taskCount++;
                break;
            case 2:
                displayTasks(taskList, taskCount);
                break;
            case 3:
                runScheduler(taskList, taskCount);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/* Function to add a new task to the scheduler */
void addTask(Task taskList[], int taskCount) {
    Task newTask;

    printf("\n\t Add Task\n\n");
    printf("Enter task name: ");
    scanf("%s", newTask.name);
    printf("Enter priority (1-10): ");
    scanf("%d", &newTask.priority);
    printf("Enter frequency (in seconds): ");
    scanf("%d", &newTask.frequency);
    printf("Enter number of iterations: ");
    scanf("%d", &newTask.iterations);

    taskList[taskCount] = newTask;

    printf("\nTask added sucessfully!\n");
}

/* Function to display all tasks in the scheduler */
void displayTasks(Task taskList[], int taskCount) {
    printf("\n\n\t Task List \n\n");
    printf("Task Name \t Priority \t Frequency \t Iterations\n");

    for(int i = 0; i < taskCount; i++) {
        printf("%s \t\t %d \t\t %d \t\t %d\n", taskList[i].name, taskList[i].priority, taskList[i].frequency, taskList[i].iterations);
    }
}

/* Function to run the scheduler */
void runScheduler(Task taskList[], int taskCount) {
    while(1) {
        for(int i = 0; i < taskCount; i++) {
            executeTask(taskList, i);
        }
    }
}

/* Function to execute a single task */
void executeTask(Task taskList[], int index) {
    printf("\nExecuting task: %s\n", taskList[index].name);

    for(int i = 0; i < taskList[index].iterations; i++) {
        printf("Iteration %d \n", i+1);
        sleep(taskList[index].frequency);
    }
}