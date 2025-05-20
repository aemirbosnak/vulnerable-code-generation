//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LENGTH 50
#define MAX_TASK_PRIORITY 10

typedef struct {
    char name[MAX_TASK_NAME_LENGTH];
    int priority;
    time_t start_time;
    time_t end_time;
} Task;

void add_task(Task *task_list, int num_tasks, char *name, int priority, time_t start_time, time_t end_time) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Task list is full.\n");
        return;
    }

    strncpy(task_list[num_tasks].name, name, MAX_TASK_NAME_LENGTH);
    task_list[num_tasks].priority = priority;
    task_list[num_tasks].start_time = start_time;
    task_list[num_tasks].end_time = end_time;

    num_tasks++;
}

void display_tasks(Task *task_list, int num_tasks) {
    printf("Task List:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s (Priority: %d)\n", i+1, task_list[i].name, task_list[i].priority);
        printf("Start Time: %s\n", ctime(&task_list[i].start_time));
        printf("End Time: %s\n", ctime(&task_list[i].end_time));
        printf("\n");
    }
}

int main() {
    Task task_list[MAX_TASKS];
    int num_tasks = 0;

    add_task(task_list, num_tasks, "Scavenge for Supplies", 5, time(NULL), time(NULL) + 60*60*2);
    add_task(task_list, num_tasks, "Repair Shelter", 7, time(NULL) + 60*60*2, time(NULL) + 60*60*4);
    add_task(task_list, num_tasks, "Gather Water", 4, time(NULL) + 60*60*4, time(NULL) + 60*60*6);

    display_tasks(task_list, num_tasks);

    return 0;
}