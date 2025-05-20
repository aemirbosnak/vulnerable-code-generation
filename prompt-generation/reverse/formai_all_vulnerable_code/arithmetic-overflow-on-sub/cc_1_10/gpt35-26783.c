//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

struct process {
   int pid; // process id
   int burstTime; // burst time required by the process
   int arrivalTime; // arrival time of the process
   int priority; // priority of the process
   int waitingTime; // waiting time of the process
   int turnaroundTime; // turnaround time of the process
};

// function to sort the processes based on arrival time
void sortArrivalTime(struct process *p, int n) {
   struct process temp;
   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         if (p[i].arrivalTime > p[j].arrivalTime) {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
         }
      }
   }
}

// function to sort the processes based on burst time
void sortBurstTime(struct process *p, int n) {
   struct process temp;
   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         if (p[i].burstTime > p[j].burstTime) {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
         }
      }
   }
}

// function to sort the processes based on priority
void sortPriority(struct process *p, int n) {
   struct process temp;
   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         if (p[i].priority > p[j].priority) {
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
         }
      }
   }
}

// function to calculate waiting and turnaround time of each process
void calculateTime(struct process *p, int n) {
   int totalWaitingTime = 0, totalTurnaroundTime = 0, currentTime = 0;
   for (int i = 0; i < n; i++) {
      if (p[i].arrivalTime > currentTime) {
         currentTime = p[i].arrivalTime;
      }
      p[i].waitingTime = currentTime - p[i].arrivalTime;
      totalWaitingTime += p[i].waitingTime;
      currentTime += p[i].burstTime;
      p[i].turnaroundTime = currentTime - p[i].arrivalTime;
      totalTurnaroundTime += p[i].turnaroundTime;
   }
   printf("\nAverage Waiting Time: %f", (float) totalWaitingTime / n);
   printf("\nAverage Turnaround Time: %f", (float) totalTurnaroundTime / n);
}

// function to print the details of each process
void printDetails(struct process *p, int n) {
   printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
   for (int i = 0; i < n; i++) {
      printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burstTime, p[i].arrivalTime, p[i].priority, p[i].waitingTime, p[i].turnaroundTime);
   }
}

int main() {
   int n;
   printf("Enter the number of processes: ");
   scanf("%d", &n);
   struct process *p = (struct process *) malloc(n * sizeof(struct process));
   for (int i = 0; i < n; i++) {
      printf("\nEnter details of process %d\n", i + 1);
      printf("Process ID: ");
      scanf("%d", &p[i].pid);
      printf("Burst Time: ");
      scanf("%d", &p[i].burstTime);
      printf("Arrival Time: ");
      scanf("%d", &p[i].arrivalTime);
      printf("Priority: ");
      scanf("%d", &p[i].priority);
   }
   printf("\nMenu:\n");
   printf("1. First Come First Serve\n");
   printf("2. Shortest Job First\n");
   printf("3. Priority Scheduling\n");
   int choice;
   printf("\nEnter your choice: ");
   scanf("%d", &choice);
   switch (choice) {
      case 1: sortArrivalTime(p, n);
              calculateTime(p, n);
              printDetails(p, n);
              break;
      case 2: sortBurstTime(p, n);
              calculateTime(p, n);
              printDetails(p, n);
              break;
      case 3: sortPriority(p, n);
              calculateTime(p, n);
              printDetails(p, n);
              break;
      default: printf("\nInvalid Choice\n");
   }
   free(p);
   return 0;
}