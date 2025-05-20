#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Task {
    char *command;
    struct Task *next;
} Task;

Task* create_task(const char *cmd) {
    Task *task = (Task*)malloc(sizeof(Task));
    task->command = strdup(cmd);
    task->next = NULL;
    return task;
}

void add_task(Task **head, const char *cmd) {
    Task *new_task = create_task(cmd);
    new_task->next = *head;
    *head = new_task;
}

void remove_task(Task **head, int index) {
    if (*head == NULL) return;
    if (index == 0) {
        Task *temp = *head;
        *head = (*head)->next;
        free(temp->command);
        free(temp);
        return;
    }
    Task *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) return;
    Task *temp = current->next;
    current->next = temp->next;
    free(temp->command);
    free(temp);
}

void execute_tasks(Task *head) {
    while (head != NULL) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            execlp(head->command, head->command, NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
        head = head->next;
    }
    wait(NULL);
}

void free_tasks(Task *head) {
    while (head != NULL) {
        Task *temp = head;
        head = head->next;
        free(temp->command);
        free(temp);
    }
}

int main() {
    Task *tasks = NULL;
    add_task(&tasks, "ls -l");
    add_task(&tasks, "pwd");
    add_task(&tasks, "echo Hello");

    execute_tasks(tasks);

    // Intentionally introducing a use-after-free vulnerability
    remove_task(&tasks, 2); // Remove the last task

    free_tasks(tasks);

    return 0;
}
