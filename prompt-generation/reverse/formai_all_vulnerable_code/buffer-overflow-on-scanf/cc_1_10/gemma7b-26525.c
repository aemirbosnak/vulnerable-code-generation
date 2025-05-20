//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void schedule()
{
    int i, j, k, quantum, current, next, wait, time;
    char name[MAX];

    // Create a circular queue to store process information
    struct node
    {
        char name[MAX];
        int priority, time, remainingTime, next;
    } node[MAX];

    // Initialize the queue
    for (i = 0; i < MAX; i++)
    {
        node[i].next = -1;
    }

    // Get the quantum time
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    // Get the current process
    printf("Enter the name of the current process: ");
    scanf("%s", name);

    // Search for the process in the queue
    current = -1;
    for (i = 0; i < MAX; i++)
    {
        if (strcmp(node[i].name, name) == 0)
        {
            current = i;
        }
    }

    // If the process is found, start the scheduling algorithm
    if (current != -1)
    {
        next = current;
        wait = 0;
        time = quantum;

        // While the process has remaining time and the quantum time is not over
        while (node[next].remainingTime > 0 && time > 0)
        {
            // Subtract the quantum time from the remaining time
            node[next].remainingTime -= time;

            // Increment the wait time
            wait++;

            // Move to the next process in the queue
            next = node[next].next;

            // Reset the time
            time = quantum;
        }

        // Print the process completion status
        printf("Process %s completed with %d wait time\n", name, wait);
    }
    else
    {
        printf("Process not found.\n");
    }
}

int main()
{
    schedule();

    return 0;
}