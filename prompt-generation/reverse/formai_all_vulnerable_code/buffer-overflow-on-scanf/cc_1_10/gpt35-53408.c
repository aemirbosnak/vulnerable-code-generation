//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Touring
#include <stdio.h>

#define MAX_NODES 50

int main() {
    int numNodes, numResistors, source, destination;
    float resistance[MAX_NODES][MAX_NODES], voltages[MAX_NODES];
    
    printf("Enter the number of nodes in the circuit (minimum 2, maximum 50): ");
    scanf("%d", &numNodes);
    
    printf("Enter the number of resistors in the circuit (maximum %d): ", numNodes*(numNodes-1)/2);
    scanf("%d", &numResistors);
    
    // Initialize resistance matrix to 0
    for(int i=1; i<=numNodes; i++) {
        for(int j=1; j<=numNodes; j++) {
            resistance[i][j] = 0;
        }
    }
    
    // Read resistances from user
    for(int i=0; i<numResistors; i++) {
        printf("Enter the source and destination nodes for resistor %d (separated by whitespace): ", i+1);
        scanf("%d %d", &source, &destination);
        printf("Enter the resistance value for resistor %d: ", i+1);
        scanf("%f", &resistance[source][destination]);
        resistance[destination][source] = resistance[source][destination];
    }
    
    // Print resistance matrix
    printf("\nResistance Matrix:\n");
    for(int i=1; i<=numNodes; i++) {
        for(int j=1; j<=numNodes; j++) {
            printf("%0.2f ", resistance[i][j]);
        }
        printf("\n");
    }
    
    // Read voltages from user
    printf("\nEnter the voltage values for each node (separated by whitespace):\n");
    for(int i=1; i<=numNodes; i++) {
        printf("Node %d: ", i);
        scanf("%f", &voltages[i]);
    }
    
    // Calculate current through each node
    float current[numNodes];
    for(int i=1; i<=numNodes; i++) {
        current[i] = 0;
        for(int j=1; j<=numNodes; j++) {
            current[i] += (voltages[i] - voltages[j]) / resistance[i][j];
        }
    }
    
    // Print current values for each node
    printf("\nCurrent values for each node:\n");
    for(int i=1; i<=numNodes; i++) {
        printf("Node %d: %0.2f\n", i, current[i]);
    }
    
    return 0;
}