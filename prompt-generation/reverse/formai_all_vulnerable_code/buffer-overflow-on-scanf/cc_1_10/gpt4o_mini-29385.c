//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

// Function to calculate checksum
unsigned long calculate_checksum(FILE *file) {
    unsigned long checksum = 0;
    int byte;

    // Read file byte by byte and compute checksum
    while ((byte = fgetc(file)) != EOF) {
        checksum += (unsigned char)byte;
    }

    return checksum;
}

// Function to display the main menu
void display_menu() {
    printf("\nChecksum Calculator\n");
    printf("1. Calculate Checksum\n");
    printf("2. Exit\n");
    printf("Choose an option (1 or 2): ");
}

// Main function
int main() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
    unsigned long checksum;
    int choice;
    int exit_program = 0;

    // Main loop
    while (!exit_program) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the file name: ");
                scanf("%s", filename);

                // Attempt to open the file
                file = fopen(filename, "rb");
                if (file == NULL) {
                    perror("Error opening file");
                    break;
                }

                // Calculate the checksum
                checksum = calculate_checksum(file);
                printf("Checksum for '%s': %lu\n", filename, checksum);
                fclose(file);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit_program = 1;
                break;

            default:
                printf("Invalid choice! Please select 1 or 2.\n");
                break;
        }
    }

    return 0;
}