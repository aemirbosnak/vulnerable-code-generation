//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5
#define DELAY_MIN 1000
#define DELAY_MAX 60000

typedef struct task {
    int id;
    char name[20];
    time_t start;
    time_t end;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, time_t start, time_t end) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached\n");
        return;
    }

    tasks[num_tasks].id = num_tasks++;
    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].start = start;
    tasks[num_tasks].end = end;
}

void schedule() {
    time_t now = time(NULL);
    int i;

    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].start <= now && now < tasks[i].end) {
            printf("Running task %d: %s\n", tasks[i].id, tasks[i].name);
            // Do the task's work here
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    add_task("Task 1", time(NULL) + (rand() % DELAY_MIN + DELAY_MAX), time(NULL) + (rand() % DELAY_MIN + DELAY_MAX));
    add_task("Task 2", time(NULL) + (rand() % DELAY_MIN + DELAY_MAX), time(NULL) + (rand() % DELAY_MIN + DELAY_MAX));
    add_task("Task 3", time(NULL) + (rand() % DELAY_MIN + DELAY_MAX), time(NULL) + (rand() % DELAY_MIN + DELAY_MAX));

    while (1) {
        schedule();
        sleep(1);
    }

    return 0;
}