//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_DELAY 1000

struct task {
    char name[20];
    int priority;
    time_t delay;
};

int task_compare(const void* a, const void* b) {
    struct task* task_a = (struct task*)a;
    struct task* task_b = (struct task*)b;
    if(task_a->priority > task_b->priority) {
        return -1;
    } else if(task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

void run_tasks(struct task* tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(struct task), task_compare);
    for(int i = 0; i < num_tasks; i++) {
        printf("Running task %s with priority %d\n", tasks[i].name, tasks[i].priority);
        sleep(tasks[i].delay);
    }
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);
    struct task tasks[MAX_TASKS];
    for(int i = 0; i < num_tasks; i++) {
        printf("Enter the name of task %d: ", i+1);
        scanf("%s", tasks[i].name);
        printf("Enter the priority of task %s (1-10): ", tasks[i].name);
        scanf("%d", &tasks[i].priority);
        printf("Enter the delay time for task %s in milliseconds: ", tasks[i].name);
        scanf("%d", &tasks[i].delay);
    }
    run_tasks(tasks, num_tasks);
    return 0;
}