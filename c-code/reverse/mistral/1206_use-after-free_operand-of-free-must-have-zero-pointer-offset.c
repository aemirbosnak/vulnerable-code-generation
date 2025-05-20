#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

typedef struct Task {
    char *name;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(char *name) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = name;
    new_task->next = head;
    head = new_task;
}

void remove_task(char *name) {
    Task *current = head;
    Task *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void handle_signal(int sig) {
    printf("Received signal %d. Removing task: %s\n", sig, head->name);
    remove_task(head->name);
}

int main() {
    add_task("Task1");
    add_task("Task2");
    add_task("Task3");

    signal(SIGINT, handle_signal);

    for (int i = 0; i < 10; ++i) {
        sleep(1);
        printf("Running tasks: ");
        Task *current = head;
        while (current != NULL) {
            printf("%s ", current->name);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}
