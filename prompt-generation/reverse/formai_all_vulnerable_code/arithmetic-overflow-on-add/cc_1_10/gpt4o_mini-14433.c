//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[50];
    int duration; // in seconds
    time_t execution_time; // when to execute
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
sem_t semaphore;

void* execute_task(void* arg) {
    Task* task = (Task*)arg;
    
    printf("Task %s will start executing for %d seconds...\n", task->name, task->duration);
    sleep(task->duration);
    printf("Task %s completed.\n", task->name);

    sem_post(&semaphore); // Indicate completion of task
    return NULL;
}

void add_task(const char* name, int duration, time_t execution_time) {
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, name, sizeof(task_list[task_count].name) - 1);
        task_list[task_count].duration = duration;
        task_list[task_count].execution_time = execution_time;
        task_count++;
    } else {
        printf("Task list full! Cannot add more tasks.\n");
    }
}

void schedule_tasks() {
    pthread_t threads[MAX_TASKS];
    int i;

    // Sort tasks based on execution time (earliest first)
    for (i = 0; i < task_count - 1; i++) {
        for (int j = 0; j < task_count - i - 1; j++) {
            if (task_list[j].execution_time > task_list[j + 1].execution_time) {
                Task temp = task_list[j];
                task_list[j] = task_list[j + 1];
                task_list[j + 1] = temp;
            }
        }
    }
    
    // Execute all tasks in separate threads
    sem_init(&semaphore, 0, 0);
    for (i = 0; i < task_count; i++) {
        if (difftime(task_list[i].execution_time, time(NULL)) > 0) {
            sleep(difftime(task_list[i].execution_time, time(NULL))); // Wait till task execution time
        }
        pthread_create(&threads[i], NULL, execute_task, &task_list[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < task_count; i++) {
        sem_wait(&semaphore);
    }

    // Cleanup
    for (i = 0; i < task_count; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&semaphore);
}

int main() {
    printf("Welcome to the simple C Task Scheduler!\n");

    // Adding tasks
    time_t now = time(NULL);
    add_task("Task A", 3, now + 2); // Starts in 2 seconds
    add_task("Task B", 5, now + 4); // Starts in 4 seconds
    add_task("Task C", 2, now + 1); // Starts in 1 second
    add_task("Task D", 6, now + 7); // Starts in 7 seconds

    printf("Scheduled %d tasks. Executing...\n", task_count);
    schedule_tasks();

    printf("All tasks have been executed successfully!\n");
    return 0;
}