//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char input[100];
    char *output = malloc(100 * sizeof(char));
    int i, j, len, num, base;
    char *ptr;

    // Prompt the user for the input
    printf("Enter the number to be converted: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the input string
    j = strlen(input) - 1;
    if (input[j] == '\n') {
        input[j] = '\0';
    }

    // Check if the input is a valid binary number
    for (i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i]) && input[i]!= '0' && input[i]!= '1') {
            printf("Invalid input. Please enter a binary number.\n");
            free(output);
            return 1;
        }
    }

    // Convert the binary number to decimal
    num = 0;
    base = 1;
    for (i = strlen(input) - 1; i >= 0; i--) {
        if (input[i] == '1') {
            num += base;
        }
        base *= 2;
    }

    // Convert the decimal number to the desired base
    base = 10;
    if (argc > 1) {
        base = atoi(argv[1]);
    }
    len = 0;
    ptr = output;
    do {
        num /= base;
        if (num == 0) {
            break;
        }
        *ptr++ = num % 10 + '0';
        len++;
    } while (num > 0);

    // Reverse the output string
    j = 0;
    for (i = len - 1; i >= 0; i--) {
        output[i] = output[j++];
    }
    output[len] = '\0';

    // Print the output
    printf("The number %s in binary is %s in base %d.\n", input, output, base);

    free(output);
    return 0;
}