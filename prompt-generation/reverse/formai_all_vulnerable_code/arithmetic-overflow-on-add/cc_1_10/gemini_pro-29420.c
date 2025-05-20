//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct task {
    int id;
    char *name;
    int priority;
    int remaining_time;
};

struct task_queue {
    struct task *tasks;
    int num_tasks;
    int max_tasks;
};

struct task_queue *create_task_queue(int max_tasks) {
    struct task_queue *queue = malloc(sizeof(struct task_queue));
    if (!queue) {
        return NULL;
    }

    queue->tasks = malloc(max_tasks * sizeof(struct task));
    if (!queue->tasks) {
        free(queue);
        return NULL;
    }

    queue->num_tasks = 0;
    queue->max_tasks = max_tasks;

    return queue;
}

void destroy_task_queue(struct task_queue *queue) {
    for (int i = 0; i < queue->num_tasks; i++) {
        free(queue->tasks[i].name);
    }

    free(queue->tasks);
    free(queue);
}

int add_task(struct task_queue *queue, struct task task) {
    if (queue->num_tasks == queue->max_tasks) {
        return -1;
    }

    queue->tasks[queue->num_tasks++] = task;

    return 0;
}

struct task *get_highest_priority_task(struct task_queue *queue) {
    int highest_priority = -1;
    struct task *highest_priority_task = NULL;

    for (int i = 0; i < queue->num_tasks; i++) {
        if (queue->tasks[i].priority > highest_priority) {
            highest_priority = queue->tasks[i].priority;
            highest_priority_task = &queue->tasks[i];
        }
    }

    return highest_priority_task;
}

int main() {
    struct task_queue *queue = create_task_queue(10);

    struct task task1 = {1, "Task 1", 10, 100};
    struct task task2 = {2, "Task 2", 5, 50};
    struct task task3 = {3, "Task 3", 15, 150};

    add_task(queue, task1);
    add_task(queue, task2);
    add_task(queue, task3);

    struct task *highest_priority_task = get_highest_priority_task(queue);

    printf("Highest priority task: %s\n", highest_priority_task->name);

    destroy_task_queue(queue);

    return 0;
}