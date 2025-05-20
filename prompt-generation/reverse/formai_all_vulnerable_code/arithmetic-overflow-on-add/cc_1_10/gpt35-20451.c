//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    void (* func)(void);
    int interval;
    time_t next_run;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(void (* func)(void), int interval) {
    if (num_tasks == MAX_TASKS) {
        printf("Error: Maximum number of tasks (%d) reached\n", MAX_TASKS);
        return;
    }
    tasks[num_tasks].id = num_tasks + 1;
    tasks[num_tasks].func = func;
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].next_run = time(NULL) + interval;
    printf("Added Task %d with interval %d\n", num_tasks + 1, interval);
    num_tasks++;
}

void remove_task(int task_id) {
    int i, index = -1;
    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].id == task_id) {
            printf("Removed Task %d\n", task_id);
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Task with id %d not found\n", task_id);
        return;
    }
    for (i = index; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i+1];
    }
    num_tasks--;
}

void print_tasks() {
    int i;
    printf("Task List:\n");
    for (i = 0; i < num_tasks; i++) {
        printf("Task %d (interval %d)\n", tasks[i].id, tasks[i].interval);
    }
}

void handle_signal(int signal) {
    int i;
    time_t now = time(NULL);
    for (i = 0; i < num_tasks; i++) {
        if (now >= tasks[i].next_run) {
            tasks[i].func();
            tasks[i].next_run += tasks[i].interval;
        }
    }
}

void initialize_scheduler() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("Error: sigaction");
        exit(1);
    }
    alarm(1);
}

void task1() {
    printf("Hello from Task 1!\n");
}

void task2() {
    printf("Hello from Task 2!\n");
}

int main() {
    initialize_scheduler();
    add_task(task1, 2);
    add_task(task2, 5);
    while (1) {
        print_tasks();
        sleep(1);
    }
    return 0;
}