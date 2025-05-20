#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

typedef struct Task {
    char *command;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(char *command) {
    Task *new_task = malloc(sizeof(Task));
    new_task->command = strdup(command);
    new_task->next = head;
    head = new_task;
}

void execute_tasks() {
    Task *current = head;
    pid_t pid;

    while (current != NULL) {
        pid = fork();

        if (pid == 0) {
            execvp(current->command, (char *const[]) {current->command, NULL});
            perror("Error executing command");
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("Error forking process");
        }

        current = current->next;
    }
}

void sigint_handler(int sig) {
    Task *current = head;
    while (current != NULL) {
        Task *next = current->next;
        free(current->command);
        free(current);
        current = next;
    }
    head = NULL;
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);

    char input[1024];
    while (1) {
        printf("Task Scheduler> ");
        fgets(input, sizeof(input), stdin);
        add_task(strtok(input, " \n"));
    }

    return 0;
}
