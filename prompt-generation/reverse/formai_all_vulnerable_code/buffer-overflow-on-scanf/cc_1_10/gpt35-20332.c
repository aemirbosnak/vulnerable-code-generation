//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h> 

#define MAX_GATES 10
#define MAX_INPUTS 5

int simulate(int gates[MAX_GATES][3], int inputs[MAX_INPUTS]);

int main()
{
    int gates[MAX_GATES][3], inputs[MAX_INPUTS];
    int ngates, ninputs, i, j;
    char answer;

    printf("Welcome to the Paranoid Circuit Simulator!\n");
    printf("How many gates in the circuit? ");
    scanf("%d", &ngates);
    printf("How many inputs to the circuit? ");
    scanf("%d", &ninputs);

    printf("Please enter the gates of the circuit:\n");
    for (i = 0; i < ngates; i++) {
        printf("Gate %d: ", i+1);
        scanf("%d %d %d", &gates[i][0], &gates[i][1], &gates[i][2]);
    }

    printf("Please enter the input values:\n");
    for (i = 0; i < ninputs; i++) {
        printf("Input %d: ", i+1);
        scanf("%d", &inputs[i]);
    }

    printf("Here is how your circuit is connected:\n");
    for (i = 0; i < ngates; i++) {
        printf("Gate %d: %d %d %d\n", i+1, gates[i][0], gates[i][1], gates[i][2]);
    }

    printf("Are you sure you want to simulate this circuit? (y/n) ");
    scanf("%s", &answer);

    if (answer == 'y' || answer == 'Y') {
        int result = simulate(gates, inputs);
        printf("The output of the circuit is: %d\n", result);
    } else {
        printf("Aborted.\n");
    }

    return 0;
}

int simulate(int gates[MAX_GATES][3], int inputs[MAX_INPUTS])
{
    int i, j;
    int ninputs = sizeof(inputs) / sizeof(inputs[0]);
    int nout = 0, out = 0;
    int in[MAX_INPUTS] = {0};

    for (i = 0; i < MAX_GATES; i++) {
        for (j = 0; j < ninputs; j++) {
            if (gates[i][1] == j) {
                in[j] = inputs[j];
            }
        }

        if (gates[i][0] == 1) {
            out = in[gates[i][1]] & in[gates[i][2]];
        }
        else if (gates[i][0] == 2) {
            out = in[gates[i][1]] | in[gates[i][2]];
        }

        nout = out;
        out = 0;
    }

    return nout;
}