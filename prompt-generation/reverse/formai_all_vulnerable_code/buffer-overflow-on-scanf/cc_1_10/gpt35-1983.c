//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODE 100
#define MAX_ELEMENT 200

struct Element {
    int nodeId1, nodeId2;
    double value;
};

int numberOfNodes, numberOfElements;
double nodeVoltages[MAX_NODE];
double elementCurrents[MAX_ELEMENT];
struct Element circuitElements[MAX_ELEMENT];

int main() {
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d",&numberOfNodes);

    printf("Enter the number of elements in the circuit: ");
    scanf("%d",&numberOfElements);

    printf("\nEnter the elements of the circuit-\n");

    for(int i=0; i<numberOfElements; i++) {
        printf("Enter element %d's details -\n",i+1);

        printf("Node 1 ID: ");
        scanf("%d",&circuitElements[i].nodeId1);

        printf("Node 2 ID: ");
        scanf("%d",&circuitElements[i].nodeId2);

        printf("Value: ");
        scanf("%lf",&circuitElements[i].value);
    }

    printf("\nEnter the initial node voltages-\n");

    for(int i=0; i<numberOfNodes; i++) {
        printf("Node %d voltage: ",i+1);
        scanf("%lf",&nodeVoltages[i]);
    }

    printf("\nEnter the element currents-\n");

    for(int i=0; i<numberOfElements; i++) {
        printf("Element %d current: ",i+1);
        scanf("%lf",&elementCurrents[i]);
    }

    printf("\nCircuit Simulation Results:\n\n");

    for(int i=0; i<numberOfNodes; i++) {
        printf("Node %d voltage: %.3lf\n",i+1,nodeVoltages[i]);

        for(int j=0; j<numberOfElements; j++) {
            if(circuitElements[j].nodeId1 == i+1) {
                nodeVoltages[circuitElements[j].nodeId2-1] += elementCurrents[j]*circuitElements[j].value;
            }
            else if(circuitElements[j].nodeId2 == i+1){
                nodeVoltages[circuitElements[j].nodeId1-1] -= elementCurrents[j]*circuitElements[j].value;
            }
        }
    }

    return 0;
}