//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TASKS 5

void *execute_task(void *arg);

int main() {
    int num_tasks;
    pthread_t threads[MAX_TASKS];
    
    printf("Enter the number of tasks to schedule (up to %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);
    
    if (num_tasks < 1 || num_tasks > MAX_TASKS) {
        printf("Invalid number of tasks. Exiting program.\n");
        exit(1);
    }
    
    printf("TASK SCHEDULER\n");
    printf("--------------------\n");
    
    // Create a thread for each task
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d created.\n", i+1);
        pthread_create(&threads[i], NULL, execute_task, (void *) (long) (i+1));
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < num_tasks; i++) {
        printf("Waiting for Task %d to complete...\n", i+1);
        pthread_join(threads[i], NULL);
        printf("Task %d complete.\n", i+1);
    }
    
    printf("--------------------\n");
    printf("All tasks completed.\n");
    
    return 0;
}

void *execute_task(void *arg) {
    int task_num = (int) (long) arg;
    printf("Task %d starting...\n", task_num);
    sleep(5);
    printf("Task %d complete.\n", task_num);
    pthread_exit(NULL);
}