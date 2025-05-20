//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    char name[50];
    time_t deadline;
    void (*func)();
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, time_t deadline, void (*func)()) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Too many tasks.\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].deadline = deadline;
    tasks[num_tasks].func = func;
    num_tasks++;
}

void remove_task(char *name) {
    for (int i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            for (int j = i; j < num_tasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            num_tasks--;
            return;
        }
    }

    printf("Error: Task not found.\n");
}

bool check_conflict(time_t new_deadline) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].deadline < new_deadline) {
            return true;
        }
    }

    return false;
}

void print_tasks() {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s (deadline: %s)\n", tasks[i].name, ctime(&tasks[i].deadline));
    }
}

void task_one() {
    printf("Task One: Analyzing footprints...\n");
}

void task_two() {
    printf("Task Two: Examining documents...\n");
}

void task_three() {
    printf("Task Three: Interviewing suspects...\n");
}

void task_four() {
    printf("Task Four: Studying crime scene...\n");
}

void task_five() {
    printf("Task Five: Searching for clues...\n");
}

int main() {
    add_task("Task One", time(NULL) + 60, task_one);
    add_task("Task Four", time(NULL) + 120, task_four);
    add_task("Task Two", time(NULL) + 180, task_two);

    if (check_conflict(time(NULL) + 90)) {
        printf("Error: New task conflicts with existing tasks.\n");
        return 1;
    }

    add_task("Task Three", time(NULL) + 90, task_three);
    add_task("Task Five", time(NULL) + 240, task_five);

    print_tasks();

    for (int i = 0; i < num_tasks; i++) {
        tasks[i].func();
    }

    return 0;
}