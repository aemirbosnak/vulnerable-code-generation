#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char *command;
    struct Task *next;
} Task;

Task* create_task(const char *cmd) {
    Task *new_task = (Task*)malloc(sizeof(Task));
    new_task->command = strdup(cmd);
    new_task->next = NULL;
    return new_task;
}

void free_task(Task *task) {
    free(task->command);
    free(task);
}

void append_task(Task **head, const char *cmd) {
    Task *new_task = create_task(cmd);
    if (*head == NULL) {
        *head = new_task;
    } else {
        Task *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_task;
    }
}

void execute_tasks(Task *head) {
    Task *current = head;
    while (current != NULL) {
        system(current->command); // Vulnerable to use-after-free
        Task *temp = current;
        current = current->next;
        free_task(temp);
    }
}

int main() {
    Task *tasks = NULL;
    append_task(&tasks, "echo Hello");
    append_task(&tasks, "ls -la");
    execute_tasks(tasks);
    return 0;
}
