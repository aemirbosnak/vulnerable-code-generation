//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
/**
 * @file task_scheduler.c
 * @brief A scientific example program for task scheduling.
 *
 * A program that demonstrates task scheduling using a fixed priority
 * scheduling algorithm. The program reads in multiple tasks with their
 * execution times and priorities, and assigns them to a set of processors
 * for execution. The program prints out the order in which the tasks
 * were executed and the total time taken to complete all the tasks.
 *
 * Compilation: gcc -o task_scheduler task_scheduler.c
 * Usage: ./task_scheduler
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100        // maximum number of tasks supported
#define MAX_PROCESSORS 10    // maximum number of processors available

struct task {
    int id;                // task ID
    int time;              // time required for execution
    int priority;          // task priority
    int start_time;        // start time for the task
    int end_time;          // end time for the task
};

/**
 * @brief Calculate the minimum priority task from a set of tasks.
 *
 * @param tasks the set of tasks to search.
 * @param num_tasks the number of tasks in the set.
 * @return the index of the task with the minimum priority.
 */
int get_min_priority_task(struct task tasks[], int num_tasks) {
    int min_priority = 10;
    int min_priority_task = -1;

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].priority < min_priority) {
            min_priority = tasks[i].priority;
            min_priority_task = i;
        }
    }

    return min_priority_task;
}

/**
 * @brief Get the next available processor for task execution.
 *
 * @param processors an array indicating the status of each processor.
 * @param num_processors the number of processors available.
 * @return the index of the next available processor, or -1 if all processors are busy.
 */
int get_next_processor(int processors[], int num_processors) {
    for (int i = 0; i < num_processors; i++) {
        if (processors[i] == 0) {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Schedule tasks using a fixed priority scheduling algorithm.
 *
 * @param tasks the set of tasks to schedule.
 * @param num_tasks the number of tasks in the set.
 * @param num_processors the number of processors available for task execution.
 */
void schedule_tasks(struct task tasks[], int num_tasks, int num_processors) {
    int processors[MAX_PROCESSORS] = {0};   // 0 indicates processor is available, 1 indicates processor is busy
    int current_time = 0;                   // current time in simulation
    int tasks_remaining = num_tasks;        // number of tasks remaining to be executed

    while (tasks_remaining > 0) {
        // get the next available processor
        int processor = get_next_processor(processors, num_processors);

        // if all processors are busy, increment current time and check again
        if (processor == -1) {
            current_time++;
            continue;
        }

        // get the task with the minimum priority
        int next_task = get_min_priority_task(tasks, num_tasks);

        // assign the task to the next available processor
        processors[processor] = 1;   // mark the processor as busy
        tasks[next_task].start_time = current_time;
        tasks[next_task].end_time = current_time + tasks[next_task].time;

        // update the current time and remaining tasks
        tasks_remaining--;
        current_time = tasks[next_task].end_time;

        // print out the progress
        printf("Processor %d executing task %d from time %d to time %d\n", processor+1, tasks[next_task].id, tasks[next_task].start_time, tasks[next_task].end_time);

        // free up the processor
        processors[processor] = 0;

        // mark the task as completed
        tasks[next_task].priority = 10;
    }

    printf("All tasks completed in %d units of time\n", current_time);
}

int main(int argc, char *argv[]) {
    // read in the number of tasks and processors
    int num_tasks, num_processors;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);
    printf("Enter the number of processors: ");
    scanf("%d", &num_processors);

    // read in the tasks
    struct task tasks[MAX_TASKS];
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter the execution time for task %d: ", i+1);
        scanf("%d", &tasks[i].time);
        printf("Enter the priority for task %d: ", i+1);
        scanf("%d", &tasks[i].priority);
        tasks[i].id = i+1;
        tasks[i].start_time = -1;
        tasks[i].end_time = -1;
    }

    // schedule the tasks
    schedule_tasks(tasks, num_tasks, num_processors);

    return 0;
}