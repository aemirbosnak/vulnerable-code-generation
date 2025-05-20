//FormAI DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t run_time;
    void (*task)(void);
} Task;

Task task_list[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, time_t start_time, time_t run_time, void (*task)(void)) {
    if (num_tasks < MAX_TASKS) {
        Task new_task;
        strcpy(new_task.name, name);
        new_task.start_time = start_time;
        new_task.run_time = run_time;
        new_task.task = task;
        task_list[num_tasks] = new_task;
        num_tasks++;
        printf("Task added successfully.\n");
    } else {
        printf("Unable to add task. Maximum number of tasks reached.\n");
    }
}

void remove_task(char *name) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (strcmp(task_list[i].name, name) == 0) {
            int j;
            for (j = i; j < num_tasks-1; j++) {
                task_list[j] = task_list[j+1];
            }
            num_tasks--;
            printf("Task removed successfully.\n");
            return;
        }
    }
    printf("Task not found.\n");
}

void list_tasks() {
    printf("Task list:\n");
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("%s (start time: %ld, run time: %ld)\n", task_list[i].name, task_list[i].start_time, task_list[i].run_time);
    }
}

void execute_tasks() {
    printf("Executing tasks...\n");
    time_t current_time = time(NULL);
    int i;
    for (i = 0; i < num_tasks; i++) {
        if (current_time >= task_list[i].start_time && current_time < task_list[i].start_time + task_list[i].run_time) {
            printf("Executing task: %s\n", task_list[i].name);
            task_list[i].task();
        }
    }
    printf("Task execution complete.\n");
}

void task1() {
    printf("This is task 1.\n");
}

void task2() {
    printf("This is task 2.\n");
}

int main() {
    add_task("task1", time(NULL)+5, 10, task1);
    add_task("task2", time(NULL)+15, 5, task2);
    list_tasks();
    execute_tasks();
    remove_task("task1");
    execute_tasks();
    return 0;
}