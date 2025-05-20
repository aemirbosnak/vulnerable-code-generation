//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_INPUTS 10

typedef struct {
    char input[MAX_INPUT_LENGTH];
    int sanitized;
} Input;

void sanitize_input(Input *input) {
    int i, j;
    for (i = 0, j = 0; i < strlen(input->input); i++) {
        if (isalpha(input->input[i])) {
            input->input[j++] = input->input[i];
        }
    }
    input->input[j] = '\0';
    input->sanitized = 1;
}

void unsanitize_input(Input *input) {
    input->sanitized = 0;
}

int main() {
    int num_inputs, i;
    Input inputs[MAX_INPUTS];

    printf("Enter the number of inputs (maximum %d): ", MAX_INPUTS);
    scanf("%d", &num_inputs);

    for (i = 0; i < num_inputs; i++) {
        printf("Enter input #%d: ", i + 1);
        scanf("%s", inputs[i].input);
        inputs[i].sanitized = 0;
    }

    printf("Sanitized inputs:\n");
    for (i = 0; i < num_inputs; i++) {
        if (!inputs[i].sanitized) {
            sanitize_input(&inputs[i]);
        }
        printf("Input #%d: %s\n", i + 1, inputs[i].input);
    }

    printf("\nUnsanitized inputs:\n");
    for (i = 0; i < num_inputs; i++) {
        unsanitize_input(&inputs[i]);
        printf("Input #%d: %s\n", i + 1, inputs[i].input);
    }

    return 0;
}