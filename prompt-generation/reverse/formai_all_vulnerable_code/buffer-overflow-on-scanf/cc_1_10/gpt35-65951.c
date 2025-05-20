//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 
#define MAX_TASKS 10
#define MAX_TASK_NAME 20
 
typedef struct {
    char name[MAX_TASK_NAME];
    int priority;
    bool completed;
} task;
 
void addTask(task t_list[], int *num_tasks);
void printTasks(task t_list[], int num_tasks);
void completeTask(task t_list[], int num_tasks);
void printCompletedTasks(task t_list[], int num_tasks);
void runTasks(task t_list[], int num_tasks);
 
int main() {
    task task_list[MAX_TASKS];
    int num_tasks = 0;
    int choice;
 
    printf("***Task Scheduler***\n");
    printf("---Main Menu---\n");
    printf("1. Add Task\n");
    printf("2. Print Tasks\n");
    printf("3. Complete Task\n");
    printf("4. Print Completed Tasks\n");
    printf("5. Run Tasks\n");
    printf("6. Exit\n");
 
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch(choice) {
            case 1:
                addTask(task_list, &num_tasks);
                break;
            case 2:
                printTasks(task_list, num_tasks);
                break;
            case 3:
                completeTask(task_list, num_tasks);
                break;
            case 4:
                printCompletedTasks(task_list, num_tasks);
                break;
            case 5:
                runTasks(task_list, num_tasks);
                break;
            case 6:
                printf("Exiting Task Scheduler...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 6);
 
    return 0;
}
 
void addTask(task t_list[], int *num_tasks) {
    if (*num_tasks >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
 
    task new_task;
 
    printf("Enter task name: ");
    scanf("%s", new_task.name);
 
    printf("Enter priority (1-10): ");
    scanf("%d", &new_task.priority);
 
    new_task.completed = false;
 
    t_list[*num_tasks] = new_task;
    (*num_tasks)++;
 
    printf("Task added successfully.\n");
}
 
void printTasks(task t_list[], int num_tasks) {
    printf("---Task List---\n");
 
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s (Priority: %d, Completed: %s)\n", i+1, t_list[i].name, t_list[i].priority, t_list[i].completed ? "Yes" : "No");
    }
}
 
void completeTask(task t_list[], int num_tasks) {
    int task_num;
 
    printTasks(t_list, num_tasks);
 
    printf("Enter task number to complete: ");
    scanf("%d", &task_num);
 
    if (task_num <= 0 || task_num > num_tasks) {
        printf("Invalid task number.\n");
        return;
    }
 
    t_list[task_num-1].completed = true;
 
    printf("Task completed successfully.\n");
}
 
void printCompletedTasks(task t_list[], int num_tasks) {
    bool found_completed_task = false;
 
    printf("---Completed Task List---\n");
 
    for (int i = 0; i < num_tasks; i++) {
        if (t_list[i].completed) {
            printf("%d. %s (Priority: %d, Completed: Yes)\n", i+1, t_list[i].name, t_list[i].priority);
            found_completed_task = true;
        }
    }
 
    if (!found_completed_task) {
        printf("No completed tasks.\n");
    }
}
 
void runTasks(task t_list[], int num_tasks) {
    if (num_tasks == 0) {
        printf("No tasks to run.\n");
        return;
    }
 
    printf("---Running Tasks---\n");
 
    int tasks_to_run[MAX_TASKS];
    int num_tasks_to_run = 0;
 
    // Find tasks to run
    for (int i = 0; i < num_tasks; i++) {
        if (!t_list[i].completed) {
            tasks_to_run[num_tasks_to_run] = i;
            num_tasks_to_run++;
        }
    }
 
    // Shuffle tasks to run using Fisher-Yates algorithm
    srand(time(NULL));
 
    for (int i = num_tasks_to_run - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = tasks_to_run[i];
        tasks_to_run[i] = tasks_to_run[j];
        tasks_to_run[j] = temp;
    }
 
    // Run tasks in order of priority for shuffled tasks
    for (int i = 0; i < num_tasks_to_run; i++) {
        int task_index = tasks_to_run[i];
        int priority = t_list[task_index].priority;
 
        printf("- Running Task %s (Priority: %d)\n", t_list[task_index].name, priority);
 
        for (int j = 0; j < 10000000; j++);
 
        printf("- Task %s completed.\n", t_list[task_index].name);
        t_list[task_index].completed = true;
    }
 
    printf("All tasks completed.\n");
}