//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter the number of qubits in the circuit: ");
    int num_qubits;
    scanf("%d", &num_qubits);

    printf("Enter the number of gates in the circuit: ");
    int num_gates;
    scanf("%d", &num_gates);

    printf("Enter the initial state of the qubits (0 or 1): ");
    int initial_state[num_qubits];
    for (int i = 0; i < num_qubits; ++i) {
        scanf("%d", &initial_state[i]);
    }

    printf("\nRomeo: My fair Juliet, with this circuit simulator, I shall test the bounds of my love for you.\n");
    printf("Juliet: Oh, Romeo! How wondrous! Pray tell, what doth thine tests entail?\n");
    printf("Romeo: I have here a circuit with %d qubits and %d gates. I shall run it with the initial state of: ", num_qubits, num_gates);
    for (int i = 0; i < num_qubits; ++i) {
        printf("%d", initial_state[i]);
    }
    printf(".\n");

    printf("Juliet: Verily, Romeo! I cannot wait to see the result of thy experiment.\n");

    // Perform circuit simulation
    int *state = (int*) calloc(1 << num_qubits, sizeof(int));
    state[0] = 1;
    for (int i = 0; i < num_gates; ++i) {
        // Read gate specs
        printf("\nPlease enter details for gate %d:\n", i+1);
        printf("Gate type (H, X or Z): ");
        char gate_type;
        scanf(" %c", &gate_type);

        printf("Target qubit (0 to %d): ", num_qubits-1);
        int target_qubit;
        scanf("%d", &target_qubit);

        // Apply gate
        switch(gate_type) {
            case 'H': {
                for (int j = 0; j < (1 << num_qubits); j += (1 << (target_qubit+1))) { // loop through states
                    for (int k = 0; k < (1 << target_qubit); ++k) { // loop through elements of each state
                        int index1 = j + k;
                        int index2 = index1 + (1 << target_qubit);
                        int temp = state[index1];
                        state[index1] = (state[index1] + state[index2]) / 2;
                        state[index2] = (temp - state[index2]) / 2;
                    }
                }
                printf("Romeo: I hereby applyeth the Hadamard gate to qubit %d, my dear Juliet.\n", target_qubit);
                break;
            }

            case 'X': {
                for (int j = 0; j < (1 << num_qubits); ++j) { // loop through states
                    if ((j >> target_qubit) % 2 == 1) {
                        state[j] = state[j] * -1;
                    }
                }
                printf("Romeo: I hereby applyeth the Pauli-X gate to qubit %d, my fair lady.\n", target_qubit);
                break;
            }

            case 'Z': {
                for (int j = 0; j < (1 << num_qubits); ++j) { // loop through states
                    if ((j >> target_qubit) % 2 == 1) {
                        state[j] = state[j] * -1;
                    }
                }
                printf("Romeo: I hereby applyeth the Pauli-Z gate to qubit %d, my sweet Juliet.\n", target_qubit);
                break;
            }

            default: {
                printf("Romeo: Forsooth! Thou hast entered an invalid gate type, my beloved Juliet. I must take my leave.\n");
                exit(0);
            }
        }
    }

    printf("\nRomeo: The results of our circuit simulation, my dearest Juliet, are as follows:\n");
    for (int i = 0; i < (1 << num_qubits); ++i) {
        printf("State %d: %d\n", i, state[i]);
    }

    free(state);
    printf("Juliet: Oh, Romeo! How wonderful thy knowledge of classical circuit simulation! Impressive, indeed!\n");

    return 0;
}