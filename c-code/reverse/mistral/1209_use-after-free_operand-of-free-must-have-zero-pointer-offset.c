#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct Task {
    char *command;
    struct Task *next;
} Task;

Task *head = NULL;
pid_t current_task_pid;

void add_task(char *command) {
    Task *new_task = malloc(sizeof(Task));
    new_task->command = strdup(command);
    new_task->next = head;
    head = new_task;
}

void execute_task(Task *task) {
    pid_t pid = fork();

    if (pid == 0) {
        execl(task->command, task->command, (char *)NULL);
        perror("execl failed");
        exit(1);
    } else if (pid > 0) {
        current_task_pid = pid;
        waitpid(pid, NULL, 0);
    } else {
        perror("fork failed");
        exit(1);
    }
}

void sigint_handler(int sig) {
    if (current_task_pid > 0) {
        kill(current_task_pid, SIGTERM);
    }
    while (head != NULL) {
        Task *temp = head;
        head = head->next;
        free(temp->command);
        free(temp);
    }
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);

    add_task("task1");
    add_task("task2");
    add_task("task3");

    execute_task(head);

    return 0;
}
