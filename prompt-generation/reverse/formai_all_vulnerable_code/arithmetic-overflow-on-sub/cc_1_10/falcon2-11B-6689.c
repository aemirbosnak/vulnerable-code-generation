//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_TASKS 20

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;
};

struct Process processes[MAX_PROCESSES];
int num_processes;
int total_time = 0;

void process_arrival(int id, int arrival_time) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Process queue is full. Process %d cannot be added.\n", id);
    } else {
        processes[num_processes].id = id;
        processes[num_processes].arrival_time = arrival_time;
        num_processes++;
    }
}

void process_completion(int id) {
    int index = 0;
    for (; index < num_processes; index++) {
        if (processes[index].id == id) {
            break;
        }
    }
    if (index < num_processes) {
        processes[index].completion_time = total_time;
        processes[index].waiting_time = total_time - processes[index].arrival_time;
        processes[index].turn_around_time = total_time - processes[index].burst_time;
    }
}

int main() {
    int num_tasks = 0;
    int task_arrival[MAX_TASKS];
    int task_burst[MAX_TASKS];
    int task_completion[MAX_TASKS];

    int task_id;
    int task_arrival_time;
    int task_burst_time;
    int task_completion_time;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter the arrival time of task %d: ", i + 1);
        scanf("%d", &task_arrival_time);

        printf("Enter the burst time of task %d: ", i + 1);
        scanf("%d", &task_burst_time);

        task_id = i + 1;
        task_completion_time = task_arrival_time + task_burst_time;

        process_arrival(task_id, task_arrival_time);
        processes[task_id].burst_time = task_burst_time;
        process_completion(task_id);

        total_time += task_burst_time;
    }

    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        printf("Arrival Time: %d\n", processes[i].arrival_time);
        printf("Burst Time: %d\n", processes[i].burst_time);
        printf("Completion Time: %d\n", processes[i].completion_time);
        printf("Waiting Time: %d\n", processes[i].waiting_time);
        printf("Turn Around Time: %d\n", processes[i].turn_around_time);
        printf("\n");
    }

    printf("Total Time: %d\n", total_time);
    return 0;
}