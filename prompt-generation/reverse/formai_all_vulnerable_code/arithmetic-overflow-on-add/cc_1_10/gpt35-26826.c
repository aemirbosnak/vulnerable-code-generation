//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define TASK_COUNT 10
#define MAX_TASK_DURATION 15

typedef struct {
    int id;
    int duration;
    time_t scheduled_time;
} Task;

Task tasks[TASK_COUNT];

void schedule_task(Task *task);
void execute_task(Task *task);
int compare_tasks(const void *task1, const void *task2);

int main() {
    srand(time(NULL));
    
    // Initialize tasks
    for (int i = 0; i < TASK_COUNT; i++) {
        tasks[i].id = i + 1;
        tasks[i].duration = rand() % MAX_TASK_DURATION + 1;
        tasks[i].scheduled_time = 0;
    }

    // Sort tasks by duration
    qsort(tasks, TASK_COUNT, sizeof(Task), compare_tasks);

    // Schedule tasks
    for (int i = 0; i < TASK_COUNT; i++) {
        schedule_task(&tasks[i]);
    }

    // Execute tasks
    printf("Task execution started...\n");
    for (int i = 0; i < TASK_COUNT; i++) {
        execute_task(&tasks[i]);
    }

    return 0;
}

void schedule_task(Task *task) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    int hour = tm_now->tm_hour;
    int minute = tm_now->tm_min + task->duration;

    if (minute >= 60) {
        hour += 1;
        minute -= 60;
    }

    task->scheduled_time = now + (minute - tm_now->tm_min) * 60;

    printf("Task %d scheduled for %02d:%02d\n", task->id, hour, minute);
}

void execute_task(Task *task) {
    time_t now = time(NULL);

    if (now < task->scheduled_time) {
        printf("Task %d is not due yet\n", task->id);
        return;
    }

    printf("Executing task %d...\n", task->id);
    printf("Task %d duration: %d seconds\n", task->id, task->duration);
    printf("Task %d execution completed\n", task->id);
}

int compare_tasks(const void *task1, const void *task2) {
    Task *t1 = (Task *)task1;
    Task *t2 = (Task *)task2;

    if (t1->duration < t2->duration) {
        return -1;
    } else if (t1->duration > t2->duration) {
        return 1;
    } else {
        return 0;
    }
}