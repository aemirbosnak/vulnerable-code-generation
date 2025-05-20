//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inputA;
    int inputB;
    int (*gateFunction)(int, int);
} Circuit;

int AND_Gate(int a, int b) {
    return a & b;
}

int OR_Gate(int a, int b) {
    return a | b;
}

void printCircuitState(const char* name, Circuit circuit) {
    printf("Circuit %s\n", name);
    printf("Input A: %d, Input B: %d\n", circuit.inputA, circuit.inputB);
    printf("Output: %d\n\n", circuit.gateFunction(circuit.inputA, circuit.inputB));
}

int main() {
    Circuit andCircuit = {0, 0, AND_Gate};
    Circuit orCircuit = {0, 0, OR_Gate};
    
    int testCases[4][2] = {
        {0, 0}, // 0 AND 0, 0 OR 0
        {0, 1}, // 0 AND 1, 0 OR 1
        {1, 0}, // 1 AND 0, 1 OR 0
        {1, 1}  // 1 AND 1, 1 OR 1
    };
    
    printf("Synchronous Circuit Simulator\n");
    printf("==============================\n");
    
    for (int i = 0; i < 4; i++) {
        andCircuit.inputA = testCases[i][0];
        andCircuit.inputB = testCases[i][1];
        printCircuitState("AND Gate", andCircuit);
        
        orCircuit.inputA = testCases[i][0];
        orCircuit.inputB = testCases[i][1];
        printCircuitState("OR Gate", orCircuit);
    }

    // User interaction for dynamic input
    int inputA, inputB;
    char continueSimulation;

    do {
        printf("Enter input A (0 or 1): ");
        scanf("%d", &inputA);
        printf("Enter input B (0 or 1): ");
        scanf("%d", &inputB);
        
        if ((inputA < 0 || inputA > 1) || (inputB < 0 || inputB > 1)) {
            printf("Invalid input! Please enter either 0 or 1.\n");
            continue;
        }
        
        andCircuit.inputA = inputA;
        andCircuit.inputB = inputB;
        printCircuitState("AND Gate", andCircuit);

        orCircuit.inputA = inputA;
        orCircuit.inputB = inputB;
        printCircuitState("OR Gate", orCircuit);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueSimulation);
    } while (continueSimulation == 'y' || continueSimulation == 'Y');

    printf("Exiting the simulator. Goodbye!\n");
    return 0;
}