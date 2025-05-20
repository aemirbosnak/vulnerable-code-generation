//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    time_t execution_time;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void* execute_task(void* task_ptr) {
    Task* task = (Task*)task_ptr;
    sleep(task->execution_time - time(NULL)); // sleep until the execution time
    printf("Task '%s' is being executed at %s", task->name, ctime(&(task->execution_time)));
    return NULL;
}

void add_task(const char* task_name, time_t exec_time) {
    if (task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    strncpy(task_list[task_count].name, task_name, TASK_NAME_LENGTH);
    task_list[task_count].execution_time = exec_time;
    task_count++;
}

void start_scheduling() {
    pthread_t threads[MAX_TASKS];
    for (int i = 0; i < task_count; i++) {
        if (pthread_create(&threads[i], NULL, execute_task, (void*)&task_list[i]) != 0) {
            fprintf(stderr, "Error creating thread for task '%s'\n", task_list[i].name);
        }
    }

    for (int i = 0; i < task_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    while (1) {
        char task_name[TASK_NAME_LENGTH];
        time_t future_time;

        printf("Enter task name (or type 'exit' to quit): ");
        fgets(task_name, TASK_NAME_LENGTH, stdin);
        task_name[strcspn(task_name, "\n")] = 0;  // remove trailing newline

        if (strcmp(task_name, "exit") == 0) {
            break;
        }

        printf("Enter execution time in seconds from now (e.g., 5 for 5 seconds): ");
        int seconds;
        scanf("%d", &seconds);
        getchar(); // consume the newline character

        future_time = time(NULL) + seconds;
        add_task(task_name, future_time);
        printf("Task '%s' scheduled for execution in %d seconds.\n", task_name, seconds);

        start_scheduling(); // execute scheduled tasks
    }

    return 0;
}