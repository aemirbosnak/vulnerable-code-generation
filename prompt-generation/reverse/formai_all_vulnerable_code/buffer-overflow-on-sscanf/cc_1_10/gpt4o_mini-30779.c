//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BINARY_LENGTH 65

// Function prototypes
void decToBinary(unsigned int n, char* binary);
void displayBinary(char* binary);
void convertInputToBinary(const char* input);
char* getBinaryRepresentation(char* binary, int count);

int main() {
    char input[100];

    // Mind-bending welcome message
    printf("Welcome, traveler of digits and binary realms!\n");
    printf("This is the C Binary Converter: a portal between worlds!\n");
    printf("Enter a decimal number (followed by 'Enter') to discover its binary disguise:\n");
    
    while (1) {
        printf("Your entry: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Strip newline character
            input[strcspn(input, "\n")] = 0;

            // Exit condition for the loop
            if (strcmp(input, "exit") == 0) {
                printf("Farewell! May you find clarity among your digits.\n");
                break;
            }

            convertInputToBinary(input);
        } else {
            fprintf(stderr, "Notice: Input error. Please try again.\n");
        }
    }

    return 0;
}

void convertInputToBinary(const char* input) {
    unsigned int decimal;

    // Check if the input is a valid integer
    if (sscanf(input, "%u", &decimal) != 1) {
        fprintf(stderr, "Error: Please enter a valid decimal number!\n");
        return;
    }

    // Prepare to generate binary representation
    char binary[MAX_BINARY_LENGTH] = {0};
    decToBinary(decimal, binary);
    displayBinary(binary);
}

void decToBinary(unsigned int n, char* binary) {
    for (int i = MAX_BINARY_LENGTH - 2; n > 0; i--) {
        binary[i] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    binary[MAX_BINARY_LENGTH - 1] = '\0';  // Null-terminate the string
}

void displayBinary(char* binary) {
    // Create a visually appealing representation
    char *formattedBinary = getBinaryRepresentation(binary, strlen(binary));
    
    printf("The binary representation is:\n");
    printf("%s\n", formattedBinary);
    
    // Clean up the dynamically allocated memory
    free(formattedBinary);
}

char* getBinaryRepresentation(char* binary, int length) {
    char *formattedBinary = (char*) malloc((length + 1) * sizeof(char));
    if (!formattedBinary) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Copy the original binary string to the formatted version
    for (int i = 0; i < length; i++) {
        formattedBinary[i] = binary[i];
    }
    formattedBinary[length] = '\0'; // Null-terminate

    // Add spaces for better readability
    for (int i = length - 1; i >= 0; i--) {
        if ((length - i) % 4 == 0 && i != 0) {
            // Shift the string to make space for a space
            for (int j = length; j > i; j--) {
                formattedBinary[j] = formattedBinary[j - 1];
            }
            formattedBinary[i] = ' ';
            length++; // Length of the new string has increased
        }
    }

    return formattedBinary;
}