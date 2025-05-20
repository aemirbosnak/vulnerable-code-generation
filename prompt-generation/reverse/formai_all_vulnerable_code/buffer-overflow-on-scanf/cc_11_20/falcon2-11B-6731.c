//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUTS 10
#define MAX_OUTPUTS 10

typedef struct {
    char name[20];
    float value;
} input_t;

typedef struct {
    char name[20];
    float value;
} output_t;

int main() {
    // Initialize inputs and outputs
    input_t inputs[MAX_INPUTS];
    input_t* inputs_ptr = &inputs[0];
    input_t inputs_temp = { "speed", 0.0 };

    output_t outputs[MAX_OUTPUTS];
    output_t* outputs_ptr = &outputs[0];
    output_t outputs_temp = { "steering", 0.0 };

    // Main loop
    while (1) {
        // Read inputs
        printf("Enter inputs: ");
        for (int i = 0; i < MAX_INPUTS; i++) {
            scanf("%s %f", inputs_ptr->name, &inputs_ptr->value);
            inputs_ptr++;
        }

        // Process inputs
        for (int i = 0; i < MAX_INPUTS; i++) {
            if (inputs_ptr->name[0] =='s') {
                outputs_ptr->value = inputs_ptr->value;
            } else if (inputs_ptr->name[0] == 'w') {
                outputs_ptr->value = inputs_ptr->value * 2;
            } else if (inputs_ptr->name[0] == 'a') {
                outputs_ptr->value = inputs_ptr->value * -1;
            } else if (inputs_ptr->name[0] == 'd') {
                outputs_ptr->value = inputs_ptr->value + 10;
            }
            outputs_ptr++;
        }

        // Print outputs
        printf("Outputs: ");
        for (int i = 0; i < MAX_OUTPUTS; i++) {
            if (outputs_ptr->name[0] =='s') {
                printf("Speed: %f\n", outputs_ptr->value);
            } else if (outputs_ptr->name[0] == 'w') {
                printf("Wheel: %f\n", outputs_ptr->value);
            } else if (outputs_ptr->name[0] == 'a') {
                printf("Steering: %f\n", outputs_ptr->value);
            } else if (outputs_ptr->name[0] == 'd') {
                printf("Direction: %f\n", outputs_ptr->value);
            }
            outputs_ptr++;
        }
    }

    return 0;
}