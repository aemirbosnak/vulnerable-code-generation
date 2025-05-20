//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int process_id;
} process;

typedef struct {
    int time;
    int process_id;
} event;

int compare_arrival_times(const void *a, const void *b) {
    return ((process *)a)->arrival_time - ((process *)b)->arrival_time;
}

int compare_priorities(const void *a, const void *b) {
    return ((process *)a)->priority - ((process *)b)->priority;
}

void schedule_processes(process processes[], int num_processes) {
    // Sort processes by arrival times
    qsort(processes, num_processes, sizeof(process), compare_arrival_times);

    // Initialize event queue
    event event_queue[MAX_PROCESSES];
    int num_events = 0;

    // Initialize time
    int time = 0;

    // While there are still processes to schedule
    while (num_processes > 0) {
        // Add arrival events to event queue
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time == time) {
                event_queue[num_events++] = (event){.time = time, .process_id = processes[i].process_id};
            }
        }

        // Sort event queue by priorities
        qsort(event_queue, num_events, sizeof(event), compare_priorities);

        // Schedule the highest priority process
        int process_id = event_queue[0].process_id;
        int remaining_time = processes[process_id].remaining_time;

        // Run the process for one time unit
        time++;
        remaining_time--;

        // If the process has finished, remove it from the event queue and decrement the number of processes
        if (remaining_time == 0) {
            for (int i = 0; i < num_events; i++) {
                if (event_queue[i].process_id == process_id) {
                    for (int j = i; j < num_events - 1; j++) {
                        event_queue[j] = event_queue[j + 1];
                    }
                    num_events--;
                    break;
                }
            }
            num_processes--;
        } else {
            // Update the process's remaining time
            processes[process_id].remaining_time = remaining_time;

            // Add a departure event to the event queue
            event_queue[num_events++] = (event){.time = time + remaining_time, .process_id = process_id};
        }
    }

    // Print the schedule
    printf("Schedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%d: Process %d\n", event_queue[i].time, event_queue[i].process_id);
    }
}

int main() {
    // Create some processes
    process processes[] = {
        {.arrival_time = 0, .burst_time = 10, .priority = 1, .process_id = 0},
        {.arrival_time = 1, .burst_time = 5, .priority = 2, .process_id = 1},
        {.arrival_time = 2, .burst_time = 8, .priority = 3, .process_id = 2},
        {.arrival_time = 3, .burst_time = 4, .priority = 4, .process_id = 3},
        {.arrival_time = 4, .burst_time = 6, .priority = 5, .process_id = 4},
    };

    int num_processes = sizeof(processes) / sizeof(process);

    // Schedule the processes
    schedule_processes(processes, num_processes);

    return 0;
}