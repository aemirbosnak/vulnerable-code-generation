//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 10
#define NAME_LEN 15
#define TIME_QUANTUM 3

typedef struct {
    char name[NAME_LEN];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void create_process(Process *process, int index) {
    sprintf(process->name, "Process-%d", index + 1);
    process->burst_time = rand() % 10 + 1; // Random burst time between 1 and 10
    process->waiting_time = 0;
    process->turnaround_time = 0;
}

void display_processes(Process processes[], int count) {
    printf("\nSurreal Galaxy of Processes:\n");
    for (int i = 0; i < count; i++) {
        printf("%s with burst time: %d and waiting time: %d\n",
               processes[i].name, processes[i].burst_time, processes[i].waiting_time);
    }
}

void round_robin(Process processes[], int count, int time_quantum) {
    int time = 0;
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < count; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    while (1) {
        int all_done = 1;

        for (int i = 0; i < count; i++) {
            if (remaining_time[i] > 0) {
                all_done = 0;
                if (remaining_time[i] > time_quantum) {
                    time += time_quantum;
                    remaining_time[i] -= time_quantum;
                } else {
                    time += remaining_time[i];
                    processes[i].turnaround_time = time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }

        if (all_done) break; // All processes are done
        usleep(100000); // Adding surreal delay
    }
}

void print_turnaround_waiting(Process processes[], int count) {
    printf("\nThe Dance of Turnaround and Waiting Times:\n");
    for (int i = 0; i < count; i++) {
        printf("For %s, Turnaround Time: %d, Waiting Time: %d\n",
               processes[i].name, processes[i].turnaround_time, processes[i].waiting_time);
    }
}

int main() {
    srand(time(NULL)); // The Mad Randomizer of the Universe
    Process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes (1-10): ");
    scanf("%d", &num_processes);
    if (num_processes < 1 || num_processes > MAX_PROCESSES) {
        printf("Behold! The number should be between 1 and 10!\n");
        return 1;
    }

    for (int i = 0; i < num_processes; i++) {
        create_process(&processes[i], i);
    }

    display_processes(processes, num_processes);
    round_robin(processes, num_processes, TIME_QUANTUM);
    print_turnaround_waiting(processes, num_processes);

    printf("\nAnd thus, the grand escapade of CPU scheduling concludes...\n");
    return 0;
}