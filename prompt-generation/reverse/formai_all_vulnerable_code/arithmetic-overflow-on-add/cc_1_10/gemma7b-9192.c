//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority, time_t start, time_t end) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start;
    newTask->end_time = end;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* currentTask = head;
        while (currentTask->next != NULL) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }

    return head;
}

void printTasks(Task* head) {
    Task* currentTask = head;
    while (currentTask) {
        printf("Name: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", currentTask->name, currentTask->priority, currentTask->start_time, currentTask->end_time);
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(head, "Task 1", 1, time(NULL) + 3600, time(NULL) + 7200);
    insertTask(head, "Task 2", 2, time(NULL) + 1800, time(NULL) + 2400);
    insertTask(head, "Task 3", 3, time(NULL) + 600, time(NULL) + 1200);

    printTasks(head);

    return 0;
}