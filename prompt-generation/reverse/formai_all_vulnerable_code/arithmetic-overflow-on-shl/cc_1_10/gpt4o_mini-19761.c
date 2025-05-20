//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate checksum using simple additive method
unsigned int calculate_checksum(const char *data) {
    unsigned int checksum = 0;
    while (*data) {
        checksum += (unsigned char)*data++;
    }
    return checksum;
}

// Function to print the binary representation of the checksum
void print_binary(unsigned int checksum) {
    printf("Binary Representation of Checksum: ");
    for (int i = sizeof(checksum) * 8 - 1; i >= 0; i--) {
        putchar((checksum & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

// Function to validate the input data
void validate_input(const char *data) {
    if (data == NULL || strlen(data) == 0) {
        fprintf(stderr, "Input data cannot be empty!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to read data from the user
void read_input_data(char *buffer, size_t size) {
    printf("Enter the data to calculate checksum (max %zu characters): ", size - 1);
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = 0;
    } else {
        fprintf(stderr, "Failed to read input!\n");
        exit(EXIT_FAILURE);
    }
}

// Main function to demonstrate the checksum calculator
int main() {
    const size_t BUFFER_SIZE = 256;
    char input_data[BUFFER_SIZE];

    // Read input from the user
    read_input_data(input_data, BUFFER_SIZE);
    
    // Validate the input
    validate_input(input_data);

    // Calculate checksum
    unsigned int checksum = calculate_checksum(input_data);

    // Output the results
    printf("Input Data: %s\n", input_data);
    printf("Checksum (Decimal): %u\n", checksum);
    print_binary(checksum);

    // Returning success state
    return 0;
}