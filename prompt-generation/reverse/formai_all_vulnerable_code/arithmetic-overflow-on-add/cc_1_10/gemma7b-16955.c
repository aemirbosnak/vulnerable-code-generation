//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10
#define TASK_STATE_NEW 0
#define TASK_STATE_RUNNING 1
#define TASK_STATE_DONE 2

typedef struct task_node {
    char name[20];
    int state;
    time_t start_time;
    time_t end_time;
    struct task_node* next;
} task_node;

void schedule_add(task_node** head, char* name, time_t start_time, time_t end_time) {
    task_node* new_task = (task_node*)malloc(sizeof(task_node));
    strcpy(new_task->name, name);
    new_task->state = TASK_STATE_NEW;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void schedule_print(task_node* head) {
    while (head) {
        printf("Name: %s, State: %d, Start Time: %ld, End Time: %ld\n", head->name, head->state, head->start_time, head->end_time);
        head = head->next;
    }
}

int main() {
    task_node* head = NULL;

    schedule_add(&head, "Task 1", time(NULL) + 10, time(NULL) + 20);
    schedule_add(&head, "Task 2", time(NULL) + 15, time(NULL) + 25);
    schedule_add(&head, "Task 3", time(NULL) + 20, time(NULL) + 30);

    schedule_print(head);

    return 0;
}