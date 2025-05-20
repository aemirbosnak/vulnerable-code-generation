//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    time_t scheduled_time;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority, time_t scheduled_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->scheduled_time = scheduled_time;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task* head, Task* newTask) {
    if (head == NULL) {
        head = newTask;
    } else {
        Task* currentTask = head;
        while (currentTask->next) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;
    while (currentTask) {
        if (currentTask->scheduled_time <= now) {
            printf("Task: %s, completed.\n", currentTask->name);
            free(currentTask);
            currentTask = NULL;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task* head = NULL;

    addTask(head, createTask("Task 1", 1, time(NULL) + 60));
    addTask(head, createTask("Task 2", 2, time(NULL) + 30));
    addTask(head, createTask("Task 3", 3, time(NULL) + 90));

    scheduleTasks(head);

    return 0;
}