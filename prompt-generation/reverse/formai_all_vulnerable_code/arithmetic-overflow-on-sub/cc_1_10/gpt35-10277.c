//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* Define the maximum number of tasks */
#define MAX_TASKS 10

/* Define the maximum length of task names */
#define MAX_NAME_LEN 20

/* Define the task struct */
typedef struct task_t {
    char name[MAX_NAME_LEN];
    int interval;
    time_t last_execution;
    void (*func)(void);
} task_t;

/* Define an array of tasks */
static task_t tasks[MAX_TASKS];

/* Define the number of tasks */
static int num_tasks = 0;

/* Add a task to the task array */
static int add_task(char *name, int interval, void (*func)(void))
{
    /* Check if the maximum number of tasks has been reached */
    if (num_tasks == MAX_TASKS) {
        return -1;
    }

    /* Add the task to the task array */
    tasks[num_tasks].func = func;
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].last_execution = time(NULL);
    snprintf(tasks[num_tasks].name, MAX_NAME_LEN, "%s", name);
    num_tasks++;

    return 0;
}

/* Remove a task from the task array */
static int remove_task(char *name)
{
    int i;

    /* Find the task with the given name */
    for (i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            /* Shift the remaining tasks in the array */
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            /* Decrement the number of tasks */
            num_tasks--;

            return 0;
        }
    }

    return -1;
}

/* Execute the tasks */
static void run_tasks(void)
{
    int i;
    time_t current_time;

    /* Get the current time */
    current_time = time(NULL);

    /* Loop through the tasks */
    for (i = 0; i < num_tasks; i++) {
        /* Check if the interval has elapsed */
        if ((current_time - tasks[i].last_execution) >= tasks[i].interval) {
            /* Execute the task */
            tasks[i].func();

            /* Update the last execution time */
            tasks[i].last_execution = current_time;
        }
    }
}

/* Task functions */
static void task1(void)
{
    printf("Task 1 executed!\n");
}

static void task2(void)
{
    printf("Task 2 executed!\n");
}

static void task3(void)
{
    printf("Task 3 executed!\n");
}

int main(void)
{
    /* Add the tasks */
    add_task("Task 1", 1, &task1);
    add_task("Task 2", 2, &task2);
    add_task("Task 3", 3, &task3);

    /* Run the tasks */
    while (1) {
        run_tasks();
        sleep(1);
    }

    return 0;
}