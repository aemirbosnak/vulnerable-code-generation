//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Welcome to the Airport Baggage Handling Simulation!\n");

    // Initiate variables
    int numberOfBaggage, secondsToProcess, i, j;
    bool isQueueFull;
    int queue[100];
    int waitingTime[100];

    // Ask user for input values
    printf("Enter the number of baggage to process: ");
    scanf("%d", &numberOfBaggage);
    printf("Enter the seconds to process each baggage: ");
    scanf("%d", &secondsToProcess);

    // Start processing the baggage
    for (i = 1; i <= numberOfBaggage; i++)
    {
        isQueueFull = true;

        // Check if the queue is full
        for (j = 0; j < 100; j++)
        {
            if (queue[j] == 0)
            {
                // Add baggage to the queue
                queue[j] = i;
                isQueueFull = false;
                break;
            }
        }

        // If the queue is full, wait for some time and try again
        if (isQueueFull)
        {
            printf("The queue is full. Please wait for a baggage to be processed.\n");
            int index = 0;
            while (queue[index] != 0)
            {
                waitingTime[queue[index]] += secondsToProcess;
                queue[index] = 0;
                index++;
            }
            queue[0] = i;
        }
        else
        {
            // Process the baggage
            printf("Processing Baggage %d.\n", i);
            waitingTime[i] = 0;
            int index = 0;
            while (queue[index] != 0)
            {
                waitingTime[queue[index]] += secondsToProcess;
                queue[index] = 0;
                index++;
            }
        }
    }

    // Print the result
    printf("Baggage No.\tWaiting Time\n");
    for (i = 1; i <= numberOfBaggage; i++)
    {
        printf("%d\t\t%d seconds\n", i, waitingTime[i]);
    }

    return 0;
}