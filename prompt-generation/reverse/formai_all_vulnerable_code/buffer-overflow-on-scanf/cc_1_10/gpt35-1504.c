//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// define process structure
typedef struct {
    int pid;      // process ID
    int arrival;  // arrival time
    int burst;    // burst time
    int priority; // priority
} Process;

// define function to read process data
void readProcesses(Process *processes, int n) {
    printf("Enter process details (pid, arrival time, burst time, priority):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrival, &processes[i].burst, &processes[i].priority);
    }
}

// define function to print process data
void printProcesses(Process *processes, int n) {
    printf("PID\tArrival\tBurst\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival, processes[i].burst, processes[i].priority);
    }
}

// define function to sort processes by arrival time
void sortByArrival(Process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival > processes[j].arrival) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// define function to schedule processes using Multilevel Feedback Queue algorithm
void multilevelFeedbackQueue(Process *processes, int n) {
    // define constants for quantum and number of queues
    const int quantum[] = {6, 10, 16};
    const int numQueues = 3;

    // define variables for queue and time quantum
    int queue = 0;
    int timeQuantum = quantum[queue];

    // define variables for process status and completion time
    int status[n];
    int completionTime[n];

    // initialize status and completion time arrays
    for (int i = 0; i < n; i++) {
        status[i] = 0;          // 0 = not started, 1 = running, 2 = completed
        completionTime[i] = 0;  // 0 = not completed
    }

    // loop until all processes are completed
    int currentTime = 0;
    while (1) {
        // check if all processes are completed
        int allCompleted = 1;
        for (int i = 0; i < n; i++) {
            if (status[i] != 2) {
                allCompleted = 0;
                break;
            }
        }
        if (allCompleted == 1) {
            break;
        }

        // check if any process has arrived
        int processArrived = 0;
        for (int i = 0; i < n; i++) {
            if (status[i] == 0 && processes[i].arrival <= currentTime) {
                processArrived = 1;
                break;
            }
        }

        // if process has arrived,loop through processes and find the one with highest priority
        if (processArrived == 1) {
            int highestPriority = -1;
            int highestPriorityProcess = -1;
            for (int i = 0; i < n; i++) {
                if (status[i] == 0 && processes[i].arrival <= currentTime) {
                    if (processes[i].priority > highestPriority) {
                        highestPriority = processes[i].priority;
                        highestPriorityProcess = i;
                    }
                }
            }
            // set the status of the process to running
            status[highestPriorityProcess] = 1;
        }

        // process running process according to the queue it is in
        int processRunning = -1;
        for (int i = 0; i < n; i++) {
            if (status[i] == 1) {
                processRunning = i;
                break;
            }
        }
        if (processRunning != -1) {
            if (processes[processRunning].burst > timeQuantum) {
                processes[processRunning].burst -= timeQuantum;
                currentTime += timeQuantum;
                timeQuantum = quantum[++queue % numQueues];
            } else {
                completionTime[processRunning] = currentTime + processes[processRunning].burst;
                status[processRunning] = 2;
                timeQuantum = quantum[0];
            }
        } else {
            currentTime++;
            timeQuantum = quantum[0];
        }
    }

    // print completion time for each process
    printf("Completion times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: %d\n", processes[i].pid, completionTime[i]);
    }
}

// main function
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));
    readProcesses(processes, n);
    printProcesses(processes, n);
    sortByArrival(processes, n);
    multilevelFeedbackQueue(processes, n);

    return 0;
}