//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int interval;  // seconds
    time_t next_run;
    void (*task_function)();
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_t scheduler_thread;
int running = 1;

void* scheduler(void* arg);
void dummy_task();
void signal_handler(int signum);

int main() {
    // Handling SIGINT (Ctrl+C) to exit cleanly
    signal(SIGINT, signal_handler);

    // User interface for task scheduling
    printf("Welcome to the Simple Task Scheduler!\n");
    printf("You can add tasks in the format: <task_name> <interval_in_seconds>\n");
    printf("Type 'exit' to quit the program.\n");

    // Create a scheduler thread
    pthread_create(&scheduler_thread, NULL, scheduler, NULL);

    char input[100];
    while (running) {
        printf("Enter task (or 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n"); // Remove newline character

        if (strcmp(input, "exit") == 0) {
            running = 0; // Set flag to exit
            break;
        }

        // Parsing input
        char task_name[MAX_NAME_LENGTH];
        int interval;
        if (sscanf(input, "%s %d", task_name, &interval) == 2) {
            if (task_count < MAX_TASKS) {
                strcpy(task_list[task_count].name, task_name);
                task_list[task_count].interval = interval;
                task_list[task_count].next_run = time(NULL) + interval;
                task_list[task_count].task_function = dummy_task; // Assign a dummy function
                task_count++;
                printf("Task '%s' added to scheduler with interval %d seconds.\n", task_name, interval);
            } else {
                printf("Task list is full! Cannot add more tasks.\n");
            }
        } else {
            printf("Invalid input format. Please use: <task_name> <interval_in_seconds>\n");
        }
    }

    // Clean up
    pthread_join(scheduler_thread, NULL);
    printf("Exiting scheduler. Goodbye!\n");
    return 0;
}

void* scheduler(void* arg) {
    while (running) {
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (current_time >= task_list[i].next_run) {
                printf("Executing task: %s\n", task_list[i].name);
                task_list[i].task_function();
                task_list[i].next_run = current_time + task_list[i].interval; // Re-schedule the task
            }
        }
        sleep(1); // Sleep for a second before checking again
    }
    return NULL;
}

void dummy_task() {
    // Replace this with actual task implementation
    printf("Dummy task executed at %ld\n", time(NULL));
}

void signal_handler(int signum) {
    running = 0; // Set the running flag to false to exit the loop
}