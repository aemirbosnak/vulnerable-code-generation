//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50
#define SCHEDULE_INTERVAL 1

// Task structure
typedef struct {
    char name[TASK_NAME_LEN];
    time_t scheduled_time;
    bool active;
} Task;

// Global Variables
Task tasks[MAX_TASKS];
int task_count = 0;
pthread_mutex_t task_mutex = PTHREAD_MUTEX_INITIALIZER;
volatile sig_atomic_t stop_program = 0;

// Function Declarations
void *task_scheduler(void *arg);
void add_task(const char *name, int delay);
void execute_task(Task *task);
void signal_handler(int signal);
void print_tasks();
void clean_up();

int main() {
    signal(SIGINT, signal_handler); // Catch interrupt signal (Ctrl+C)
    pthread_t scheduler_thread;

    pthread_create(&scheduler_thread, NULL, task_scheduler, NULL);
    
    char command[TASK_NAME_LEN];
    int delay;

    printf("Welcome to the paranoid task scheduler! (Press Ctrl+C to exit)\n");

    while (!stop_program) {
        printf("Enter task name (or type 'exit' to quit): ");
        fgets(command, TASK_NAME_LEN, stdin);
        
        command[strcspn(command, "\n")] = 0; // Remove newline character
        
        if (strcmp(command, "exit") == 0) {
            stop_program = 1;
            break;
        }

        printf("Enter delay in seconds for task '%s': ", command);
        scanf("%d", &delay);
        getchar(); // Consume the leftover newline

        add_task(command, delay);
        print_tasks();
    }

    pthread_join(scheduler_thread, NULL); // Wait for the scheduler thread to finish
    clean_up();
    return 0;
}

// Function to handle SIGINT
void signal_handler(int signal) {
    stop_program = 1; // Set flag to stop program
}

// Add a new task
void add_task(const char *name, int delay) {
    pthread_mutex_lock(&task_mutex);
    
    if (task_count < MAX_TASKS) {
        Task *new_task = &tasks[task_count++];
        strncpy(new_task->name, name, TASK_NAME_LEN);
        new_task->scheduled_time = time(NULL) + delay; // Schedule after delay
        new_task->active = true;
        printf("Task '%s' scheduled to run in %d seconds.\n", name, delay);
    } else {
        printf("Max task limit reached. Cannot add more tasks.\n");
    }

    pthread_mutex_unlock(&task_mutex);
}

// Task execution function
void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
    // Simulate task execution (e.g., print message)
    printf("Task '%s' completed successfully.\n", task->name);
    task->active = false; // Mark task as inactive
}

// Task scheduler thread function
void *task_scheduler(void *arg) {
    while (!stop_program) {
        pthread_mutex_lock(&task_mutex);
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].active && time(NULL) >= tasks[i].scheduled_time) {
                execute_task(&tasks[i]);
            }
        }
        pthread_mutex_unlock(&task_mutex);
        sleep(SCHEDULE_INTERVAL);
    }
    return NULL;
}

// Print currently scheduled tasks
void print_tasks() {
    pthread_mutex_lock(&task_mutex);
    printf("Current scheduled tasks:\n");
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].active) {
            printf(" - %s scheduled at %s", tasks[i].name, ctime(&tasks[i].scheduled_time));
        }
    }
    pthread_mutex_unlock(&task_mutex);
}

// Clean up resources
void clean_up() {
    printf("Cleaning up and exiting...\n");
}