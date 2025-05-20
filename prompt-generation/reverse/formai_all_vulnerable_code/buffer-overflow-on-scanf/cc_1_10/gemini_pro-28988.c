//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Global variables
int boot_time;
int num_processes;
int *process_times;

// Function to read the boot time and process times from the user
void read_input() {
  printf("Enter the boot time (in seconds): ");
  scanf("%d", &boot_time);

  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);

  process_times = (int *)malloc(sizeof(int) * num_processes);

  for (int i = 0; i < num_processes; i++) {
    printf("Enter the time required by process %d (in seconds): ", i);
    scanf("%d", &process_times[i]);
  }
}

// Function to sort the processes in ascending order of their times
void sort_processes() {
  for (int i = 0; i < num_processes; i++) {
    for (int j = i + 1; j < num_processes; j++) {
      if (process_times[i] > process_times[j]) {
        int temp = process_times[i];
        process_times[i] = process_times[j];
        process_times[j] = temp;
      }
    }
  }
}

// Function to calculate the optimal schedule for the processes
void calculate_schedule() {
  int current_time = boot_time;

  for (int i = 0; i < num_processes; i++) {
    printf("Process %d starts at time %d and finishes at time %d\n", i, current_time, current_time + process_times[i]);
    current_time += process_times[i];
  }
}

// Main function
int main() {
  // Read the input from the user
  read_input();

  // Sort the processes in ascending order of their times
  sort_processes();

  // Calculate the optimal schedule for the processes
  calculate_schedule();

  // Free the allocated memory
  free(process_times);

  return 0;
}