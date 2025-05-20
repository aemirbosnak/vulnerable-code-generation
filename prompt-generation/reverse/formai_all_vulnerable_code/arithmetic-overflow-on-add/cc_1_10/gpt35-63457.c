//FormAI DATASET v1.0 Category: Task Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    char name[50];
    int priority;
    int time_required;
} Task;

#define MAX_TASKS 10

Task* task_queue[MAX_TASKS];
int queue_size = 0;

void add_task(Task* task) {
    if (queue_size < MAX_TASKS) {
        task_queue[queue_size] = task;
        queue_size++;
    } else {
        printf("Task queue is full.\n");
    }
}

Task* get_next_task() {
    if (queue_size == 0) {
        return NULL;
    }
    int highest_priority = -1;
    Task* next_task = NULL;
    for (int i = 0; i < queue_size; i++) {
        Task* current_task = task_queue[i];
        if (current_task && current_task->priority > highest_priority) {
            highest_priority = current_task->priority;
            next_task = current_task;
        }
    }
    return next_task;
}

void remove_task(Task* task) {
    for (int i = 0; i < queue_size; i++) {
        if (task_queue[i] == task) {
            // Shift all elements after the removed task one index to the left
            for (int j = i; j < queue_size - 1; j++) {
                task_queue[j] = task_queue[j+1];
            }
            queue_size--;
            break;
        }
    }
}

void print_task_queue() {
    printf("Task Queue:\n");
    for (int i = 0; i < queue_size; i++) {
        printf("- Name: %s, Priority: %d, Time Required: %d\n", task_queue[i]->name, task_queue[i]->priority, task_queue[i]->time_required);
    }
}

void schedule_task(Task* task) {
    printf("Scheduling task: %s\n", task->name);
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + task->time_required) {
        printf(".");
    }
    printf("\nTask complete: %s\n", task->name);
    remove_task(task);
}

int main() {
    Task task1 = {"Task 1", 10, 2}; // name, priority, time required
    Task task2 = {"Task 2", 3, 5};
    Task task3 = {"Task 3", 7, 3};
    Task task4 = {"Task 4", 1, 1};
    Task task5 = {"Task 5", 6, 4};

    add_task(&task1);
    add_task(&task2);
    add_task(&task3);
    add_task(&task4);
    add_task(&task5);

    print_task_queue();

    while (queue_size > 0) {
        Task* next_task = get_next_task();
        if (next_task) {
            schedule_task(next_task);
        } else {
            printf("No tasks remaining.\n");
            break;
        }
    }

    return 0;
}