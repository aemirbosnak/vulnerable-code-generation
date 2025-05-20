//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_OUTPUT_LENGTH];
    int input_length = 0;
    int output_length = 0;
    int i = 0;
    int j = 0;

    printf("Enter a binary number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    input_length = strlen(input);

    // Remove any leading or trailing whitespace
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[input_length - 1])) {
        input_length--;
    }

    if (input_length == 0 || input_length > MAX_INPUT_LENGTH) {
        printf("Invalid input. Please enter a binary number with a maximum length of %d.\n", MAX_INPUT_LENGTH);
        return 1;
    }

    // Convert binary to decimal
    while (i < input_length) {
        if (input[i] == '1') {
            output[output_length++] = '1';
        } else if (input[i] == '0') {
            output[output_length++] = '0';
        } else {
            printf("Invalid input. Please enter a binary number.\n");
            return 1;
        }
        i++;
    }

    output[output_length] = '\0';
    printf("Decimal equivalent: %s\n", output);

    return 0;
}