#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

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

void execute_tasks() {
    Task *current = head;
    while (current != NULL) {
        printf("Executing task %d\n", current->id);
        sleep(1);
        current = current->next;
    }
}

void remove_task(int id) {
    Task *current = head;
    Task *prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current); // Deliberate use-after-free vulnerability
            return;
        }
        prev = current;
        current = current->next;
    }
}

void handle_sigint(int sig) {
    printf("\nReceived SIGINT. Removing all tasks...\n");
    while (head != NULL) {
        remove_task(head->id);
    }
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);

    add_task(1);
    add_task(2);
    add_task(3);

    printf("Starting task scheduler...\n");

    while (1) {
        execute_tasks();
        sleep(5);
    }

    return 0;
}
