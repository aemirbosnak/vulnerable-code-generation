#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TASKS 100
#define TASK_SIZE 256

typedef struct {
    char command[TASK_SIZE];
    pid_t pid;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void handle_signal(int sig) {
    int status;
    pid_t pid;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].pid == pid) {
                printf("Task %d completed\n", i);
                tasks[i] = tasks[--task_count];
                break;
            }
        }
    }
}

int add_task(const char *command) {
    if (task_count >= MAX_TASKS) return -1;
    strcpy(tasks[task_count].command, command);
    tasks[task_count].pid = fork();
    if (tasks[task_count].pid == 0) {
        execl("/bin/sh", "sh", "-c", command, NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else if (tasks[task_count].pid < 0) {
        perror("fork");
        return -1;
    }
    task_count++;
    return 0;
}

int main() {
    signal(SIGCHLD, handle_signal);

    while (1) {
        char input[TASK_SIZE];
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) break;
        if (add_task(input) != 0) {
            fprintf(stderr, "Failed to add task\n");
        }
    }

    for (int i = 0; i < task_count; i++) {
        kill(tasks[i].pid, SIGKILL);
        waitpid(tasks[i].pid, NULL, 0);
    }

    return 0;
}
