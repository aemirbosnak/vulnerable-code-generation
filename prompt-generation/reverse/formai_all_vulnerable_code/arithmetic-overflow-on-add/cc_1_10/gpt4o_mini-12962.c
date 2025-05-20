//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define BUFFER_SIZE 256

typedef struct {
    int id;
    char name[50];
    time_t scheduled_time;
    void (*task_function)(void);
} Task;

void task1() {
    printf("Executing Task 1...\n");
}

void task2() {
    printf("Executing Task 2...\n");
}

void task3() {
    printf("Executing Task 3...\n");
}

void display_tasks(Task* tasks, int count) {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < count; i++) {
        printf("Task ID: %d, Name: %s, Scheduled Time: %s", 
            tasks[i].id, tasks[i].name, ctime(&tasks[i].scheduled_time));
    }
}

void* task_scheduler(void* arg) {
    Task* tasks = (Task*)arg;
    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].id != 0 && tasks[i].scheduled_time <= current_time) {
                tasks[i].task_function();
                tasks[i].id = 0; // Marking the task as executed
            }
        }
        sleep(1); // Wait for a second before checking again
    }
    return NULL;
}

int main() {
    Task tasks[MAX_TASKS] = {0};
    char buffer[BUFFER_SIZE];
    
    tasks[0].id = 1;
    strcpy(tasks[0].name, "Task 1");
    tasks[0].scheduled_time = time(NULL) + 5; // Schedule for 5 seconds later
    tasks[0].task_function = task1;

    tasks[1].id = 2;
    strcpy(tasks[1].name, "Task 2");
    tasks[1].scheduled_time = time(NULL) + 10; // Schedule for 10 seconds later
    tasks[1].task_function = task2;

    tasks[2].id = 3;
    strcpy(tasks[2].name, "Task 3");
    tasks[2].scheduled_time = time(NULL) + 15; // Schedule for 15 seconds later
    tasks[2].task_function = task3;

    display_tasks(tasks, MAX_TASKS);

    // Create and start the scheduler in a separate thread
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, task_scheduler, (void*)tasks);

    // Main program loop
    while (1) {
        printf("Type 'exit' to stop the scheduler: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    // Cleanup and exit
    printf("Stopping the scheduler...\n");
    pthread_cancel(scheduler_thread);
    pthread_join(scheduler_thread, NULL);
    printf("Scheduler stopped. Exiting program.\n");

    return 0;
}