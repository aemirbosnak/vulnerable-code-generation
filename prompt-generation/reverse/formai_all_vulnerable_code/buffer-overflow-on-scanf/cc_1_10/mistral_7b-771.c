//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_QUEUE_SIZE 5

typedef struct {
    pid_t pid;
    char *command;
    int state;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void print_tasks() {
    printf("Current tasks:\n");
    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].pid != -1) {
            printf("%d. %s (%d)\n", i + 1, tasks[i].command, tasks[i].pid);
        }
    }
}

int main() {
    char input[100];
    int choice;
    while (1) {
        print_tasks();
        printf("\nEnter a command to schedule (or 'q' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        Task new_task = {-1, strdup(input), 0};
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].pid == -1 && num_tasks < MAX_TASKS) {
                tasks[i] = new_task;
                num_tasks++;
                break;
            }
        }
        if (num_tasks >= MAX_TASKS) {
            printf("Task queue is full. Please wait for a task to finish before scheduling another one.\n");
        }
        printf("Task scheduled.\n");
        sleep(1); // Add a delay between tasks for better visibility
    }

    for (int i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].pid == -1) {
            continue;
        }
        waitpid(tasks[i].pid, &choice, 0);
        if (choice > 0) {
            tasks[i].state = 1;
            free(tasks[i].command);
        } else {
            perror("waitpid");
            tasks[i].state = -1;
        }
    }

    printf("\nTasks finished.\n");

    return 0;
}