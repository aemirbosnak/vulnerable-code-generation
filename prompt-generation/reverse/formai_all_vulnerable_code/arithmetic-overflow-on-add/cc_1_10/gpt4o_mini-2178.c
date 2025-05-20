//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    int interval;  // in seconds
    int execution_time;  // in seconds
    time_t next_run_time;
} Task;

void add_task(Task tasks[], int *task_count);
void execute_tasks(Task tasks[], int task_count);
void display_tasks(Task tasks[], int task_count);
void simulate_execution(int execution_time);

int main() {
    Task tasks[MAX_TASKS];
    int task_count = 0;
    int choice;

    while (1) {
        printf("=== C Task Scheduler ===\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (task_count < MAX_TASKS) {
                    add_task(tasks, &task_count);
                } else {
                    printf("Max task limit reached!\n");
                }
                break;
            case 2:
                display_tasks(tasks, task_count);
                break;
            case 3:
                execute_tasks(tasks, task_count);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}

void add_task(Task tasks[], int *task_count) {
    Task new_task;
    printf("Enter Task Name: ");
    scanf("%s", new_task.name);
    printf("Enter Interval (in seconds): ");
    scanf("%d", &new_task.interval);
    printf("Enter Execution Time (in seconds): ");
    scanf("%d", &new_task.execution_time);
    
    new_task.next_run_time = time(NULL) + new_task.interval;
    
    tasks[*task_count] = new_task;
    (*task_count)++;
    
    printf("Task '%s' added successfully!\n", new_task.name);
}

void execute_tasks(Task tasks[], int task_count) {
    time_t current_time = time(NULL);
    printf("Executing tasks...\n");

    for (int i = 0; i < task_count; i++) {
        if (current_time >= tasks[i].next_run_time) {
            printf("Executing task: %s\n", tasks[i].name);
            simulate_execution(tasks[i].execution_time);
            tasks[i].next_run_time = current_time + tasks[i].interval; // Reschedule
        }
    }
}

void display_tasks(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks to display.\n");
        return;
    }
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task Name: %s, Interval: %d seconds, Execution Time: %d seconds\n",
                tasks[i].name, tasks[i].interval, tasks[i].execution_time);
    }
}

void simulate_execution(int execution_time) {
    printf("Simulating execution for %d seconds...\n", execution_time);
    for (int i = 0; i < execution_time; i++) {
        sleep(1);
    }
    printf("Execution complete!\n");
}