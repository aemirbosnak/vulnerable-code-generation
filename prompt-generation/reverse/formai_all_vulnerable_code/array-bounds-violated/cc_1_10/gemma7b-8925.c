//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turnaround_time;
} Process;

Process processes[MAX_PROCESS];
int schedule[MAX_SCHEDULE_SIZE];

void roundrobin(int quantum) {
  int i = 0;
  int time = 0;
  while (i < MAX_SCHEDULE_SIZE) {
    if (processes[schedule[i]].burst_time > 0) {
      processes[schedule[i]].burst_time--;
      time++;
    } else {
      processes[schedule[i]].waiting_time++;
      i++;
    }
  }

  processes[schedule[i]].turnaround_time = time + processes[schedule[i]].arrival_time;
}

int main() {
  // Initialize processes
  processes[0].process_id = 0;
  processes[0].arrival_time = 0;
  processes[0].burst_time = 5;

  processes[1].process_id = 1;
  processes[1].arrival_time = 2;
  processes[1].burst_time = 4;

  processes[2].process_id = 2;
  processes[2].arrival_time = 3;
  processes[2].burst_time = 3;

  processes[3].process_id = 3;
  processes[3].arrival_time = 4;
  processes[3].burst_time = 2;

  processes[4].process_id = 4;
  processes[4].arrival_time = 5;
  processes[4].burst_time = 1;

  // Create schedule
  schedule[0] = 0;
  schedule[1] = 1;
  schedule[2] = 2;
  schedule[3] = 3;
  schedule[4] = 4;

  // Round robin
  roundrobin(2);

  // Print results
  for (int i = 0; i < MAX_PROCESS; i++) {
    printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
  }

  return 0;
}