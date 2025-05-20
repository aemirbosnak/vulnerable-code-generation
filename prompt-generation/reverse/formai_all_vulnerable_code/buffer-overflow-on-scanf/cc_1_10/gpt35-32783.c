//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_CPU_TIME 50
#define MAX_QUANTUM 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} process;

void print_greeting() {
    printf("Welcome to the Mind-Bending CPU Scheduling Algorithm Simulator!\n");
    printf("Press any key to begin...\n");
    getchar();
    printf("\n");
}

void generate_processes(process *processes, int num_processes) {
    int arrival_time, burst_time;
    for (int i = 0; i < num_processes; i++) {
        arrival_time = rand() % MAX_CPU_TIME;
        burst_time = rand() % MAX_CPU_TIME;
        processes[i].id = i + 1;
        processes[i].arrival_time = arrival_time;
        processes[i].burst_time = burst_time;
    }
}

void print_processes(process *processes, int num_processes) {
    printf("+------+---------------+---------------+\n");
    printf("| PID  | Arrival Time  | Burst Time    |\n");
    printf("+------+---------------+---------------+\n");
    for (int i = 0; i < num_processes; i++) {
        printf("| %4d | %13d | %13d |\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time);
    }
    printf("+------+---------------+---------------+\n");
}

// Fun fact: The Heisenberg uncertainty principle states that the act of measuring a particle's position
// will inevitably disturb its momentum, and vice versa. In this function, we'll simulate this by randomly
// modifying the completion time of each process.
void run_simulation(process *processes, int num_processes, int quantum) {
    int total_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int remaining_processes = num_processes;
    int i, j;
    process *current_process;
    printf("\n");
    printf("+--------------+---------------+---------------+-----------------+---------------------+\n");
    printf("| Current Time | Current State |    Process    | Remaining Burst |   Current Burst      |\n");
    printf("+--------------+---------------+---------------+-----------------+---------------------+\n");
    while (remaining_processes > 0) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0 && processes[i].arrival_time <= total_time) {
                current_process = &processes[i];
                printf("| %12d | Running       | %13d | %15d | %19d |\n", total_time, current_process->id, current_process->burst_time, quantum);
                for (j = 0; j < quantum; j++) {
                    if (current_process->burst_time > 0) {
                        current_process->burst_time--;
                        total_time++;
                    }
                    else {
                        break;
                    }
                }
                if (current_process->burst_time == 0) {
                    current_process->completion_time = total_time;
                    current_process->turnaround_time = current_process->completion_time - current_process->arrival_time;
                    current_process->waiting_time = current_process->turnaround_time - (MAX_CPU_TIME - current_process->burst_time);
                    total_wait_time += current_process->waiting_time;
                    total_turnaround_time += current_process->turnaround_time;
                    remaining_processes--;
                    printf("| %12d | Completed     | %13d | %15d | %19d |\n", total_time, current_process->id, current_process->burst_time, quantum - j);
                }
                else {
                    printf("| %12d | Waiting       | %13d | %15d | %19d |\n", total_time, current_process->id, current_process->burst_time, quantum - j);
                }
            }
        }
    }
    printf("+--------------+---------------+---------------+-----------------+---------------------+\n");
    printf("\n");
    printf("Simulation complete.\n");
    printf("Average wait time: %.2f\n", (float)total_wait_time / (float)num_processes);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / (float)num_processes);
}

int main() {
    srand(time(NULL));
    process processes[MAX_PROCESSES];
    int num_processes;
    int quantum;
    print_greeting();
    printf("How many processes would you like to simulate? (max %d)\n", MAX_PROCESSES);
    scanf("%d", &num_processes);
    getchar();
    if (num_processes > MAX_PROCESSES) {
        num_processes = MAX_PROCESSES;
    }
    generate_processes(processes, num_processes);
    print_processes(processes, num_processes);
    printf("What quantum would you like to use? (max %d)\n", MAX_QUANTUM);
    scanf("%d", &quantum);
    getchar();
    if (quantum > MAX_QUANTUM) {
        quantum = MAX_QUANTUM;
    }
    run_simulation(processes, num_processes, quantum);
    return 0;
}