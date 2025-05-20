//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
unsigned long calculate_checksum(const char *data);
void print_checksum(unsigned long checksum, const char *format);
void convert_to_hex(unsigned long checksum);

int main() {
    char data[256];
    int choice;
    unsigned long checksum;

    printf("Welcome to the Shape Shifting Checksum Calculator!\n");
    printf("Enter a string to calculate its checksum: ");
    fgets(data, sizeof(data), stdin);
    
    // Remove newline character from fgets input
    size_t len = strlen(data);
    if (len > 0 && data[len - 1] == '\n') {
        data[len - 1] = '\0';
    }

    checksum = calculate_checksum(data);

    printf("Choose the format of your checksum:\n");
    printf("1. Integer\n");
    printf("2. Hexadecimal\n");
    printf("Select an option (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_checksum(checksum, "integer");
            break;
        case 2:
            convert_to_hex(checksum);
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
    }

    printf("Thank you for using the Shape Shifting Checksum Calculator!\n");
    return 0;
}

// Function to calculate checksum
unsigned long calculate_checksum(const char *data) {
    unsigned long sum = 0;
    for (size_t i = 0; data[i] != '\0'; i++) {
        sum += (unsigned char)data[i];
    }
    return sum;
}

// Function to print checksum in integer format
void print_checksum(unsigned long checksum, const char *format) {
    printf("The checksum of your input in %s format is: %lu\n", format, checksum);
}

// Function to convert checksum to hexadecimal and print it
void convert_to_hex(unsigned long checksum) {
    printf("The checksum of your input in hexadecimal format is: ");
    printf("0x%lX\n", checksum);
}