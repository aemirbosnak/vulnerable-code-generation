//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_OF_THREADS 10
#define STACK_SIZE 1024

struct thread_data {
    int id;
    void *(*routine)(void *);
    void *arg;
};

void *runner(void *param) {
    struct thread_data *data = (struct thread_data *) param;
    data->routine(data->arg);
    pthread_exit(NULL);
}

void schedule_task(int interval, void *(*routine)(void *), void *arg) {
    struct thread_data *data = malloc(sizeof(struct thread_data));
    data->id = rand() % NUM_OF_THREADS;
    data->routine = routine;
    data->arg = arg;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, runner, data);

    printf("Task scheduled for thread %d\n", data->id);
}

void *task1(void *arg) {
    printf("Task 1 executed by thread %d\n", (int) arg);
    sleep(2);
}

void *task2(void *arg) {
    printf("Task 2 executed by thread %d\n", (int) arg);
    sleep(3);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_OF_THREADS; i++) {
        schedule_task(i + 1, task1, (void *) i);
        schedule_task(i + 2, task2, (void *) i);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}