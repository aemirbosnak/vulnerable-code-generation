//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to simulate CPU scheduling
void schedule() {
    int num_processes = 10;
    int min_time = 1;
    int max_time = 10;
    int num_jobs = 20;
    int num_threads = 4;
    int num_cpus = 2;

    // Create a list of processes with random arrival and completion times
    int processes[num_processes];
    int arrival_times[num_processes];
    int completion_times[num_processes];
    int cpu_times[num_processes];

    for (int i = 0; i < num_processes; i++) {
        processes[i] = rand_range(0, num_jobs);
        arrival_times[i] = rand_range(1, num_jobs);
        completion_times[i] = rand_range(arrival_times[i] + 1, num_jobs);
        cpu_times[i] = rand_range(min_time, max_time);
    }

    // Sort processes by arrival time
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (arrival_times[j] > arrival_times[j + 1]) {
                int temp = arrival_times[j];
                arrival_times[j] = arrival_times[j + 1];
                arrival_times[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                temp = completion_times[j];
                completion_times[j] = completion_times[j + 1];
                completion_times[j + 1] = temp;

                temp = cpu_times[j];
                cpu_times[j] = cpu_times[j + 1];
                cpu_times[j + 1] = temp;
            }
        }
    }

    // Assign processes to threads
    int threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        threads[i] = -1;
    }

    for (int i = 0; i < num_processes; i++) {
        int thread = -1;
        for (int j = 0; j < num_threads; j++) {
            if (threads[j] == -1) {
                thread = j;
                break;
            }
        }
        if (thread == -1) {
            printf("Too many processes, not enough threads.\n");
            return;
        }
        threads[thread] = i;
    }

    // Assign processes to CPUs
    int cpus[num_cpus];
    for (int i = 0; i < num_cpus; i++) {
        cpus[i] = -1;
    }

    for (int i = 0; i < num_threads; i++) {
        int cpu = -1;
        for (int j = 0; j < num_cpus; j++) {
            if (cpus[j] == -1) {
                cpu = j;
                break;
            }
        }
        if (cpu == -1) {
            printf("Too many threads, not enough CPUs.\n");
            return;
        }
        cpus[cpu] = threads[i];
    }

    // Simulate CPU scheduling
    int current_time = 0;
    while (current_time < num_jobs) {
        // Find the process that is ready to run
        int ready_process = -1;
        for (int i = 0; i < num_cpus; i++) {
            if (cpus[i]!= -1) {
                int process = cpus[i];
                if (arrival_times[process] <= current_time && completion_times[process] >= current_time) {
                    ready_process = process;
                    break;
                }
            }
        }

        // Run the ready process
        int thread = threads[ready_process];
        int cpu = cpus[ready_process];
        int start_time = arrival_times[ready_process];
        int end_time = completion_times[ready_process];
        int cpu_time = cpu_times[ready_process];
        printf("Process %d running on CPU %d from %d to %d, CPU time %d\n", processes[thread], cpu, start_time, end_time, cpu_time);

        // Update process status
        completion_times[thread] = end_time + 1;
        cpu_times[thread] -= cpu_time;

        // Advance current time
        current_time += cpu_time;
    }
}

int main() {
    schedule();
    return 0;
}