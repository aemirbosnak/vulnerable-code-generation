//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum
unsigned char calculate_checksum(const unsigned char *data, size_t length) {
    unsigned char checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum ^= data[i]; // Using XOR operation for checksum
    }
    return checksum; 
}

// Function to perform the checksum calculation on a user-defined string
void checksum_from_string() {
    char input[256];

    printf("\n🎉 Surprise! Let's calculate a checksum for a string. 🎉\n");
    printf("Please enter a string (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    
    // Removing newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    unsigned char checksum = calculate_checksum((unsigned char *)input, strlen(input));
    printf("🔑 Checksum for the input string: 0x%02X\n", checksum);
}

// Function to read from a file and calculate its checksum
void checksum_from_file() {
    char filename[256];
    
    printf("\n🗂️ Surprise! Now let's calculate a checksum for a file. 🗂️\n");
    printf("Please enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char buffer[1024];
    size_t bytesRead;
    unsigned char checksum = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        checksum = calculate_checksum(buffer, bytesRead);
        printf("Read %zu bytes, current checksum: 0x%02X\n", bytesRead, checksum);
    }

    fclose(file);
    printf("✅ Final checksum for file '%s': 0x%02X\n", filename, checksum);
}

// Main function to run the checksum calculator
int main() {
    int choice;

    do {
        printf("\n🤔 Surprise! What would you like to do?\n");
        printf("1. Calculate checksum from string\n");
        printf("2. Calculate checksum from file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after entering choice

        switch (choice) {
            case 1:
                checksum_from_string();
                break;
            case 2:
                checksum_from_file();
                break;
            case 3:
                printf("🚪 Exiting the checksum calculator. Goodbye! 🎈\n");
                break;
            default:
                printf("⚠️ Invalid option! Please choose again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}