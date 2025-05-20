#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

typedef struct Task {
    char *name;
    void (*func)(void);
    struct Task *next;
} Task;

Task *head = NULL;

void task_add(char *name, void (*func)(void)) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->func = func;
    new_task->next = head;
    head = new_task;
}

void task_execute(int sig) {
    Task *current = head;
    while (current != NULL) {
        current->func();
        current = current->next;
        free(current); // Use-after-free vulnerability
    }
}

void task1(void) {
    printf("Task 1 executed\n");
}

void task2(void) {
    printf("Task 2 executed\n");
}

void sigint_handler(int sig) {
    signal(SIGINT, SIG_IGN); // Ignore further SIGINT signals
    task_execute(SIGINT);
}

int main() {
    task_add("Task 1", task1);
    task_add("Task 2", task2);

    signal(SIGINT, sigint_handler);

    for (;;) {
        sleep(1);
    }

    return 0;
}
