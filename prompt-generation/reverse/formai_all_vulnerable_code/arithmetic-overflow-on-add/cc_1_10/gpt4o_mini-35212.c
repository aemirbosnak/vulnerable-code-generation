//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50
#define TASK_TIME_BUFFER_LENGTH 20

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t schedule_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int delay_seconds) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    strcpy(task_list[task_count].name, name);
    task_list[task_count].schedule_time = time(NULL) + delay_seconds;
    task_count++;
    printf("Task '%s' added to run in %d seconds.\n", name, delay_seconds);
}

void display_tasks() {
    if (task_count == 0) {
        printf("No scheduled tasks.\n");
        return;
    }

    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        char time_buffer[TASK_TIME_BUFFER_LENGTH];
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S",
                 localtime(&task_list[i].schedule_time));
        printf("Task %d: '%s' at %s\n", i + 1, task_list[i].name, time_buffer);
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);
    
    for (int i = 0; i < task_count; i++) {
        if (difftime(task_list[i].schedule_time, current_time) <= 0) {
            printf("Executing Task: '%s'\n", task_list[i].name);
            // Simulate task execution
            sleep(1); // simulate a task taking some time
            printf("Task '%s' completed.\n", task_list[i].name);
            // Remove task and shift tasks down
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Adjust index after removing a task
        }
    }
}

int main() {
    int choice, delay;
    char task_name[TASK_NAME_LENGTH];

    while (1) {
        printf("\n--- Simple C Task Scheduler ---\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf(" %[^\n]", task_name); // Read string with spaces
                printf("Enter delay in seconds: ");
                scanf("%d", &delay);
                add_task(task_name, delay);
                break;

            case 2:
                display_tasks();
                break;

            case 3:
                execute_tasks();
                break;

            case 4:
                printf("Exiting Task Scheduler. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
        
        // Delay to allow user to see output if hurry
        sleep(1);
    }

    return 0;
}