//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

// Function to calculate XOR checksum
unsigned char calculate_checksum(const char *data) {
    unsigned char checksum = 0;
    while (*data) {
        checksum ^= *data; // XOR operation
        data++;
    }
    return checksum;
}

// Function to display menu options
void display_menu() {
    printf("\n=== Checksum Calculator ===\n");
    printf("1. Calculate checksum\n");
    printf("2. Exit\n");
    printf("===========================\n");
}

// Main function
int main() {
    char input[MAX_LENGTH];
    unsigned char checksum;
    int choice;

    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after integer input

        switch (choice) {
            case 1:
                printf("Enter a string to calculate its checksum (max %d characters): ", MAX_LENGTH - 1);
                fgets(input, MAX_LENGTH, stdin);

                // Remove newline character if present (fgets includes it)
                input[strcspn(input, "\n")] = 0;

                checksum = calculate_checksum(input);
                printf("The checksum for string \"%s\" is: 0x%02X\n", input, checksum);
                break;

            case 2:
                printf("Exiting the program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }

    } while (choice != 2);

    return 0;
}