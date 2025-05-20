//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[50];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* task_create() {
    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->next = NULL;
    return new_task;
}

void task_add(Task* head, char* name, time_t start_time, time_t end_time) {
    Task* new_task = task_create();
    strcpy(new_task->name, name);
    new_task->start_time = start_time;
    new_task->end_time = end_time;

    if (head == NULL) {
        head = new_task;
    } else {
        new_task->next = head;
        head = new_task;
    }
}

void task_list(Task* head) {
    while (head) {
        printf("%s, start: %d, end: %d\n", head->name, head->start_time, head->end_time);
        head = head->next;
    }
}

int main() {
    time_t now = time(NULL);
    Task* head = NULL;

    task_add(head, "Forage for supplies", now + 3600, now + 4320);
    task_add(head, "Build shelter", now + 4320, now + 5040);
    task_add(head, "Defend against raiders", now + 5040, now + 5760);

    task_list(head);

    return 0;
}