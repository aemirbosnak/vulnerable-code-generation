//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Task {
    char* name;
    int priority;
    time_t time;
};

struct TaskList {
    struct Task* tasks;
    int count;
    int capacity;
};

void add_task(struct TaskList* list, char* name, int priority, time_t time) {
    struct Task new_task;
    new_task.name = name;
    new_task.priority = priority;
    new_task.time = time;

    if (list->count >= list->capacity) {
        list->capacity <<= 1;
        struct Task* new_tasks = realloc(list->tasks, list->capacity * sizeof(struct Task));
        if (new_tasks!= NULL) {
            list->tasks = new_tasks;
        } else {
            printf("Out of memory.\n");
            exit(1);
        }
    }

    list->tasks[list->count++] = new_task;
}

void remove_task(struct TaskList* list, char* name) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->tasks[i].name, name) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->tasks[j] = list->tasks[j + 1];
            }
            list->count--;
            break;
        }
    }
}

void execute_tasks(struct TaskList* list, time_t now) {
    struct Task* task = NULL;
    for (int i = 0; i < list->count; i++) {
        if (now >= list->tasks[i].time) {
            task = list->tasks + i;
            break;
        }
    }
    if (task!= NULL) {
        printf("Executing task '%s' with priority %d.\n", task->name, task->priority);
    }
}

void print_tasks(struct TaskList* list) {
    struct Task* task;
    for (int i = 0; i < list->count; i++) {
        task = list->tasks + i;
        printf("%s (%d) - %s\n", task->name, task->priority, ctime(&task->time));
    }
}

void main() {
    struct TaskList task_list;
    task_list.capacity = 10;
    task_list.tasks = malloc(task_list.capacity * sizeof(struct Task));
    if (task_list.tasks == NULL) {
        printf("Out of memory.\n");
        exit(1);
    }
    task_list.count = 0;

    add_task(&task_list, "Task 1", 1, time(NULL));
    add_task(&task_list, "Task 2", 2, time(NULL) + 60);
    add_task(&task_list, "Task 3", 3, time(NULL) + 120);

    print_tasks(&task_list);
    execute_tasks(&task_list, time(NULL));
    print_tasks(&task_list);
    execute_tasks(&task_list, time(NULL) + 60);
    print_tasks(&task_list);
}