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
    printf("Signal %d received, cleaning up...\n", sig);
    Task *current = head;
    while (current != NULL) {
        Task *temp = current;
        current = current->next;
        free(temp);
    }
    exit(0);
}

int main() {
    signal(SIGINT, handle_signal);

    add_task(1);
    add_task(2);
    add_task(3);

    remove_task(2); // Vulnerability: Use after free

    return 0;
}
