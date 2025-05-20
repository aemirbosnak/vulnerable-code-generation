//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 50

typedef struct {
    char name[MAX_TASK_NAME_LEN];
    int hour;
    int minute;
    int second;
} Task;

void add_task(Task tasks[], char* task_name, int hour, int minute, int second) {
    Task task;
    strcpy(task.name, task_name);
    task.hour = hour;
    task.minute = minute;
    task.second = second;
    tasks[MAX_TASKS - 1] = task;
}

void remove_task(Task tasks[], char* task_name) {
    for (int i = 0; i < MAX_TASKS; i++) {
        if (strcmp(tasks[i].name, task_name) == 0) {
            tasks[i] = tasks[MAX_TASKS - 1];
            break;
        }
    }
}

void run_tasks(Task tasks[]) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].hour == tm->tm_hour && tasks[i].minute == tm->tm_min && tasks[i].second == tm->tm_sec) {
            printf("Running task: %s\n", tasks[i].name);
            // Add your task code here
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];

    add_task(tasks, "Task 1", 12, 0, 0);
    add_task(tasks, "Task 2", 18, 0, 0);
    add_task(tasks, "Task 3", 20, 0, 0);
    add_task(tasks, "Task 4", 22, 0, 0);

    while (1) {
        run_tasks(tasks);
        sleep(1);
    }

    return 0;
}