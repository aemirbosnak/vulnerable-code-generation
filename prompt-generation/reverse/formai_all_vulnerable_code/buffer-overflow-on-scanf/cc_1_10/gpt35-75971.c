//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>

#define MAX_PROCESSES 10
#define QUANTUM 3 // default quantum

// Process structure
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} process;

// Queue structure
typedef struct {
    int front, rear;
    process processes[MAX_PROCESSES];
} queue;

// Function to initialize the queue
void init(queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int is_empty(queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int is_full(queue *q) {
    return q->rear == MAX_PROCESSES - 1;
}

// Function to add a process to the queue
void enqueue(queue *q, process p) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->processes[q->rear] = p;
}

// Function to remove a process from the queue
process dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        process null_process;
        null_process.process_id = -1;
        return null_process;
    }
    process p = q->processes[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return p;
}

// Function to display the process details
void display(process p) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p.process_id, p.arrival_time, p.burst_time, p.remaining_time, 
            p.completion_time, p.turnaround_time, p.waiting_time);
}

// Function to implement the FCFS scheduling algorithm
void fcfs(process processes[], int num_processes) {
    queue q;
    init(&q);
    int time = 0;
    int i = 0;
    while (i < num_processes || !is_empty(&q)) {
        while (i < num_processes && processes[i].arrival_time == time) {
            enqueue(&q, processes[i]);
            i++;
        }
        if (!is_empty(&q)) {
            process p = dequeue(&q);
            p.completion_time = time + p.burst_time;
            p.turnaround_time = p.completion_time - p.arrival_time;
            p.waiting_time = p.turnaround_time - p.burst_time;
            display(p);
            time = p.completion_time;
        } else {
            time++;
        }
    }
}

// Function to implement the SJF scheduling algorithm
void sjf(process processes[], int num_processes) {
    queue q;
    init(&q);
    int time = 0;
    int i = 0;
    while (i < num_processes || !is_empty(&q)) {
        while (i < num_processes && processes[i].arrival_time == time) {
            enqueue(&q, processes[i]);
            i++;
        }
        if (!is_empty(&q)) {
            // Sort the queue based on remaining time using bubble sort
            for (int j = q.front; j <= q.rear; j++) {
                for (int k = j + 1; k <= q.rear; k++) {
                    if (q.processes[j].remaining_time > q.processes[k].remaining_time) {
                        process temp = q.processes[j];
                        q.processes[j] = q.processes[k];
                        q.processes[k] = temp;
                    }
                }
            }
            process p = dequeue(&q);
            p.remaining_time = 0; // process completes
            p.completion_time = time + p.burst_time;
            p.turnaround_time = p.completion_time - p.arrival_time;
            p.waiting_time = p.turnaround_time - p.burst_time;
            display(p);
            time = p.completion_time;
        } else {
            time++;
        }
    }
}

// Function to implement the Round Robin scheduling algorithm
void round_robin(process processes[], int num_processes, int quantum) {
    queue q;
    init(&q);
    int time = 0;
    int i = 0;
    while (i < num_processes || !is_empty(&q)) {
        while (i < num_processes && processes[i].arrival_time == time) {
            enqueue(&q, processes[i]);
            i++;
        }
        if (!is_empty(&q)) {
            process p = dequeue(&q);
            if (p.remaining_time > quantum) {
                time += quantum;
                p.remaining_time -= quantum;
                enqueue(&q, p);
            } else {
                time += p.remaining_time;
                p.remaining_time = 0; // process completes
                p.completion_time = time;
                p.turnaround_time = p.completion_time - p.arrival_time;
                p.waiting_time = p.turnaround_time - p.burst_time;
                display(p);
            }
        } else {
            time++;
        }
    }
}

int main() {
    // Initialize the array of processes
    process processes[MAX_PROCESSES] = {
        {1, 0, 4, 4},
        {2, 1, 2, 2},
        {3, 2, 3, 3},
        {4, 3, 5, 5},
        {5, 4, 1, 1},
        {6, 5, 4, 4},
        {7, 6, 6, 6},
        {8, 7, 7, 7},
        {9, 8, 8, 8},
        {10, 9, 9, 9},
    };
    int num_processes = MAX_PROCESSES;

    // Prompt the user for the type of scheduling algorithm to use
    printf("Enter the type of scheduling algorithm to use:\n");
    printf("1. FCFS\n");
    printf("2. SJF\n");
    printf("3. Round Robin\n");
    int choice;
    scanf("%d", &choice);

    // Prompt the user for the quantum time in case of Round Robin
    int quantum = QUANTUM;
    if (choice == 3) {
        printf("Enter the quantum time: ");
        scanf("%d", &quantum);
    }

    // Run the selected scheduling algorithm
    switch (choice) {
        case 1:
            fcfs(processes, num_processes);
            break;
        case 2:
            sjf(processes, num_processes);
            break;
        case 3:
            round_robin(processes, num_processes, quantum);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}