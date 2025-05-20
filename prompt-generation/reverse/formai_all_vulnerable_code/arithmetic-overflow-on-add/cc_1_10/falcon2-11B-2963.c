//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct {
    int id;
    int priority;
    int start_time;
    int end_time;
} Task;

int compare_tasks(const void *a, const void *b) {
    const Task *task1 = (const Task *)a;
    const Task *task2 = (const Task *)b;
    if (task1->start_time == task2->start_time) {
        return task1->priority - task2->priority;
    } else {
        return task1->start_time - task2->start_time;
    }
}

void *run_task(void *arg) {
    Task *task = (Task *)arg;
    printf("Task %d running...\n", task->id);
    sleep(task->end_time - task->start_time);
    return NULL;
}

int main() {
    srand(time(NULL));
    int num_tasks = 5;
    Task *tasks = malloc(num_tasks * sizeof(Task));
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i + 1;
        tasks[i].priority = rand() % 100;
        tasks[i].start_time = time(NULL);
        tasks[i].end_time = tasks[i].start_time + (rand() % 300);
    }
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);
    pthread_t threads[num_tasks];
    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, run_task, &tasks[i]);
    }
    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }
    free(tasks);
    return 0;
}