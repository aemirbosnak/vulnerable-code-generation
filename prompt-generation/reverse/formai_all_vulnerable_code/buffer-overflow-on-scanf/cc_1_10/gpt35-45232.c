//FormAI DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    int time;
    int priority;
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void print_task_list() {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: time=%d, priority=%d\n", task_list[i].id, task_list[i].time, task_list[i].priority);
    }
}

int get_random_time() {
    return (rand() % 10) + 1; // Random time between 1 and 10
}

int get_random_priority() {
    return (rand() % 5) + 1; // Random priority between 1 and 5
}

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("Cannot add task, maximum task limit reached.\n");
        return;
    }

    Task new_task;
    new_task.id = num_tasks + 1;
    new_task.time = get_random_time();
    new_task.priority = get_random_priority();
    task_list[num_tasks++] = new_task;

    printf("Added task %d to task list.\n", new_task.id);
}

void remove_task() {
    if (num_tasks == 0) {
        printf("Cannot remove task, task list is empty.\n");
        return;
    }

    int task_id;
    printf("Enter task id to remove: ");
    scanf("%d", &task_id);

    for (int i = 0; i < num_tasks; i++) {
        if (task_list[i].id == task_id) {
            for (int j = i; j < num_tasks - 1; j++) {
                task_list[j] = task_list[j+1];
            }
            num_tasks--;
            printf("Removed task %d from task list.\n", task_id);
            return;
        }
    }

    printf("Could not find task %d in task list.\n", task_id);
}

void run_task() {
    if (num_tasks == 0) {
        printf("Cannot run task, task list is empty.\n");
        return;
    }

    int selected_task = 0;
    for (int i = 0; i < num_tasks; i++) {
        if (task_list[i].priority > task_list[selected_task].priority) {
            selected_task = i;
        } else if (task_list[i].priority == task_list[selected_task].priority &&
                   task_list[i].time < task_list[selected_task].time) {
            selected_task = i;
        }
    }

    printf("Task %d is running...\n", task_list[selected_task].id);
    task_list[selected_task].time = 0;

    for (int i = selected_task; i < num_tasks - 1; i++) {
        task_list[i] = task_list[i+1];
    }
    num_tasks--;
}

int main() {
    srand(time(NULL)); // Initialize random seed

    printf("Welcome to Task Scheduler version 1.0\n");
    printf("====================================\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Run Task\n");
        printf("4. Print Task List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                run_task();
                break;
            case 4:
                print_task_list();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}