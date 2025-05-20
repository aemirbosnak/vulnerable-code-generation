//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int main(void)
{
    int circuit[SIZE][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    int voltage[SIZE];
    int current[SIZE];
    int resistance[SIZE];
    int i;

    printf("Enter the voltage (in volts) and resistance (in ohms) for each element:\n");

    for(i = 0; i < SIZE; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d %d", &voltage[i], &resistance[i]);
    }

    printf("\n");

    //initializing current to 0
    for(i = 0; i < SIZE; i++)
    {
        current[i] = 0;
    }

    printf("Enter the maximum number of iterations: ");
    int maxIterations;
    scanf("%d", &maxIterations);

    int iteration = 0;
    int converged = 0;

    do
    {
        converged = 1;
        printf("Iteration %d:\n", iteration+1);

        for(i = 0; i < SIZE; i++)
        {
            int start = circuit[i][0];
            int end = circuit[i][1];
            int deltaI = (voltage[start] - voltage[end]) / resistance[i];
            current[i] += deltaI;
            voltage[start] -= deltaI;
            voltage[end] += deltaI;
        }

        for(i = 0; i < SIZE; i++)
        {
            printf("Element %d:\n", i+1);
            printf("Voltage: %d\n", voltage[i]);
            printf("Current: %d\n", current[i]);
            printf("Resistance: %d\n", resistance[i]);

            if(abs(current[i]) > 0.01) //check for convergence
            {
                converged = 0;
            }
        }

        printf("\n");

        iteration++;

        if(iteration >= maxIterations)
        {
            printf("Maximum number of iterations reached.\n");
            break;
        }

    } while(!converged);

    printf("Circuit simulation completed.\n");

    return 0;
}