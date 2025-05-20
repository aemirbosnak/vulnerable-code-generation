//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASK_COUNT 5
#define TASK_DURATION 10
#define SLEEP_TIME 1

typedef struct task_t {
    int id;
    int start_time;
    int end_time;
} task_t;

task_t tasks[TASK_COUNT] = {
    {1, 0, 10}, // Task 1: Sleep for 10 seconds
    {2, 10, 20}, // Task 2: Sleep for 20 seconds
    {3, 20, 30}, // Task 3: Sleep for 30 seconds
    {4, 30, 40}, // Task 4: Sleep for 40 seconds
    {5, 40, 50}  // Task 5: Sleep for 50 seconds
};

void schedule(void) {
    int i, j;
    int max_id = TASK_COUNT - 1;

    // Calculate the next task to be executed
    for (i = 0; i < max_id; i++) {
        if (tasks[i].end_time <= clock()) {
            // Current task has ended, move on to the next one
            i++;
        }
    }

    // Find the next available task
    for (j = i; j < max_id; j++) {
        if (tasks[j].start_time <= clock()) {
            break;
        }
    }

    // Execute the next task
    tasks[j].start_time = clock();
    printf("Task %d started at %d\n", tasks[j].id, tasks[j].start_time);

    // Sleep for the task duration
    sleep(tasks[j].end_time - clock());

    // Print the task completion time
    printf("Task %d completed at %d\n", tasks[j].id, tasks[j].end_time);
}

int main(void) {
    while (1) {
        schedule();
        sleep(SLEEP_TIME);
    }
    return 0;
}