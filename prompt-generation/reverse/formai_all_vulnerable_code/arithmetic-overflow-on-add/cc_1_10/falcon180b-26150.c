//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 20

typedef struct {
    char name[MAX_TASK_NAME_LEN];
    time_t start_time;
    time_t end_time;
    int duration;
} Task;

void add_task(Task tasks[], int num_tasks, char* name, time_t start_time, time_t end_time) {
    if (num_tasks == MAX_TASKS) {
        printf("Sorry, task list is full!\n");
        return;
    }

    strncpy(tasks[num_tasks].name, name, MAX_TASK_NAME_LEN);
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;
    tasks[num_tasks].duration = difftime(tasks[num_tasks].end_time, tasks[num_tasks].start_time);

    printf("Task \"%s\" added to the list!\n", name);
    num_tasks++;
}

void display_tasks(Task tasks[], int num_tasks) {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s: Start time - %s, End time - %s, Duration - %d seconds\n", tasks[i].name, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time), tasks[i].duration);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, "Happy coding", time(NULL), time(NULL) + 60*5);
    add_task(tasks, num_tasks, "Take a break", time(NULL) + 60*5, time(NULL) + 60*10);
    add_task(tasks, num_tasks, "Lunch time", time(NULL) + 60*10, time(NULL) + 60*30);
    add_task(tasks, num_tasks, "Back to work", time(NULL) + 60*30, time(NULL) + 60*35);
    add_task(tasks, num_tasks, "Finish up", time(NULL) + 60*35, time(NULL) + 60*40);

    display_tasks(tasks, num_tasks);

    return 0;
}