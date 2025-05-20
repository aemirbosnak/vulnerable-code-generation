//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 100

struct task {
    char name[20];
    int priority;
    int period;
    int deadline;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int num_tasks;
struct task tasks[MAX_TASKS];

void read_tasks() {
    FILE *fp;
    char filename[20];
    sprintf(filename, "tasks.txt");
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: tasks.txt not found.\n");
        exit(1);
    }

    fscanf(fp, "%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        fscanf(fp, "%s %d %d %d %d", tasks[i].name, &tasks[i].priority, &tasks[i].period, &tasks[i].deadline, &tasks[i].burst_time);
    }

    fclose(fp);
}

void print_tasks() {
    printf("Task\tPriority\tPeriod\tDeadline\tBurst Time\tRemaining Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", tasks[i].name, tasks[i].priority, tasks[i].period, tasks[i].deadline, tasks[i].burst_time, tasks[i].remaining_time, tasks[i].waiting_time, tasks[i].turnaround_time);
    }
}

void schedule_tasks() {
    for (int i = 0; i < num_tasks; i++) {
        tasks[i].remaining_time = tasks[i].burst_time;
    }

    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        int min_remaining_time = tasks[0].remaining_time;
        int min_index = 0;

        for (int i = 1; i < num_tasks; i++) {
            if (tasks[i].remaining_time < min_remaining_time) {
                min_remaining_time = tasks[i].remaining_time;
                min_index = i;
            }
        }

        if (min_remaining_time <= current_time) {
            tasks[min_index].remaining_time -= current_time;
            tasks[min_index].waiting_time += current_time - tasks[min_index].deadline;
            tasks[min_index].turnaround_time = tasks[min_index].waiting_time + tasks[min_index].burst_time;
            completed_tasks++;
        } else {
            current_time += min_remaining_time;
        }
    }
}

void *display_tasks(void *arg) {
    while (1) {
        sleep(1);
        printf("\r");
        print_tasks();
    }
}

int main() {
    read_tasks();
    schedule_tasks();

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, display_tasks, NULL);

    while (1) {
        sleep(1);
    }

    return 0;
}