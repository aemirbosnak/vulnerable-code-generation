//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

#define MAX_TASKS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
    int time_slice;
    void (*function)(void);
} task;

void execute_tasks(void* arg) {
    int i;
    task* tasks = (task*) arg;
    for(i=0; i<MAX_TASKS; i++) {
        if(tasks[i].function!= NULL) {
            tasks[i].function();
        }
    }
}

int main() {
    int i, j;
    task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];

    printf("Enter tasks:\n");
    for(i=0; i<MAX_TASKS; i++) {
        printf("Task %d name: ", i+1);
        scanf("%s", tasks[i].name);
        printf("Task %d priority: ", i+1);
        scanf("%d", &tasks[i].priority);
        printf("Task %d time slice: ", i+1);
        scanf("%d", &tasks[i].time_slice);
        printf("Task %d function: ", i+1);
        tasks[i].function = (void*) malloc(sizeof(void*));
        scanf("%p", tasks[i].function);
    }

    for(i=0; i<MAX_TASKS; i++) {
        if(tasks[i].function!= NULL) {
            pthread_create(&threads[i], NULL, tasks[i].function, NULL);
        }
    }

    while(1) {
        sleep(1);
    }

    return 0;
}