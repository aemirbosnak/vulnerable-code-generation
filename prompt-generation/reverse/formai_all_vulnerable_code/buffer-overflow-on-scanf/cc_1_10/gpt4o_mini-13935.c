//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 100

typedef struct {
    char name[TASK_NAME_LEN];
    time_t due_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

// Function to add a task
void add_task(const char *name, int delay) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached, cannot add more tasks!\n");
        return;
    }
    
    Task new_task;
    strncpy(new_task.name, name, TASK_NAME_LEN);
    new_task.due_time = time(NULL) + delay;
    task_list[task_count++] = new_task;
    printf("Task '%s' added, will execute in %d seconds.\n", new_task.name, delay);
}

// Function to execute due tasks
void execute_due_tasks() {
    time_t now = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].due_time <= now) {
            printf("Executing task: %s\n", task_list[i].name);
            // Remove the executed task by shifting the rest of the tasks up
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Check the current index again after shifting
        }
    }
}

// Function to display the tasks
void display_tasks() {
    if (task_count == 0) {
        printf("No scheduled tasks.\n");
        return;
    }
    printf("Scheduled tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task: %s, Due in: %ld seconds\n", task_list[i].name, task_list[i].due_time - time(NULL));
    }
    printf("\n");
}

int main() {
    int choice, delay;
    char task_name[TASK_NAME_LEN];

    while (1) {
        printf("Simple Task Scheduler\n");
        printf("1. Add Task\n");
        printf("2. Show Tasks\n");
        printf("3. Execute Due Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", task_name);
                printf("Enter delay (in seconds): ");
                scanf("%d", &delay);
                add_task(task_name, delay);
                break;
            case 2:
                display_tasks();
                break;
            case 3:
                execute_due_tasks();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
        sleep(1); // To prevent rapid looping
    }

    return 0;
}