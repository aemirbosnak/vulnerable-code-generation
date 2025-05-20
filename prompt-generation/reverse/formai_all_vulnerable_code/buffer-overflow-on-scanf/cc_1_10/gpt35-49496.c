//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

// Define the circuit element struct
typedef struct circuitElement {
    char type;
    int node1;
    int node2;
    float value;
} CircuitElement;

// Define the circuit node struct
typedef struct circuitNode {
    int number;
    float voltage;
} CircuitNode;

// Function to read in the circuit elements
void readCircuitElements(CircuitElement* elements, int* numElements) {
    char type;
    int node1, node2;
    float value;
    int num = 0;
    printf("\nEnter circuit elements (-1 to end):\n");
    
    while(1) {
        printf("\nElement %d:\nType (R/L/C/V): ", num+1);
        scanf(" %c", &type);
        
        if(type == 'V') {
            printf("Node 1: ");
            scanf("%d", &node1);
            printf("Node 2: ");
            scanf("%d", &node2);
            printf("Value: ");
            scanf("%f", &value);
            
            elements[num].type = type;
            elements[num].node1 = node1;
            elements[num].node2 = node2;
            elements[num].value = value;
            num++;
        } else if(type == 'R' || type == 'L' || type == 'C') {
            printf("Node 1: ");
            scanf("%d", &node1);
            printf("Node 2: ");
            scanf("%d", &node2);
            printf("Value: ");
            scanf("%f", &value);
            
            elements[num].type = type;
            elements[num].node1 = node1;
            elements[num].node2 = node2;
            elements[num].value = value;
            num++;
        } else if(type == -1) {
            break;
        } else {
            printf("\nInvalid type, try again!\n");
        }
        
        if(num >= MAX_ELEMENTS) {
            printf("\nMax number of elements reached!\n");
            break;
        }
    }
    
    *numElements = num;
}

// Function to get the number of nodes in the circuit
int getNumNodes(CircuitElement* elements, int numElements) {
    int numNodes = -1;
    
    for(int i = 0; i < numElements; i++) {
        if(elements[i].node1 > numNodes) {
            numNodes = elements[i].node1;
        }
        
        if(elements[i].node2 > numNodes) {
            numNodes = elements[i].node2;
        }
    }
    
    return numNodes;
}

// Function to solve the circuit
void solveCircuit(CircuitElement* elements, int numElements, CircuitNode* nodes, int numNodes) {
    // Initialize the nodes to 0 volts
    for(int i = 0; i < numNodes; i++) {
        nodes[i].number = i+1;
        nodes[i].voltage = 0;
    }
    
    // Solve the circuit
    for(int i = 0; i < numNodes; i++) {
        float current = 0;
        
        for(int j = 0; j < numElements; j++) {
            if(elements[j].type == 'V') {
                if(elements[j].node1 == i+1) {
                    current += elements[j].value;
                } else if(elements[j].node2 == i+1) {
                    current -= elements[j].value;
                }
            } else if(elements[j].type == 'R') {
                if(elements[j].node1 == i+1) {
                    current -= (nodes[i].voltage - nodes[elements[j].node2-1].voltage) / elements[j].value;
                } else if(elements[j].node2 == i+1) {
                    current += (nodes[i].voltage - nodes[elements[j].node1-1].voltage) / elements[j].value;
                }
            } else if(elements[j].type == 'L') {
                if(elements[j].node1 == i+1) {
                    current -= ((nodes[i].voltage - nodes[elements[j].node2-1].voltage) / elements[j].value) * 0.001;
                } else if(elements[j].node2 == i+1) {
                    current += ((nodes[i].voltage - nodes[elements[j].node1-1].voltage) / elements[j].value) * 0.001;
                }
            } else if(elements[j].type == 'C') {
                if(elements[j].node1 == i+1) {
                    current -= (nodes[i].voltage - nodes[elements[j].node2-1].voltage) * elements[j].value;
                } else if(elements[j].node2 == i+1) {
                    current += (nodes[i].voltage - nodes[elements[j].node1-1].voltage) * elements[j].value;
                }
            }
        }
        
        nodes[i].voltage = current;
    }
    
    // Print the node voltages
    printf("\nNode voltages:\n");
    for(int i = 0; i < numNodes; i++) {
        printf("Node %d: %f volts\n", nodes[i].number, nodes[i].voltage);
    }
}

int main() {
    CircuitElement elements[MAX_ELEMENTS];
    int numElements;
    CircuitNode nodes[MAX_ELEMENTS];
    int numNodes;
    
    readCircuitElements(elements, &numElements);
    numNodes = getNumNodes(elements, numElements);
    
    solveCircuit(elements, numElements, nodes, numNodes);

    return 0;
}