//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_NAME_LENGTH 50

struct task {
    char name[MAX_NAME_LENGTH];
    time_t scheduled_time;
    void (*function)(void);
};

struct task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, int seconds, void (*function)(void)) {
    if (num_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached\n");
        return;
    }

    tasks[num_tasks].scheduled_time = time(NULL) + seconds;
    tasks[num_tasks].function = function;
    if (strlen(name) + 1 > MAX_NAME_LENGTH) {
        printf("Task name too long\n");
        return;
    }
    strcpy(tasks[num_tasks].name, name);

    num_tasks++;
}

void execute_task(int index) {
    tasks[index].function();
}

void print_task(int index) {
    printf("%s - scheduled for %s\n", tasks[index].name, ctime(&tasks[index].scheduled_time));
}

void list_tasks() {
    for (int i = 0; i < num_tasks; i++) {
        print_task(i);
    }
}

void remove_task(int index) {
    for (int i = index; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    num_tasks--;
}

void task1() {
    printf("Task 1 executed\n");
}

void task2() {
    printf("Task 2 executed\n");
}

int main() {
    add_task("Task 1", 5, task1); // scheduled in 5 seconds
    add_task("Task 2", 10, task2); // scheduled in 10 seconds

    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < num_tasks; i++) {
            if (current_time >= tasks[i].scheduled_time) {
                printf("Executing task: %s\n", tasks[i].name);
                execute_task(i);
                remove_task(i);
                i--;
            }
        }
        sleep(1); // check for tasks every second
    }
    return 0;
}