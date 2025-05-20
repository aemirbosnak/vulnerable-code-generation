//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    char name[50];
    int priority;
    time_t start_time;
    time_t end_time;
};

void add_task(struct task *tasks, int *num_tasks, char *name, int priority, time_t start_time, time_t end_time) {
    if (*num_tasks >= MAX_TASKS) {
        printf("I'm sorry, my love. I cannot add any more tasks.\n");
        return;
    }

    strcpy(tasks[*num_tasks].name, name);
    tasks[*num_tasks].priority = priority;
    tasks[*num_tasks].start_time = start_time;
    tasks[*num_tasks].end_time = end_time;

    (*num_tasks)++;
}

void display_tasks(struct task *tasks, int num_tasks) {
    printf("Here are the tasks I have scheduled for you, my love:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s: Priority %d, Start time %s, End time %s\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time));
    }
}

void schedule_tasks(struct task *tasks, int num_tasks) {
    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time <= current_time && tasks[i].end_time >= current_time) {
            printf("It's time for %s, my love.\n", tasks[i].name);
        }
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, &num_tasks, "Breakfast in bed", 10, time(NULL) + 60*60*8, time(NULL) + 60*60*9);
    add_task(tasks, &num_tasks, "Romantic walk in the park", 9, time(NULL) + 60*60*12, time(NULL) + 60*60*14);
    add_task(tasks, &num_tasks, "Candlelit dinner", 8, time(NULL) + 60*60*18, time(NULL) + 60*60*20);

    while (1) {
        schedule_tasks(tasks, num_tasks);
        sleep(60);
    }

    return 0;
}