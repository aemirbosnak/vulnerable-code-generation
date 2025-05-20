//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct task {
    int id;
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
} Task;

void add_task(Task* tasks, int num_tasks, int id, char* name, int priority, time_t start_time, time_t end_time) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].id == id) {
            printf("Error: Task with ID %d already exists.\n", id);
            return;
        }
    }

    tasks[num_tasks].id = id;
    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;

    num_tasks++;
}

void display_tasks(Task* tasks, int num_tasks) {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s (Priority: %d, Start Time: %s, End Time: %s)\n", tasks[i].id, tasks[i].name, tasks[i].priority, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time));
    }
}

void schedule_tasks(Task* tasks, int num_tasks) {
    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time <= current_time && tasks[i].end_time >= current_time) {
            printf("Task %s is currently running.\n", tasks[i].name);
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, 1, "Task 1", 1, time(NULL), time(NULL) + 10);
    add_task(tasks, num_tasks, 2, "Task 2", 2, time(NULL), time(NULL) + 20);
    add_task(tasks, num_tasks, 3, "Task 3", 3, time(NULL), time(NULL) + 30);

    display_tasks(tasks, num_tasks);

    while (1) {
        schedule_tasks(tasks, num_tasks);
        sleep(1);
    }

    return 0;
}