//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t scheduled_time;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int priority, time_t scheduled_time) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->scheduled_time = scheduled_time;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newTask;
    }
}

void scheduleTasks() {
    time_t now = time(NULL);

    for (Task* currentTask = head; currentTask != NULL; currentTask = currentTask->next) {
        if (currentTask->scheduled_time <= now) {
            printf("Executing task: %s\n", currentTask->name);
            free(currentTask);
        }
    }
}

int main() {
    addTask("Do laundry", 3, time(NULL) + 60 * 60);
    addTask("Pay bills", 2, time(NULL) + 60 * 30);
    addTask("Water plants", 4, time(NULL) + 60 * 15);

    scheduleTasks();

    return 0;
}