//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* scheduler_add_task(Task* head, char* name, time_t start_time, time_t end_time) {
    if (head == NULL) {
        head = (Task*)malloc(sizeof(Task));
        head->next = NULL;
    } else {
        Task* new_task = (Task*)malloc(sizeof(Task));
        new_task->next = head;
        head = new_task;
    }

    strcpy(head->name, name);
    head->start_time = start_time;
    head->end_time = end_time;

    return head;
}

void scheduler_print_tasks(Task* head) {
    Task* current_task = head;

    while (current_task) {
        printf("Name: %s\n", current_task->name);
        printf("Start Time: %ld\n", current_task->start_time);
        printf("End Time: %ld\n", current_task->end_time);
        printf("\n");

        current_task = current_task->next;
    }
}

int main() {
    Task* head = NULL;

    // Add some tasks
    scheduler_add_task(head, "Task 1", time(NULL) + 3600, time(NULL) + 7200);
    scheduler_add_task(head, "Task 2", time(NULL) + 5400, time(NULL) + 9000);
    scheduler_add_task(head, "Task 3", time(NULL) + 6000, time(NULL) + 10800);

    // Print the tasks
    scheduler_print_tasks(head);

    return 0;
}