//FormAI DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 5
#define MAX_TASK_NAME_LENGTH 20

typedef struct task {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    int time;
} Task;

int numTasks = 0;
Task taskList[MAX_TASKS];

void addTask(char name[], int priority, int time) {
    if (numTasks >= MAX_TASKS) {
        printf("Unable to add task. Maximum number of tasks reached.\n");
        return;
    }
    
    Task newTask;
    strcpy(newTask.name, name);
    newTask.priority = priority;
    newTask.time = time;
    
    taskList[numTasks++] = newTask;
    
    printf("Task added successfully.\n");
}

void printTasks() {
    if (numTasks == 0) {
        printf("No tasks found.\n");
        return;
    }
    
    printf("Task\tPriority\tTime\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%s\t%d\t\t%d\n", taskList[i].name, taskList[i].priority, taskList[i].time);
    }
}

void executeTasks() {
    if (numTasks == 0) {
        printf("No tasks found.\n");
        return;
    }
    
    for (int i = 1; i <= 10; i++) {
        printf("Time = %d\n", i);
        
        for (int j = 0; j < numTasks; j++) {
            if (taskList[j].time == i) {
                printf("Task %s completed.\n", taskList[j].name);
            }
        }
    }
}

int main() {
    char name[MAX_TASK_NAME_LENGTH];
    int priority, time;
    char choice;
    
    do {
        printf("\n");
        printf("Task Scheduler\n");
        printf("--------------\n");
        printf("1. Add task\n");
        printf("2. Print tasks\n");
        printf("3. Execute tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                printf("Enter task name: ");
                scanf("%s", name);
                
                printf("Enter priority (1-10): ");
                scanf("%d", &priority);
                
                printf("Enter time to complete (1-10): ");
                scanf("%d", &time);
                
                addTask(name, priority, time);
                break;
                
            case '2':
                printTasks();
                break;
                
            case '3':
                executeTasks();
                break;
                
            case '4':
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
    } while (choice != '4');
    
    return 0;
}