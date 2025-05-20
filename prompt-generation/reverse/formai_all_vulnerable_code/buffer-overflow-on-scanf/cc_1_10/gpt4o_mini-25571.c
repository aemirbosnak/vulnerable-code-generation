//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t execution_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(const char *task_name, int seconds_from_now) {
    if (task_count < MAX_TASKS) {
        strcpy(task_list[task_count].name, task_name);
        task_list[task_count].execution_time = time(NULL) + seconds_from_now;
        task_count++;
        printf("🎉 Task '%s' added! It will execute in %d seconds. 🎉\n", task_name, seconds_from_now);
    } else {
        printf("😢 Sorry! Maximum task limit reached. Cannot add more tasks. 😢\n");
    }
}

void execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].execution_time <= current_time) {
            printf("🚀 Executing task: '%s' at %s", task_list[i].name, ctime(&task_list[i].execution_time));
            // Remove task by shifting the remaining tasks
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Move back to the same index to check the new task list
        }
    }
}

void display_tasks() {
    if (task_count == 0) {
        printf("😴 No tasks scheduled! #Bored 😴\n");
    } else {
        printf("📅 Scheduled Tasks: 📅\n");
        for (int i = 0; i < task_count; i++) {
            printf("[%d] %s - Execute at: %s", i + 1, task_list[i].name, ctime(&task_list[i].execution_time));
        }
    }
}

int main() {
    int choice;
    char task_name[TASK_NAME_LENGTH];
    int seconds;

    while (1) {
        printf("\n🎈 Welcome to the Awesome Task Scheduler! 🎈\n");
        printf("1. Add Task\n");
        printf("2. Execute Tasks\n");
        printf("3. Display Scheduled Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", task_name);
                printf("Enter time to execute (in seconds): ");
                scanf("%d", &seconds);
                add_task(task_name, seconds);
                break;
            case 2:
                execute_tasks();
                break;
            case 3:
                display_tasks();
                break;
            case 4:
                printf("🌟 Thank you for using the Task Scheduler! Goodbye! 🌟\n");
                return 0;
            default:
                printf("🚫 Invalid choice, please try again! 🚫\n");
                break;
        }
    }
}