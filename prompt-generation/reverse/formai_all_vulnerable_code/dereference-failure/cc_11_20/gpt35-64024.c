//FormAI DATASET v1.0 Category: System boot optimizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initializing variables
    int num_of_processes = 0;
    int quantum = 5;
    int priority_levels = 10;
    int time_slice = 1;
    int current_time = 0;
    int throughput = 0;
    float average_waiting_time = 0.0;
    float average_turnaround_time = 0.0;
    char user_input[50];

    // Greeting the user
    printf("Hello! Welcome to the C System Boot Optimizer.\n");

    // Prompting the user for the number of processes
    printf("Please enter the number of processes you want to optimize: ");
    fgets(user_input, sizeof(user_input), stdin);
    sscanf(user_input, "%d", &num_of_processes);

    // Memory allocation for dynamic arrays
    int *process_ids = malloc(num_of_processes * sizeof(int));
    int *burst_times = malloc(num_of_processes * sizeof(int));
    int *arrival_times = malloc(num_of_processes * sizeof(int));
    int *remaining_times = malloc(num_of_processes * sizeof(int));
    int *waiting_times = calloc(num_of_processes, sizeof(int));
    int *turnaround_times = calloc(num_of_processes, sizeof(int));
    int *run_times = calloc(num_of_processes, sizeof(int));
    int *completion_times = calloc(num_of_processes, sizeof(int));
    int *priorities = malloc(num_of_processes * sizeof(int));
    int *priority_quantums = malloc(priority_levels * sizeof(int));
    int current_queue = 0;

    // Prompting the user for each process's details
    for (int i = 0; i < num_of_processes; i++) {
        printf("\nProcess ID [%d]: ", i);
        fgets(user_input, sizeof(user_input), stdin);
        sscanf(user_input, "%d", &process_ids[i]);

        printf("Arrival Time [%d]: ", i);
        fgets(user_input, sizeof(user_input), stdin);
        sscanf(user_input, "%d", &arrival_times[i]);

        printf("Burst Time [%d]: ", i);
        fgets(user_input, sizeof(user_input), stdin);
        sscanf(user_input, "%d", &burst_times[i]);

        printf("Priority [%d]: ", i);
        fgets(user_input, sizeof(user_input), stdin);
        sscanf(user_input, "%d", &priorities[i]);

        remaining_times[i] = burst_times[i];
    }

    // Prompting the user for the priority quantums for round-robin scheduling
    printf("\nPlease enter the priority quantums for round-robin scheduling:\n");
    for (int i = 0; i < priority_levels; i++) {
        printf("Priority Level [%d]: ", i);
        fgets(user_input, sizeof(user_input), stdin);
        sscanf(user_input, "%d", &priority_quantums[i]);
    }

    printf("\nStarting optimization...\n");

    // Run the processes until they all complete
    while (1) {
        int remaining_processes = num_of_processes;
        int running_process = -1;
        for (int i = 0; i < num_of_processes; i++) {
            if (arrival_times[i] <= current_time && remaining_times[i] > 0) {
                if (running_process == -1 && priorities[i] == current_queue) {
                    running_process = i;
                }
                else if (priorities[i] == current_queue && remaining_times[i] < remaining_times[running_process]) {
                    running_process = i;
                }
            }
            if (remaining_times[i] <= 0) {
                remaining_processes -= 1;
                continue;
            }
        }

        if (remaining_processes == 0) {
            break;
        }

        // If there is no running process in the current queue, move to the next queue
        if (running_process == -1) {
            current_queue = (current_queue + 1) % priority_levels;
            continue;
        }

        // Run the process for the time slice
        run_times[running_process] += time_slice;
        remaining_times[running_process] -= time_slice;
        current_time += time_slice;

        // If the process has completed, update completion time and throughput
        if (remaining_times[running_process] <= 0) {
            completion_times[running_process] = current_time;
            throughput += 1;
        }
    }

    // Calculate waiting and turnaround times for each process
    for (int i = 0; i < num_of_processes; i++) {
        turnaround_times[i] = completion_times[i] - arrival_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];
        average_waiting_time += (float)waiting_times[i] / num_of_processes;
        average_turnaround_time += (float)turnaround_times[i] / num_of_processes;
    }

    // Output results to the user
    printf("\n[RESULTS]\n");
    printf("Throughput: %d\n", throughput);
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);

    // Deallocate memory
    free(process_ids);
    free(burst_times);
    free(arrival_times);
    free(remaining_times);
    free(waiting_times);
    free(turnaround_times);
    free(run_times);
    free(completion_times);
    free(priorities);
    free(priority_quantums);

    return 0;
}