//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the buffer size
#define BUFFER_SIZE 256

// Function to calculate XOR checksum
unsigned char calculate_checksum(const char *data) {
    unsigned char checksum = 0;
    
    // Iterate through each character and perform XOR operation
    while (*data) {
        checksum ^= *data++;
    }
    return checksum; // Return the final checksum
}

// Function to simulate reading data from a file (for demonstration purposes)
void read_data_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    unsigned char checksum = 0;

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), file)) {
        total_bytes += strlen(buffer); // Update total byte count
        checksum ^= calculate_checksum(buffer); // Calculate checksum
    }

    printf("Total Bytes Read: %zu\n", total_bytes);
    printf("Checksum: 0x%02X\n", checksum); // Print checksum in hexadecimal

    fclose(file); // Close the file
}

// Function to display a simple menu for user interaction
void display_menu() {
    printf("\n==== Checksum Calculator ====\n");
    printf("1. Calculate Checksum from File\n");
    printf("2. Exit\n");
    printf("===========================\n");
}

// Function to validate user input
int get_user_selection() {
    int choice;
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || (choice < 1 || choice > 2)) {
        while (getchar() != '\n'); // Clear invalid input
        printf("Please enter a valid choice (1 or 2): ");
    }
    return choice;
}

// Main function entry point
int main() {
    int choice;
    const char *filename = "example.txt"; // example file name 

    // Example data writing (creates a sample file for checksum calculation)
    FILE *write_file = fopen(filename, "w");
    if (write_file == NULL) {
        perror("Could not create file");
        return EXIT_FAILURE;
    }

    // Writing some example data to the file
    fprintf(write_file, "Hello, World!\n");
    fprintf(write_file, "Checksum Calculation Example\n");
    fprintf(write_file, "Check this out!\n");
    fclose(write_file); // Close the file after writing

    display_menu(); // Show the menu
    choice = get_user_selection(); // Get user's choice

    // Process user selection
    switch (choice) {
        case 1:
            read_data_from_file(filename); // Calculate checksum
            break;
        case 2:
            printf("Exiting the program.\n");
            break; // Exit
    }

    return 0; // End of program
}