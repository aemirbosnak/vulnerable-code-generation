//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 100

typedef struct {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
} Task;

void add_task(Task* task_list, int count, char name[], int priority, time_t start_time, time_t end_time) {
    if (count >= MAX_TASKS) {
        printf("Error: Task list is full.\n");
        return;
    }

    strcpy(task_list[count].name, name);
    task_list[count].priority = priority;
    task_list[count].start_time = start_time;
    task_list[count].end_time = end_time;

    printf("Task added: %s\n", name);
}

void display_tasks(Task* task_list, int count) {
    printf("Task List:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - Priority: %d - Start Time: %s - End Time: %s\n", task_list[i].name, task_list[i].priority, ctime(&task_list[i].start_time), ctime(&task_list[i].end_time));
    }
}

void execute_tasks(Task* task_list, int count) {
    time_t current_time = time(NULL);

    for (int i = 0; i < count; i++) {
        if (current_time >= task_list[i].start_time && current_time <= task_list[i].end_time) {
            printf("Executing task: %s\n", task_list[i].name);
        }
    }
}

int main() {
    Task task_list[MAX_TASKS];
    int count = 0;

    add_task(task_list, count, "Task 1", 1, time(NULL) + 10, time(NULL) + 20);
    add_task(task_list, count, "Task 2", 2, time(NULL) + 5, time(NULL) + 15);
    add_task(task_list, count, "Task 3", 3, time(NULL) + 20, time(NULL) + 30);

    printf("Initial Task List:\n");
    display_tasks(task_list, count);

    sleep(5);

    printf("Executing tasks at 5 seconds:\n");
    execute_tasks(task_list, count);

    sleep(10);

    printf("Executing tasks at 10 seconds:\n");
    execute_tasks(task_list, count);

    return 0;
}