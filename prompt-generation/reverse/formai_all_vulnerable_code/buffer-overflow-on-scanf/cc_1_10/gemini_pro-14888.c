//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet CPU Scheduling Algorithms

// The Montagues and Capulets
typedef struct {
  int arrival_time;
  int burst_time;
  int priority;
  int remaining_time;
} process;

// The queue of processes
process queue[100];

// The number of processes
int num_processes;

// The current time
int current_time;

// The CPU scheduling algorithm
int scheduling_algorithm;

// Romeo's algorithm (First-Come, First-Served)
void romeo(void) {
  // Run the processes in the order they arrived
  for (int i = 0; i < num_processes; i++) {
    // Wait for the process to arrive
    while (queue[i].arrival_time > current_time) {
      current_time++;
    }

    // Run the process
    while (queue[i].remaining_time > 0) {
      current_time++;
      queue[i].remaining_time--;
    }
  }
}

// Juliet's algorithm (Shortest Job First)
void juliet(void) {
  // Sort the processes by arrival time
  for (int i = 0; i < num_processes; i++) {
    for (int j = i + 1; j < num_processes; j++) {
      if (queue[i].arrival_time > queue[j].arrival_time) {
        process temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  // Run the processes with the shortest burst time first
  for (int i = 0; i < num_processes; i++) {
    // Wait for the process to arrive
    while (queue[i].arrival_time > current_time) {
      current_time++;
    }

    // Find the process with the shortest burst time
    int shortest_process = i;
    for (int j = i + 1; j < num_processes; j++) {
      if (queue[j].remaining_time < queue[shortest_process].remaining_time && queue[j].arrival_time <= current_time) {
        shortest_process = j;
      }
    }

    // Run the process
    while (queue[shortest_process].remaining_time > 0) {
      current_time++;
      queue[shortest_process].remaining_time--;
    }
  }
}

// Friar Laurence's algorithm (Priority)
void friar_laurence(void) {
  // Sort the processes by priority
  for (int i = 0; i < num_processes; i++) {
    for (int j = i + 1; j < num_processes; j++) {
      if (queue[i].priority < queue[j].priority) {
        process temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  // Run the processes with the highest priority first
  for (int i = 0; i < num_processes; i++) {
    // Wait for the process to arrive
    while (queue[i].arrival_time > current_time) {
      current_time++;
    }

    // Find the process with the highest priority
    int highest_priority_process = i;
    for (int j = i + 1; j < num_processes; j++) {
      if (queue[j].priority > queue[highest_priority_process].priority && queue[j].arrival_time <= current_time) {
        highest_priority_process = j;
      }
    }

    // Run the process
    while (queue[highest_priority_process].remaining_time > 0) {
      current_time++;
      queue[highest_priority_process].remaining_time--;
    }
  }
}

// Main function
int main(void) {
  // Get the number of processes
  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  // Get the arrival time, burst time, and priority of each process
  for (int i = 0; i < num_processes; i++) {
    printf("Enter the arrival time, burst time, and priority of process %d: ", i + 1);
    scanf("%d %d %d", &queue[i].arrival_time, &queue[i].burst_time, &queue[i].priority);
    queue[i].remaining_time = queue[i].burst_time;
  }

  // Get the CPU scheduling algorithm
  printf("Enter the CPU scheduling algorithm (1 for Romeo, 2 for Juliet, 3 for Friar Laurence): ");
  scanf("%d", &scheduling_algorithm);

  // Run the CPU scheduling algorithm
  switch (scheduling_algorithm) {
    case 1:
      romeo();
      break;
    case 2:
      juliet();
      break;
    case 3:
      friar_laurence();
      break;
    default:
      printf("Invalid CPU scheduling algorithm.\n");
      return 1;
  }

  // Print the completion time of each process
  for (int i = 0; i < num_processes; i++) {
    printf("Process %d completed at time %d\n", i + 1, queue[i].remaining_time);
  }

  return 0;
}