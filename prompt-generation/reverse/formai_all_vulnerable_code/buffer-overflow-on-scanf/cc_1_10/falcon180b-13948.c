//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
#include <stdio.h>

// Define the maximum number of tasks that can be scheduled
#define MAX_TASKS 10

// Define the task structure
struct task {
    int task_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Initialize the task schedule
void init_schedule(struct task schedule[MAX_TASKS]) {
    // Prompt the user to enter the number of tasks
    printf("Enter the number of tasks: ");
    scanf("%d", &schedule[0].task_id);

    // Prompt the user to enter the arrival time and burst time for each task
    for (int i = 0; i < schedule[0].task_id; i++) {
        printf("Enter the arrival time and burst time for task %d: ", i + 1);
        scanf("%d %d", &schedule[i].arrival_time, &schedule[i].burst_time);
    }
}

// Calculate the waiting time and turnaround time for each task
void calculate_waiting_turnaround(struct task schedule[MAX_TASKS]) {
    // Assume the first task starts at time 0
    schedule[0].waiting_time = 0;

    // Calculate the waiting time for each subsequent task
    for (int i = 1; i < schedule[0].task_id; i++) {
        schedule[i].waiting_time = schedule[i].arrival_time - schedule[i - 1].arrival_time - schedule[i - 1].burst_time;
    }

    // Calculate the turnaround time for each task
    for (int i = 0; i < schedule[0].task_id; i++) {
        schedule[i].turnaround_time = schedule[i].waiting_time + schedule[i].burst_time;
    }
}

// Print the task schedule
void print_schedule(struct task schedule[MAX_TASKS]) {
    // Print the task ID, arrival time, burst time, waiting time, and turnaround time for each task
    for (int i = 0; i < schedule[0].task_id; i++) {
        printf("Task %d: Arrival time = %d, Burst time = %d, Waiting time = %d, Turnaround time = %d\n",
               i + 1, schedule[i].arrival_time, schedule[i].burst_time, schedule[i].waiting_time, schedule[i].turnaround_time);
    }
}

int main() {
    struct task schedule[MAX_TASKS];

    // Initialize the task schedule
    init_schedule(schedule);

    // Calculate the waiting time and turnaround time for each task
    calculate_waiting_turnaround(schedule);

    // Print the task schedule
    print_schedule(schedule);

    return 0;
}