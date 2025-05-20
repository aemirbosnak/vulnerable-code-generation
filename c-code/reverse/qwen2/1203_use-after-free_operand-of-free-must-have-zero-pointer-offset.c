#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct Task {
    char *command;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(const char *command) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->command = strdup(command);
    new_task->next = head;
    head = new_task;
}

void execute_tasks() {
    while (head != NULL) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execl("/bin/sh", "sh", "-c", head->command, NULL);
            perror("execl");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
        Task *temp = head;
        head = head->next;
        free(temp->command);
        free(temp);
    }
}

void handle_sigint(int sig) {
    printf("\nReceived SIGINT. Cleaning up...\n");
    while (head != NULL) {
        Task *temp = head;
        head = head->next;
        free(temp->command);
        free(temp);
    }
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, handle_sigint);

    add_task("echo Hello World");
    add_task("ls -l");

    execute_tasks();

    return 0;
}
