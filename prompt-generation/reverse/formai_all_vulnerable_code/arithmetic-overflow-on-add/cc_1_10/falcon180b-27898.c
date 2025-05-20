//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 20

typedef struct Task {
    char name[MAX_TASK_NAME_LEN];
    time_t start_time;
    int duration;
    int status;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char* name, time_t start_time, int duration) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }

    strncpy(tasks[num_tasks].name, name, MAX_TASK_NAME_LEN);
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].duration = duration;
    tasks[num_tasks].status = 0;

    num_tasks++;
}

void* task_thread(void* arg) {
    int id = (int) arg;
    Task* task = &tasks[id];

    time_t now = time(NULL);
    if (now >= task->start_time) {
        task->status = 1;
        printf("Task %s started at %s\n", task->name, ctime(&task->start_time));
    } else {
        sleep(task->start_time - now);
        task->status = 1;
        printf("Task %s started at %s\n", task->name, ctime(&task->start_time));
    }

    sleep(task->duration);
    task->status = 2;
    printf("Task %s completed at %s\n", task->name, ctime(&now));

    return NULL;
}

int main() {
    add_task("Task 1", time(NULL) + 5, 10);
    add_task("Task 2", time(NULL) + 10, 15);
    add_task("Task 3", time(NULL) + 20, 20);

    int i;
    pthread_t threads[MAX_TASKS];

    for (i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_thread, (void*) i);
        printf("Task %s created\n", tasks[i].name);
    }

    for (i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}