//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
// Cheerful C CPU Scheduling Algorithm Example Program
#include <stdio.h>
#include <stdlib.h>

struct Process {
  int id;
  int arrival_time;
  int burst_time;
  int priority;
};

struct Process *processes[10];
int num_processes = 0;

void add_process(int id, int arrival_time, int burst_time, int priority) {
  processes[num_processes] = (struct Process *)malloc(sizeof(struct Process));
  processes[num_processes]->id = id;
  processes[num_processes]->arrival_time = arrival_time;
  processes[num_processes]->burst_time = burst_time;
  processes[num_processes]->priority = priority;
  num_processes++;
}

void run_process(struct Process *p) {
  printf("Running process %d\n", p->id);
  sleep(p->burst_time);
  printf("Finished running process %d\n", p->id);
}

void run_scheduler() {
  int current_time = 0;
  while (num_processes > 0) {
    for (int i = 0; i < num_processes; i++) {
      if (processes[i]->arrival_time <= current_time) {
        run_process(processes[i]);
        num_processes--;
        break;
      }
    }
    current_time++;
  }
}

int main() {
  add_process(1, 0, 5, 5);
  add_process(2, 2, 3, 3);
  add_process(3, 3, 2, 2);
  add_process(4, 4, 4, 4);
  add_process(5, 6, 1, 1);
  run_scheduler();
  return 0;
}