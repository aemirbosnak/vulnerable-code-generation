//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// structure to represent a process
typedef struct Process {
    int pid;        // process id
    int arrival;    // arrival time
    int burst;      // burst time
    int priority;   // priority
    int wait;       // wait time
    int turnaround; // turnaround time
    int remaining;  // remaining burst time
} Process;

// function to read input from file and create process array
Process* read_input(char* filename, int* n) {
    // open file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    // read number of processes
    fscanf(file, "%d", n);
    // allocate memory for process array
    Process* processes = (Process*) malloc(*n * sizeof(Process));
    // read process info from file
    for (int i = 0; i < *n; i++) {
        int pid, arrival, burst, priority;
        fscanf(file, "%d %d %d %d", &pid, &arrival, &burst, &priority);
        processes[i].pid = pid;
        processes[i].arrival = arrival;
        processes[i].burst = burst;
        processes[i].priority = priority;
        processes[i].wait = 0;
        processes[i].turnaround = 0;
        processes[i].remaining = burst;
    }
    // close file
    fclose(file);
    return processes;
}

// function to print process info
void print_process(Process p) {
    printf("%d %d %d %d %d %d\n", p.pid, p.arrival, p.burst, p.priority, p.wait, p.turnaround);
}

// function to print process table
void print_table(Process* processes, int n) {
    printf("PID Arrival Burst Priority Wait Turnaround\n");
    for (int i = 0; i < n; i++) {
        print_process(processes[i]);
    }
}

// function to sort processes by arrival time
void sort_arrival(Process* processes, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (processes[i].arrival > processes[j].arrival) {
                Process tmp = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp;
            }
        }
    }
}

// function to sort processes by priority
void sort_priority(Process* processes, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (processes[i].priority < processes[j].priority) {
                Process tmp = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp;
            }
        }
    }
}

// function to simulate first-come first-serve scheduling
void fcfs(Process* processes, int n) {
    // sort processes by arrival time
    sort_arrival(processes, n);
    // run processes in order
    for (int i = 0; i < n; i++) {
        // calculate wait time
        if (i == 0) {
            processes[i].wait = 0;
        } else {
            processes[i].wait = processes[i-1].wait + processes[i-1].burst - processes[i].arrival;
        }
        // calculate turnaround time
        processes[i].turnaround = processes[i].wait + processes[i].burst;
    }
}

// function to simulate shortest-job-first scheduling
void sjf(Process* processes, int n) {
    // sort processes by arrival time
    sort_arrival(processes, n);
    // initialize remaining time to burst time
    for (int i = 0; i < n; i++) {
        processes[i].remaining = processes[i].burst;
    }
    // run processes in order of shortest remaining time
    for (int time = 0; ; time++) {
        bool done = true;
        int shortest = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining > 0 && processes[i].arrival <= time) {
                if (shortest == -1 || processes[i].remaining < processes[shortest].remaining) {
                    shortest = i;
                }
                done = false;
            }
        }
        if (done) {
            break;
        }
        // calculate wait time
        if (shortest == 0) {
            processes[shortest].wait = 0;
        } else {
            processes[shortest].wait = time - processes[shortest].arrival;
        }
        // decrement remaining time for current process
        processes[shortest].remaining--;
        // calculate turnaround time
        if (processes[shortest].remaining == 0) {
            processes[shortest].turnaround = processes[shortest].wait + processes[shortest].burst;
        }
    }
}

// function to simulate round-robin scheduling
void rr(Process* processes, int n, int q) {
    // sort processes by arrival time
    sort_arrival(processes, n);
    // initialize remaining time to burst time
    for (int i = 0; i < n; i++) {
        processes[i].remaining = processes[i].burst;
    }
    // run processes in round-robin fashion
    int time = 0;
    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining > 0) {
                done = false;
                if (processes[i].arrival <= time) {
                    // calculate wait time
                    if (processes[i].remaining == processes[i].burst) {
                        processes[i].wait = time - processes[i].arrival;
                    }
                    // execute process for quantum q or until completed
                    if (processes[i].remaining < q) {
                        time += processes[i].remaining;
                        processes[i].remaining = 0;
                    } else {
                        time += q;
                        processes[i].remaining -= q;
                    }
                    // calculate turnaround time
                    if (processes[i].remaining == 0) {
                        processes[i].turnaround = processes[i].wait + processes[i].burst;
                    }
                }
            }
        }
    }
}

// function to simulate priority scheduling
void priority(Process* processes, int n) {
    // sort processes by arrival time
    sort_arrival(processes, n);
    // sort processes by priority
    sort_priority(processes, n);
    // run processes in order of highest priority
    for (int i = 0; i < n; i++) {
        // calculate wait time
        if (i == 0) {
            processes[i].wait = 0;
        } else {
            processes[i].wait = processes[i-1].wait + processes[i-1].burst;
        }
        // calculate turnaround time
        processes[i].turnaround = processes[i].wait + processes[i].burst;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        // incorrect number of arguments
        printf("Usage: %s <filename> <algorithm> <quantum(if round-robin)>\n", argv[0]);
        exit(1);
    }
    // read input file and create process array
    int n;
    Process* processes = read_input(argv[1], &n);
    // run selected algorithm
    if (strcmp(argv[2], "fcfs") == 0) {
        fcfs(processes, n);
    } else if (strcmp(argv[2], "sjf") == 0) {
        sjf(processes, n);
    } else if (strcmp(argv[2], "rr") == 0) {
        int q = atoi(argv[3]);
        rr(processes, n, q);
    } else if (strcmp(argv[2], "priority") == 0) {
        priority(processes, n);
    } else {
        printf("Error: invalid algorithm '%s'\n", argv[2]);
        exit(1);
    }
    // print process table
    print_table(processes, n);
    // free memory
    free(processes);
    return 0;
}