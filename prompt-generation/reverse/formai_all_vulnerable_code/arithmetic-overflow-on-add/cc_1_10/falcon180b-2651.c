//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

struct task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
};

void add_task(struct task *tasks, int num_tasks, char *name, int priority, time_t start_time, time_t end_time) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    int i;
    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].priority == priority) {
            printf("Error: Task with same priority already exists.\n");
            return;
        }
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;

    num_tasks++;
}

void display_tasks(struct task *tasks, int num_tasks) {
    printf("Task Name\tPriority\tStart Time\tEnd Time\n");

    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%s\t%s\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time));
    }
}

void schedule_tasks(struct task *tasks, int num_tasks) {
    time_t current_time;

    while (1) {
        time(&current_time);

        int i;
        for (i = 0; i < num_tasks; i++) {
            if (difftime(current_time, tasks[i].start_time) == 0) {
                system(tasks[i].name);
            } else if (difftime(current_time, tasks[i].end_time) == 0) {
                printf("Task \"%s\" ended at %s.\n", tasks[i].name, ctime(&current_time));
            }
        }

        sleep(1);
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, "Task A", 1, time(NULL) + 5, time(NULL) + 10);
    add_task(tasks, num_tasks, "Task B", 2, time(NULL) + 15, time(NULL) + 20);
    add_task(tasks, num_tasks, "Task C", 3, time(NULL) + 25, time(NULL) + 30);

    display_tasks(tasks, num_tasks);

    schedule_tasks(tasks, num_tasks);

    return 0;
}