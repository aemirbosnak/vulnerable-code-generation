//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>

// Enum to represent the processes state
enum ProcessState {
    READY,
    RUNNING,
    WAITING,
    FINISHED
};

// Struct to represent a process
struct Process {
    int id;
    int cpuBurst;
    int priority;
    int timeQuantum;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    enum ProcessState state;
};

// Struct to represent the CPU scheduler
struct CPUScheduler {
    int currentTime;
    int timeSlice;
};

// Function to create a new process
struct Process createProcess(int id, int cpuBurst, int priority, int timeQuantum, int arrivalTime) {
    struct Process process;
    process.id = id;
    process.cpuBurst = cpuBurst;
    process.priority = priority;
    process.timeQuantum = timeQuantum;
    process.arrivalTime = arrivalTime;
    process.waitingTime = 0;
    process.turnaroundTime = 0;
    process.state = READY;
    return process;
}

// Function to run the Round Robin CPU scheduling algorithm
void roundRobin(struct Process processes[], int n, struct CPUScheduler scheduler) {
    // Initialize the ready queue
    struct Process readyQueue[n];
    int front = -1, rear = -1;

    // Initialize the time remaining for each process
    int timeRemaining[n];
    for(int i = 0; i < n; i++) {
        timeRemaining[i] = processes[i].cpuBurst;
    }

    // Run the algorithm until all processes finish execution
    while(1) {
        // Check if all processes are finished execution
        int finished = 1;
        for(int i = 0; i < n; i++) {
            if(processes[i].state != FINISHED) {
                finished = 0;
                break;
            }
        }

        if(finished) {
            break;
        }

        // Enqueue newly arrived processes to the ready queue
        for(int i = 0; i < n; i++) {
            if(processes[i].state == READY && processes[i].arrivalTime <= scheduler.currentTime) {
                if(front == -1) {
                    front = 0;
                }
                rear++;
                readyQueue[rear] = processes[i];
                processes[i].state = WAITING;
            }
        }

        // Dequeue the process from the front of ready queue if any
        if(front != -1) {
            struct Process runningProcess = readyQueue[front];
            front++;

            // Run the process for the time slice
            int timeSpent = 0;
            while(timeSpent < scheduler.timeSlice && timeRemaining[runningProcess.id] > 0) {
                scheduler.currentTime++;
                timeSpent++;
                timeRemaining[runningProcess.id]--;
            }

            // Check if the process has finished execution
            if(timeRemaining[runningProcess.id] == 0) {
                runningProcess.state = FINISHED;
                runningProcess.turnaroundTime = scheduler.currentTime - runningProcess.arrivalTime;
            }
            // If the process still has time remaining, enqueue it to the end of ready queue
            else {
                runningProcess.state = READY;
                rear++;
                readyQueue[rear] = runningProcess;
            }
        } else {
            scheduler.currentTime++;
        }
    }

    // Calculate the waiting time for each process
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    for(int i = 0; i < n; i++) {
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].cpuBurst;
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    // Print the results
    float averageWaitingTime = (float) totalWaitingTime / n;
    float averageTurnaroundTime = (float) totalTurnaroundTime / n;
    printf("\nRound Robin Scheduling Algorithm\n");
    printf("==================================\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].cpuBurst, processes[i].waitingTime, processes[i].turnaroundTime);
    }
    printf("Average waiting time: %.2f\n", averageWaitingTime);
    printf("Average turnaround time: %.2f\n", averageTurnaroundTime);
}

int main() {
    struct Process p1 = createProcess(0, 10, 2, 4, 0);
    struct Process p2 = createProcess(1, 5, 1, 3, 1);
    struct Process p3 = createProcess(2, 8, 3, 5, 2);
    struct Process processes[] = {p1, p2, p3};
    int n = sizeof(processes) / sizeof(processes[0]);
    struct CPUScheduler scheduler = {0, 2};
    roundRobin(processes, n, scheduler);
    return 0;
}