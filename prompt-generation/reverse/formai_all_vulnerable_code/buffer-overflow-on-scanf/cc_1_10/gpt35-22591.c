//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10

typedef struct {
    int task_id;
    char task_name[50];
    int task_priority;
    int task_duration;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    Task task;
    printf("Enter task name: ");
    scanf(" %[^\n]", task.task_name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &task.task_priority);
    printf("Enter task duration (in minutes): ");
    scanf("%d", &task.task_duration);

    task.task_id = ++num_tasks;

    tasks[num_tasks-1] = task;

    printf("Task added successfully!\n");
}

void remove_task() {
    int task_id;
    printf("Enter task ID: ");
    scanf("%d", &task_id);

    for(int i=0; i<num_tasks; i++) {
        if(tasks[i].task_id == task_id) {
            for(int j=i; j<num_tasks-1; j++) {
                tasks[j] = tasks[j+1];
            }
            num_tasks--;
            printf("Task removed successfully!\n");
            return;
        }
    }

    printf("Task not found!\n");
}

void list_tasks() {
    printf("\nTask List\n");
    printf("---------\n");

    for(int i=0; i<num_tasks; i++) {
        printf("ID: %d, Name: %s, Priority: %d, Duration: %d\n", tasks[i].task_id, tasks[i].task_name, tasks[i].task_priority, tasks[i].task_duration);
    }

    if(num_tasks == 0) {
        printf("No tasks found!\n");
    }
}

void execute_task() {
    int task_id;
    printf("Enter task ID: ");
    scanf("%d", &task_id);

    for(int i=0; i<num_tasks; i++) {
        if(tasks[i].task_id == task_id) {
            printf("Executing task \"%s\" for %d minutes...\n", tasks[i].task_name, tasks[i].task_duration);
            return;
        }
    }

    printf("Task not found!\n");
}

void show_menu() {
    printf("\nTask Scheduler Menu\n");
    printf("-------------------\n");
    printf("1. Add Task\n");
    printf("2. Remove Task\n");
    printf("3. List Tasks\n");
    printf("4. Execute Task\n");
    printf("5. Exit\n");
}

int main() {
    srand(time(NULL));

    while(1) {
        show_menu();

        int choice;
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                remove_task();
                break;
            case 3:
                list_tasks();
                break;
            case 4:
                execute_task();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}