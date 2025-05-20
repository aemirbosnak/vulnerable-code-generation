//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_INPUT_LENGTH 1024

// Function prototypes
int calculate_checksum(char *input);
void print_checksum(int checksum);

// Main function
int main() {
    // Declare variables
    char input[MAX_INPUT_LENGTH];
    int checksum;

    // Prompt the user for input
    printf("Enter a string: ");
    scanf("%s", input);

    // Calculate the checksum
    checksum = calculate_checksum(input);

    // Print the checksum
    print_checksum(checksum);

    return 0;
}

// Function to calculate the checksum
int calculate_checksum(char *input) {
    // Declare variables
    int checksum = 0;
    int length = strlen(input);

    // Calculate the checksum
    for (int i = 0; i < length; i++) {
        checksum += (int)input[i];
    }

    // Return the checksum
    return checksum;
}

// Function to print the checksum
void print_checksum(int checksum) {
    // Print the checksum
    printf("The checksum is: %d\n", checksum);
}