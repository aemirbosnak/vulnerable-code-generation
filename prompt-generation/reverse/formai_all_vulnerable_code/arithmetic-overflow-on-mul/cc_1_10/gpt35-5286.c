//FormAI DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <unistd.h>

struct task {
    int id;
    int duration;
};

int task_count = 0;
struct timeval start_time;

void add_task(struct task **tasks, int duration) {
    *tasks = realloc(*tasks, (task_count + 1) * sizeof(struct task));
    struct task new_task = {.id = task_count, .duration = duration};
    (*tasks)[task_count] = new_task;
    task_count++;
    printf("New task #%d added. Duration: %d\n", new_task.id, new_task.duration);
}

void remove_task(struct task **tasks, int id) {
    if (id < task_count) {
        for (int i = id; i < task_count - 1; i++) {
            (*tasks)[i] = (*tasks)[i + 1];
        }
        *tasks = realloc(*tasks, (task_count - 1) * sizeof(struct task));
        task_count--;
        printf("Task #%d removed.\n", id);
    } else {
        printf("Invalid task id.\n");
    }
}

void execute_task(struct task task) {
    int elapsed;
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    elapsed = (int)(current_time.tv_sec - start_time.tv_sec) * 1000 +
              (int)(current_time.tv_usec - start_time.tv_usec) / 1000;
    printf("Executing task #%d. Started at %d. Elapsed: %d ms\n", task.id, elapsed, task.duration);
    usleep(task.duration * 1000);
    gettimeofday(&current_time, NULL);
    elapsed = (int)(current_time.tv_sec - start_time.tv_sec) * 1000 +
              (int)(current_time.tv_usec - start_time.tv_usec) / 1000;
    printf("Task #%d completed. Duration: %d ms. End time: %d ms\n", task.id, task.duration, elapsed);
}

bool task_exists(struct task *tasks, int id) {
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            return true;
        }
    }
    return false;
}

void schedule(struct task *tasks) {
    while (task_count > 0) {
        for (int i = 0; i < task_count; i++) {
            if (task_exists(tasks, i)) {
                execute_task(tasks[i]);
                remove_task(&tasks, i);
            }
        }
    }
}

int main() {
    struct task *tasks = NULL;
    add_task(&tasks, 500);
    add_task(&tasks, 1500);
    add_task(&tasks, 200);
    gettimeofday(&start_time, NULL);
    schedule(tasks);
    return 0;
}