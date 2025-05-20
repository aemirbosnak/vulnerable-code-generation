//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task *next;
} Task;

Task *head = NULL;

void addTask(char *name, int priority, time_t start_time, time_t end_time) {
    Task *newTask = malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task *currTask = head;
        while (currTask->next) {
            currTask = currTask->next;
        }
        currTask->next = newTask;
    }
}

void schedule() {
    time_t now = time(NULL);
    Task *currTask = head;

    while (currTask) {
        if (now >= currTask->start_time && now < currTask->end_time) {
            printf("Task: %s, Priority: %d\n", currTask->name, currTask->priority);
        }
        currTask = currTask->next;
    }
}

int main() {
    addTask("Task 1", 1, time(NULL) + 60, time(NULL) + 90);
    addTask("Task 2", 2, time(NULL) + 30, time(NULL) + 60);
    addTask("Task 3", 3, time(NULL) + 10, time(NULL) + 30);

    schedule();

    return 0;
}