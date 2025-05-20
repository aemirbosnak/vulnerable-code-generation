//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROCESSES 50    // Maximum number of processes.
#define MAX_PRIORITY  10    // Maximum priority level.

// Process struct
typedef struct Process {
    char name;
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

// Queue struct
typedef struct Queue {
    Process processes[MAX_PROCESSES];
    int front, rear, size;
} Queue;

// Functions declaration
void init_queue(Queue *q);
void enqueue(Queue *q, Process p);
Process dequeue(Queue *q);
int is_empty(Queue *q);
void print_gantt_chart(Process processes[], int n);
int fcfs_scheduling(Process processes[], int n);
int sjf_scheduling(Process processes[], int n);
int priority_scheduling(Process processes[], int n);
int round_robin_scheduling(Process processes[], int n, int quantum);
int get_random_burst_time();
int get_random_priority();
int get_random_arrival_time();

// Main function
int main() {
    int n, choice, quantum;
    Process processes[MAX_PROCESSES];

    printf("Medieval CPU Scheduling Algorithms Simulation\n\n");

    // Get user input
    printf("Enter the number of processes [1-50]: ");
    scanf("%d", &n);

    printf("\nEnter the burst time range (in milliseconds) [1-1000]: ");
    int min_burst_time, max_burst_time;
    printf("\nMin: ");
    scanf("%d", &min_burst_time);
    printf("\nMax: ");
    scanf("%d", &max_burst_time);

    printf("\nEnter the priority range [1-10]: ");
    int min_priority, max_priority;
    printf("\nMin: ");
    scanf("%d", &min_priority);
    printf("\nMax: ");
    scanf("%d", &max_priority);

    printf("\nEnter the arrival time range (in seconds) [0-10]: ");
    int min_arrival_time, max_arrival_time;
    printf("\nMin: ");
    scanf("%d", &min_arrival_time);
    printf("\nMax: ");
    scanf("%d", &max_arrival_time);

    printf("\nEnter the scheduling algorithm [1-4]:");
    printf("\n1. First Come First Serve (FCFS)");
    printf("\n2. Shortest Job First (SJF)");
    printf("\n3. Priority Scheduling");
    printf("\n4. Round Robin Scheduling");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter the quantum (in milliseconds): ");
            scanf("%d", &quantum);
            printf("\nFirst Come First Serve (FCFS) Scheduling\n");
            break;
        case 2:
            printf("\nShortest Job First (SJF) Scheduling\n");
            break;
        case 3:
            printf("\nPriority Scheduling\n");
            break;
        case 4:
            printf("\nEnter the quantum (in milliseconds): ");
            scanf("%d", &quantum);
            printf("\nRound Robin Scheduling\n");
            break;
    }

    // Initialize random seed
    srand(time(NULL));

    // Generate random processes
    for (int i = 0; i < n; i++) {
        processes[i].name = 'A' + i;
        processes[i].pid = i + 1;
        processes[i].burst_time = get_random_burst_time(min_burst_time, max_burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].arrival_time = get_random_arrival_time(min_arrival_time, max_arrival_time);
        processes[i].priority = get_random_priority(min_priority, max_priority);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Schedule processes
    int total_waiting_time, total_turnaround_time;
    switch (choice) {
        case 1:
            total_waiting_time = fcfs_scheduling(processes, n);
            break;

        case 2:
            total_waiting_time = sjf_scheduling(processes, n);
            break;

        case 3:
            total_waiting_time = priority_scheduling(processes, n);
            break;

        case 4:
            total_waiting_time = round_robin_scheduling(processes, n, quantum);
            break;
    }

    // Calculate turnaround time, average waiting time and average turnaround time.
    total_turnaround_time = total_waiting_time;
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

    // Print simulation results
    printf("\nSimulation Results:\n");
    printf("Process\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P[%c]\t%d ms\t\t%d s\t\t%d\t\t%d ms\t\t%d ms\n", processes[i].name, processes[i].burst_time,
               processes[i].arrival_time, processes[i].priority, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n\n", avg_turnaround_time);

    print_gantt_chart(processes, n);

    return 0;
}

// Initialize queue
void init_queue(Queue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}

// Insert process into queue
void enqueue(Queue *q, Process p) {
    if (q->rear == MAX_PROCESSES - 1) {
        printf("Queue is full.\n");
        return;
    }
    q->rear++;
    q->processes[q->rear] = p;
    q->size++;
    if (q->front == -1) {
        q->front = 0;
    }
}

// Remove process from queue
Process dequeue(Queue *q) {
    Process p;
    p.name = ' ';
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty.\n");
        return p;
    }
    p = q->processes[q->front];
    q->front++;
    q->size--;
    return p;
}

// Check if queue is empty
int is_empty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// First Come First Serve (FCFS) scheduling algorithm
int fcfs_scheduling(Process processes[], int n) {
    int current_time = 0;
    Queue ready_queue;
    init_queue(&ready_queue);

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        enqueue(&ready_queue, processes[i]);
    }

    int total_waiting_time = 0;
    while (!is_empty(&ready_queue)) {
        Process p = dequeue(&ready_queue);
        p.waiting_time = current_time - p.arrival_time;
        total_waiting_time += p.waiting_time;
        current_time += p.burst_time;
    }

    return total_waiting_time;
}

// Shortest Job First (SJF) scheduling algorithm
int sjf_scheduling(Process processes[], int n) {
    int current_time = 0;
    Queue ready_queue;
    init_queue(&ready_queue);

    int i = 0;
    while (i < n || !is_empty(&ready_queue)) {
        if (!is_empty(&ready_queue)) {
            Process p = dequeue(&ready_queue);
            p.waiting_time = current_time - p.arrival_time;
            p.remaining_time = 0;
            current_time += p.burst_time;
            processes[p.pid - 1] = p;
        } else {
            current_time = processes[i].arrival_time;
        }
        while (i < n && processes[i].arrival_time <= current_time) {
            enqueue(&ready_queue, processes[i]);
            i++;
        }

        int shortest_job = MAX_PROCESSES;
        Process *p = NULL;

        for (int j = 0; j < ready_queue.size; j++) {
            int k = (ready_queue.front + j) % MAX_PROCESSES;
            if (ready_queue.processes[k].remaining_time < shortest_job) {
                shortest_job = ready_queue.processes[k].remaining_time;
                p = &ready_queue.processes[k];
            }
        }

        if (p != NULL) {
            dequeue(&ready_queue);
            p->remaining_time = shortest_job;
            current_time += shortest_job;
            enqueue(&ready_queue, *p);
        }
    }

    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }

    return total_waiting_time;
}

// Priority Scheduling algorithm
int priority_scheduling(Process processes[], int n) {
    int current_time = 0;
    Queue ready_queue;
    init_queue(&ready_queue);

    int i = 0;
    while (i < n || !is_empty(&ready_queue)) {
        if (!is_empty(&ready_queue)) {
            Process p = dequeue(&ready_queue);
            p.waiting_time = current_time - p.arrival_time;
            p.remaining_time = 0;
            current_time += p.burst_time;
            processes[p.pid - 1] = p;
        } else {
            current_time = processes[i].arrival_time;
        }
        while (i < n && processes[i].arrival_time <= current_time) {
            enqueue(&ready_queue, processes[i]);
            i++;
        }

        int highest_priority = MAX_PRIORITY + 1;
        Process *p = NULL;

        for (int j = 0; j < ready_queue.size; j++) {
            int k = (ready_queue.front + j) % MAX_PROCESSES;
            if (ready_queue.processes[k].priority < highest_priority) {
                highest_priority = ready_queue.processes[k].priority;
                p = &ready_queue.processes[k];
            }
        }

        if (p != NULL) {
            dequeue(&ready_queue);
            p->priority = highest_priority;
            current_time += p->burst_time;
            enqueue(&ready_queue, *p);
        }
    }

    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }

    return total_waiting_time;
}

// Round Robin Scheduling algorithm
int round_robin_scheduling(Process processes[], int n, int quantum) {
    int current_time = 0;
    Queue ready_queue;
    init_queue(&ready_queue);

    int i = 0;
    while (i < n || !is_empty(&ready_queue)) {
        if (!is_empty(&ready_queue)) {
            Process p = dequeue(&ready_queue);
            p.waiting_time = current_time - p.arrival_time;
            p.remaining_time -= quantum;
            current_time += quantum;
            if (p.remaining_time <= 0) {
                p.remaining_time = 0;
                current_time -= quantum - p.remaining_time;
            } else {
                enqueue(&ready_queue, p);
            }
            processes[p.pid - 1] = p;
        } else {
            current_time = processes[i].arrival_time;
        }
        while (i < n && processes[i].arrival_time <= current_time) {
            processes[i].remaining_time = processes[i].burst_time;
            enqueue(&ready_queue, processes[i]);
            i++;
        }
    }

    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }

    return total_waiting_time;
}

// Get a random burst time in the given range
int get_random_burst_time(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Get a random priority in the given range
int get_random_priority(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Get a random arrival time in the given range
int get_random_arrival_time(int min, int max) {
    return rand() % (max - min + 1);
}

// Print Gantt Chart
void print_gantt_chart(Process processes[], int n) {
    printf("\nGantt Chart:\n");

    for (int i = 0; i < n; i++) {
        printf("+--------");
    }
    printf("+\n");

    printf("|");
    for (int i = 0; i < n; i++) {
        printf("  P[%c]  |", processes[i].name);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("+--------");
    }
    printf("+\n");

    printf("0");
    for (int i = 0; i < n; i++) {
        printf("       %d", processes[i].burst_time);
    }
    printf("\n");
}