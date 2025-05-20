//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 50

// Define the Circuit components data structure
struct CircuitComponent {
    int type;  //Type of the component 
    float value; //Value of the component 
    int node1; //Node1 of the component 
    int node2; //Noe2 of the component 
};

typedef struct CircuitComponent CircuitComponent;

// Define the Node data structure
struct Node {
    float voltage; // Voltage of the node
    int components[MAXSIZE];  //Components connected to the node 
    int numComponents; // Number of components connected to the node 
};

typedef struct Node Node;

// Define the circuit data structure
struct Circuit {
    Node *nodes; // List of all the nodes in the circuit
    int numNodes; //Number of nodes in the circuit 
    CircuitComponent *components; //List of all the components in the circuit
    int numComponents; //Number of components in the circuit
};

typedef struct Circuit Circuit;

//Initializing the circuit
Circuit initializeCircuit() {
    Circuit circuit;
    circuit.nodes = (Node*)malloc(sizeof(Node) * MAXSIZE); //Allocate memory for list of all the nodes in the circuit
    circuit.numNodes = 0;
    circuit.components = (CircuitComponent*)malloc(sizeof(CircuitComponent) * MAXSIZE); //Allocate memory for the list of all the components in the circuit
    circuit.numComponents = 0;
    return circuit;
}

// Function to add a component to the circuit
void addComponent(Circuit *circuit, int type, float value, int node1, int node2) {
    CircuitComponent component;
    component.type = type;
    component.value = value;
    component.node1 = node1;
    component.node2 = node2;
  
    circuit->components[circuit->numComponents] = component;
    circuit->numComponents++;
  
    //Adding the component to the appropriate nodes
    circuit->nodes[node1].components[circuit->nodes[node1].numComponents] = circuit->numComponents - 1;
    circuit->nodes[node1].numComponents++;
    circuit->nodes[node2].components[circuit->nodes[node2].numComponents] = circuit->numComponents - 1;
    circuit->nodes[node2].numComponents++;
}

// Function to update the voltage of each node
void updateNodeVoltages(Circuit *circuit) {
    float maxDiff = 0;
  
    do {
        maxDiff = 0;
        //Loop through all the nodes and update their voltage
        for (int i = 1; i < circuit->numNodes; i++) {
            Node *node = &circuit->nodes[i];
            float oldVoltage = node->voltage;
            float totalCurrent = 0;
            //Loop through all the components connected to the node
            for (int j = 0; j < node->numComponents; j++) {
                CircuitComponent *component = &circuit->components[node->components[j]];
                //If the component is a resistor
                if (component->type == 1) {
                    int otherNode;
                    if (component->node1 == i) {
                        otherNode = component->node2;
                    } else {
                        otherNode = component->node1;
                    }
                    totalCurrent += (node->voltage - circuit->nodes[otherNode].voltage) / component->value;
                }
            }
            node->voltage = totalCurrent;
            if (fabs(node->voltage - oldVoltage) > maxDiff) {
                maxDiff = fabs(node->voltage - oldVoltage);
            }
        }
    } while (maxDiff > 0.0001);  //Running the loop until the difference between old voltage and new voltage is less than a minimum threshold
  
}

// Function to print the node voltages of the circuit
void printNodeVoltages(Circuit *circuit) {
    for (int i = 1; i < circuit->numNodes; i++) {
        printf("Node %d Voltage: %f\n", i, circuit->nodes[i].voltage);
    }
}

//Main Function
int main() {
    Circuit circuit = initializeCircuit();
    circuit.numNodes = 3;
  
    //Adding the components to the circuit
    addComponent(&circuit, 1, 10000, 1, 2);
    addComponent(&circuit, 2, 0.1e-6, 2, 3);
    addComponent(&circuit, 3, 0.1e-6, 3, 1);
  
    //Calculate the voltage of each node
    updateNodeVoltages(&circuit);
  
    //Print the node voltages
    printNodeVoltages(&circuit);
  
    return 0;
}