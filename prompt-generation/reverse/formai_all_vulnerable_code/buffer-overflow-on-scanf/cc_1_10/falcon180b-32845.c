//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

typedef struct {
    int task_id;
    char task_name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void execute_task(Task task) {
    printf("Executing task %d: %s\n", task.task_id, task.task_name);
}

void create_task(Task* task_list, int task_count, int task_id) {
    printf("Enter task ID: ");
    scanf("%d", &task_list[task_count].task_id);
    printf("Enter task name: ");
    scanf("%s", task_list[task_count].task_name);
    printf("Enter priority: ");
    scanf("%d", &task_list[task_count].priority);
    printf("Enter burst time: ");
    scanf("%d", &task_list[task_count].burst_time);
    task_list[task_count].waiting_time = 0;
    task_list[task_count].turnaround_time = 0;
}

void display_tasks(Task* task_list, int task_count) {
    printf("\nTask ID\tTask Name\tPriority\tBurst Time\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d\t%s\t%d\t%d\n", task_list[i].task_id, task_list[i].task_name, task_list[i].priority, task_list[i].burst_time);
    }
}

int main() {
    Task task_list[MAX_TASKS];
    int task_count = 0;
    int choice;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    printf("Welcome to the Task Scheduler!\n");
    printf("Enter number of tasks (up to %d): ", MAX_TASKS);
    scanf("%d", &task_count);

    for (int i = 0; i < task_count; i++) {
        create_task(task_list, i, i + 1);
    }

    printf("\nTasks created:\n");
    display_tasks(task_list, task_count);

    do {
        printf("\nEnter your choice:\n");
        printf("1. Execute task\n");
        printf("2. Display tasks\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task ID to execute: ");
                scanf("%d", &task_list[0].task_id);
                execute_task(task_list[0]);
                break;
            case 2:
                display_tasks(task_list, task_count);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}