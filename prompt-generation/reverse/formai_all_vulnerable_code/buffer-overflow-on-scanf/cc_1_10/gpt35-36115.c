//FormAI DATASET v1.0 Category: Task Scheduler ; Style: authentic
// A Unique C Task Scheduler Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 1000

typedef struct Task {
    char task[100];
    char description[500];
    time_t due_date;
} Task;

void print_menu() {
    printf("Task Scheduler Program\n");
    printf("1. Add Task\n");
    printf("2. View Tasks for Today\n");
    printf("3. View Tasks for This Week\n");
    printf("4. View All Tasks\n");
    printf("5. Exit\n");
}

int add_task(Task tasks[], int total_tasks) {
    if (total_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return total_tasks;
    }

    Task new_task;
    printf("Enter task name: ");
    scanf(" %[^\n]", &new_task.task);
    printf("Enter task description: ");
    scanf(" %[^\n]", &new_task.description);
    printf("Enter due date (mm/dd/yyyy): ");
    scanf(" %ld", &new_task.due_date);

    tasks[total_tasks++] = new_task;
    printf("Task added successfully.\n");
    return total_tasks;
}

void print_task(Task task) {
    printf("----------------------------------------\n");
    printf("Task: %s\n", task.task);
    printf("Description: %s\n", task.description);
    printf("Due Date: %s", ctime(&task.due_date));
}

void view_tasks_today(Task tasks[], int total_tasks) {
    time_t current_time = time(NULL);
    int i;

    for (i = 0; i < total_tasks; i++) {
        Task task = tasks[i];
        double diff_time = difftime(task.due_date, current_time);

        if (diff_time >= 0 && diff_time <= 86400) {
            print_task(task);
        }
    }
}

void view_tasks_week(Task tasks[], int total_tasks) {
    time_t current_time = time(NULL);
    int i;

    for (i = 0; i < total_tasks; i++) {
        Task task = tasks[i];
        double diff_time = difftime(task.due_date, current_time);

        if (diff_time >= 0 && diff_time <= 604800) {
            print_task(task);
        }
    }
}

void view_all_tasks(Task tasks[], int total_tasks) {
    int i;

    for (i = 0; i < total_tasks; i++) {
        print_task(tasks[i]);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int total_tasks = 0;
    int option;

    do {
        print_menu();
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                total_tasks = add_task(tasks, total_tasks);
                break;
            case 2:
                view_tasks_today(tasks, total_tasks);
                break;
            case 3:
                view_tasks_week(tasks, total_tasks);
                break;
            case 4:
                view_all_tasks(tasks, total_tasks);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please enter a number between 1 and 5.\n");
        }
    } while (option != 5);

    return 0;
}