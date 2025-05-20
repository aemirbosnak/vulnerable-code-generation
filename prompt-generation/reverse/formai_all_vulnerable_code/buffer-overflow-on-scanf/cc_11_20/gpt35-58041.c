//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GATES 50
#define MAX_INPUTS 10

typedef struct gate {
    char type[10]; // type of gate
    int inputs[MAX_INPUTS]; // input values
    int output; // output value
} gate;

int main() {
    printf("Welcome to the Cyberpunk Circuit Simulator!\n");
    printf("Enter the number of gates: ");
    int num_gates;
    scanf("%d", &num_gates);
    gate gates[MAX_GATES];

    for (int i = 0; i < num_gates; i++) {
        printf("Enter the type of gate (AND/OR/XOR): ");
        scanf("%s", gates[i].type);

        printf("Enter the input values (0/1) separated by spaces (up to %d): ", MAX_INPUTS);
        for (int j = 0; j < MAX_INPUTS; j++) {
            int input;
            scanf("%d", &input);
            if (input != 0 && input != 1) {
                printf("Invalid input. Only 0 or 1 allowed.\n");
                j--;
                continue;
            }
            gates[i].inputs[j] = input;

            if (j == 0 && strcmp(gates[i].type, "NOT") == 0) {
                break;
            } else if (j == 1 && strcmp(gates[i].type, "NOT") != 0) {
                break;
            }
        }

        if (strcmp(gates[i].type, "AND") == 0) {
            gates[i].output = gates[i].inputs[0] && gates[i].inputs[1];
        } else if (strcmp(gates[i].type, "OR") == 0) {
            gates[i].output = gates[i].inputs[0] || gates[i].inputs[1];
        } else if (strcmp(gates[i].type, "XOR") == 0) {
            gates[i].output = gates[i].inputs[0] ^ gates[i].inputs[1];
        } else if (strcmp(gates[i].type, "NOT") == 0) {
            gates[i].output = !gates[i].inputs[0];
        }
    }

    printf("Results:\n");
    for (int i = 0; i < num_gates; i++) {
        printf("Gate %d: %s ", i+1, gates[i].type);
        for (int j = 0; j < MAX_INPUTS; j++) {
            if (gates[i].inputs[j] != -1) {
                printf("%d ", gates[i].inputs[j]);
            }
        }
        printf("= %d\n", gates[i].output);
    }

    return 0;
}