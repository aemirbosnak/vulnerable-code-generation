//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100
#define MAX_OUTPUT_LEN 100

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_LEN];
    char output[MAX_OUTPUT_LEN];
    int input_len, output_len;

    // Prompt user for input
    printf("Enter a binary number: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    input_len = strlen(input);

    // Remove newline character from input
    input[input_len-1] = '\0';

    // Convert binary to decimal
    output_len = 0;
    int decimal = 0;
    int power = 0;
    for (int i = input_len - 1; i >= 0; i--) {
        if (input[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    // Convert decimal to binary
    sprintf(output, "%d", decimal);
    int j = strlen(output) - 1;
    while (j >= 0) {
        if (output[j] == '0') {
            output[j] = '1';
            output_len++;
        } else if (output[j] == '1') {
            output[j] = '0';
            output_len--;
        }
        j--;
    }

    // Print output
    printf("Binary to decimal conversion: %d\n", decimal);
    printf("Decimal to binary conversion: %s\n", output);

    return 0;
}