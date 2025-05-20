//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    char name[50];
    int interval; // in seconds
    bool active;
    pthread_t thread;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void *execute_task(void *arg) {
    Task *task = (Task *)arg;
    while (task->active) {
        sleep(task->interval);
        if (task->active) {
            printf("Executing task: %s\n", task->name);
        }
    }
    return NULL;
}

void add_task(const char *name, int interval) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached! Cannot add more tasks.\n");
        return;
    }
    
    Task *new_task = &task_list[task_count++];
    strncpy(new_task->name, name, sizeof(new_task->name) - 1);
    new_task->interval = interval;
    new_task->active = true;

    pthread_create(&new_task->thread, NULL, execute_task, new_task);
    printf("Task '%s' added with an interval of %d seconds.\n", new_task->name, new_task->interval);
}

void remove_task(int index) {
    if (index < 0 || index >= task_count) {
        printf("Invalid task index!\n");
        return;
    }

    Task *task = &task_list[index];
    task->active = false;
    pthread_join(task->thread, NULL);
    printf("Task '%s' removed.\n", task->name);

    // Shift remaining tasks
    for (int i = index; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
    }
    task_count--;
}

void list_tasks() {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("Current Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf(" [%d] %s (Every %d seconds) %s\n", i, task_list[i].name, task_list[i].interval, task_list[i].active ? "(active)" : "(inactive)");
    }
}

void clear_all_tasks() {
    for (int i = 0; i < task_count; i++) {
        task_list[i].active = false;
        pthread_join(task_list[i].thread, NULL);
    }
    task_count = 0;
    printf("All tasks cleared.\n");
}

int main() {
    char command[100];
    char name[50];
    int interval, index;

    printf("Welcome to the C Task Scheduler!\n");
    printf("Commands:\n");
    printf("  add <name> <interval> - Adds a task\n");
    printf("  remove <index>       - Removes a task\n");
    printf("  list                 - Lists all tasks\n");
    printf("  clear                - Clears all tasks\n");
    printf("  exit                 - Exits the scheduler\n");

    while (true) {
        printf("> ");
        fgets(command, sizeof(command), stdin);

        if (sscanf(command, "add %s %d", name, &interval) == 2) {
            add_task(name, interval);
        } else if (sscanf(command, "remove %d", &index) == 1) {
            remove_task(index);
        } else if (strcmp(command, "list\n") == 0) {
            list_tasks();
        } else if (strcmp(command, "clear\n") == 0) {
            clear_all_tasks();
        } else if (strcmp(command, "exit\n") == 0) {
            clear_all_tasks();
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    printf("Exiting the C Task Scheduler. Goodbye!\n");
    return 0;
}