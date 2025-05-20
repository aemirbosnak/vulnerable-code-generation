//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    int delay; // in seconds
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void handle_alarm(int sig) {
    // Signal handler to indicate an alarm has gone off
}

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached! Can't add more tasks.\n");
        return;
    }

    Task newTask;
    printf("Enter task name (max %d characters): ", TASK_NAME_LEN);
    fgets(newTask.name, TASK_NAME_LEN, stdin);
    newTask.name[strcspn(newTask.name, "\n")] = 0; // Remove newline

    printf("Enter delay in seconds: ");
    scanf("%d", &newTask.delay);
    getchar(); // to catch the newline character

    tasks[task_count++] = newTask;
    printf("Task '%s' scheduled to run in %d seconds!\n", newTask.name, newTask.delay);
}

void execute_task(const Task* task) {
    printf("Executing task: %s\n", task->name);
    // Here you could add the functionality for what the task should do
    sleep(1); // Simulating a task taking time
    printf("Task '%s' finished executing!\n", task->name);
}

void run_tasks() {
    for (int i = 0; i < task_count; i++) {
        alarm(tasks[i].delay);
        pause(); // Waiting for the signal
        execute_task(&tasks[i]);
    }
}

int main() {
    signal(SIGALRM, handle_alarm);
    
    printf("Welcome to the Exciting C Task Scheduler!\n");
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Run Scheduled Tasks\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Catch newline
        
        if (choice == 1) {
            add_task();
        } else if (choice == 2) {
            printf("Running scheduled tasks!\n");
            run_tasks();
        } else if (choice == 3) {
            printf("Exiting the Exciting C Task Scheduler!\n");
            break;
        } else {
            printf("Invalid option, please try again!\n");
        }
    }

    return 0;
}