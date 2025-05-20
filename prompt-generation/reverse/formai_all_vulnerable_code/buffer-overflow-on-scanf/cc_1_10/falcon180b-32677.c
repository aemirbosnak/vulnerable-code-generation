//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_NUM_INPUTS 10

typedef struct Input {
    char* value;
    int data_type; // 0 for string, 1 for integer
} Input;

void sanitize_input(Input* input) {
    if (input->data_type == 0) {
        // String input
        int length = strlen(input->value);
        if (length > MAX_INPUT_LENGTH) {
            input->value[MAX_INPUT_LENGTH - 1] = '\0';
            printf("Input truncated to %d characters\n", MAX_INPUT_LENGTH);
        }
    } else {
        // Integer input
        int num_digits = 0;
        while (isdigit(input->value[num_digits])) {
            num_digits++;
        }
        if (num_digits > MAX_NUM_INPUTS) {
            input->value[MAX_NUM_INPUTS - 1] = '\0';
            printf("Input truncated to %d digits\n", MAX_NUM_INPUTS);
        }
    }
}

int main() {
    int num_inputs;
    printf("Enter the number of inputs: ");
    scanf("%d", &num_inputs);

    if (num_inputs > MAX_NUM_INPUTS) {
        printf("Maximum number of inputs is %d\n", MAX_NUM_INPUTS);
        return 1;
    }

    Input inputs[MAX_NUM_INPUTS];
    for (int i = 0; i < num_inputs; i++) {
        printf("Enter input %d: ", i+1);
        scanf("%s", inputs[i].value);
        if (isdigit(inputs[i].value[0])) {
            inputs[i].data_type = 1;
        } else {
            inputs[i].data_type = 0;
        }
    }

    for (int i = 0; i < num_inputs; i++) {
        sanitize_input(&inputs[i]);
        printf("Sanitized input %d: %s\n", i+1, inputs[i].value);
    }

    return 0;
}