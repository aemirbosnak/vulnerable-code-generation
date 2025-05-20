//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

// Task structure
typedef struct {
    char name[50];
    int priority;
    int duration;
    int start_time;
    int end_time;
} Task;

// Function prototypes
void *task_executor(void *arg);
int compare_tasks(const void *a, const void *b);

int main() {
    int i, j, num_tasks;
    Task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];

    // Get number of tasks from user
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    // Get task details from user
    for (i = 0; i < num_tasks; i++) {
        printf("Enter task name: ");
        scanf("%s", tasks[i].name);
        printf("Enter task priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Enter task duration: ");
        scanf("%d", &tasks[i].duration);
    }

    // Sort tasks based on priority
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    // Calculate start and end times for each task
    for (i = 0; i < num_tasks; i++) {
        tasks[i].start_time = i * tasks[i].duration;
        tasks[i].end_time = (i + 1) * tasks[i].duration;
    }

    // Create threads for each task
    for (i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_executor, &tasks[i]);
    }

    // Join all threads
    for (i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Task executor function
void *task_executor(void *arg) {
    Task *task = arg;
    int start_time = task->start_time;
    int end_time = task->end_time;

    // Sleep until start time
    sleep(start_time);

    // Execute task
    printf("%s is executing...\n", task->name);
    fflush(stdout);

    // Sleep until end time
    sleep(end_time - start_time);

    return NULL;
}

// Comparison function for tasks
int compare_tasks(const void *a, const void *b) {
    Task *task1 = (Task *)a;
    Task *task2 = (Task *)b;

    if (task1->priority > task2->priority)
        return -1;
    else if (task1->priority < task2->priority)
        return 1;
    else
        return 0;
}