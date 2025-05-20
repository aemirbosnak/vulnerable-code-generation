//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_NAME_LENGTH 100

// Define a basic element (resistor)
typedef struct {
    int node1, node2;
    double resistance;
} Resistor;

// Define a circuit (originally an empty array of resistors)
typedef struct {
    Resistor resistors[MAX_NODES];
    int num_resistors;
} Circuit;

//Define a function that checks if a node is in the circuit already
bool nodeExists(int node, Circuit circuit) {
    for(int i = 0; i < circuit.num_resistors; i++) {
        if(circuit.resistors[i].node1 == node || circuit.resistors[i].node2 == node) {
            return true;
        }
    }
    return false;
}

int main() {
    //Declare our circuit and variables for user input
    Circuit circuit = {{}, 0};
    char resistor_name[MAX_NAME_LENGTH];
    int node1, node2;
    double resistance;

    //Greet the user and explain the program
    printf("Welcome to the joyful Circuit Simulator!\n");
    printf("Enter resistor info in the format 'name node1 node2 resistance': \n");

    //Loop for user input until they choose to exit
    while(true) {
        printf(">> ");
        scanf("%s %d %d %lf", &resistor_name, &node1, &node2, &resistance);

        //If the user types "exit", exit the program
        if(resistor_name[0] == 'e' && resistor_name[1] == 'x' && resistor_name[2] == 'i' && resistor_name[3] == 't') {
            printf("Goodbye!\n");
            return 0;
        }

        //Check if the input is valid
        bool valid_input = true;
        if(node1 < 0 || node2 < 0 || node1 == node2 || resistance < 0) {
            valid_input = false;
        }
        if(nodeExists(node1, circuit) == false && nodeExists(node2, circuit) == false) {
            printf("Error: Node(s) not found in circuit. Please enter valid nodes.\n");
            valid_input = false;
        }
        if(valid_input == true) {
            printf("Resistor added: %s %d %d %lf\n", resistor_name, node1, node2, resistance);
            Resistor resistor = {node1, node2, resistance};
            circuit.resistors[circuit.num_resistors] = resistor;
            circuit.num_resistors++;
        }
    }
    return 0;
}