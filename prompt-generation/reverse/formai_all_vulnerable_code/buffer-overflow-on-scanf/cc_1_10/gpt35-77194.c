//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    char name[50];
    time_t start_time;
    int duration;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    if (num_tasks < MAX_TASKS) {
        Task new_task;
        new_task.id = num_tasks + 1;

        printf("Enter task name: ");
        scanf("%s", new_task.name);

        printf("Enter task duration (in minutes): ");
        scanf("%d", &new_task.duration);

        new_task.start_time = time(NULL);

        tasks[num_tasks] = new_task;
        num_tasks++;
        printf("Task added.\n");
    } else {
        printf("Sorry, maximum number of tasks reached.\n");
    }
}

void remove_task(int task_id) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == task_id) {
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j+1];
            }
            num_tasks--;
            printf("Task removed.\n");
            return;
        }
    }
    printf("Task with ID %d not found.\n", task_id);
}

void run_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < num_tasks; i++) {
        Task task = tasks[i];
        if (current_time - task.start_time >= task.duration * 60) {
            printf("Task '%s' completed.\n", task.name);
            remove_task(task.id);
        }
    }
}

int main() {
    int choice;
    do {
        printf("Task Scheduler Menu\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Run Tasks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                if (num_tasks > 0) {
                    int task_id;
                    printf("Enter task ID: ");
                    scanf("%d", &task_id);
                    remove_task(task_id);
                } else {
                    printf("No tasks to remove.\n");
                }
                break;
            case 3:
                run_tasks();
                break;
            case 4:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}