//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct {
    char name[20];
    int priority;
    int duration;
    time_t start_time;
    time_t end_time;
} Task;

void init_task(Task *task, char *name, int priority, int duration) {
    strcpy(task->name, name);
    task->priority = priority;
    task->duration = duration;
    task->start_time = 0;
    task->end_time = 0;
}

int compare_priority(const void *a, const void *b) {
    Task *task_a = (Task *)a;
    Task *task_b = (Task *)b;

    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

void schedule_tasks(Task tasks[], int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        tasks[i].start_time = time(NULL) + tasks[i].duration;
        tasks[i].end_time = tasks[i].start_time + tasks[i].duration;
    }
}

void print_schedule(Task tasks[], int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        printf("%s: %d (%d-%d)\n", tasks[i].name, tasks[i].priority, tasks[i].start_time, tasks[i].end_time);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    init_task(&tasks[num_tasks++], "Task A", 3, 5);
    init_task(&tasks[num_tasks++], "Task B", 1, 2);
    init_task(&tasks[num_tasks++], "Task C", 5, 7);
    init_task(&tasks[num_tasks++], "Task D", 2, 4);
    init_task(&tasks[num_tasks++], "Task E", 4, 6);

    schedule_tasks(tasks, num_tasks);
    print_schedule(tasks, num_tasks);

    return 0;
}