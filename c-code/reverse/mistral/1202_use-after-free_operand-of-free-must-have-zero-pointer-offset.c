#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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

void execute_task(Task *task) {
    pid_t pid = fork();

    if (pid == 0) {
        execlp(task->command, task->command, (char *)NULL);
        _exit(1);
    } else {
        wait(NULL);
        free(task->command);
        Task *temp = head;
        while (temp != task) {
            temp = temp->next;
        }
        head = temp->next;
        free(task);
    }
}

void handle_sigint(int sig) {
    while (head != NULL) {
        execute_task(head);
    }
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    add_task("ls");
    add_task("uname -a");
    add_task("date");

    for (;;) {
        sleep(1);
    }

    return 0;
}
