//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*task_function_t) (void*);

typedef struct {
    time_t scheduled_time;
    task_function_t task;
    void* args;
} task_t;

typedef struct {
    task_t *tasks;
    size_t count;
    size_t max_count;
} task_list_t;

void task_scheduler(task_list_t *task_list, time_t current_time) {
    size_t i = 0;
    while (i < task_list->count && task_list->tasks[i].scheduled_time <= current_time) {
        task_t *task = &task_list->tasks[i];
        task->task(task->args);
        i++;
    }
    task_list->count -= i;
    if (task_list->count > 0) {
        memmove(task_list->tasks, task_list->tasks + i, task_list->count * sizeof(task_t));
    }
}

void add_task(task_list_t *task_list, time_t scheduled_time, task_function_t task, void *args) {
    if (task_list->count == task_list->max_count) {
        task_list->max_count += 16;
        task_list->tasks = realloc(task_list->tasks, task_list->max_count * sizeof(task_t));
    }
    task_t *new_task = &task_list->tasks[task_list->count];
    new_task->scheduled_time = scheduled_time;
    new_task->task = task;
    new_task->args = args;
    task_list->count++;
}

void print_task(void *args) {
    const char *text = (const char*) args;
    printf("Task executed: %s\n", text);
}

int main(void) {
    task_list_t task_list = { NULL, 0, 0 };
    add_task(&task_list, time(NULL) + 3, print_task, "Hello from task 1");
    add_task(&task_list, time(NULL) + 5, print_task, "Hello from task 2");
    add_task(&task_list, time(NULL) + 2, print_task, "Hello from task 3");
    add_task(&task_list, time(NULL) + 1, print_task, "Hello from task 4");

    while (task_list.count > 0) {
        time_t current_time = time(NULL);
        task_scheduler(&task_list, current_time);
    }

    return 0;
}