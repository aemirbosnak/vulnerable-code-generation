//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_WAIT_TIME 5

typedef struct {
    char *name;
    void (*function)(void);
    time_t start_time;
    int interval;
} Task;

void print_tasks(Task tasks[], int num_tasks) {
    printf("Current tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s (%d seconds)\n", tasks[i].name, tasks[i].interval);
    }
}

void execute_task(Task task) {
    printf("%s is executing...\n", task.name);
    usleep(task.interval * 1000000);
    printf("%s has finished executing.\n", task.name);
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task name (or type 'done' to finish): ");
        char name[50];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter task interval (in seconds): ");
        int interval;
        scanf("%d", &interval);

        tasks[num_tasks].name = strdup(name);
        tasks[num_tasks].function = &execute_task;
        tasks[num_tasks].start_time = time(NULL) + TASK_WAIT_TIME;
        tasks[num_tasks].interval = interval;

        num_tasks++;
    }

    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].start_time <= current_time) {
                execute_task(tasks[i]);
                tasks[i].start_time = current_time + tasks[i].interval;
            }
        }

        usleep(1000000);
    }

    return 0;
}