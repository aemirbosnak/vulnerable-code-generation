//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 10

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    time_t start_time;
    int duration;
} Task;

void run_task(Task task) {
    printf("Running task '%s'...\n", task.name);
    sleep(task.duration);
    printf("Task '%s' completed!\n\n", task.name);
}

void add_task(Task* task_list, int index) {
    printf("Adding a new task...\n");
    printf("Enter task name: ");
    scanf("%s", task_list[index].name);
    printf("Enter task duration (in seconds): ");
    scanf("%d", &task_list[index].duration);
    task_list[index].start_time = time(NULL);
    printf("Task added successfully!\n\n");
}

void print_time_remaining(Task task) {
    int time_remaining = task.start_time + task.duration - time(NULL);
    if (time_remaining > 0) {
        printf("Task '%s' is scheduled to complete in %d seconds.\n\n", task.name, time_remaining);
    } else {
        printf("Task '%s' has already completed!\n\n", task.name);
    }
}

int main() {
    Task task_list[MAX_TASKS];
    int num_tasks = 0;
    
    while (1) {
        int choice;
        printf("What do you want to do?\n");
        printf("1. Add a task\n");
        printf("2. Run a task\n");
        printf("3. Print remaining time for a task\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (num_tasks < MAX_TASKS) {
                    add_task(task_list, num_tasks);
                    num_tasks++;
                } else {
                    printf("Error: Maximum number of tasks reached!\n\n");
                }
                break;
            case 2:
                if (num_tasks > 0) {
                    int task_choice;
                    printf("Which task do you want to run?\n");
                    for (int i = 0; i < num_tasks; i++) {
                        printf("%d. %s\n", i + 1, task_list[i].name);
                    }
                    printf("Enter your choice (1-%d): ", num_tasks);
                    scanf("%d", &task_choice);
                    if (task_choice > 0 && task_choice <= num_tasks) {
                        run_task(task_list[task_choice - 1]);
                    } else {
                        printf("Error: Invalid task choice!\n\n");
                    }
                } else {
                    printf("Error: No tasks available!\n\n");
                }
                break;
            case 3:
                if (num_tasks > 0) {
                    int task_choice;
                    printf("For which task do you want to print remaining time?\n");
                    for (int i = 0; i < num_tasks; i++) {
                        printf("%d. %s\n", i + 1, task_list[i].name);
                    }
                    printf("Enter your choice (1-%d): ", num_tasks);
                    scanf("%d", &task_choice);
                    if (task_choice > 0 && task_choice <= num_tasks) {
                        print_time_remaining(task_list[task_choice - 1]);
                    } else {
                        printf("Error: Invalid task choice!\n\n");
                    }
                } else {
                    printf("Error: No tasks available!\n\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice!\n\n");
        }
    }
    return 0;
}