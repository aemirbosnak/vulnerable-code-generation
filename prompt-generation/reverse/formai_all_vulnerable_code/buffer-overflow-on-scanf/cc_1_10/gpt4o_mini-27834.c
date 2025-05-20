//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH]; 
    time_t scheduled_time;       
} Task;

void add_task(Task tasks[], int *task_count);
void display_tasks(Task tasks[], int task_count);
void execute_tasks(Task tasks[], int *task_count);
void clear_screen();

int main() {
    Task tasks[MAX_TASKS];  
    int task_count = 0;      
    int choice;

    do {
        clear_screen();
        printf("========== SIMPLE TASK SCHEDULER ==========\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &task_count);
                break;
            case 2:
                display_tasks(tasks, task_count);
                break;
            case 3:
                execute_tasks(tasks, &task_count);
                break;
            case 4:
                printf("Exiting the Task Scheduler. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }

        if (choice != 4) {
            printf("Press Enter to continue...");
            while (getchar() != '\n'); // clear input buffer
            getchar(); // wait for user input
        }
    } while (choice != 4);
    
    return 0;
}

void add_task(Task tasks[], int *task_count) {
    if (*task_count >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }
    
    printf("Enter task name: ");
    scanf("%s", tasks[*task_count].name);
    
    time_t current_time;
    time(&current_time);
    
    printf("Enter time to schedule the task (in seconds from now): ");
    int seconds;
    scanf("%d", &seconds);
    
    tasks[*task_count].scheduled_time = current_time + seconds;
    (*task_count)++;
    
    printf("Task '%s' scheduled in %d seconds!\n", tasks[*task_count - 1].name, seconds);
}

void display_tasks(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks scheduled.\n");
    } else {
        printf("Scheduled Tasks:\n");
        for (int i = 0; i < task_count; i++) {
            printf("%d: %s at %s", i + 1, tasks[i].name, ctime(&tasks[i].scheduled_time));
        }
    }
}

void execute_tasks(Task tasks[], int *task_count) {
    if (*task_count == 0) {
        printf("No tasks to execute.\n");
        return;
    }

    time_t current_time;
    time(&current_time);
    
    for (int i = 0; i < *task_count; ) {
        if (difftime(current_time, tasks[i].scheduled_time) >= 0) {
            printf("Executing task: %s\n", tasks[i].name);
            // Shift remaining tasks down
            for (int j = i; j < *task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            (*task_count)--;
        } else {
            i++;
        }
    }
}

void clear_screen() {
    // This will clear the console on Linux
    printf("\033[H\033[J");
}