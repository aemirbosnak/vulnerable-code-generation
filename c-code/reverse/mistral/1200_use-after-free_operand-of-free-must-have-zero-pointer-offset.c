#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
    while (current != NULL) {
        Task *next = current->next;
        pid_t pid = fork();
        if (pid == 0) {
            execlp(current->command, current->command, (char *)NULL);
            _exit(1);
        } else {
            wait(NULL);
        }
        current = next;
        free(current);
    }
}

int main() {
    add_task("ls");
    add_task("date");
    add_task("uname -a");
    execute_tasks();
    return 0;
}
