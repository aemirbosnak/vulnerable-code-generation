//FormAI DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

/* Task struct */
typedef struct Task {
    int id;
    char* name;
    int priority;
    time_t schedule_time;
    void (*function)(void*);
    void* arg;
} Task;

/* Scheduler struct */
typedef struct Scheduler {
    int num_tasks;
    Task* task_list[MAX_TASKS];
} Scheduler;

/* Function declarations */
void add_task(Scheduler* sched, char* name, int priority, time_t schedule_time, void (*function)(void*), void* arg);
void delete_task(Scheduler* sched, int task_id);
void execute_tasks(Scheduler* sched);

/* Main */
int main() {
    Scheduler* sched = (Scheduler*) malloc(sizeof(Scheduler));
    sched->num_tasks = 0;

    /* Add some tasks to the scheduler */
    add_task(sched, "Task 1", 1, time(NULL) + 10, NULL, NULL);
    add_task(sched, "Task 2", 2, time(NULL) + 5, NULL, NULL);
    add_task(sched, "Task 3", 3, time(NULL) + 15, NULL, NULL);
    add_task(sched, "Task 4", 4, time(NULL) + 20, NULL, NULL);

    /* Delete a task from the scheduler */
    delete_task(sched, 2);

    /* Execute tasks in the scheduler */
    execute_tasks(sched);

    return 0;
}

/* Adds a task to the scheduler */
void add_task(Scheduler* sched, char* name, int priority, time_t schedule_time, void (*function)(void*), void* arg) {
    if (sched->num_tasks >= MAX_TASKS) {
        printf("Scheduler is full, cannot add task.\n");
        return;
    }

    Task* task = (Task*) malloc(sizeof(Task));
    task->id = sched->num_tasks + 1;
    task->name = name;
    task->priority = priority;
    task->schedule_time = schedule_time;
    task->function = function;
    task->arg = arg;

    sched->task_list[sched->num_tasks++] = task;
    printf("Task '%s' added to scheduler.\n", name);
}

/* Deletes a task from the scheduler */
void delete_task(Scheduler* sched, int task_id) {
    int i, index;

    /* Find the index of the task to be deleted */
    for (i = 0; i < sched->num_tasks; i++) {
        if (sched->task_list[i]->id == task_id) {
            index = i;
            break;
        }
    }

    /* Delete the task */
    if (i == sched->num_tasks) {
        printf("Task with ID '%d' not found in scheduler.\n", task_id);
    } else {
        Task* task = sched->task_list[index];
        printf("Task '%s' deleted from scheduler.\n", task->name);

        /* Shift all tasks to the left */
        for (i = index; i < sched->num_tasks - 1; i++) {
            sched->task_list[i] = sched->task_list[i+1];
            sched->task_list[i]->id--;
        }

        sched->num_tasks--;
        free(task);
    }
}

/* Executes tasks in the scheduler */
void execute_tasks(Scheduler* sched) {
    int i;
    printf("\nExecuting tasks...\n");

    /* Sleep until the first task is scheduled */
    time_t current_time = time(NULL);
    double time_diff = difftime(sched->task_list[0]->schedule_time, current_time);
    printf("Waiting for %d seconds...\n", (int) time_diff);
    sleep((int) time_diff);

    /* Execute the tasks in priority order */
    for (i = 0; i < sched->num_tasks; i++) {
        Task* task = sched->task_list[i];
        printf("Executing task '%s'...\n", task->name);

        /* Call the task function */
        if (task->function != NULL) {
            task->function(task->arg);
        }

        /* Sleep until the next task is scheduled */
        if (i < sched->num_tasks - 1) {
            Task* next_task = sched->task_list[i+1];
            time_diff = difftime(next_task->schedule_time, time(NULL));
            printf("Waiting for %d seconds...\n", (int) time_diff);
            sleep((int) time_diff);
        }
    }

    printf("\nAll tasks executed.\n");
}