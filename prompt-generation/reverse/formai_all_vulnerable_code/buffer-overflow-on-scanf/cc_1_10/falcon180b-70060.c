//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    time_t start_time;
    time_t end_time;
    int duration;
    int status;
} Task;

int task_compare(const void *a, const void *b) {
    const Task *task1 = (const Task *)a;
    const Task *task2 = (const Task *)b;

    if (task1->priority > task2->priority) {
        return 1;
    } else if (task1->priority < task2->priority) {
        return -1;
    } else {
        return 0;
    }
}

void task_scheduler(Task *tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), task_compare);

    for (int i = 0; i < num_tasks; i++) {
        printf("%s: %d\n", tasks[i].name, tasks[i].priority);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task name (max %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", tasks[num_tasks].name);

        printf("Enter task priority (1-10): ");
        scanf("%d", &tasks[num_tasks].priority);

        printf("Enter task start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", tasks[num_tasks].start_time);

        printf("Enter task end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", tasks[num_tasks].end_time);

        tasks[num_tasks].duration = difftime(mktime(tasks[num_tasks].end_time), mktime(tasks[num_tasks].start_time));
        tasks[num_tasks].status = 0;

        num_tasks++;
    }

    task_scheduler(tasks, num_tasks);

    return 0;
}