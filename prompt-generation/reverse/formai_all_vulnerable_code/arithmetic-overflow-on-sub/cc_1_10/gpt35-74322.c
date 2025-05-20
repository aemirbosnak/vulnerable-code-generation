//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: artistic
#include <stdio.h>
#include <math.h>

// Structure to represent a classical logic gate
struct Gate {
    char* name;
    int num_inputs;
    int* input_indices;
    int output_index;
    int function_type; // 1 for AND, 2 for OR, 3 for NOT
};

// Function to get the value of an input pin
int get_input(int* inputs, int input_index) {
    return inputs[input_index];
}

// Function to evaluate an AND gate
int eval_AND(int* inputs, int num_inputs) {
    int output = 1;
    for (int i = 0; i < num_inputs; i++) {
        if (inputs[i] != 1) {
            output = 0;
            break;
        }
    }
    return output;
}

// Function to evaluate an OR gate
int eval_OR(int* inputs, int num_inputs) {
    int output = 0;
    for (int i = 0; i < num_inputs; i++) {
        if (inputs[i] == 1) {
            output = 1;
            break;
        }
    }
    return output;
}

// Function to evaluate a NOT gate
int eval_NOT(int* inputs, int num_inputs) {
    return (1 - inputs[0]); 
}

// Function to evaluate a gate
int eval_gate(int* inputs, struct Gate* gate) {
    int num_inputs = gate->num_inputs;
    int* input_indices = gate->input_indices;
    int function_type = gate->function_type;
    int output;
    
    if (function_type == 1) { // AND gate
        output = eval_AND(inputs, num_inputs);
    } 
    else if (function_type == 2) { // OR gate
        output = eval_OR(inputs, num_inputs);
    } 
    else if (function_type == 3) { // NOT gate
        output = eval_NOT(inputs, num_inputs);
    }
    
    return output;
}

// Function to simulate the circuit
void simulate_circuit(int* inputs, int num_inputs, struct Gate* gates, int num_gates, int* outputs, int num_outputs) {
    // Evaluate all gates in order
    for (int i = 0; i < num_gates; i++) {
        struct Gate* gate = &gates[i];
        int num_inputs = gate->num_inputs;
        int* input_indices = gate->input_indices;
        int output_index = gate->output_index;
        int inputs[num_inputs];
        for (int j = 0; j < num_inputs; j++) {
            inputs[j] = get_input(inputs, input_indices[j]);
        }
        int output = eval_gate(inputs, gate);
        outputs[output_index] = output;
    }
}

int main() {
    // Define gates
    struct Gate gates[3] = {
        {"AND1", 2, (int[2]){0, 1}, 2, 1},
        {"OR1", 3, (int[3]){0, 1, 2}, 3, 2},
        {"NOT1", 1, (int[1]){2}, 4, 3}
    };
    
    // Define inputs and outputs
    int inputs[3] = {1, 0, 1};
    int outputs[5];
    
    // Simulate circuit
    simulate_circuit(inputs, 3, gates, 3, outputs, 5);
    
    // Print outputs
    printf("Input values:\n");
    printf("Input 1: %d\n", inputs[0]);
    printf("Input 2: %d\n", inputs[1]);
    printf("Input 3: %d\n");
    printf("Output values:\n");
    printf("Output 1 (AND1): %d\n", outputs[0]);
    printf("Output 2 (AND1): %d\n", outputs[1]);
    printf("Output 3 (OR1): %d\n", outputs[2]);
    printf("Output 4 (OR1): %d\n", outputs[3]);
    printf("Output 5 (NOT1): %d\n", outputs[4]);
    
    return 0;
}