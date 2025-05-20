//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef enum {
    FCFS,
    SJF,
    RR
} Algorithm;

typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} Process;

void simulate(Process* processes, int n, Algorithm algorithm, int quantum) {
    int remaining_n = n;
    int current_time = 0;
    int current_process = -1;
    int* queue = malloc(sizeof(*queue) * MAX_PROCESSES);
    int front = 0;
    int rear = -1;
    int quantum_countdown = 0;

    while (remaining_n > 0) {
        switch (algorithm) {
            case FCFS:
                for (int i = 0; i < n; ++i) {
                    if (processes[i].arrival_time <= current_time) {
                        if (current_process == -1 || processes[i].arrival_time < processes[current_process].arrival_time) {
                            current_process = i;
                        }
                    }
                }
                break;
            case SJF:
                for (int i = 0; i < n; ++i) {
                    if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                        if (current_process == -1 || processes[i].remaining_time < processes[current_process].remaining_time) {
                            current_process = i;
                        }
                    }
                }
                break;
            case RR:
                if (quantum_countdown == 0 || processes[current_process].remaining_time == 0) {
                    if (rear == -1) {
                        break;
                    }
                    current_process = queue[front++];
                    if (front > rear) {
                        front = 0;
                        rear = -1;
                    }
                    quantum_countdown = quantum;
                }
                break;
        }

        if (current_process >= 0) {
            --processes[current_process].remaining_time;
            --quantum_countdown;
            if (processes[current_process].remaining_time == 0) {
                --remaining_n;
                processes[current_process].turnaround_time = current_time - processes[current_process].arrival_time;
                processes[current_process].waiting_time = processes[current_process].turnaround_time - processes[current_process].burst_time;
                current_process = -1;
                quantum_countdown = 0;
            } else if (algorithm == RR && quantum_countdown == 0) {
                queue[++rear] = current_process;
                current_process = -1;
            }
        }

        ++current_time;
    }

    printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "PID", "Burst", "Arrival", "Waiting", "Turnaround", "Remaining");
    for (int i = 0; i < n; ++i) {
        printf("%-10d %-10d %-10d %-10d %-10d %-10d\n",
            processes[i].pid,
            processes[i].burst_time,
            processes[i].arrival_time,
            processes[i].waiting_time,
            processes[i].turnaround_time,
            processes[i].remaining_time
        );
    }
}

int main(int argc, char** argv) {
    int n;
    Algorithm algorithm;
    int quantum;

    if (argc < 3) {
        printf("Usage: %s [FCFS|SJF|RR] [QUANTUM]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "FCFS") == 0) {
        algorithm = FCFS;
    } else if (strcmp(argv[1], "SJF") == 0) {
        algorithm = SJF;
    } else if (strcmp(argv[1], "RR") == 0) {
        algorithm = RR;
    } else {
        printf("Invalid algorithm: %s\n", argv[1]);
        return 1;
    }

    if (algorithm == RR) {
        if (argc < 4) {
            printf("RR algorithm requires a quantum parameter\n");
            return 1;
        }
        quantum = atoi(argv[3]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process* processes = malloc(sizeof(*processes) * n);
    for (int i = 0; i < n; ++i) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    simulate(processes, n, algorithm, quantum);

    return 0;
}