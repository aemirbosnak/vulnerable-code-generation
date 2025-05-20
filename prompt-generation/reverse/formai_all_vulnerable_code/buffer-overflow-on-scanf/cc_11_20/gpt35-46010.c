//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: surprised
#include <stdio.h>

int main() {
    printf("Oh my goodness, I can't believe I just wrote a Classical Circuit Simulator program in C!\n");

    int num_inputs, num_gates;
    printf("How many inputs does your circuit have? ");
    scanf("%d", &num_inputs);

    printf("How many gates does your circuit have? ");
    scanf("%d", &num_gates);

    int inputs[num_inputs];

    printf("Enter the initial values of your inputs (0 or 1): ");
    for (int i = 0; i < num_inputs; i++) {
        scanf("%d", &inputs[i]);
    }

    int gates[num_gates][3];
    char gate_type;

    printf("Enter the details of your gates (type, input 1, input 2):");
    for (int i = 0; i < num_gates; i++) {
        scanf(" %c %d %d", &gate_type, &gates[i][1], &gates[i][2]);
        if (gate_type == 'N') {
            gates[i][0] = 1;
        } else if (gate_type == 'A') {
            gates[i][0] = 2;
        } else if (gate_type == 'O') {
            gates[i][0] = 3;
        } else {
            printf("Invalid gate type!\n");
            return 0;
        }
    }

    for (int i = 0; i < num_gates; i++) {
        int input1 = gates[i][1] - 1;
        int input2 = gates[i][2] - 1;
        if (gates[i][0] == 1) {
            inputs[i] = !inputs[input1];
        } else if (gates[i][0] == 2) {
            inputs[i] = inputs[input1] && inputs[input2];
        } else if (gates[i][0] == 3) {
            inputs[i] = inputs[input1] || inputs[input2];
        }
    }

    printf("The final output values are: ");
    for (int i = 0; i < num_inputs; i++) {
        printf("%d ", inputs[i]);
    }
    printf("\n");

    return 0;
}