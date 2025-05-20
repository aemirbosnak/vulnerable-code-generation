//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define the structure for a process */
typedef struct process_t {
    int pid; /* Process ID */
    int arrival_time; /* Arrival time */
    int burst_time; /* Burst time */
    int priority; /* Priority level */
} process_t;

/* Define the structure for a node in the ready queue */
typedef struct node_t {
    process_t process;
    struct node_t* next;
} node_t;

node_t* ready_queue = NULL; /* Initialize an empty ready queue */

/* Function to add a process to the ready queue */
void add_process(process_t process) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t)); /* Allocate memory for the new node */
    new_node->process = process; /* Assign the process to the new node */
    new_node->next = NULL;
    if (ready_queue == NULL) { /* If the ready queue is empty */
        ready_queue = new_node; /* The new node becomes the head of the queue */
    } else { /* If the ready queue is not empty */
        node_t* current_node = ready_queue;
        while (current_node->next != NULL) {
            current_node = current_node->next; /* Traverse the queue until the last node */
        }
        current_node->next = new_node; /* Assign the new node as the next node of the last node */
    }
}

/* Function to remove the process with the highest priority from the ready queue */
process_t remove_process() {
    node_t* highest_priority_node = ready_queue;
    node_t* current_node = ready_queue->next;
    while (current_node != NULL) {
        if (current_node->process.priority < highest_priority_node->process.priority) {
            highest_priority_node = current_node; /* Update the highest priority node */
        }
        current_node = current_node->next;
    }
    process_t process_to_remove = highest_priority_node->process;
    if (highest_priority_node == ready_queue) { /* If the highest priority node is the head of the queue */
        ready_queue = ready_queue->next; /* Remove the head of the queue */
    } else {
        current_node = ready_queue;
        while (current_node->next != highest_priority_node) {
            current_node = current_node->next; /* Traverse the queue until the node before the highest priority node */
        }
        current_node->next = highest_priority_node->next; /* Remove the highest priority node from the queue */
    }
    free(highest_priority_node); /* Deallocate the memory used by the node */
    return process_to_remove;
}

/* Function to check if the ready queue is empty */
bool is_queue_empty() {
    return ready_queue == NULL;
}

int main() {
    int num_processes, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    process_t processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d", &processes[i].priority);
        processes[i].pid = i+1;
        add_process(processes[i]); /* Add the process to the ready queue */
    }
    int current_time = 0;
    while (!is_queue_empty()) { /* While there are still processes in the ready queue */
        process_t current_process = remove_process(); /* Remove the process with the highest priority */
        int remaining_burst_time = current_process.burst_time - quantum;
        if (remaining_burst_time <= 0) { /* If the process completes within the quantum */
            current_time += current_process.burst_time; /* Increment the current time by the burst time */
            printf("Process %d completes at time %d\n", current_process.pid, current_time);
        } else { /* If the process does not complete within the quantum */
            current_time += quantum; /* Increment the current time by the quantum */
            current_process.burst_time = remaining_burst_time;
            add_process(current_process); /* Add the process back to the ready queue */
        }
    }
    return 0;
}