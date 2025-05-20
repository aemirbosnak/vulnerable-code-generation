//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TASKS 20
#define MAX_PRIORITY 5

int current_time;
int task_counter;

typedef struct {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    bool completed;
} Task;

void print_task(Task *task) {
    printf("Task %d:\nPriority: %d\nArrival Time: %d\nBurst Time: %d\nWaiting Time: %d\nTurnaround Time: %d\n", task->id, task->priority, task->arrival_time, task->burst_time, task->waiting_time, task->turnaround_time);
}

void print_schedule(Task schedule[MAX_TASKS], int n) {
    int i;
    printf("\nTask Schedule:\n");
    for(i = 0; i < n; i++) {
        printf("Time: %d\n", current_time);
        print_task(&schedule[i]);
    }
}

int get_random_number(int min_num, int max_num) {
    return (rand() % (max_num - min_num + 1)) + min_num;
}

void generate_tasks(Task *tasks, int num_tasks) {
    int i;
    for(i = 0; i < num_tasks; i++) {
        tasks[i].id = i + 1;
        tasks[i].priority = get_random_number(1, MAX_PRIORITY);
        tasks[i].arrival_time = get_random_number(0, 10);
        tasks[i].burst_time = get_random_number(1, 10);
        tasks[i].completed = false;
    }
}

int main() {
    srand(time(NULL));
    int i;
    int total_waiting_time = 0, total_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;
    Task tasks[MAX_TASKS];
    Task task_schedule[MAX_TASKS];

    printf("Enter the number of tasks: ");
    scanf("%d", &task_counter);
    generate_tasks(tasks, task_counter);

    printf("Task List:\n");
    for(i = 0; i < task_counter; i++) {
        print_task(&tasks[i]);
    }

    while(true) {
        int current_task_index = -1;
        int highest_priority = MAX_PRIORITY + 1;
        bool all_tasks_completed = true;

        for(i = 0; i < task_counter; i++) {
            if(!tasks[i].completed) {
                all_tasks_completed = false;
                if(tasks[i].priority < highest_priority && tasks[i].arrival_time <= current_time) {
                    highest_priority = tasks[i].priority;
                    current_task_index = i;
                }
            }
        }

        if(all_tasks_completed) {
            break;
        }

        task_schedule[current_time] = tasks[current_task_index];
        task_schedule[current_time].waiting_time = current_time - tasks[current_task_index].arrival_time;
        task_schedule[current_time].turnaround_time = task_schedule[current_time].waiting_time + tasks[current_task_index].burst_time;
        total_waiting_time += task_schedule[current_time].waiting_time;
        total_turnaround_time += task_schedule[current_time].turnaround_time;
        tasks[current_task_index].completed = true;
        current_time++;
    }

    average_waiting_time = (float) total_waiting_time / task_counter;
    average_turnaround_time = (float) total_turnaround_time / task_counter;

    print_schedule(task_schedule, current_time);
    printf("\nAverage Waiting Time: %f\nAverage Turnaround Time: %f\n", average_waiting_time, average_turnaround_time);

    return 0;
}