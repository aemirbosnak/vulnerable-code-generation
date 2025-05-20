#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

typedef struct Task {
    char* command;
    struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* command) {
    Task* new_task = (Task*) malloc(sizeof(Task));
    new_task->command = strdup(command);
    new_task->next = head;
    head = new_task;
}

void execute_tasks() {
    Task* current = head;
    while (current != NULL) {
        pid_t pid = fork();
        if (pid == 0) {
            execl(current->command, current->command, (char*)NULL);
            printf("Failed to execute command: %s\n", current->command);
            exit(1);
        } else if (pid > 0) {
            current = current->next;
        } else {
            perror("Fork failed");
        }
    }
}

void free_tasks(Task* task) {
    if (task == NULL) return;
    free(task->command);
    free_tasks(task->next);
    free(task);
}

void signal_handler(int sig) {
    printf("Interrupted, cleaning up...\n");
    free_tasks(head);
    head = NULL;
    exit(0);
}

int main() {
    signal(SIGINT, signal_handler);

    add_task("sleep 5");
    add_task("echo Task 1");
    add_task("sleep 3");
    add_task("echo Task 2");
    add_task("sleep 10");
    add_task("echo Task 3");

    execute_tasks();

    return 0;
}
