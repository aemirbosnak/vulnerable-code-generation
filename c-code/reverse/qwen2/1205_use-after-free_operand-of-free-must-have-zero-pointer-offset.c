#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

typedef struct Task {
    char *name;
    int priority;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(const char *name, int priority) {
    Task *new_task = malloc(sizeof(Task));
    if (!new_task) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->next = head;
    head = new_task;
}

void remove_task(const char *name) {
    Task *current = head;
    Task *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void handle_sigint(int sig) {
    printf("Received SIGINT. Shutting down gracefully...\n");
    Task *current = head;
    while (current != NULL) {
        Task *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
    exit(0);
}

void print_tasks() {
    Task *current = head;
    while (current != NULL) {
        printf("Task: %s, Priority: %d\n", current->name, current->priority);
        current = current->next;
    }
}

int main() {
    signal(SIGINT, handle_sigint);

    add_task("Task1", 3);
    add_task("Task2", 1);
    add_task("Task3", 2);

    print_tasks();

    remove_task("Task2");

    print_tasks();

    return 0;
}
