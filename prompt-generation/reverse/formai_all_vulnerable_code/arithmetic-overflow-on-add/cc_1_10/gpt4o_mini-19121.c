//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t schedule_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, int delay_seconds) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full, can't add new task.\n");
        return;
    }
    
    strcpy(task_list[task_count].name, name);
    task_list[task_count].schedule_time = time(NULL) + delay_seconds;
    task_count++;
    
    printf("Task '%s' added. It will run in %d seconds.\n", name, delay_seconds);
}

void view_tasks() {
    if (task_count == 0) {
        printf("No tasks scheduled.\n");
        return;
    }
    
    printf("Current Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s - Scheduled at %s", i + 1, task_list[i].name, ctime(&task_list[i].schedule_time));
    }
}

void delete_task(int index) {
    if (index < 1 || index > task_count) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = index - 1; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
    }
    
    task_count--;
    printf("Task %d deleted successfully.\n", index);
}

void execute_tasks() {
    time_t current_time = time(NULL);
    
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].schedule_time <= current_time) {
            printf("Executing task: %s\n", task_list[i].name);
            delete_task(i + 1);
            i--; // Since we deleted a task, adjust the index accordingly
        }
    }
}

void display_menu() {
    printf("\n--- Task Scheduler ---\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Execute Tasks\n");
    printf("4. Delete Task\n");
    printf("5. Exit\n");
    printf("----------------------\n");
}

int main() {
    int choice, delay_seconds, task_index;
    char task_name[TASK_NAME_LENGTH];
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf(" %[^\n]", task_name);
                printf("Enter delay in seconds: ");
                scanf("%d", &delay_seconds);
                add_task(task_name, delay_seconds);
                break;
                
            case 2:
                view_tasks();
                break;
                
            case 3:
                execute_tasks();
                break;
                
            case 4:
                view_tasks();
                printf("Enter task number to delete: ");
                scanf("%d", &task_index);
                delete_task(task_index);
                break;
                
            case 5:
                printf("Exiting Task Scheduler. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}