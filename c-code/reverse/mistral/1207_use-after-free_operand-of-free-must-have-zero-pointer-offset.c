#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    char* command;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* command) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->command = (char*)malloc(strlen(command) + 1);
    strcpy(newTask->command, command);
    newTask->next = head;
    head = newTask;
}

void executeTasks() {
    Task* current = head;
    while (current != NULL) {
        system(current->command);
        free(current->command);
        current->command = NULL;
        Task* temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }
    head = NULL;
}

int main() {
    addTask("echo Hello, World!");
    addTask("sleep 1");
    addTask("echo Goodbye!");
    executeTasks();
    return 0;
}
