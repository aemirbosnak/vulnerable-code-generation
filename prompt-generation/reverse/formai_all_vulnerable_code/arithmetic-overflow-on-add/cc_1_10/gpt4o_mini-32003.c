//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50
#define SLEEP_DURATION 1  // Check for scheduled tasks every 1 second

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t scheduled_time; // Time at which to execute the task
    pid_t pid;             // Process ID of the task
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(const char *name, time_t scheduled_time) {
    if (task_count >= MAX_TASKS) {
        printf("Maximum task limit reached. Cannot add more tasks.\n");
        return;
    }
    strncpy(tasks[task_count].name, name, TASK_NAME_LENGTH);
    tasks[task_count].scheduled_time = scheduled_time;
    tasks[task_count].pid = -1; // Uninitialized
    task_count++;
    printf("Task added: %s scheduled at %s", name, ctime(&scheduled_time));
}

void execute_task(Task *task) {
    task->pid = fork();
    if (task->pid == 0) {
        // Child process for the task
        printf("Executing Task: %s\n", task->name);
        // Simulate task execution with sleep
        sleep(3);
        printf("Task %s completed.\n", task->name);
        exit(0);
    } else if (task->pid < 0) {
        perror("Fork failed");
    }
}

void check_tasks() {
    time_t now = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].pid == -1 && tasks[i].scheduled_time <= now) {
            execute_task(&tasks[i]);
        }
    }
}

void remove_completed_tasks() {
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].pid > 0) {
            int status;
            pid_t result = waitpid(tasks[i].pid, &status, WNOHANG);
            if (result == tasks[i].pid) {
                // Task completed, shift tasks
                printf("Removing completed Task: %s\n", tasks[i].name);
                for (int j = i; j < task_count - 1; j++) {
                    tasks[j] = tasks[j + 1];
                }
                task_count--;
                i--; // Adjust index after removal
            }
        }
    }
}

void signal_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nScheduler has been terminated by user.\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signal_handler);

    time_t now = time(NULL);
    add_task("Task 1", now + 5); // Schedule to run after 5 seconds
    add_task("Task 2", now + 10); // Schedule to run after 10 seconds
    add_task("Task 3", now + 15); // Schedule to run after 15 seconds

    printf("Starting Task Scheduler...\n");

    while (1) {
        check_tasks();
        remove_completed_tasks();
        sleep(SLEEP_DURATION);
    }

    return 0;
}