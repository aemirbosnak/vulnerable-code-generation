//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* scheduler_insert(Task* head, char* name, int priority, time_t start_time, time_t end_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_task;
    }

    return head;
}

void scheduler_print(Task* head) {
    Task* current = head;
    printf("Tasks:\n");
    while (current) {
        printf("  - %s (priority %d)\n", current->name, current->priority);
        current = current->next;
    }
}

int main() {
    Task* head = NULL;

    // Insert some tasks
    scheduler_insert(head, "Task 1", 1, time(NULL) + 30, time(NULL) + 60);
    scheduler_insert(head, "Task 2", 2, time(NULL) + 40, time(NULL) + 80);
    scheduler_insert(head, "Task 3", 3, time(NULL) + 50, time(NULL) + 90);

    // Print the tasks
    scheduler_print(head);

    // Sleep for a while
    sleep(20);

    // Print the tasks again after a delay
    scheduler_print(head);

    return 0;
}