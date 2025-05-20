//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pthread.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

struct task {
    char name[50];
    int priority;
    void (*function)(void *arg);
    void *arg;
};

struct task tasks[MAX_TASKS];
int num_tasks = 0;

int compare_priority(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void run_tasks() {
    while (1) {
        int i;
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].priority == 0) {
                tasks[i].function(tasks[i].arg);
            }
        }
        usleep(100000); // sleep for 100ms
    }
}

void add_task(char *name, int priority, void (*function)(void *arg), void *arg) {
    if (num_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return;
    }
    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].function = function;
    tasks[num_tasks].arg = arg;
    num_tasks++;
    qsort(tasks, num_tasks, sizeof(struct task), compare_priority);
}

void start_scheduler() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, run_tasks, NULL);
}

int main() {
    setpriority(PRIO_PROCESS, 0, 19); // set highest priority for the main thread
    start_scheduler();

    while (1) {
        char name[50];
        int priority;
        printf("Enter task name: ");
        scanf("%s", name);
        printf("Enter task priority (0-9): ");
        scanf("%d", &priority);
        add_task(name, priority, NULL, NULL);
    }

    return 0;
}