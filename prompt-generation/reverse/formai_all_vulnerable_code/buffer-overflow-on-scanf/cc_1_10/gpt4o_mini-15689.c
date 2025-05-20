//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

// Function to calculate the checksum of a string
unsigned int calculate_checksum(const char* data) {
    unsigned int checksum = 0;
    while (*data) {
        checksum += *data++;
    }
    return checksum;
}

// Function to read a file and calculate the checksum
unsigned int calculate_file_checksum(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    unsigned int checksum = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        checksum += ch;
    }
    
    fclose(file);
    return checksum;
}

// Function to display the checksum result
void display_checksum(const char* input_type, unsigned int checksum) {
    printf("The checksum for the %s is: %u\n", input_type, checksum);
}

// Main function
int main() {
    int choice;

    printf("Checksum Calculator\n");
    printf("1. Calculate checksum from string input\n");
    printf("2. Calculate checksum from file input\n");
    printf("Choose an option (1 or 2): ");
    
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter 1 or 2.\n");
        return EXIT_FAILURE;
    }

    // Buffer to store string input if option 1 is chosen
    char data[MAX_INPUT_LENGTH];

    switch (choice) {
        case 1:
            printf("Enter the string: ");
            scanf(" %[^\n]%*c", data); // Read a line of text
            unsigned int string_checksum = calculate_checksum(data);
            display_checksum("string input", string_checksum);
            break;

        case 2:
            printf("Enter the filename: ");
            char filename[MAX_INPUT_LENGTH];
            scanf(" %[^\n]%*c", filename);
            unsigned int file_checksum = calculate_file_checksum(filename);
            display_checksum("file input", file_checksum);
            break;

        default:
            fprintf(stderr, "Error: Invalid option selected.\n");
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}