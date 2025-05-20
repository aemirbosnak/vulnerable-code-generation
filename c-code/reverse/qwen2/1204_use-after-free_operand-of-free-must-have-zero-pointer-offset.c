#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef struct Task {
    int id;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(int id) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->id = id;
    new_task->next = head;
    head = new_task;
}

void remove_task(int id) {
    Task *current = head;
    Task *previous = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void handle_signal(int sig) {
    remove_task(1); // Simulate removing a task
}

int main() {
    add_task(1);
    add_task(2);

    signal(SIGINT, handle_signal);

    printf("Tasks before signal: ");
    Task *current = head;
    while (current != NULL) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");

    raise(SIGINT);

    printf("Tasks after signal: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");

    return 0;
}
