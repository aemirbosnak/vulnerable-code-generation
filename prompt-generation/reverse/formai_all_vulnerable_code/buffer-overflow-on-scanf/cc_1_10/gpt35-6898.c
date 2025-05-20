//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10    // maximum number of tasks in the scheduler

typedef struct {
    int id;
    char name[50];
    int priority;
    int time;
    int status;         // 0: not executed, 1: executing, 2: executed
} Task;

Task task_list[MAX_TASKS];  // list of tasks in the scheduler
int num_tasks = 0;          // number of tasks in the scheduler

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    printf("Enter task name: ");
    scanf("%s", task_list[num_tasks].name);
    printf("Enter task priority: ");
    scanf("%d", &task_list[num_tasks].priority);
    printf("Enter task time: ");
    scanf("%d", &task_list[num_tasks].time);
    task_list[num_tasks].status = 0;
    task_list[num_tasks].id = num_tasks + 1;
    num_tasks++;
}

void display_tasks() {
    printf("ID\tNAME\tPRIORITY\tTIME\tSTATUS\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t%d\t\t%d\t", task_list[i].id, task_list[i].name, task_list[i].priority, task_list[i].time);
        if (task_list[i].status == 0) {
            printf("Not executed\n");
        } else if (task_list[i].status == 1) {
            printf("Executing\n");
        } else {
            printf("Executed\n");
        }
    }
}

void execute_tasks() {
    int current_time = 0;
    for (int i = 0; i < num_tasks; i++) {
        int shortest_idx = -1;
        for (int j = 0; j < num_tasks; j++) {
            if (task_list[j].status == 0 && task_list[j].time <= current_time && (shortest_idx == -1 || task_list[j].priority < task_list[shortest_idx].priority)) {
                shortest_idx = j;
            }
        }
        if (shortest_idx != -1) {
            task_list[shortest_idx].status = 1;
            printf("Executing task %d: %s\n", task_list[shortest_idx].id, task_list[shortest_idx].name);
            for (int t = 1; t <= task_list[shortest_idx].time; t++) {
                current_time++;
                printf("Time elapsed: %d/%d\n", t, task_list[shortest_idx].time);
            }
            task_list[shortest_idx].status = 2;
            printf("Task %d: %s executed successfully.\n", task_list[shortest_idx].id, task_list[shortest_idx].name);
        } else {
            printf("No tasks available for execution.\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to the task scheduler!\n");
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add task\n");
        printf("2. Display tasks\n");
        printf("3. Execute tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                display_tasks();
                break;
            case 3:
                execute_tasks();
                break;
            case 4:
                printf("Exiting task scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}