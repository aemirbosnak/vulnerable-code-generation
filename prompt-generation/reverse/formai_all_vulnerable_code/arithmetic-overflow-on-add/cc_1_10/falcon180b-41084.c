//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
};

void add_task(struct task tasks[], int num_tasks, char name[], int priority, time_t start_time, time_t end_time) {
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

void display_tasks(struct task tasks[], int num_tasks) {
    printf("Task Name\tPriority\tStart Time\tEnd Time\n");

    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%s\t%s\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time));
    }
}

void schedule_tasks(struct task tasks[], int num_tasks) {
    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time == current_time) {
            printf("Task %s started at %s.\n", tasks[i].name, ctime(&tasks[i].start_time));
        }

        if (tasks[i].end_time == current_time) {
            printf("Task %s ended at %s.\n", tasks[i].name, ctime(&tasks[i].end_time));
        }
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, "Task 1", 1, time(NULL) + 5, time(NULL) + 10);
    add_task(tasks, num_tasks, "Task 2", 2, time(NULL) + 10, time(NULL) + 15);
    add_task(tasks, num_tasks, "Task 3", 3, time(NULL) + 20, time(NULL) + 25);

    display_tasks(tasks, num_tasks);

    while (num_tasks > 0) {
        schedule_tasks(tasks, num_tasks);
        sleep(1);
    }

    return 0;
}