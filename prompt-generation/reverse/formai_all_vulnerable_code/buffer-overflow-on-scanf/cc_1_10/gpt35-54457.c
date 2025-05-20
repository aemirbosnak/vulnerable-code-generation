//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[50];
    int priority;
    int time_to_execute;
} Task;

void add_task(Task tasks[], int *num_tasks);
void delete_task(Task tasks[], int *num_tasks);
void view_tasks(Task tasks[], int num_tasks);
void run_tasks(Task tasks[], int num_tasks);

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;
    char command[10];
    
    printf("Welcome to Sherlock's Task Scheduler!\n");
    
    while (true) {
        printf("\nEnter a command (Add, Delete, View, Run or Exit): ");
        scanf("%s", command);
        if (strcmp(command, "Add") == 0) {
            add_task(tasks, &num_tasks);
        } else if (strcmp(command, "Delete") == 0) {
            delete_task(tasks, &num_tasks);
        } else if (strcmp(command, "View") == 0) {
            view_tasks(tasks, num_tasks);
        } else if (strcmp(command, "Run") == 0) {
            run_tasks(tasks, num_tasks);
        } else if (strcmp(command, "Exit") == 0) {
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("\nInvalid command!\n");
        }
    }
    
    return 0;
}

void add_task(Task tasks[], int *num_tasks) {
    if (*num_tasks == MAX_TASKS) {
        printf("\nNo more tasks can be added!\n");
    } else {
        printf("\nEnter task name: ");
        scanf("%s", tasks[*num_tasks].name);
        printf("Enter task priority (1 = low, 2 = medium, 3 = high): ");
        scanf("%d", &tasks[*num_tasks].priority);
        printf("Enter time to execute (in seconds): ");
        scanf("%d", &tasks[*num_tasks].time_to_execute);
        (*num_tasks)++;
        printf("\nTask added successfully!\n");
    }
}

void delete_task(Task tasks[], int *num_tasks) {
    if (*num_tasks == 0) {
        printf("\nNo tasks to delete!\n");
    } else {
        char task_name[50];
        printf("\nEnter task name to delete: ");
        scanf("%s", task_name);
        bool found = false;
        for (int i = 0; i < *num_tasks; i++) {
            if (strcmp(task_name, tasks[i].name) == 0) {
                found = true;
                for (int j = i; j < *num_tasks - 1; j++) {
                    tasks[j] = tasks[j+1];
                }
                (*num_tasks)--;
                printf("\nTask deleted successfully!\n");
                break;
            }
        }
        if (!found) {
            printf("\nTask not found!\n");
        }
    }
}

void view_tasks(Task tasks[], int num_tasks) {
    if (num_tasks == 0) {
        printf("\nNo tasks to view!\n");
    } else {
        printf("\nTask List:\n");
        printf("-----------------------------------------------------\n");
        printf("| %-20s | %-10s | %-15s |\n", "Task Name", "Priority", "Time to Execute");
        printf("-----------------------------------------------------\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("| %-20s | %-10d | %-15d |\n", tasks[i].name, tasks[i].priority, tasks[i].time_to_execute);
        }
        printf("-----------------------------------------------------\n");
    }
}

void run_tasks(Task tasks[], int num_tasks) {
    if (num_tasks == 0) {
        printf("\nNo tasks to run!\n");
    } else {
        printf("\nRunning tasks:\n");
        printf("-----------------------\n");
        for (int i = 0; i < num_tasks; i++) {
            printf("Running task %d: %s\n", i+1, tasks[i].name);
            printf("Priority: %d\n", tasks[i].priority);
            printf("Time to execute: %d seconds\n", tasks[i].time_to_execute);
            printf("Task completed!\n");
        }
        printf("-----------------------\n");
    }
}