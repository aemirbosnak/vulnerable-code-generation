//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_BURST_TIME 100
#define MAX_PRIORITY 10

// Structure to hold process information
typedef struct {
    int process_id;
    int burst_time;
    int priority;
} Process;

// Structure to hold queue information
typedef struct {
    Process arr[MAX_PROCESSES];
    int front;
    int rear;
} Queue;

int time_quantum;
Queue ready_queue;
pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to initialize the queue
void init_queue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if queue is empty
int is_queue_empty(Queue *queue) {
    return queue->front == -1 && queue->rear == -1;
}

// Function to check if queue is full
int is_queue_full(Queue *queue) {
    return queue->rear == MAX_PROCESSES - 1;
}

// Function to enqueue a process in the queue
void enqueue(Queue *queue, Process process) {
    if (is_queue_full(queue)) {
        printf("Queue is full, process %d not added.\n", process.process_id);
        return;
    }
    if (is_queue_empty(queue)) {
        queue->front = 0;
    }
    queue->rear += 1;
    queue->arr[queue->rear] = process;
}

// Function to dequeue a process from the queue
Process dequeue(Queue *queue) {
    if (is_queue_empty(queue)) {
        printf("Queue is empty, returning dummy process.\n");
        Process dummy_process;
        dummy_process.process_id = -1;
        return dummy_process;
    }
    if (queue->front == queue->rear) {
        Process dequeued_process = queue->arr[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return dequeued_process;
    }
    Process dequeued_process = queue->arr[queue->front];
    queue->front += 1;
    return dequeued_process;
}

// Function to check if the ready queue has processes with higher priority
int has_higher_priority(Queue *queue, int priority) {
    for (int i = queue->front; i <= queue->rear; i++) {
        if (queue->arr[i].priority < priority) {
            return 1;
        }
    }
    return 0;
}

// Function to execute a process
void execute_process(Process process) {
    printf("Executing process %d for %d seconds.\n", process.process_id, process.burst_time);
    sleep(process.burst_time);
    printf("Process %d completed.\n", process.process_id);
}

// Function to run First Come First Serve algorithm
void fcfs_algorithm(Process *processes, int num_processes) {
    printf("Executing FCFS Algorithm:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("\n");
        execute_process(processes[i]);
    }
}

// Function to run Shortest Job First algorithm
void sjf_algorithm(Process *processes, int num_processes) {
    printf("Executing SJF Algorithm:\n");
    for (int i = 0; i < num_processes; i++) {
        int min_burst_time = MAX_BURST_TIME + 1;
        int min_burst_time_index = -1;
        for (int j = 0; j < num_processes; j++) {
            if (processes[j].burst_time < min_burst_time && processes[j].burst_time != 0) {
                min_burst_time = processes[j].burst_time;
                min_burst_time_index = j;
            }
        }
        printf("\n");
        execute_process(processes[min_burst_time_index]);
        processes[min_burst_time_index].burst_time = 0;
    }
}

// Function to run Priority algorithm
void priority_algorithm(Process *processes, int num_processes) {
    printf("Executing Priority Algorithm:\n");
    for (int priority = MAX_PRIORITY; priority >= 0; priority--) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].priority == priority) {
                printf("\n");
                execute_process(processes[i]);
            }
        }
    }
}

// Function to run Round Robin algorithm
void *rr_algorithm(void *arg) {
    while(!is_queue_empty(&ready_queue)) {
        pthread_mutex_lock(&queue_mutex);
        Process process = dequeue(&ready_queue);
        pthread_mutex_unlock(&queue_mutex);
        if (process.process_id != -1) {
            printf("\n");
            if (process.burst_time > time_quantum) {
                process.burst_time -= time_quantum;
                process.priority += 1;
                pthread_mutex_lock(&queue_mutex);
                enqueue(&ready_queue, process);
                pthread_mutex_unlock(&queue_mutex);
            } else {
                execute_process(process);
            }
        }
    }
    pthread_exit(NULL);
}

// Main function
int main() {
    int num_processes;
    int algorithm_choice;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    Process processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        printf("\nEnter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].priority = rand() % MAX_PRIORITY + 1;
    }
    printf("\nSelect the CPU Scheduling Algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Priority Scheduling\n");
    printf("4. Round Robin (RR)\n");
    scanf("%d", &algorithm_choice);
    if (algorithm_choice == 1) {
        fcfs_algorithm(processes, num_processes);
    } else if (algorithm_choice == 2) {
        sjf_algorithm(processes, num_processes);
    } else if (algorithm_choice == 3) {
        priority_algorithm(processes, num_processes);
    } else if (algorithm_choice == 4) {
        printf("Enter the time quantum for Round Robin: ");
        scanf("%d", &time_quantum);
        init_queue(&ready_queue);
        for (int i = 0; i < num_processes; i++) {
            enqueue(&ready_queue, processes[i]);
        }
        pthread_t thread;
        int rc = pthread_create(&thread, NULL, rr_algorithm, NULL);
        if (rc) {
            printf("Error - pthread_create() return code: %d\n", rc);
            exit(EXIT_FAILURE);
        }
        pthread_join(thread, NULL);
    }
    return 0;
}