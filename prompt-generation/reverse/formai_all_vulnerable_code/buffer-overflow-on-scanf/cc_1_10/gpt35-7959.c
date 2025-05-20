//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 20

typedef struct task {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    time_t scheduled_time;
    int duration;
} task;

task *task_scheduler[MAX_TASKS];
int num_tasks = 0;

void add_task() {
    if (num_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached. Cannot add task.\n");
        return;
    }

    task *new_task = malloc(sizeof(task));
    printf("Enter task name: ");
    scanf("%s", new_task->name);
    printf("Enter task priority (1-10): ");
    scanf("%d", &new_task->priority);
    printf("Enter scheduled time (seconds since epoch): ");
    scanf("%ld", &new_task->scheduled_time);
    printf("Enter task duration (in seconds): ");
    scanf("%d", &new_task->duration);

    task_scheduler[num_tasks++] = new_task;
    printf("Task added successfully.\n");
}

void print_task(task *t) {
    printf("%-20s%-10d%-30s%-10d\n", t->name, t->priority, ctime(&t->scheduled_time), t->duration);
}

void list_tasks() {
    printf("%-20s%-10s%-30s%-10s\n", "Task Name", "Priority", "Scheduled Time", "Duration");
    for (int i = 0; i < num_tasks; i++) {
        print_task(task_scheduler[i]);
    }
}

void schedule_task(task *t) {
    printf("Task \"%s\" scheduled at %s\n", t->name, ctime(&t->scheduled_time));
    sleep(t->duration);
    printf("Task \"%s\" completed\n", t->name);
}

void run_scheduler() {
    while (num_tasks > 0) {
        time_t current_time = time(NULL);
        for (int i = 0; i < num_tasks; i++) {
            if (task_scheduler[i]->scheduled_time <= current_time) {
                schedule_task(task_scheduler[i]);
                free(task_scheduler[i]);
                task_scheduler[i] = task_scheduler[--num_tasks];
            }
        }
    }
    printf("All tasks completed.\n");
}

int main() {
    while (1) {
        printf("Enter 'a' to add a task, 'l' to list tasks, 'r' to run scheduler, or 'q' to quit: ");
        char choice = getchar();
        getchar(); // consume newline character
        switch (choice) {
            case 'a':
                add_task();
                break;
            case 'l':
                list_tasks();
                break;
            case 'r':
                run_scheduler();
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}