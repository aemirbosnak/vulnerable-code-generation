//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function to calculate checksum
uint32_t calculate_checksum(const uint8_t *data, size_t length) {
    uint32_t checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += data[i]; // Add each byte to the checksum
    }
    return checksum;
}

// Function to display the checksum in hexadecimal
void print_checksum(uint32_t checksum) {
    printf("Checksum: 0x%08X\n", checksum);
}

// Function to interactively read data from user
void read_data(uint8_t *buffer, size_t max_length) {
    printf("Enter data (up to %zu characters, press ENTER to finish):\n", max_length - 1);
    if (fgets((char *)buffer, max_length, stdin) != NULL) {
        size_t length = strlen((char *)buffer);
        // If the string was cut off because of max_length, truncate it
        if (length == (max_length - 1) && buffer[length - 1] != '\n') {
            buffer[length - 1] = '\0'; // Null-terminate the string
        } else {
            buffer[length] = '\0'; // Ensure it's null-terminated
        }
    }
}

// Function to display original data
void display_data(const uint8_t *data) {
    printf("Original data: %s\n", data);
}

// Function to initiate checksum calculation
void initiate_checksum() {
    const size_t MAX_LENGTH = 256;
    uint8_t data[MAX_LENGTH];
    
    read_data(data, MAX_LENGTH);
    display_data(data);

    uint32_t checksum = calculate_checksum(data, strlen((char *)data));
    print_checksum(checksum);
}

// Main function
int main() {
    printf("Welcome to the Checksum Calculator!\n");
    char choice;

    do {
        initiate_checksum();
        printf("Do you want to calculate another checksum? (y/n): ");
        scanf(" %c", &choice);
        // Clear the newline character from the input buffer
        while (getchar() != '\n') { continue; }
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Checksum Calculator. Goodbye!\n");
    return 0;
}