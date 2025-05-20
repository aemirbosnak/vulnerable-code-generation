//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of a string

int main() {
    char input[MAX_LENGTH]; // Input string
    char *result; // Pointer to result string
    int length, i; // Variables for string length and loop counter
    char operation; // Variable for operation

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);
    length = strlen(input);

    // Prompt user for operation
    printf("Enter operation (+ for concatenation, * for multiplication): ");
    scanf("%c", &operation);

    // Perform operation on input string
    switch(operation) {
        case '+':
            // Concatenate input string with itself
            result = malloc(length * 2 + 1); // Allocate memory for result string
            for(i = 0; i < length; i++) {
                result[i] = input[i];
            }
            for(i = length; i < length * 2; i++) {
                result[i] = input[i - length];
            }
            result[length * 2] = '\0';
            printf("Result: %s\n", result);
            free(result);
            break;
        case '*':
            // Multiply each character in input string by 2
            result = malloc(length * 2 + 1); // Allocate memory for result string
            for(i = 0; i < length; i++) {
                result[i] = input[i] * 2;
            }
            result[length] = '\0';
            printf("Result: %s\n", result);
            free(result);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}