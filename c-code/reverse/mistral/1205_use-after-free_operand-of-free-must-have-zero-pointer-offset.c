#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

typedef struct Task {
    char *name;
    int (*func)(void);
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(char *name, int (*func)(void)) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->func = func;
    new_task->next = head;
    head = new_task;
}

void sigint_handler(int sig) {
    printf("\nGracefully shutting down...\n");
    Task *current = head;
    while (current != NULL) {
        Task *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    exit(0);
}

int task1(void) {
    printf("Task 1 executed.\n");
    sleep(3);
    return 0;
}

int task2(void) {
    printf("Task 2 executed.\n");
    sleep(2);
    return 0;
}

int main() {
    signal(SIGINT, sigint_handler);

    add_task("Task 1", task1);
    add_task("Task 2", task2);

    while (head != NULL) {
        Task *current = head;
        head = head->next;
        (current->func)();
        free(current->name);
        free(current);
    }

    return 0;
}
