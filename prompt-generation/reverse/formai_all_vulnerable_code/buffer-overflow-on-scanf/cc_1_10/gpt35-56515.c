//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to calculate waiting and turnaround time for all processes
void calculateTimes(int burstTimes[], int arrivalTimes[], int waitTimes[], int turnTimes[], int numProcesses) {
    int completionTimes[numProcesses]; // Array to store completion times
    int remainingTime[numProcesses]; // Array to store remaining CPU burst times
    int completed[numProcesses]; // Array to keep track of completed processes
    
    // Initialize remaining time array and completed array
    for (int i = 0; i < numProcesses; i++) {
        remainingTime[i] = burstTimes[i];
        completed[i] = 0;
    }
    
    int currentTime = 0; // Current time initialized to 0
    int totalWaitTime = 0; // Total waiting time initialized to 0
    int totalTurnTime = 0; // Total turnaround time initialized to 0
    int numCompleted = 0; // Number of completed processes initialized to 0
    
    while (numCompleted != numProcesses) { // Loop until all processes are completed
        int shortestJobIndex = -1; // Set shortest job index to -1
        int shortestJobTime = 99999; // Set shortest job time to a high number
        
        // Find the shortest job that has arrived
        for (int i = 0; i < numProcesses; i++) {
            if (arrivalTimes[i] <= currentTime && completed[i] == 0 && remainingTime[i] < shortestJobTime) {
                shortestJobIndex = i;
                shortestJobTime = remainingTime[i];
            }
        }
        
        // If a job is found, update remaining time, completion time, wait time, and turn time
        if (shortestJobIndex != -1) {
            remainingTime[shortestJobIndex]--; // Decrement remaining time
            currentTime++; // Increment current time
            if (remainingTime[shortestJobIndex] == 0) { // If remaining time is 0, process is completed
                completed[shortestJobIndex] = 1;
                numCompleted++;
                completionTimes[shortestJobIndex] = currentTime;
                waitTimes[shortestJobIndex] = completionTimes[shortestJobIndex] - arrivalTimes[shortestJobIndex] - burstTimes[shortestJobIndex];
                turnTimes[shortestJobIndex] = completionTimes[shortestJobIndex] - arrivalTimes[shortestJobIndex];
                totalWaitTime += waitTimes[shortestJobIndex];
                totalTurnTime += turnTimes[shortestJobIndex];
            }
        }
        else { // If no process has arrived, increment current time
            currentTime++;
        }
    }
    
    // Print the waiting and turnaround times for each process
    printf("Process\tBurst Time\tArrival Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i, burstTimes[i], arrivalTimes[i], waitTimes[i], turnTimes[i]);
    }
    
    // Print the average waiting and turnaround times for all processes
    printf("Average waiting time: %.2f\n", (float) totalWaitTime / numProcesses);
    printf("Average turnaround time: %.2f\n", (float) totalTurnTime / numProcesses);
}

int main() {
    int numProcesses; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    
    int burstTimes[numProcesses]; // Array to store CPU burst times
    int arrivalTimes[numProcesses]; // Array to store arrival times
    int waitTimes[numProcesses]; // Array to store waiting times
    int turnTimes[numProcesses]; // Array to store turnaround times
    
    // Prompt user to enter CPU burst times and arrival times for each process
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter CPU burst time for P%d: ", i);
        scanf("%d", &burstTimes[i]);
        printf("Enter arrival time for P%d: ", i);
        scanf("%d", &arrivalTimes[i]);
        printf("\n");
    }
    
    sort(arrivalTimes, numProcesses); // Sort arrival times in ascending order
    
    calculateTimes(burstTimes, arrivalTimes, waitTimes, turnTimes, numProcesses); // Calculate waiting and turnaround times
    
    return 0;
}