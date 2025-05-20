//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct task {
    char name[50];
    int priority;
    time_t start_time;
    time_t end_time;
    int duration;
    int status;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int priority, time_t start_time, time_t end_time, int duration) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;
    tasks[num_tasks].duration = duration;
    tasks[num_tasks].status = 0;

    num_tasks++;
}

void schedule_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time <= current_time && tasks[i].status == 0) {
            tasks[i].status = 1;
            printf("Starting task %s at %s\n", tasks[i].name, ctime(&current_time));
        } else if (tasks[i].end_time <= current_time && tasks[i].status == 1) {
            tasks[i].status = 2;
            printf("Ending task %s at %s\n", tasks[i].name, ctime(&current_time));
        }
    }
}

int main() {
    add_task("Task 1", 1, time(NULL) + 10, time(NULL) + 20, 10);
    add_task("Task 2", 2, time(NULL) + 15, time(NULL) + 30, 15);
    add_task("Task 3", 3, time(NULL) + 25, time(NULL) + 40, 15);

    while (1) {
        schedule_tasks();
        sleep(1);
    }

    return 0;
}