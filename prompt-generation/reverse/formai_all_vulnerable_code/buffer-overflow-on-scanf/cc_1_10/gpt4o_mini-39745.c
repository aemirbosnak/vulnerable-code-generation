//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    char name[50];
    int interval; // in seconds
    int repeats; // -1 for infinite
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;
pthread_mutex_t lock;

void* task_function(void* arg) {
    Task* task = (Task*)arg;
    int executions = 0;

    while (task->repeats == -1 || executions < task->repeats) {
        sleep(task->interval);
        printf("Task %s executed\n", task->name);
        executions++;
    }

    return NULL;
}

void add_task(const char* name, int interval, int repeats) {
    pthread_mutex_lock(&lock);
    
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        pthread_mutex_unlock(&lock);
        return;
    }

    strcpy(tasks[task_count].name, name);
    tasks[task_count].interval = interval;
    tasks[task_count].repeats = repeats;
    task_count++;

    pthread_mutex_unlock(&lock);
}

void sigint_handler(int signum) {
    printf("\nShutting down the scheduler.\n");
    exit(0);
}

void list_tasks() {
    printf("Current scheduled tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. Task: %s, Interval: %d seconds, Repeats: %d\n", 
                i + 1, tasks[i].name, tasks[i].interval, tasks[i].repeats);
    }
}

int main() {
    signal(SIGINT, sigint_handler);
    pthread_mutex_init(&lock, NULL);

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. List Tasks\n");
        printf("3. Start Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char name[50];
            int interval, repeats;

            printf("Enter task name: ");
            scanf("%s", name);
            printf("Enter task interval (seconds): ");
            scanf("%d", &interval);
            printf("Enter number of repeats (-1 for infinite): ");
            scanf("%d", &repeats);

            add_task(name, interval, repeats);
        } 
        else if (choice == 2) {
            list_tasks();
        } 
        else if (choice == 3) {
            pthread_t threads[MAX_TASKS];

            for (int i = 0; i < task_count; i++) {
                pthread_create(&threads[i], NULL, task_function, (void*)&tasks[i]);
            }

            for (int i = 0; i < task_count; i++) {
                pthread_join(threads[i], NULL);
            }
        } 
        else if (choice == 4) {
            printf("Exiting scheduler.\n");
            break;
        } 
        else {
            printf("Invalid option. Please try again.\n");
        }
    }

    pthread_mutex_destroy(&lock);
    return 0;
}