//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    char* command;
    time_t start_time;
    time_t interval;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char* command, time_t start_time, time_t interval) {
    tasks[num_tasks].command = command;
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].interval = interval;
    num_tasks++;
}

void remove_task(int index) {
    for (int i = index; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    num_tasks--;
}

void run_task(int index) {
    pid_t pid = fork();
    if (pid == 0) {
        execlp(tasks[index].command, tasks[index].command, NULL);
    } else {
        wait(NULL);
    }
}

void schedule_task(int index) {
    time_t current_time = time(NULL);
    if (current_time >= tasks[index].start_time) {
        run_task(index);
        tasks[index].start_time = current_time + tasks[index].interval;
    }
}

void run_scheduler() {
    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            schedule_task(i);
        }
        sleep(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <command> <start_time> <interval>\n", argv[0]);
        return 1;
    }
    add_task(argv[1], atoi(argv[2]), atoi(argv[3]));
    run_scheduler();
    return 0;
}