//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TASKS 10
#define TASK_QUEUE_SIZE 10
#define TASK_EXECUTION_TIME 10

typedef struct task_s {
    int pid;
    int status;
    struct task_s *next;
} task_t;

typedef struct schedule_s {
    task_t *head;
    task_t *tail;
} schedule_t;

void init_schedule(schedule_t *schedule) {
    schedule->head = NULL;
    schedule->tail = NULL;
}

void enqueue_task(schedule_t *schedule, int pid, int status) {
    task_t *task = malloc(sizeof(task_t));
    task->pid = pid;
    task->status = status;
    task->next = NULL;

    if (schedule->head == NULL) {
        schedule->head = task;
    } else {
        schedule->tail->next = task;
    }
    schedule->tail = task;
}

void dequeue_task(schedule_t *schedule) {
    task_t *task = schedule->head;
    if (task == NULL) {
        return;
    }
    schedule->head = task->next;
    free(task);
}

void run_tasks(schedule_t *schedule) {
    while (1) {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        ts.tv_sec += TASK_EXECUTION_TIME;
        ts.tv_nsec = 0;
        while (schedule->head != NULL) {
            task_t *task = schedule->head;
            schedule->head = task->next;
            if (task->status == 0) {
                break;
            }
            task->status--;
            if (task->status == 0) {
                // task finished, remove from schedule
                dequeue_task(schedule);
            }
        }
        if (schedule->head == NULL) {
            break;
        }
        nanosleep(&ts, NULL);
    }
}

int main() {
    schedule_t schedule;
    init_schedule(&schedule);

    // Example tasks
    enqueue_task(&schedule, 1, 10);
    enqueue_task(&schedule, 2, 5);
    enqueue_task(&schedule, 3, 15);

    run_tasks(&schedule);

    return 0;
}