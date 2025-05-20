//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 32
#define MAX_TASK_CMD_LEN 256

struct task {
    char name[MAX_TASK_NAME_LEN];
    char cmd[MAX_TASK_CMD_LEN];
    time_t scheduled_time;
};

struct task_scheduler {
    struct task tasks[MAX_TASKS];
    int num_tasks;
};

struct task_scheduler scheduler;

void load_tasks()
{
    FILE *fp;
    int i;

    fp = fopen("tasks.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    scheduler.num_tasks = 0;
    while (fscanf(fp, "%s %s %ld", scheduler.tasks[scheduler.num_tasks].name,
                 scheduler.tasks[scheduler.num_tasks].cmd,
                 &scheduler.tasks[scheduler.num_tasks].scheduled_time) != EOF) {
        scheduler.num_tasks++;
    }

    fclose(fp);
}

void run_tasks()
{
    int i;
    time_t now;

    now = time(NULL);

    for (i = 0; i < scheduler.num_tasks; i++) {
        if (scheduler.tasks[i].scheduled_time <= now) {
            printf("Running task %s\n", scheduler.tasks[i].name);
            system(scheduler.tasks[i].cmd);
        }
    }
}

int main()
{
    load_tasks();
    run_tasks();
    return EXIT_SUCCESS;
}