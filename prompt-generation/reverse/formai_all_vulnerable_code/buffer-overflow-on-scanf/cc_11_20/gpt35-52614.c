//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
// Invasive C Classical Circuit Simulator Example Program

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_VOLTAGE 10.0
#define MIN_VOLTAGE -10.0

float nodeVoltage[MAX_NODES + 1];
float resistorValues[MAX_NODES][MAX_NODES];

int main()
{
    int numNodes, numResistors;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &numNodes);

    printf("Enter the number of resistors in the circuit: ");
    scanf("%d", &numResistors);

    printf("Enter the values of the resistors:\n");
    for (int i = 1; i <= numResistors; i++)
    {
        printf("Resistance %d: ", i);
        for (int j = 1; j <= numNodes; j++)
        {
            printf("Resistance %d to Node %d: ", i, j);
            scanf("%f", &resistorValues[i][j]);
        }
    }

    printf("Enter the known node voltages:\n");
    for (int i = 1; i <= numNodes; i++)
    {
        printf("Node %d: ", i);
        scanf("%f", &nodeVoltage[i]);
    }

    for (int i = 1; i <= numNodes; i++)
    {
        for (int j = 1; j <= numNodes; j++)
        {
            if (i == j)
            {
                resistorValues[i][j] = 1;
            }
            else
            {
                resistorValues[i][j] = 0;
            }
        }
    }

    printf("Solving the circuit...\n");
    for (int i = 1; i <= numNodes; i++)
    {
        for (int j = 1; j <= numResistors; j++)
        {
            if (resistorValues[i][j])
            {
                for (int k = 1; k <= numNodes; k++)
                {
                    resistorValues[k][j] /= resistorValues[i][j];
                }
                nodeVoltage[i] /= resistorValues[i][j];
                resistorValues[i][j] = 1;
            }
        }
    }

    for (int i = numNodes; i > 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            float factor = resistorValues[i - 1][j];
            for (int k = 1; k <= numResistors; k++)
            {
                resistorValues[i - 1][k] -= resistorValues[j][k] * factor;
            }
            nodeVoltage[i - 1] -= nodeVoltage[j] * factor;
        }
    }

    printf("The voltage at each node of the circuit is:\n");
    for (int i = 1; i <= numNodes; i++)
    {
        printf("Node %d: %f\n", i, nodeVoltage[i]);
    }

    return 0;
}