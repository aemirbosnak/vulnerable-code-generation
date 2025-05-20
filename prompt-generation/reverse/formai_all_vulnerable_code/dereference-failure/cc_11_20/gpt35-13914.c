//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_GATES 10

typedef struct Gate {
    char type[4];
    int input1;
    int input2;
    int output;
} Gate;

int main() {
    char input[MAX_INPUT_SIZE];
    Gate circuit[MAX_GATES];
    int gateCount = 0;
    int outputValue;

    printf("Welcome to the Classical Circuit Simulator!\n");
    printf("Please enter your circuit one gate at a time.\n");
    printf("When you are finished, type 'done'.\n");

    while(1) {
        fgets(input, MAX_INPUT_SIZE, stdin);
        if(strncmp(input, "done", 4) == 0) {
            break;
        }
        char *token = strtok(input, " ");
        Gate gate;
        if(strcmp(token, "NOT") == 0) {
            strcpy(gate.type, "NOT");
            gate.input1 = atoi(strtok(NULL, " "));
            gate.output = atoi(strtok(NULL, " "));
        } else if(strcmp(token, "AND") == 0) {
            strcpy(gate.type, "AND");
            gate.input1 = atoi(strtok(NULL, " "));
            gate.input2 = atoi(strtok(NULL, " "));
            gate.output = atoi(strtok(NULL, " "));
        } else if(strcmp(token, "OR") == 0) {
            strcpy(gate.type, "OR");
            gate.input1 = atoi(strtok(NULL, " "));
            gate.input2 = atoi(strtok(NULL, " "));
            gate.output = atoi(strtok(NULL, " "));
        } else {
            printf("Invalid gate type: %s\n", token);
            continue;
        }
        circuit[gateCount++] = gate;
    }

    int input1, input2;
    printf("Please enter the input values (0 or 1) for the circuit.\n");
    printf("Input 1: ");
    scanf("%d", &input1);
    printf("Input 2: ");
    scanf("%d", &input2);

    for(int i = 0; i < gateCount; i++) {
        Gate gate = circuit[i];
        if(strcmp(gate.type, "NOT") == 0) {
            int inputValue = (gate.input1 == 1) ? input1 : !input1;
            outputValue = !inputValue;
        } else if(strcmp(gate.type, "AND") == 0) {
            int inputValue1 = (gate.input1 == 1) ? input1 : !input1;
            int inputValue2 = (gate.input2 == 1) ? input2 : !input2;
            outputValue = inputValue1 && inputValue2;
        } else if(strcmp(gate.type, "OR") == 0) {
            int inputValue1 = (gate.input1 == 1) ? input1 : !input1;
            int inputValue2 = (gate.input2 == 1) ? input2 : !input2;
            outputValue = inputValue1 || inputValue2;
        }
        if(i == gateCount - 1) {
            printf("Output: %d", outputValue);
        }
    }

    return 0;
}