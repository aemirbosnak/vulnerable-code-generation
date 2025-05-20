//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_NUM_INPUTS 100

int main() {
    char input_buffer[MAX_INPUT_LENGTH];
    int num_inputs;
    int i;

    // Get the number of inputs from the user
    printf("Enter the number of inputs: ");
    if (scanf("%d", &num_inputs)!= 1 || num_inputs <= 0 || num_inputs > MAX_NUM_INPUTS) {
        printf("Invalid number of inputs.\n");
        return 1;
    }

    // Get the inputs from the user
    for (i = 0; i < num_inputs; i++) {
        printf("Enter input %d: ", i + 1);
        if (fgets(input_buffer, MAX_INPUT_LENGTH, stdin) == NULL) {
            printf("Error reading input.\n");
            return 1;
        }

        // Sanitize the input
        input_buffer[strcspn(input_buffer, "\n")] = '\0'; // Remove the newline character
        int input_length = strlen(input_buffer);
        int j;
        for (j = 0; j < input_length; j++) {
            if (!isalnum(input_buffer[j])) {
                printf("Invalid character in input.\n");
                return 1;
            }
        }

        // Check for overflow
        if (strtod(input_buffer, NULL) == HUGE_VAL) {
            printf("Input is too large.\n");
            return 1;
        }
    }

    printf("All inputs are valid.\n");
    return 0;
}