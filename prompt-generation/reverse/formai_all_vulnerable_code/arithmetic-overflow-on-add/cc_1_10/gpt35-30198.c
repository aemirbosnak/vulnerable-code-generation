//FormAI DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define NUM_TASKS 5

typedef struct {
    int id;
    int interval;
    int next_execution;
} Task;

Task tasks[NUM_TASKS];

int get_current_time() {
    return (int) time(NULL);
}

void task_1() {
    printf("Task 1 executed!\n");
}

void task_2() {
    printf("Task 2 executed!\n");
}

void task_3() {
    printf("Task 3 executed!\n");
}

void task_4() {
    printf("Task 4 executed!\n");
}

void task_5() {
    printf("Task 5 executed!\n");
}

void setup_tasks() {
    tasks[0].id = 1;
    tasks[0].interval = 1;
    tasks[0].next_execution = get_current_time() + tasks[0].interval;
    tasks[1].id = 2;
    tasks[1].interval = 2;
    tasks[1].next_execution = get_current_time() + tasks[1].interval;
    tasks[2].id = 3;
    tasks[2].interval = 3;
    tasks[2].next_execution = get_current_time() + tasks[2].interval;
    tasks[3].id = 4;
    tasks[3].interval = 4;
    tasks[3].next_execution = get_current_time() + tasks[3].interval;
    tasks[4].id = 5;
    tasks[4].interval = 5;
    tasks[4].next_execution = get_current_time() + tasks[4].interval;
}

void run_tasks() {
    int i;
    for (i=0; i<NUM_TASKS; i++) {
        if (tasks[i].next_execution <= get_current_time()) {
            // Execute task i
            switch (tasks[i].id) {
                case 1:
                    task_1();
                    break;
                case 2:
                    task_2();
                    break;
                case 3:
                    task_3();
                    break;
                case 4:
                    task_4();
                    break;
                case 5:
                    task_5();
                    break;
            }

            // Update the next execution time
            tasks[i].next_execution = get_current_time() + tasks[i].interval;
        }
    }
}

void signal_handler(int sig) {
    switch(sig) {
        case SIGTERM:
            printf("Received SIGTERM\n");
            exit(0);
            break;
        case SIGINT:
            printf("Received SIGINT\n");
            exit(0);
            break;
        case SIGHUP:
            printf("Received SIGHUP\n");
            break;
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGINT");
    }
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGTERM");
    }
    if (sigaction(SIGHUP, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGHUP");
    }

    setup_tasks();

    printf("Starting task scheduler...\n");

    while(1) {
        run_tasks();
        sleep(1);
    }

    return 0;
}