//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to perform a simple hash on input data
uint32_t simple_hash(const char *data) {
    uint32_t hash = 5381;
    int c;

    while ((c = *data++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

// Function to convert hash to hexadecimal format
void hash_to_hex(uint32_t hash, char *output) {
    sprintf(output, "%08x", hash);
}

// Function to process the input string and generate a hash
void process_input(const char *input) {
    uint32_t hash = simple_hash(input);
    char hex_output[9]; // 8 hex digits + 1 for null terminator
    hash_to_hex(hash, hex_output);
    printf("Input: %s\nHash: %s\n", input, hex_output);
}

// Function to read input string from the user
void read_input() {
    char input[256];  // Buffer for user input, allowing for strings of length 255
    printf("Enter a string to hash (max 255 characters): ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character if present
        input[strcspn(input, "\n")] = 0; 
        process_input(input);
    } else {
        printf("Error reading input.\n");
    }
}

// Function to demonstrate hashing multiple inputs
void hash_multiple_inputs() {
    const char *inputs[] = {
        "Hello, World!",
        "Learning C!",
        "Cryptographic Hash Functions",
        "Sample Input 1",
        "Sample Input 2"
    };
    
    for (size_t i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++) {
        process_input(inputs[i]);
    }
}

// Main function
int main() {
    int choice;

    printf("Welcome to the Simple Hash Function Program!\n");
    printf("1. Hash User Input\n");
    printf("2. Hash Predefined Inputs\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // Consumes the newline character after entering choice

        switch (choice) {
            case 1:
                read_input();
                break;
            case 2:
                hash_multiple_inputs();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
        
        printf("\n");
    }

    return 0;
}