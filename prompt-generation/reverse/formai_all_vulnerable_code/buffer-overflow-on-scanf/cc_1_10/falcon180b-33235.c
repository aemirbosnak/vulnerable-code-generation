//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char *name;
    time_t start_time;
    unsigned int duration;
} Task;

void schedule_task(Task *task, int index) {
    printf("Scheduling task %s at %d seconds\n", task->name, index);
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d name: ", i + 1);
        scanf("%s", tasks[i].name);

        printf("Enter task %d start time (in seconds): ", i + 1);
        scanf("%d", &tasks[i].start_time);

        printf("Enter task %d duration (in seconds): ", i + 1);
        scanf("%d", &tasks[i].duration);
    }

    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        int index = tasks[i].start_time - current_time;

        if (index <= 0) {
            printf("Task %s has already started\n", tasks[i].name);
        } else {
            printf("Scheduling task %s in %d seconds\n", tasks[i].name, index);
            schedule_task(&tasks[i], index);
        }
    }

    return 0;
}