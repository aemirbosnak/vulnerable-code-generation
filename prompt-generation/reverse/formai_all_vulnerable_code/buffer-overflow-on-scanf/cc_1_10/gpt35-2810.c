//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>

#define MAX_NODES 20
#define MAX_TIME 10

int main()
{
    int C[MAX_NODES][MAX_NODES] = {{0}};   // Capacitance matrix
    int R[MAX_NODES][MAX_NODES] = {{0}};   // Resistance matrix
    float V[MAX_NODES] = {0};              // Voltage array
    float I[MAX_NODES] = {0};              // Current array
    float dV[MAX_NODES] = {0};             // Change in voltage array
    float dI[MAX_NODES] = {0};             // Change in current array

    int num_nodes, num_elements;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of elements in the circuit: ");
    scanf("%d", &num_elements);

    printf("Enter element data (node1, node2, resistance, capacitance):\n");
    for(int i=0; i<num_elements; i++)
    {
        int n1, n2, r, c;
        scanf("%d %d %d %d", &n1, &n2, &r, &c);
        C[n1][n2] += c;
        C[n2][n1] += c;
        R[n1][n2] += r;
        R[n2][n1] += r;
    }

    printf("Enter initial conditions (voltage of each node):\n");
    for(int i=0; i<num_nodes; i++)
    {
        scanf("%f", &V[i]);
    }

    printf("Simulating circuit for %d seconds...\n", MAX_TIME);

    for(int t=1; t<=MAX_TIME; t++)
    {
        // Calculate change in voltage and current for each node
        for(int i=0; i<num_nodes; i++)
        {
            for(int j=0; j<num_nodes; j++)
            {
                dV[i] += (I[j] * R[i][j]) / C[i][j];
                dI[i] += (V[j] - V[i]) / R[i][j];
            }
        }

        // Update voltage and current for each node
        for(int i=0; i<num_nodes; i++)
        {
            V[i] = V[i] + dV[i];
            I[i] = I[i] + dI[i];
        }

        // Reset change in voltage and current arrays
        for(int i=0; i<num_nodes; i++)
        {
            dV[i] = 0;
            dI[i] = 0;
        }
    }

    printf("Simulation completed. Final voltage of nodes:\n");
    for(int i=0; i<num_nodes; i++)
    {
        printf("Node %d: %f\n", i, V[i]);
    }

    return 0;
}