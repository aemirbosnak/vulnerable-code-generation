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
    void (*func)();
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(int id, void (*func)()) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->id = id;
    new_task->func = func;
    new_task->next = head;
    head = new_task;
}

void execute_tasks() {
    while (head != NULL) {
        Task *current = head;
        current->func();
        head = current->next;
        free(current);
    }
}

void handle_sigint(int sig) {
    printf("SIGINT received. Cleaning up...\n");
    execute_tasks();
    exit(0);
}

void task1() {
    printf("Executing task 1\n");
}

void task2() {
    printf("Executing task 2\n");
}

int main() {
    signal(SIGINT, handle_sigint);

    add_task(1, task1);
    add_task(2, task2);

    while (1) {
        sleep(1);
    }

    return 0;
}
