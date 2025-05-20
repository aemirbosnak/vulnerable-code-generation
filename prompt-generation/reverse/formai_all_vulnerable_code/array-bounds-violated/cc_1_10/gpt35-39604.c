//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: happy
#include <stdio.h>

#define MAX_NODES 10
#define MAX_EDGES 15

int adjMatrix[MAX_NODES][MAX_NODES] = {0};
int nodeValues[MAX_NODES] = {0};

void addEdge(int fromNode, int toNode) {
    adjMatrix[fromNode][toNode] = 1;
}

void simulateCircuit(int inputNode) {
    int outputNode = -1;

    // Find output node
    for (int i = 0; i < MAX_NODES; i++) {
        if (adjMatrix[i][inputNode] == 1) {
            outputNode = i;
            break;
        }
    }

    // If output node exists, simulate circuit
    if (outputNode != -1) {
        int queue[MAX_NODES];
        int front = 0, rear = 0;

        queue[rear++] = inputNode;

        while (front < rear) {
            int currentNode = queue[front++];

            // If node has not been visited, simulate its value
            if (nodeValues[currentNode] == 0) {
                int value = 0;
                for (int i = 0; i < MAX_NODES; i++) {
                    if (adjMatrix[currentNode][i] == 1) {
                        value += nodeValues[i];
                    }
                }
                nodeValues[currentNode] = value % 2;
            }

            // Add adjacent nodes to the queue
            for (int i = 0; i < MAX_NODES; i++) {
                if (adjMatrix[currentNode][i] == 1) {
                    queue[rear++] = i;
                }
            }
        }
    }

    printf("Output node value: %d\n", nodeValues[outputNode]);
}

int main() {
    // Example circuit: XOR gate
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    // Input values
    nodeValues[0] = 1;
    nodeValues[1] = 0;

    // Simulate circuit
    simulateCircuit(0);

    return 0;
}