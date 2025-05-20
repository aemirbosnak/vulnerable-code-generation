//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority, time_t start_time, time_t end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t current_time = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (current_time >= currentTask->start_time && current_time < currentTask->end_time) {
            printf("Task: %s, Start Time: %s, End Time: %s\n", currentTask->name, currentTask->start_time, currentTask->end_time);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;

    addTask(head, "Task 1", 1, time(NULL) + 60, time(NULL) + 90);
    addTask(head, "Task 2", 2, time(NULL) + 30, time(NULL) + 60);
    addTask(head, "Task 3", 3, time(NULL) + 15, time(NULL) + 45);

    scheduleTasks(head);

    return 0;
}