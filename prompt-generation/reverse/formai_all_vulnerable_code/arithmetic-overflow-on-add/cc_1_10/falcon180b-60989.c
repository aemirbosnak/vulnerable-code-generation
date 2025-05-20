//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    char name[50];
    int priority;
    time_t start_time;
    time_t end_time;
};

void add_task(struct task *tasks, int num_tasks, char *name, int priority, time_t start_time, time_t end_time) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;

    num_tasks++;
}

void print_tasks(struct task *tasks, int num_tasks) {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s (Priority %d) - %s to %s\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time));
    }
}

int compare_tasks(const void *a, const void *b) {
    struct task task_a = *(struct task *)a;
    struct task task_b = *(struct task *)b;

    if (task_a.start_time > task_b.start_time) {
        return 1;
    } else if (task_a.start_time < task_b.start_time) {
        return -1;
    } else {
        return 0;
    }
}

void schedule_tasks(struct task *tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(struct task), compare_tasks);

    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time <= current_time && tasks[i].end_time >= current_time) {
            printf("Currently executing: %s\n", tasks[i].name);
        }
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, "Task 1", 1, time(NULL) + 5, time(NULL) + 10);
    add_task(tasks, num_tasks, "Task 2", 2, time(NULL) + 3, time(NULL) + 8);
    add_task(tasks, num_tasks, "Task 3", 3, time(NULL) + 1, time(NULL) + 6);

    print_tasks(tasks, num_tasks);

    schedule_tasks(tasks, num_tasks);

    return 0;
}