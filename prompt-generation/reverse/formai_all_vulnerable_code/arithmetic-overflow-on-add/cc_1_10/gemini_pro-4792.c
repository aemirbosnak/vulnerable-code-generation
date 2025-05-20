//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

#define MAX_TASKS 10

typedef struct task {
    int id;
    int interval;
    int start_time;
    int next_run_time;
    void (*func)(void*);
    void* arg;
} task;

task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(int id, int interval, void (*func)(void*), void* arg) {
    if (num_tasks == MAX_TASKS) {
        fprintf(stderr, "Error: maximum number of tasks reached.\n");
        return;
    }

    task* t = &tasks[num_tasks++];
    t->id = id;
    t->interval = interval;
    t->start_time = time(NULL);
    t->next_run_time = t->start_time + interval;
    t->func = func;
    t->arg = arg;
}

void remove_task(int id) {
    for (int i = 0; i < num_tasks; i++) {
        task* t = &tasks[i];
        if (t->id == id) {
            memmove(&tasks[i], &tasks[i+1], sizeof(task) * (num_tasks - i - 1));
            num_tasks--;
            return;
        }
    }

    fprintf(stderr, "Error: no task with ID %d found.\n", id);
}

void print_tasks() {
    printf("Current tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        task* t = &tasks[i];
        printf("  - ID: %d, Interval: %d seconds, Next run: %d seconds from now\n", t->id, t->interval, t->next_run_time - time(NULL));
    }
}

void handle_signal(int signum) {
    struct itimerval timer;

    // Check which tasks need to be run
    for (int i = 0; i < num_tasks; i++) {
        task* t = &tasks[i];
        if (t->next_run_time <= time(NULL)) {
            // Run the task
            t->func(t->arg);

            // Recalculate the next run time
            t->next_run_time = time(NULL) + t->interval;
        }
    }

    getitimer(ITIMER_REAL, &timer);
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
}

int main() {
    struct itimerval timer;

    // Add some tasks
    add_task(1, 5, print_tasks, NULL);
    add_task(2, 10, printf, "Hello, world!\n");
    add_task(3, 15, remove_task, 2);

    // Set up the timer
    getitimer(ITIMER_REAL, &timer);
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);

    // Install the signal handler
    signal(SIGALRM, handle_signal);

    // Run the main loop
    while (1) {
        pause();
    }

    return 0;
}