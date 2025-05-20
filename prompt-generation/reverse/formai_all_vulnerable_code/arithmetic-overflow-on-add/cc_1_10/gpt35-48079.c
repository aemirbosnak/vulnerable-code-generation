//FormAI DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
    void (*task_fun)(void);
} task_t;

typedef struct {
    int num_tasks;
    task_t tasks[MAX_TASKS];
} task_list_t;

volatile int signal_received = 0;

void task1(void)
{
    printf("Task 1 executed\n");
    sleep(1);
}

void task2(void)
{
    printf("Task 2 executed\n");
    sleep(1);
}

void task3(void)
{
    printf("Task 3 executed\n");
    sleep(1);
}

void signal_handler(int sig)
{
    signal_received = 1;
}

int initialize_tasks(task_list_t* task_list)
{
    task_list->num_tasks = 0;

    // Define tasks here
    task_t task1 = {1, "Task 1", time(NULL), 0, &task1};
    task_t task2 = {2, "Task 2", time(NULL), 0, &task2};
    task_t task3 = {3, "Task 3", time(NULL), 0, &task3};

    // Add tasks to the list
    task_list->tasks[task_list->num_tasks++] = task1;
    task_list->tasks[task_list->num_tasks++] = task2;
    task_list->tasks[task_list->num_tasks++] = task3;

    return 0;
}

int main(int argc, char** argv)
{
    task_list_t task_list;
    initialize_tasks(&task_list);

    signal(SIGINT, signal_handler);

    while (!signal_received) {
        for (int i = 0; i < task_list.num_tasks; i++) {
            task_t* task = &task_list.tasks[i];
            if (task->end_time == 0 || time(NULL) >= task->end_time) {
                printf("[INFO] Starting task %s (id=%d)\n", task->name, task->id);
                task->start_time = time(NULL);
                task->end_time = task->start_time + 5;
                task->task_fun();
            }
        }
    }

    return 0;
}