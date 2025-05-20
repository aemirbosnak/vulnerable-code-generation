//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100

/* Task struct */
typedef struct {
    int id;
    char task_name[20];
    int duration;
} task_t;

/* Task list */
task_t task_list[MAX_TASKS];
int num_tasks = 0;

/* Function declarations */
void add_task();
void delete_task();
void display_tasks();
void schedule_tasks();

/*
 * Main function
 */
int main() {
    int choice;

    do {
        printf("===== Task Scheduler =====\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Display Tasks\n");
        printf("4. Schedule Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                delete_task();
                break;
            case 3:
                display_tasks();
                break;
            case 4:
                schedule_tasks();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");
    } while (1);

    return 0;
}

/*
 * Function to add a task
 */
void add_task() {
    /* Check if task list is full */
    if (num_tasks >= MAX_TASKS) {
        printf("Task list is full. Cannot add any more tasks.\n");
        return;
    }

    /* Initialize new task */
    task_t new_task;
    new_task.id = num_tasks + 1;

    printf("Enter task name (max 20 characters): ");
    scanf("%s", new_task.task_name);

    printf("Enter task duration (in minutes): ");
    scanf("%d", &new_task.duration);

    /* Add task to list */
    task_list[num_tasks] = new_task;
    num_tasks++;

    printf("Task added successfully.\n");
}

/*
 * Function to delete a task
 */
void delete_task() {
    int task_id, i, j;

    printf("Enter task ID to delete: ");
    scanf("%d", &task_id);

    /* Find task in list */
    for (i = 0; i < num_tasks; i++) {
        if (task_list[i].id == task_id)
            break;
    }

    /* Task not found */
    if (i == num_tasks) {
        printf("Task not found.\n");
        return;
    }

    /* Remove task from list */
    for (j = i; j < num_tasks - 1; j++) {
        task_list[j] = task_list[j+1];
    }
    num_tasks--;

    printf("Task deleted successfully.\n");
}

/*
 * Function to display all tasks
 */
void display_tasks() {
    int i;

    printf("Task ID\tTask Name\tDuration (min)\n");
    printf("------------------------------------------------\n");
    for (i = 0; i < num_tasks; i++) {
        printf("%d\t%s\t\t%d\n", task_list[i].id, task_list[i].task_name, task_list[i].duration);
    }
    printf("------------------------------------------------\n");
}

/*
 * Function to schedule tasks
 */
void schedule_tasks() {
    int total_duration = 0, i;

    /* Compute total duration */
    for (i = 0; i < num_tasks; i++) {
        total_duration += task_list[i].duration;
    }

    /* Print schedule */
    printf("Scheduled Tasks:\n");
    printf("Task Name\tDuration (min)\n");
    printf("------------------------------------------------\n");
    for (i = 0; i < num_tasks; i++) {
        printf("%s\t\t%d\n", task_list[i].task_name, task_list[i].duration);
    }
    printf("------------------------------------------------\n");
    printf("Total duration: %d minutes\n", total_duration);
}