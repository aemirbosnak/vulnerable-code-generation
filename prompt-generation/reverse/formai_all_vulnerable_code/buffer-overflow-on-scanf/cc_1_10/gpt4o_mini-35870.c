//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    int interval; // interval in seconds
    time_t next_run; // next time it should run
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(char *name, int interval) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached! Cannot add more tasks.\n");
        return;
    }

    strncpy(task_list[task_count].name, name, TASK_NAME_LEN - 1);
    task_list[task_count].name[TASK_NAME_LEN - 1] = '\0';
    task_list[task_count].interval = interval;
    task_list[task_count].next_run = time(NULL) + interval;
    task_count++;
    printf("Task '%s' added with an interval of %d seconds.\n", name, interval);
}

void remove_task(char *name) {
    for (int i = 0; i < task_count; i++) {
        if (strcmp(task_list[i].name, name) == 0) {
            printf("Removing task '%s'.\n", task_list[i].name);
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            return;
        }
    }
    printf("Task '%s' not found.\n", name);
}

void list_tasks() {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf(" - %s (Next Run: %s)\n", 
               task_list[i].name, 
               ctime(&task_list[i].next_run));
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (difftime(current_time, task_list[i].next_run) >= 0) {
            printf("Executing task '%s'...\n", task_list[i].name);
            task_list[i].next_run = current_time + task_list[i].interval;
        }
    }
}

void show_menu() {
    printf("Simple Task Scheduler\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. List Tasks\n");
    printf("4. Execute Tasks\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char task_name[TASK_NAME_LEN];
    int interval;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", task_name);
                printf("Enter interval in seconds: ");
                scanf("%d", &interval);
                add_task(task_name, interval);
                break;
            
            case 2:
                printf("Enter task name to remove: ");
                scanf("%s", task_name);
                remove_task(task_name);
                break;

            case 3:
                list_tasks();
                break;

            case 4:
                execute_tasks();
                break;

            case 5:
                printf("Exiting Task Scheduler. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // sleep for a while
    }

    return 0;
}