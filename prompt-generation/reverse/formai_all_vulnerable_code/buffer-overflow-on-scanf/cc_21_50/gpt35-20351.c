//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>

// Process structure with attributes like arrival time, burst time, completion time, waiting time, and turnaround time
struct Process {
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int numProcesses, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    struct Process processes[numProcesses];
    struct Process temp;

    // Input arrival and burst time for each process
    for(int i = 0; i < numProcesses; i++) {
        printf("\nProcess %d:\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
    }

    // Input time quantum for Round Robin scheduling
    printf("\nEnter the time quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);

    // Sort the processes based on arrival time using Bubble Sort algorithm
    for(int i = 0; i < numProcesses - 1; i++) {
        for(int j = i + 1; j < numProcesses; j++) {
            if(processes[j].arrivalTime < processes[i].arrivalTime) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int currentProcess = 0;
    int currentTime = 0;
    int remainingBurstTime[numProcesses];
    int isCompleted[numProcesses];

    // Initialize remainingBurstTime to burst time of each process and isCompleted to false for each process
    for(int i = 0; i < numProcesses; i++) {
        remainingBurstTime[i] = processes[i].burstTime;
        isCompleted[i] = 0;
    }

    // Implement Round Robin scheduling algorithm
    while(1) {
        int flag = 1;
        for(int i = 0; i < numProcesses; i++) {
            if(remainingBurstTime[i] > 0) {
                flag = 0;
                if(remainingBurstTime[i] > quantum) {
                    currentTime += quantum;
                    remainingBurstTime[i] -= quantum;
                } else {
                    currentTime += remainingBurstTime[i];
                    processes[i].completionTime = currentTime;
                    remainingBurstTime[i] = 0;
                    isCompleted[i] = 1;
                }
            }
        }
        if(flag == 1) {
            break;
        }
    }

    // Calculate waiting time and turnaround time for each process
    for(int i = 0; i < numProcesses; i++) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }

    // Print the Gantt Chart for Round Robin scheduling
    printf("\nGantt Chart for Round Robin Scheduling:\n");
    int totalTime = processes[numProcesses - 1].completionTime - processes[0].arrivalTime;
    for(int i = 0; i < totalTime; i+=quantum) {
        printf("+");
        for(int j = 0; j < numProcesses; j++) {
            if(processes[j].arrivalTime <= i) {
                if(isCompleted[j] == 1) {
                    printf("%*c", quantum, ' ');
                } else {
                    printf("%*d", quantum, remainingBurstTime[j]);
                }
                printf("+");
            } else {
                printf("%*c", quantum + 1, ' ');
            }
        }
        printf("\n|");
        for(int j = 0; j < numProcesses; j++) {
            if(processes[j].arrivalTime <= i) {
                printf("%*c", quantum/2, ' ');
                printf("P%d", j+1);
                printf("%*c|", quantum/2, ' ');
            } else {
                printf("%*c", quantum + 1, ' ');
            }
        }
        printf("\n");
    }
    printf("+");
    for(int j = 0; j < numProcesses; j++) {
        if(processes[j].arrivalTime <= totalTime) {
            printf("%*c", quantum, ' ');
            printf("+");
        } else {
            printf("%*c", quantum + 1, ' ');
        }
    }
    printf("\n");

    // Print the Process Table with attributes like arrival time, burst time, completion time, waiting time, and turnaround time
    printf("\nProcess Table:\n");
    printf("+-----+--------------+------------+--------------+---------------+\n");
    printf("| PID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time |\n");
    printf("+-----+--------------+------------+--------------+---------------+\n");
    for(int i = 0; i < numProcesses; i++) {
        printf("| %2d  |      %2d      |     %2d     |       %2d       |       %2d      |        %2d        |\n",
            i+1, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime,
            processes[i].waitingTime, processes[i].turnaroundTime);
        printf("+-----+--------------+------------+--------------+---------------+\n");
    }
    return 0;
}