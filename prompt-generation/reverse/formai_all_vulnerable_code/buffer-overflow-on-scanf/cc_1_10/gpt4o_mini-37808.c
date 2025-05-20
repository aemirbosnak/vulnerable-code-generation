//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50
#define TIME_BUFFER 26

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t scheduled_time;
    int interval; // seconds for recurring tasks
    int is_recurring; // 1 for true, 0 for false
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;
pthread_mutex_t task_mutex;

void add_task(const char *name, time_t scheduled_time, int interval, int is_recurring) {
    pthread_mutex_lock(&task_mutex);
    if (task_count < MAX_TASKS) {
        strncpy(tasks[task_count].name, name, TASK_NAME_LENGTH);
        tasks[task_count].scheduled_time = scheduled_time;
        tasks[task_count].interval = interval;
        tasks[task_count].is_recurring = is_recurring;
        task_count++;
        printf("Task \"%s\" added to schedule.\n", name);
    } else {
        printf("Task limit reached. Unable to add task \"%s\".\n", name);
    }
    pthread_mutex_unlock(&task_mutex);
}

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
    // Simulating some work being done by the task
    sleep(1);
    printf("Task \"%s\" executed.\n", task->name);
}

void *task_scheduler(void *arg) {
    while (1) {
        time_t now = time(NULL);
        pthread_mutex_lock(&task_mutex);
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].scheduled_time <= now) {
                execute_task(&tasks[i]);
                if (tasks[i].is_recurring) {
                    tasks[i].scheduled_time += tasks[i].interval;
                } else {
                    // Remove task: shift tasks down
                    for (int j = i; j < task_count - 1; j++) {
                        tasks[j] = tasks[j + 1];
                    }
                    task_count--;
                    i--; // Adjust index since we shifted tasks
                }
            }
        }
        pthread_mutex_unlock(&task_mutex);
        sleep(1); // Sleep for a second before next check
    }
    return NULL;
}

void signal_handler(int signum) {
    printf("Received signal %d, exiting...\n", signum);
    exit(0);
}

int main() {
    pthread_t scheduler_thread;

    // Initialize mutex
    pthread_mutex_init(&task_mutex, NULL);

    signal(SIGINT, signal_handler);

    // Start the scheduler thread
    if (pthread_create(&scheduler_thread, NULL, task_scheduler, NULL) != 0) {
        fprintf(stderr, "Error creating scheduler thread.\n");
        return 1;
    }

    // User inputs
    char task_name[TASK_NAME_LENGTH];
    int interval;
    char is_recurring_str[4];

    while (1) {
        time_t current_time = time(NULL);
        char time_buf[TIME_BUFFER];
        ctime_r(&current_time, time_buf);
        printf("\nCurrent time: %s", time_buf);
        printf("Enter task name (or 'exit' to quit): ");
        fgets(task_name, TASK_NAME_LENGTH, stdin);
        task_name[strcspn(task_name, "\n")] = 0; // Remove newline character

        if (strcmp(task_name, "exit") == 0) {
            break;
        }

        printf("Enter the delay in seconds before execution: ");
        scanf("%d", &interval);

        printf("Is the task recurring? (yes/no): ");
        scanf("%s", is_recurring_str);
        int is_recurring = (strcmp(is_recurring_str, "yes") == 0) ? 1 : 0;

        time_t scheduled_time = current_time + interval;

        add_task(task_name, scheduled_time, interval, is_recurring);
        getchar(); // Clear newline character from stdin
    }

    pthread_cancel(scheduler_thread);
    pthread_join(scheduler_thread, NULL); // Wait for scheduler thread to finish
    pthread_mutex_destroy(&task_mutex);

    return 0;
}