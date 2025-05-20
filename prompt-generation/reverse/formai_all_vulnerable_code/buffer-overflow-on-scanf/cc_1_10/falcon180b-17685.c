//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 1024

struct task {
    void (*func)(void *);
    void *arg;
    struct timespec start_time;
    int period;
};

void task_func(void *arg) {
    struct task *task = (struct task *) arg;
    task->func(task->arg);
}

int compare_timespec(const void *a, const void *b) {
    struct timespec *ts_a = (struct timespec *) a;
    struct timespec *ts_b = (struct timespec *) b;
    if (ts_a->tv_sec < ts_b->tv_sec)
        return -1;
    else if (ts_a->tv_sec > ts_b->tv_sec)
        return 1;
    else if (ts_a->tv_nsec < ts_b->tv_nsec)
        return -1;
    else if (ts_a->tv_nsec > ts_b->tv_nsec)
        return 1;
    else
        return 0;
}

int task_scheduler() {
    pthread_t threads[MAX_TASKS];
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task function and argument (or enter to finish): ");
        void (*func)(void *) = NULL;
        void *arg = NULL;
        if (scanf("%p %p", &func, &arg) == 2) {
            tasks[num_tasks].func = func;
            tasks[num_tasks].arg = arg;
            printf("Enter task period in seconds: ");
            scanf("%d", &tasks[num_tasks].period);
            gettimeofday(&tasks[num_tasks].start_time, NULL);
            pthread_create(&threads[num_tasks], NULL, task_func, &tasks[num_tasks]);
            num_tasks++;
        }
    }

    while (1) {
        sleep(1);

        qsort(tasks, num_tasks, sizeof(struct task), compare_timespec);

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].period > 0 &&
                difftime(time(NULL), tasks[i].start_time.tv_sec) >= tasks[i].period) {
                pthread_cancel(threads[i]);
                pthread_join(threads[i], NULL);
                tasks[i].func = NULL;
                num_tasks--;
                break;
            }
        }
    }

    return 0;
}

int main() {
    task_scheduler();
    return 0;
}