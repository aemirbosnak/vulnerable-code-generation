//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: all-encompassing
// This program is a Classical Circuit Simulator that allows users to simulate 
// the basic electrical circuits and output the current, voltage, and power 
// values of each component in the circuit.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the constants
#define MAX_NODE_NUM 100       // The maximum number of nodes in the circuit
#define MAX_DEV_NUM 100        // The maximum number of devices in the circuit
#define MAX_NAME_LEN 20        // The maximum length of device names
#define MAX_MODEL_NAME_LEN 20  // The maximum length of device model names
#define MAX_MODEL_NUM 100      // The maximum number of device models
#define MAX_FUNC_NUM 100       // The maximum number of device functions

// Define the global variables
int node_num;  // The number of nodes in the circuit
int dev_num;   // The number of devices in the circuit

// Define the data structures
struct Node {                // Define the node structure
    char name[MAX_NAME_LEN]; // The name of the node
    double volt;             // The voltage of the node
};

struct Device {                     // Define the device structure
    char name[MAX_NAME_LEN];        // The name of the device
    struct Node *node1, *node2;     // The two nodes connected to the device
    struct DevModel *dev_model;     // The model of the device
    double param[10];               // The parameters of the device
    double curr;                    // The current through the device
    double volt;                    // The voltage across the device
};

struct DevModel {                     // Define the device model structure
    char name[MAX_MODEL_NAME_LEN];    // The name of the device model
    double (*func[MAX_FUNC_NUM])(struct Device *);  // The functions of the device model
};

// Define the device model functions
double resistor_func(struct Device *dev) {
    dev->curr = (dev->node1->volt - dev->node2->volt) / dev->param[0];
    dev->volt = dev->param[0] * dev->curr;
    return dev->curr;
}

double voltage_source_func(struct Device *dev) {
    dev->volt = dev->param[0];
    dev->curr = (dev->node1->volt - dev->node2->volt) / dev->param[1];
    return dev->curr;
}

double current_source_func(struct Device *dev) {
    dev->curr = dev->param[0];
    dev->volt = (dev->node1->volt - dev->node2->volt);
    return dev->volt;
}

// Define the main program
int main() {
    // Initialize the variables
    struct Node nodes[MAX_NODE_NUM];
    struct Device devices[MAX_DEV_NUM];
    struct DevModel models[MAX_MODEL_NUM];
    int i, j;

    // Create the nodes of the circuit
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &node_num);
    printf("Enter the names of the nodes:\n");
    for (i = 0; i < node_num; i++) {
        printf("Node %d: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].volt = 0.0;
    }

    // Create the device models
    models[0].func[0] = resistor_func;
    models[0].name[0] = "Resistor";
    models[1].func[0] = voltage_source_func;
    models[1].func[1] = resistor_func;
    models[1].name[0] = "Voltage Source";
    models[1].name[1] = "Internal Resistor";
    models[2].func[0] = current_source_func;
    models[2].func[1] = resistor_func;
    models[2].name[0] = "Current Source";
    models[2].name[1] = "Internal Resistor";
    
    // Create the devices of the circuit
    printf("Enter the number of devices in the circuit: ");
    scanf("%d", &dev_num);
    for (i = 0; i < dev_num; i++) {
        devices[i].dev_model = &models[0];
        printf("Enter the name of device %d: ", i+1);
        scanf("%s", devices[i].name);
        printf("Enter the two nodes connected to the device %s: ", devices[i].name);
        for (j = 0; j < node_num; j++) {
            scanf("%s", nodes[j].name);
            if (strcmp(nodes[j].name, devices[i].node1->name) == 0) {
                devices[i].node1 = &nodes[j];
            }
            if (strcmp(nodes[j].name, devices[i].node2->name) == 0) {
                devices[i].node2 = &nodes[j];
            }
        }
        printf("Enter the parameters of the device %s: ", devices[i].name);
        for (j = 0; j < 10; j++) {
            scanf("%lf", &devices[i].param[j]);
        }
    }

    // Simulate the circuit and output the results
    printf("Node Voltages:\n");
    for (i = 0; i < node_num; i++) {
        printf("%s: %.2lfV\n", nodes[i].name, nodes[i].volt);
    }
    printf("Device Currents and Voltages:\n");
    for (i = 0; i < dev_num; i++) {
        (*devices[i].dev_model->func[0])(&devices[i]);
        printf("%s: Current = %.2lfA Voltage = %.2lfV\n", devices[i].name, devices[i].curr, devices[i].volt);
    }
    return 0;
}