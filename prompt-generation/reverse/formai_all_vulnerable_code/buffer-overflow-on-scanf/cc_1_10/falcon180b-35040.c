//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define INITIAL_STACK_SIZE 100

typedef struct task_s {
    char *name;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} task_t;

typedef struct stack_s {
    task_t tasks[INITIAL_STACK_SIZE];
    int top;
} stack_t;

void push(stack_t *stack, task_t task) {
    if (stack->top >= INITIAL_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->tasks[++stack->top] = task;
}

task_t pop(stack_t *stack) {
    if (stack->top <= 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->tasks[stack->top--];
}

void print_tasks(stack_t *stack) {
    for (int i = stack->top; i >= 0; i--) {
        printf("%s (%d)\n", stack->tasks[i].name, stack->tasks[i].priority);
    }
}

int main() {
    stack_t ready_queue;
    ready_queue.top = -1;

    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    task_t tasks[num_tasks];
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i+1);
        printf("Name: ");
        char name[50];
        scanf("%s", name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    int quantum = 2; // time slice for each task
    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        task_t current_task = pop(&ready_queue);
        current_time += current_task.burst_time;

        if (current_task.burst_time > quantum) {
            current_task.burst_time -= quantum;
            push(&ready_queue, current_task);
        } else {
            completed_tasks++;
        }
    }

    printf("All tasks completed in %d time units.\n", current_time);

    return 0;
}