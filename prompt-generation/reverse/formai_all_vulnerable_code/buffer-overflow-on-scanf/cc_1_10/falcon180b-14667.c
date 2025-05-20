//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    char* name;
    int priority;
    int duration;
    int start_time;
    int end_time;
    int status;
};

void* execute_task(void* arg) {
    struct task* task = (struct task*) arg;
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    sleep(task->duration);
    printf("Task %s completed\n", task->name);
    return NULL;
}

int compare_tasks(const void* a, const void* b) {
    struct task* task_a = (struct task*) a;
    struct task* task_b = (struct task*) b;
    if(task_a->priority > task_b->priority)
        return -1;
    else if(task_a->priority < task_b->priority)
        return 1;
    else
        return 0;
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    struct task tasks[MAX_TASKS];
    for(int i=0; i<num_tasks; i++) {
        printf("Enter task name: ");
        char name[20];
        scanf("%s", name);
        tasks[i].name = (char*) malloc(strlen(name)+1);
        strcpy(tasks[i].name, name);

        printf("Enter task priority: ");
        scanf("%d", &tasks[i].priority);

        printf("Enter task duration: ");
        scanf("%d", &tasks[i].duration);

        tasks[i].start_time = time(NULL) + i*tasks[i].duration;
        tasks[i].end_time = tasks[i].start_time + tasks[i].duration;
        tasks[i].status = 0;
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_tasks);

    for(int i=0; i<num_tasks; i++) {
        printf("Task %s with priority %d will start at %d and end at %d\n", tasks[i].name, tasks[i].priority, tasks[i].start_time, tasks[i].end_time);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, execute_task, (void*) &tasks[i]);
    }

    return 0;
}