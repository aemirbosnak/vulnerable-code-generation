//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    TASK_NONE,
    TASK_A,
    TASK_B,
    TASK_C
} task_t;

typedef struct {
    task_t task;
    int start;
    int duration;
} job_t;

job_t jobs[] = {
    {.task = TASK_A, .start = 0, .duration = 2},
    {.task = TASK_B, .start = 1, .duration = 3},
    {.task = TASK_C, .start = 2, .duration = 1},
    {.task = TASK_A, .start = 3, .duration = 2},
    {.task = TASK_B, .start = 4, .duration = 3},
    {.task = TASK_C, .start = 5, .duration = 1},
    {.task = TASK_A, .start = 6, .duration = 2},
    {.task = TASK_B, .start = 7, .duration = 3},
    {.task = TASK_C, .start = 8, .duration = 1},
    {.task = TASK_NONE}
};

int main(void) {
    time_t start_time = time(NULL);
    int tick = 0;
    task_t running_task = TASK_NONE;
    job_t *job_ptr = jobs;
    srand(start_time);

    while (job_ptr->task != TASK_NONE) {
        if (tick >= job_ptr->start && tick < job_ptr->start + job_ptr->duration) {
            printf("Task %d is running at tick %d\n", job_ptr->task, tick);
            running_task = job_ptr->task;
        } else {
            printf("Idle at tick %d\n", tick);
            running_task = TASK_NONE;
        }
        tick++;

        if (tick % 10 == 0) {
            printf("Time is %ld\n", time(NULL) - start_time);
        }

        if (running_task == TASK_NONE && tick >= job_ptr->start + job_ptr->duration) {
            job_ptr++;
            if (job_ptr->task == TASK_NONE) {
                printf("All jobs completed!\n");
                break;
            }
            printf("Waiting for next task...\n");
            int delay = rand() % 5 + 1;
            printf("Delaying for %d ticks...\n", delay);
            tick += delay;
        }
    }

    return 0;
}