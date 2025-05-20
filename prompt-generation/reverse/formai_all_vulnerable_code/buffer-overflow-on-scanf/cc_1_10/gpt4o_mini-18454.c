//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50
#define MAX_COMMAND_LENGTH 256

typedef struct Task {
    int id;
    char name[MAX_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    time_t execute_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_mutex_t lock;

void add_task(char *name, char *command, time_t execute_time) {
    pthread_mutex_lock(&lock);
    if (task_count < MAX_TASKS) {
        task_list[task_count].id = task_count + 1;
        strncpy(task_list[task_count].name, name, MAX_NAME_LENGTH);
        strncpy(task_list[task_count].command, command, MAX_COMMAND_LENGTH);
        task_list[task_count].execute_time = execute_time;
        task_count++;
        printf("Task '%s' added, scheduled for execution at %s", name, ctime(&execute_time));
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
    pthread_mutex_unlock(&lock);
}

void execute_task(Task task) {
    printf("Executing task: %s\n", task.name);
    system(task.command); // Execute the command
}

void *scheduler(void *arg) {
    while (1) {
        time_t now = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (task_list[i].execute_time <= now) {
                execute_task(task_list[i]);
                // Remove task by shifting tasks left
                pthread_mutex_lock(&lock);
                for (int j = i; j < task_count - 1; j++) {
                    task_list[j] = task_list[j + 1];
                }
                task_count--;
                i--; // Adjust index after removal
                pthread_mutex_unlock(&lock);
            }
        }
        sleep(1); // Check every second
    }
    return NULL;
}

void display_tasks() {
    printf("\nCurrent Scheduled Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("ID: %d | Name: %s | Command: %s | Scheduled Time: %s", 
               task_list[i].id, task_list[i].name, task_list[i].command, 
               ctime(&task_list[i].execute_time));
    }
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t scheduler_thread;

    // Create scheduler thread
    if (pthread_create(&scheduler_thread, NULL, scheduler, NULL) != 0) {
        fprintf(stderr, "Error creating scheduler thread\n");
        return 1;
    }

    while (1) {
        char name[MAX_NAME_LENGTH];
        char command[MAX_COMMAND_LENGTH];
        int hour, minute, second;
        time_t execute_time;

        printf("Enter task name (or type 'exit' to quit): ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter command (Unix command): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        printf("Enter execute time (HH MM SS): ");
        scanf("%d %d %d", &hour, &minute, &second);
        getchar(); // Consume newline left by scanf

        struct tm task_time;
        time_t now = time(NULL);
        localtime_r(&now, &task_time);
        task_time.tm_hour = hour;
        task_time.tm_min = minute;
        task_time.tm_sec = second;
        task_time.tm_year += 1900; // years since 1900
        task_time.tm_mon += 1; // months since January
        task_time.tm_isdst = -1; // automatically determine if DST is in effect
        execute_time = mktime(&task_time);

        if (execute_time < now) {
            printf("Cannot schedule task in the past.\n");
            continue;
        }

        add_task(name, command, execute_time);
        display_tasks();
    }

    pthread_cancel(scheduler_thread);
    pthread_join(scheduler_thread, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}