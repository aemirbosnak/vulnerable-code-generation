//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_DESCRIPTION 256

typedef struct {
    char description[MAX_DESCRIPTION];
    time_t execution_time;
    char frequency; // 'O' for one-time, 'D' for daily, 'W' for weekly
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskList;

void add_task(TaskList* task_list, const char* description, time_t execution_time, char frequency) {
    if (task_list->task_count >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    Task new_task;
    strncpy(new_task.description, description, MAX_DESCRIPTION);
    new_task.execution_time = execution_time;
    new_task.frequency = frequency;
    
    task_list->tasks[task_list->task_count] = new_task;
    task_list->task_count++;
}

void execute_tasks(TaskList* task_list) {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_list->task_count; i++) {
        if (task_list->tasks[i].execution_time <= current_time) {
            printf("Executing Task: %s\n", task_list->tasks[i].description);
            // Remove task after execution
            for (int j = i; j < task_list->task_count - 1; j++) {
                task_list->tasks[j] = task_list->tasks[j + 1];
            }
            task_list->task_count--;
            i--; // Adjust index after removal
        }
    }
}

void save_tasks(TaskList* task_list) {
    FILE* file = fopen("tasks.dat", "wb");
    if (file != NULL) {
        fwrite(task_list, sizeof(TaskList), 1, file);
        fclose(file);
    } else {
        printf("Error saving tasks to file.\n");
    }
}

void load_tasks(TaskList* task_list) {
    FILE* file = fopen("tasks.dat", "rb");
    if (file != NULL) {
        fread(task_list, sizeof(TaskList), 1, file);
        fclose(file);
    }
}

void print_tasks(TaskList* task_list) {
    printf("Current Tasks:\n");
    for (int i = 0; i < task_list->task_count; i++) {
        char buffer[26];
        struct tm* tm_info;
        tm_info = localtime(&task_list->tasks[i].execution_time);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("Task: %s | Time: %s | Frequency: %c\n", task_list->tasks[i].description, buffer, task_list->tasks[i].frequency);
    }
}

int main() {
    TaskList task_list = { .task_count = 0 };
    
    load_tasks(&task_list);
    
    int choice;
    do {
        printf("Task Scheduler\n");
        printf("1. Add Task\n");
        printf("2. Execute Tasks\n");
        printf("3. Print Tasks\n");
        printf("4. Save Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: {
                char description[MAX_DESCRIPTION];
                struct tm execution_time;
                char frequency;
                printf("Enter task description: ");
                fgets(description, MAX_DESCRIPTION, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline

                printf("Enter execution time (YYYY-MM-DD HH:MM:SS): ");
                char time_input[20];
                fgets(time_input, sizeof(time_input), stdin);
                strptime(time_input, "%Y-%m-%d %H:%M:%S", &execution_time);
                time_t exec_time = mktime(&execution_time);

                printf("Enter frequency (O for one-time, D for daily, W for weekly): ");
                scanf(" %c", &frequency);

                add_task(&task_list, description, exec_time, frequency);
                break;
            }
            case 2:
                execute_tasks(&task_list);
                break;
            case 3:
                print_tasks(&task_list);
                break;
            case 4:
                save_tasks(&task_list);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}