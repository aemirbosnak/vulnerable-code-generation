//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int quantum = 0, currentProcess = 0, readyQueue[10], processQueue[10], i, timeSlice = 0, finished = 0;
    char processName[20];

    // Initialize the queues
    for(i = 0; i < 10; i++)
    {
        readyQueue[i] = 0;
        processQueue[i] = 0;
    }

    // Create a process
    printf("Enter process name: ");
    scanf("%s", processName);

    // Add the process to the queue
    processQueue[currentProcess] = processName;
    currentProcess++;

    // Start the timer
    timeSlice = 10;
    finished = 0;

    // Begin the scheduling loop
    while(!finished)
    {
        // Check if the process is finished
        if(processQueue[currentProcess - 1] == NULL)
        {
            finished = 1;
        }

        // Increment the quantum
        quantum++;

        // If the quantum is greater than the time slice, move the process to the ready queue
        if(quantum > timeSlice)
        {
            readyQueue[currentProcess - 1] = processQueue[currentProcess - 1];
            processQueue[currentProcess - 1] = NULL;
            currentProcess--;
            quantum = 0;
        }

        // If the process is in the ready queue, execute it
        if(readyQueue[currentProcess] != NULL)
        {
            printf("Process: %s, Quantum: %d\n", readyQueue[currentProcess], quantum);
            timeSlice = 0;
        }

        // Increment the time slice
        timeSlice++;
    }

    // Print the final state of the system
    printf("All processes have finished execution.\n");
}