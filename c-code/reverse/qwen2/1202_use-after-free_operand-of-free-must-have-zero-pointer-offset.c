#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

void execute_task(Task *task) {
    pid_t pid = fork();
    if (pid == 0) {
        execlp(task->command, task->command, NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);
        free(task->command); // Use-after-free vulnerability
        free(task);
    }
}

void handle_sigint(int sig) {
    printf("\nReceived SIGINT. Exiting...\n");
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

    add_task("ls -l");
    add_task("pwd");

    Task *current = head;
    while (current != NULL) {
        execute_task(current);
        current = current->next;
    }

    return 0;
}
