//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input_string[MAX_SIZE];
    char output_string[MAX_SIZE];
    int input_length, output_length;
    int i, j;

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(input_string, MAX_SIZE, stdin);

    // Remove any trailing newline character
    input_string[strcspn(input_string, "\n")] = '\0';

    // Get the length of the input string
    input_length = strlen(input_string);

    // Prompt the user for the operation to perform
    printf("Enter the operation to perform:\n");
    printf("1. Convert to uppercase\n");
    printf("2. Convert to lowercase\n");
    printf("3. Reverse the string\n");
    scanf("%d", &i);

    // Perform the selected operation
    switch(i) {
        case 1: // Convert to uppercase
            // Get the length of the output string
            output_length = strlen(input_string);
            // Convert the input string to uppercase
            for(j=0; j<output_length; j++) {
                output_string[j] = toupper(input_string[j]);
            }
            break;
        case 2: // Convert to lowercase
            // Get the length of the output string
            output_length = strlen(input_string);
            // Convert the input string to lowercase
            for(j=0; j<output_length; j++) {
                output_string[j] = tolower(input_string[j]);
            }
            break;
        case 3: // Reverse the string
            // Get the length of the output string
            output_length = strlen(input_string);
            // Reverse the input string
            for(j=0; j<output_length; j++) {
                output_string[j] = input_string[output_length-j-1];
            }
            break;
        default: // Invalid operation
            printf("Invalid operation\n");
            return 0;
    }

    // Print the output string
    printf("Output string: %s\n", output_string);

    return 0;
}