//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    int remaining_time;
    struct Task* next;
} Task;

void add_task(Task** head) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    printf("Enter task name: ");
    scanf("%s", new_task->name);
    printf("Enter task priority (1-5): ");
    scanf("%d", &new_task->priority);
    printf("Enter estimated task time (in minutes): ");
    scanf("%d", &new_task->estimated_time);
    new_task->remaining_time = new_task->estimated_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void print_tasks(Task* head) {
    while (head) {
        printf("Task name: %s\n", head->name);
        printf("Priority: %d\n", head->priority);
        printf("Estimated time: %d minutes\n", head->estimated_time);
        printf("Remaining time: %d minutes\n", head->remaining_time);
        printf("\n");
        head = head->next;
    }
}

void schedule_tasks(Task* head) {
    time_t now = time(NULL);
    for (Task* task = head; task; task = task->next) {
        task->remaining_time -= (time_t)difftime(now, task->estimated_time * 60);
        if (task->remaining_time <= 0) {
            printf("Task complete: %s\n", task->name);
            free(task);
        }
    }
}

int main() {
    Task* head = NULL;
    add_task(&head);
    add_task(&head);
    add_task(&head);
    print_tasks(head);
    schedule_tasks(head);
    print_tasks(head);

    return 0;
}