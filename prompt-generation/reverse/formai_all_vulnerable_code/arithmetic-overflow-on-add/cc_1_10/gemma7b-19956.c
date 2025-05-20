//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10
#define TASK_NAME_SIZE 20

typedef struct Task {
    char name[TASK_NAME_SIZE];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

void scheduler_init(Task** head) {
    *head = NULL;
}

void scheduler_add_task(Task** head, char* name, int priority, time_t start_time, time_t end_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void scheduler_print_tasks(Task* head) {
    while (head) {
        printf("Name: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", head->name, head->priority, head->start_time, head->end_time);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;
    scheduler_init(&head);

    scheduler_add_task(&head, "Task 1", 1, time(NULL) + 30, time(NULL) + 60);
    scheduler_add_task(&head, "Task 2", 2, time(NULL) + 45, time(NULL) + 75);
    scheduler_add_task(&head, "Task 3", 3, time(NULL) + 60, time(NULL) + 90);

    scheduler_print_tasks(head);

    return 0;
}