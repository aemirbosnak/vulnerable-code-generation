//FormAI DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TASK_NAME_MAX_LEN 20
#define MAX_QUEUE_SIZE 100

typedef struct {
    char name[TASK_NAME_MAX_LEN];
    int priority;
    time_t timestamp;
    void (*task_function)(void);
} Task;

Task task_queue[MAX_QUEUE_SIZE];
int queue_size = 0;

void add_task(char *name, int priority, void (*task_function)(void)) {
    if(queue_size < MAX_QUEUE_SIZE) {
        Task new_task;
        strncpy(new_task.name, name, TASK_NAME_MAX_LEN);
        new_task.priority = priority;
        new_task.timestamp = time(NULL);
        new_task.task_function = task_function;
        task_queue[queue_size++] = new_task;
    } else {
        printf("Queue is full. Unable to add task.\n");
    }
}

void execute_task(Task task) {
    printf("Executing task: %s\n", task.name);
    task.task_function();
}

void run_task_scheduler() {
    printf("Task scheduler started.\n\n");
    while(queue_size > 0) {
        int highest_priority_idx = 0;
        for(int i = 1; i < queue_size; i++) {
            if(task_queue[i].priority > task_queue[highest_priority_idx].priority ||
            (task_queue[i].priority == task_queue[highest_priority_idx].priority &&
            task_queue[i].timestamp < task_queue[highest_priority_idx].timestamp)) {
                highest_priority_idx = i;
            }
        }
        Task next_task = task_queue[highest_priority_idx];
        execute_task(next_task);
        for(int i = highest_priority_idx; i < queue_size - 1; i++) {
            task_queue[i] = task_queue[i + 1];
        }
        queue_size--;
    }
    printf("Task scheduler ended.\n");
}

void sleep_task() {
    printf("Task sleeping...\n");
    sleep(1);
}

void read_input_task() {
    printf("Task reading input...\n");
    char input[50];
    scanf("%s", input);
}

int main() {
    add_task("Sleep task", 1, sleep_task);
    add_task("Read input task", 2, read_input_task);
    run_task_scheduler();
    return 0;
}