//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

#define MAX_TASKS 10

struct task {
    char *name;
    char *command;
    time_t start_time;
    time_t end_time;
};

struct task_scheduler {
    struct task tasks[MAX_TASKS];
    int num_tasks;
};

static struct task_scheduler scheduler;

static void add_task(char *name, char *command, time_t start_time, time_t end_time)
{
    if (scheduler.num_tasks == MAX_TASKS) {
        fprintf(stderr, "Error: maximum number of tasks reached\n");
        return;
    }

    scheduler.tasks[scheduler.num_tasks].name = name;
    scheduler.tasks[scheduler.num_tasks].command = command;
    scheduler.tasks[scheduler.num_tasks].start_time = start_time;
    scheduler.tasks[scheduler.num_tasks].end_time = end_time;

    scheduler.num_tasks++;
}

static void remove_task(char *name)
{
    int i;

    for (i = 0; i < scheduler.num_tasks; i++) {
        if (strcmp(scheduler.tasks[i].name, name) == 0) {
            break;
        }
    }

    if (i == scheduler.num_tasks) {
        fprintf(stderr, "Error: task not found\n");
        return;
    }

    for (; i < scheduler.num_tasks - 1; i++) {
        scheduler.tasks[i] = scheduler.tasks[i + 1];
    }

    scheduler.num_tasks--;
}

static void list_tasks()
{
    int i;

    for (i = 0; i < scheduler.num_tasks; i++) {
        printf("%s: %s (%ld - %ld)\n", scheduler.tasks[i].name, scheduler.tasks[i].command, scheduler.tasks[i].start_time, scheduler.tasks[i].end_time);
    }
}

static void run_scheduler()
{
    time_t now;
    int i;

    while (1) {
        now = time(NULL);

        for (i = 0; i < scheduler.num_tasks; i++) {
            if (scheduler.tasks[i].start_time <= now && scheduler.tasks[i].end_time >= now) {
                system(scheduler.tasks[i].command);
            }
        }

        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments]...\n", argv[0]);
        return EXIT_FAILURE;
    }

    add_task("task1", argv[1], time(NULL), time(NULL) + 60);

    run_scheduler();

    return EXIT_SUCCESS;
}