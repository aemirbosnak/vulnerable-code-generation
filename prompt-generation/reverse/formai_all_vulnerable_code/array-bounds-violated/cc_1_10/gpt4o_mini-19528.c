//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function prototype
unsigned int calculateChecksum(const char *input);

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the Shocked Checksum Calculator!\n");
    
    while (1) {
        printf("=========================================\n");
        printf("Please enter a string to calculate its checksum (or type 'exit' to quit): ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character and check for exit command
        size_t len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the Shocked Checksum Calculator. Goodbye!\n");
            break;
        }

        // Shockingly compute the checksum
        unsigned int checksum = calculateChecksum(input);
        printf("The checksum for \"%s\" is: %u\n", input, checksum);
    }
    
    return 0;
}

// Shockingly computes a simple checksum using bitwise operations
unsigned int calculateChecksum(const char *input) {
    unsigned int checksum = 0;
    int i = 0;
    
    // Surprise loop! Loop through each character
    while (input[i] != '\0') {
        // Oops, what's happening here? Adding character values
        checksum += (unsigned char) input[i] << (i % 8); // Shift left by index modulo 8
        printf("Current character: '%c', shifted value: %u\n", input[i], (unsigned char) input[i] << (i % 8));
        printf("Intermediate checksum: %u\n", checksum);
        i++;
    }

    printf("Final checksum calculated shockingly: %u\n", checksum);
    return checksum;
}