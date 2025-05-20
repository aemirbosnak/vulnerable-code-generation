//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    int id;
    char name[50];
    int delay; // Delay in seconds
    struct Task* next;
} Task;

Task* head = NULL;
int task_count = 0;

void add_task(const char* name, int delay);
void execute_task(int task_id);
void task_handler(int signum);
void list_tasks();
void clear_tasks();
void signal_exit(int signum);

int main() {
    signal(SIGINT, signal_exit); // Handle Ctrl+C to exit gracefully

    while (1) {
        printf("Simple C Task Scheduler\n");
        printf("1. Add Task\n2. List Tasks\n3. Execute Task\n4. Exit\n");
        printf("Choose an option: ");
        
        int choice, delay;
        char name[50];

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (task_count < MAX_TASKS) {
                    printf("Enter task name: ");
                    scanf("%s", name);
                    printf("Enter delay in seconds: ");
                    scanf("%d", &delay);
                    add_task(name, delay);
                } else {
                    printf("Maximum task limit reached!\n");
                }
                break;
            case 2:
                list_tasks();
                break;
            case 3:
                printf("Enter task ID to execute: ");
                int task_id;
                scanf("%d", &task_id);
                execute_task(task_id);
                break;
            case 4:
                clear_tasks();
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void add_task(const char* name, int delay) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->id = task_count + 1;
    strcpy(new_task->name, name);
    new_task->delay = delay;
    new_task->next = head;
    head = new_task;
    task_count++;
    printf("Task '%s' added with ID %d and delay of %d seconds.\n", name, new_task->id, delay);
}

void execute_task(int task_id) {
    Task* current = head;
    while (current != NULL) {
        if (current->id == task_id) {
            printf("Executing task '%s' after a delay of %d seconds...\n", current->name, current->delay);
            sleep(current->delay);
            printf("Task '%s' executed successfully!\n", current->name);
            return;
        }
        current = current->next;
    }
    printf("Task with ID %d not found!\n", task_id);
}

void list_tasks() {
    if (head == NULL) {
        printf("No tasks in the scheduler.\n");
        return;
    }
    printf("Scheduled Tasks:\n");
    Task* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Delay: %d seconds\n", current->id, current->name, current->delay);
        current = current->next;
    }
}

void clear_tasks() {
    Task* current = head;
    Task* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    task_count = 0;
    printf("All tasks cleared from the scheduler.\n");
}

void signal_exit(int signum) {
    printf("\nExiting the Task Scheduler...\n");
    clear_tasks();
    exit(0);
}