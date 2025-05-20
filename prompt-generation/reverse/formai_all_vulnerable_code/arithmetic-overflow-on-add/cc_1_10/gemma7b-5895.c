//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 20

typedef struct Task {
    char name[TASK_NAME_LENGTH];
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

    while (head) {
        if (current_time >= head->start_time && current_time < head->end_time) {
            printf("Task: %s, Priority: %d\n", head->name, head->priority);
        }
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Task 1", 1, time(NULL) + 3600, time(NULL) + 3600 + 1800);
    addTask(&head, "Task 2", 2, time(NULL) + 1800, time(NULL) + 1800 + 900);
    addTask(&head, "Task 3", 3, time(NULL) + 900, time(NULL) + 900 + 600);

    scheduleTasks(head);

    return 0;
}