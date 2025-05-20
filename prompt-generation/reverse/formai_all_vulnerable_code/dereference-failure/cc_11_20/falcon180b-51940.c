//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_INPUT_SIZE 1000000

int main() {
    // Declare variables
    char input[MAX_INPUT_SIZE];
    int input_size = 0;
    int binary_size = 0;
    int i, j;
    int temp;
    int carry = 0;
    
    // Prompt user for input
    printf("Enter a decimal number: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_size = strlen(input);
    
    // Remove leading and trailing spaces
    for (i = 0; i < input_size; i++) {
        if (isspace(input[i])) {
            input[i] = '\0';
            input_size--;
        }
    }
    
    // Convert decimal to binary
    for (i = input_size - 1; i >= 0; i--) {
        if (input[i] == '.') {
            printf("Error: Input must be an integer.\n");
            return 1;
        }
        temp = input[i] - '0';
        binary_size++;
        while (temp > 0) {
            binary_size++;
            temp /= 2;
        }
    }
    for (i = 0; i < binary_size; i++) {
        binary_size++;
    }
    char* binary = (char*) malloc(binary_size * sizeof(char));
    if (binary == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    j = 0;
    for (i = input_size - 1; i >= 0; i--) {
        if (input[i] == '.') {
            printf("Error: Input must be an integer.\n");
            free(binary);
            return 1;
        }
        temp = input[i] - '0';
        while (temp > 0) {
            binary[j] = (temp % 2) + '0';
            temp /= 2;
            j++;
        }
        while (j < binary_size) {
            binary[j] = '0';
            j++;
        }
    }
    binary[binary_size - 1] = '\0';
    
    // Print binary output
    printf("Binary equivalent: %s\n", binary);
    
    // Free memory
    free(binary);
    
    return 0;
}