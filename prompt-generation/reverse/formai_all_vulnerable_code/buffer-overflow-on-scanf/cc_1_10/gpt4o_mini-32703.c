//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 1024

typedef struct {
    uint32_t checksum;
    char *buffer;
    size_t length;
} ChecksumCalculator;

// Function to create a checksum calculator
ChecksumCalculator *create_calculator(size_t length) {
    ChecksumCalculator *calc = (ChecksumCalculator *)malloc(sizeof(ChecksumCalculator));
    if (!calc) {
        perror("Failed to allocate memory for ChecksumCalculator");
        exit(EXIT_FAILURE);
    }
    calc->buffer = (char *)malloc(length);
    if (!calc->buffer) {
        perror("Failed to allocate memory for buffer");
        free(calc);
        exit(EXIT_FAILURE);
    }
    calc->length = length;
    calc->checksum = 0;
    return calc;
}

// Function to free the checksum calculator
void destroy_calculator(ChecksumCalculator *calc) {
    free(calc->buffer);
    free(calc);
}

// Function to calculate checksum
uint32_t calculate_checksum(ChecksumCalculator *calc) {
    uint32_t checksum = 0;
    for (size_t i = 0; i < calc->length; i++) {
        checksum += (uint8_t)calc->buffer[i];
    }
    return checksum;
}

// Function to read data into the buffer
void read_data(ChecksumCalculator *calc) {
    printf("Enter the data (max %zu characters): ", calc->length);
    fgets(calc->buffer, calc->length, stdin);
    // Remove newline character if it's there
    calc->buffer[strcspn(calc->buffer, "\n")] = '\0'; 
    calc->length = strlen(calc->buffer);
}

// Function to display the checksum
void display_checksum(uint32_t checksum) {
    printf("Checksum: %u\n", checksum);
}

// Main function
int main() {
    size_t buffer_size;

    printf("Enter buffer size (number of characters, max %d): ", BLOCK_SIZE);
    scanf("%zu", &buffer_size);
    getchar(); // Clear newline from the input buffer

    if (buffer_size > BLOCK_SIZE) {
        printf("Buffer size exceeds maximum of %d. Setting to maximum.\n", BLOCK_SIZE);
        buffer_size = BLOCK_SIZE;
    }

    ChecksumCalculator *calc = create_calculator(buffer_size);

    read_data(calc);
    calc->checksum = calculate_checksum(calc);
    display_checksum(calc->checksum);

    destroy_calculator(calc);
    return 0;
}