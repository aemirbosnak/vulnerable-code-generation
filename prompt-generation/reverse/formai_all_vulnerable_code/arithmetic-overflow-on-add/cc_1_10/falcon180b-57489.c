//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct task {
    char name[100];
    int priority;
    time_t start_time;
    time_t end_time;
    int duration;
    int status;
} Task;

void add_task(Task* tasks, int num_tasks, char* name, int priority, time_t start_time, time_t end_time, int duration) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].status == 0) {
            strcpy(tasks[i].name, name);
            tasks[i].priority = priority;
            tasks[i].start_time = start_time;
            tasks[i].end_time = end_time;
            tasks[i].duration = duration;
            tasks[i].status = 1;
            return;
        }
    }
    printf("Error: Task list is full.\n");
}

void display_tasks(Task* tasks, int num_tasks) {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].status == 1) {
            printf("%s\tPriority: %d\tStart Time: %s\tEnd Time: %s\tDuration: %d\tStatus: Active\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time), tasks[i].duration);
        }
    }
}

void execute_tasks(Task* tasks, int num_tasks, time_t current_time) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].status == 1 && tasks[i].start_time <= current_time && tasks[i].end_time >= current_time) {
            tasks[i].status = 2;
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, "Task 1", 1, time(NULL), time(NULL) + 60, 60);
    add_task(tasks, num_tasks, "Task 2", 2, time(NULL) + 120, time(NULL) + 180, 60);
    add_task(tasks, num_tasks, "Task 3", 3, time(NULL) + 240, time(NULL) + 300, 60);

    while (1) {
        time_t current_time = time(NULL);
        execute_tasks(tasks, num_tasks, current_time);
        display_tasks(tasks, num_tasks);
        sleep(1);
    }

    return 0;
}