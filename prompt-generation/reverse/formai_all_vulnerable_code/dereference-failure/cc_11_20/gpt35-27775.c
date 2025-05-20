//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

int main() {
    int num_processes, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    int *arrival_time = (int*)malloc(num_processes * sizeof(int));
    int *burst_time = (int*)malloc(num_processes * sizeof(int));
    int *priority = (int*)malloc(num_processes * sizeof(int));
    int *wait_time = (int*)calloc(num_processes, sizeof(int));
    int *turnaround_time = (int*)calloc(num_processes, sizeof(int));
    int *completion_time = (int*)calloc(num_processes, sizeof(int));
    int *remaining_time = (int*)malloc(num_processes * sizeof(int));
    int *process_completed = (int*)calloc(num_processes, sizeof(int));
    int total_wait_time = 0, total_turnaround_time = 0;
    float avg_wait_time, avg_turnaround_time;

    srand(time(0));
    for (i = 0; i < num_processes; i++) {
        arrival_time[i] = rand() % 20;
        burst_time[i] = rand() % 50 + 1;
        priority[i] = rand() % (MAX_PRIORITY - MIN_PRIORITY + 1) + MIN_PRIORITY;
        remaining_time[i] = burst_time[i];
    }

    int current_time = 0, completed_processes = 0, shortest_remaining_time_process;
    printf("\nSurreal CPU Scheduler Output:\n\n");

    while (completed_processes != num_processes) {
        shortest_remaining_time_process = -1;
        for (i = 0; i < num_processes; i++) {
            if (arrival_time[i] <= current_time && process_completed[i] == 0) {
                if (shortest_remaining_time_process == -1) {
                    shortest_remaining_time_process = i;
                } else if (priority[i] < priority[shortest_remaining_time_process]) {
                    shortest_remaining_time_process = i;
                } else if (priority[i] == priority[shortest_remaining_time_process] && remaining_time[i] < remaining_time[shortest_remaining_time_process]) {
                    shortest_remaining_time_process = i;
                }
            }
        }

        if (shortest_remaining_time_process == -1) {
            current_time++;
            continue;
        }

        remaining_time[shortest_remaining_time_process]--;
        current_time++;

        if (remaining_time[shortest_remaining_time_process] == 0) {
            completed_processes++;
            completion_time[shortest_remaining_time_process] = current_time;
            turnaround_time[shortest_remaining_time_process] = completion_time[shortest_remaining_time_process] - arrival_time[shortest_remaining_time_process];
            wait_time[shortest_remaining_time_process] = turnaround_time[shortest_remaining_time_process] - burst_time[shortest_remaining_time_process];
            total_wait_time += wait_time[shortest_remaining_time_process];
            total_turnaround_time += turnaround_time[shortest_remaining_time_process];
            process_completed[shortest_remaining_time_process] = 1;

            printf("P%d completed in surreal fashion at time %d. ", shortest_remaining_time_process, current_time);
            printf("Turnaround Time: %d, Waiting Time: %d\n", turnaround_time[shortest_remaining_time_process], wait_time[shortest_remaining_time_process]);
        }
    }

    avg_wait_time = (float)total_wait_time / num_processes;
    avg_turnaround_time = (float)total_turnaround_time / num_processes;

    printf("\nSurreal CPU Scheduler Results:\n\n");
    printf("Total Waiting Time: %d\n", total_wait_time);
    printf("Total Turnaround Time: %d\n", total_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    free(arrival_time);
    free(burst_time);
    free(priority);
    free(wait_time);
    free(turnaround_time);
    free(completion_time);
    free(remaining_time);
    free(process_completed);

    return 0;
}