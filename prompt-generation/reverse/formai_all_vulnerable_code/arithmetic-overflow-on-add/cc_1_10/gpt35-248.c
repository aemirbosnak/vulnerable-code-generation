//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a task struct
typedef struct task {
    void (*function)(void);
    int execute_time;
    struct task* next;
} Task;

// Define the head of the task linked list
Task* head = NULL;

// Function to add a new task to the scheduler
void add_task(void (*func)(void), int time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->function = func;
    new_task->execute_time = time;

    if (head == NULL) {
        head = new_task;
        new_task->next = NULL;
    } else {
        Task* current = head;
        if (new_task->execute_time < head->execute_time) {
            new_task->next = head;
            head = new_task;
        } else {
            while (current->next != NULL && current->next->execute_time < new_task->execute_time) {
                current = current->next;
            }
            new_task->next = current->next;
            current->next = new_task;
        }
    }
}

// Function to execute all tasks that are ready
void execute_tasks() {
    Task* current = head;
    time_t current_time = time(NULL);
    while (current != NULL && current->execute_time <= current_time) {
        current->function();
        head = current->next;
        free(current);
        current = head;
    }
}

// Example tasks
void task1() {
    printf("Task 1 executed at %ld\n", time(NULL));
}

void task2() {
    printf("Task 2 executed at %ld\n", time(NULL));
}

void task3() {
    printf("Task 3 executed at %ld\n", time(NULL));
}

int main() {
    // Add example tasks
    add_task(task2, time(NULL) + 2);
    add_task(task1, time(NULL) + 1);
    add_task(task3, time(NULL) + 3);
    add_task(task1, time(NULL) + 4);

    // Execute tasks
    while (head != NULL) {
        execute_tasks();
    }

    return 0;
}