//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t execute_time;
    void (*task_function)(void);
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void greetings() {
    printf("Hello, this is your scheduled task executing!\n");
}

void farewell() {
    printf("Goodbye, this task has finished execution!\n");
}

void add_task(const char *name, unsigned int delay, void (*function)(void)) {
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, name, TASK_NAME_LENGTH - 1);
        task_list[task_count].name[TASK_NAME_LENGTH - 1] = '\0';
        task_list[task_count].execute_time = time(NULL) + delay;
        task_list[task_count].task_function = function;
        task_count++;
        printf("Task '%s' scheduled to execute in %u seconds.\n", name, delay);
    } else {
        printf("Error: Task list is full, cannot add '%s'.\n", name);
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].execute_time <= current_time) {
            printf("Executing task: %s\n", task_list[i].name);
            task_list[i].task_function();
            // Shift tasks down after execution (remove the completed task)
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Decrement i to check the next task in the next iteration
        }
    }
}

void display_menu() {
    printf("\nSimple Task Scheduler\n");
    printf("1. Schedule Greeting Task\n");
    printf("2. Schedule Farewell Task\n");
    printf("3. Execute Scheduled Tasks\n");
    printf("4. Exit\n");
}

int main() {
    int choice, delay;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter delay in seconds for Greeting Task: ");
                scanf("%d", &delay);
                add_task("Greeting Task", delay, greetings);
                break;
            case 2:
                printf("Enter delay in seconds for Farewell Task: ");
                scanf("%d", &delay);
                add_task("Farewell Task", delay, farewell);
                break;
            case 3:
                execute_tasks();
                break;
            case 4:
                printf("Exiting the scheduler. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // Sleep for a while to avoid busy waiting
    }
    return 0;
}