//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    char name[20];
    int priority;
    time_t start_time;
    int duration;
    int period;
};

void print_task(struct task task) {
    printf("%s (%d) - start time: %s, duration: %d, period: %d\n", task.name, task.priority, ctime(&task.start_time), task.duration, task.period);
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    struct task tasks[MAX_TASKS];

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Start time: ");
        scanf("%s", tasks[i].start_time);
        printf("Duration: ");
        scanf("%d", &tasks[i].duration);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
    }

    printf("Task schedule:\n");

    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_tasks; i++) {
            if (difftime(current_time, tasks[i].start_time) == 0) {
                print_task(tasks[i]);
            }
        }

        sleep(1);
    }

    return 0;
}