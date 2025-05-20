//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME 50

typedef struct {
    char name[MAX_TASK_NAME];
    int interval; // in seconds
    time_t last_run;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int interval) {
    if (task_count < MAX_TASKS) {
        strncpy(tasks[task_count].name, name, MAX_TASK_NAME - 1);
        tasks[task_count].name[MAX_TASK_NAME - 1] = '\0';
        tasks[task_count].interval = interval;
        tasks[task_count].last_run = 0;
        task_count++;
        printf("Gratitude: Task '%s' added with an interval of %d seconds.\n", name, interval);
    } else {
        printf("Gratitude: Unable to add task! Limit of %d tasks reached.\n", MAX_TASKS);
    }
}

void execute_task(int index) {
    printf("Gratitude: Executing Task - %s\n", tasks[index].name);
    tasks[index].last_run = time(NULL);
    // Simulate task execution with sleep
    sleep(1);
    printf("Gratitude: Task '%s' executed successfully!\n", tasks[index].name);
}

void check_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].last_run == 0 || (current_time - tasks[i].last_run) >= tasks[i].interval) {
            execute_task(i);
        }
    }
}

void list_tasks() {
    printf("Gratitude: Here are your scheduled tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf(" - Task %d: '%s' (runs every %d seconds)\n", i + 1, tasks[i].name, tasks[i].interval);
    }
}

int main() {
    char command[100];
    char task_name[MAX_TASK_NAME];
    int interval;

    printf("Welcome to the Grateful Task Scheduler!\n");

    while (1) {
        printf("\nGratitude: Please enter a command (add/list/exit): ");
        fgets(command, sizeof(command), stdin);
        
        // Remove trailing newline character
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "add") == 0) {
            printf("Please enter the task name: ");
            fgets(task_name, sizeof(task_name), stdin);
            task_name[strcspn(task_name, "\n")] = 0;

            printf("Please enter the task interval in seconds: ");
            scanf("%d", &interval);
            getchar(); // Consume newline left by scanf
            
            add_task(task_name, interval);
        } else if (strcmp(command, "list") == 0) {
            list_tasks();
            check_tasks();
        } else if (strcmp(command, "exit") == 0) {
            printf("Gratitude: Thank you for using the Grateful Task Scheduler! Goodbye.\n");
            break;
        } else {
            printf("Gratitude: Unknown command. Please try again.\n");
        }
    }

    return 0;
}