//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 // Maximum supported number of nodes in the circuit
#define MAX_NAME_SIZE 10 // Maximum size of a node name

int num_nodes; // Number of nodes in the circuit
int num_gates; // Number of gates in the circuit

// Structure of a node in the circuit
typedef struct {
    char name[MAX_NAME_SIZE];
    int value;
} node;

// Structure of a gate in the circuit
typedef struct {
    char type;
    node* input1;
    node* input2;
    node* output;
} gate;

node nodes[MAX_NODES]; // Array to store all nodes in the circuit
gate gates[MAX_NODES]; // Array to store all gates in the circuit

// Function to initialize all nodes in the circuit
void init_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter name for node %d: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].value = 0;
    }
}

// Function to initialize all gates in the circuit
void init_gates() {
    int input1, input2, output;
    char gate_type;

    for (int i = 0; i < num_gates; i++) {
        printf("Enter gate type for gate %d (AND/OR/XOR): ", i+1);
        scanf(" %c", &gate_type);

        printf("Enter input 1 for gate %d: ", i+1);
        scanf("%d", &input1);
        gates[i].input1 = &nodes[input1-1];

        printf("Enter input 2 for gate %d: ", i+1);
        scanf("%d", &input2);
        gates[i].input2 = &nodes[input2-1];

        printf("Enter output for gate %d: ", i+1);
        scanf("%d", &output);
        gates[i].output = &nodes[output-1];

        gates[i].type = gate_type;
    }
}

// Function to evaluate a gate based on its inputs and type
void evaluate_gate(gate* g) {
    if (g->type == 'A') {
        g->output->value = (g->input1->value && g->input2->value);
    } else if (g->type == 'O') {
        g->output->value = (g->input1->value || g->input2->value);
    } else if (g->type == 'X') {
        g->output->value = (g->input1->value ^ g->input2->value);
    }
}

int main() {
    printf("Welcome to the cheerful Classical Circuit Simulator!\n");
    printf("How many nodes does your circuit have? (max %d) ", MAX_NODES);
    scanf("%d", &num_nodes);

    if (num_nodes > MAX_NODES) {
        printf("Error: Maximum nodes exceeded.\n");
        return 1;
    }

    init_nodes();

    printf("How many gates does your circuit have? ");
    scanf("%d", &num_gates);

    init_gates();

    printf("Input values for nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s: ", nodes[i].name);
        scanf("%d", &nodes[i].value);
    }

    printf("Evaluating gates...\n");
    for (int i = 0; i < num_gates; i++) {
        evaluate_gate(&gates[i]);
    }

    printf("Output values:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s: %d\n", nodes[i].name, nodes[i].value);
    }

    printf("Thank you for using the cheerful Classical Circuit Simulator!\n");

    return 0;
}