//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 50

/* Structure to represent a task */
typedef struct {
    char name[MAX_TASK_NAME_LEN];   // name of the task
    int interval;                   // time interval in seconds
    int last_run;                   // timestamp of last run
    void (*task_function)();        // pointer to function to execute
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

/* Function to add a task to the task list */
void add_task(char* name, int interval, void (*task_function)()) {
    Task new_task;
    sprintf(new_task.name, "%s", name);
    new_task.interval = interval;
    new_task.last_run = 0;
    new_task.task_function = task_function;

    task_list[task_count++] = new_task;
}

/* Function to execute all tasks that are ready */
void execute_tasks() {
    int current_time = time(NULL);

    for (int i=0; i<task_count; i++) {
        Task current_task = task_list[i];
        if (current_time - current_task.last_run >= current_task.interval) {
            printf("[%d] Executing task: %s\n", current_time, current_task.name);
            current_task.task_function();
            current_task.last_run = current_time;
            task_list[i] = current_task;
        }
    }
}

/* Example task functions */
void say_hello() {
    printf("Hello, world!\n");
}

void play_music() {
    printf("Playing some tunes!\n");
}

void do_nothing() {
    printf("Just chilling...\n");
}

int main() {
    /* Add some tasks */
    add_task("hello_task", 2, say_hello);
    add_task("music_task", 5, play_music);
    add_task("nothing_task", 10, do_nothing);

    /* Loop forever, executing tasks when ready */
    while (1) {
        execute_tasks();
        sleep(1);
    }

    return 0;
}