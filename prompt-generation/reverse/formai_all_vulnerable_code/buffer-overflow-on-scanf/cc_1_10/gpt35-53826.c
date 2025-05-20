//FormAI DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int priority;
} Task;

void create_task(Task *task, int id, char *name, int priority) {
    task->id = id;
    strcpy(task->name, name);
    task->priority = priority;
}

void run_task(Task *task) {
    printf("Running task %d: %s\n", task->id, task->name);
    sleep(5);
    printf("Task %d completed\n", task->id);
}

int schedule_tasks(Task *tasks, int num_tasks) {
    pid_t pid;
    int status;

    for (int i = 0; i < num_tasks; i++) {
        pid = fork();

        if (pid == -1) {
            printf("Error: Failed to fork\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            run_task(&tasks[i]);
            exit(0);
        }
    }

    // Wait for all child processes to complete
    int num_completed = 0;

    while (num_completed < num_tasks) {
        pid = wait(&status);
        num_completed++;
    }

    return 0;
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    if (num_tasks > MAX_TASKS) {
        printf("Error: Maximum number of tasks is %d\n", MAX_TASKS);
        exit(1);
    }

    Task tasks[num_tasks];

    // Create tasks
    for (int i = 0; i < num_tasks; i++) {
        char name[MAX_NAME_LENGTH];
        int priority;

        printf("Enter the name and priority of task %d: ", i + 1);
        scanf("%s %d", name, &priority);

        create_task(&tasks[i], i + 1, name, priority);
    }

    // Sort tasks by priority (higher priority comes first)
    for (int i = 0; i < num_tasks; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Schedule tasks for execution
    schedule_tasks(tasks, num_tasks);

    printf("All tasks completed successfully\n");

    return 0;
}