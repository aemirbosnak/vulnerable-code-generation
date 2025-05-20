//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_LENGTH 64
#define MAX_BINARY_LENGTH (MAX_INPUT_LENGTH * 8) + 1

void print_binary(const char* binary) {
    printf("Binary Representation: %s\n", binary);
}

void string_to_binary(const char* input, char* binary_output) {
    binary_output[0] = '\0'; // Initialize the binary output string
    for (size_t i = 0; i < strlen(input); ++i) {
        char byte[9] = {0}; // 8 bits + 1 for null terminator
        for (int j = 7; j >= 0; --j) {
            byte[j] = (input[i] & (1 << (7 - j))) ? '1' : '0';
        }
        strcat(binary_output, byte);
        strcat(binary_output, " "); // Space between bytes for readability
    }
}

void convert_decimal_to_binary(int input, char* binary_output) {
    int index = 31;
    binary_output[index + 1] = '\0'; // Null terminator
    for (int i = 0; i < 32; ++i) {
        binary_output[index--] = (input & (1 << i)) ? '1' : '0';
    }
}

void display_menu() {
    printf("=== Futuristic Binary Converter ===\n");
    printf("1. Convert Text to Binary\n");
    printf("2. Convert Decimal to Binary\n");
    printf("3. Exit\n");
    printf("====================================\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char binary_output[MAX_BINARY_LENGTH];
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a string to convert to binary: ");
                scanf(" %[^\n]", input); // Read input with spaces
                string_to_binary(input, binary_output);
                print_binary(binary_output);
                break;

            case 2:
                printf("Enter an integer to convert to binary: ");
                int decimal_input;
                scanf("%d", &decimal_input);
                convert_decimal_to_binary(decimal_input, binary_output);
                print_binary(binary_output);
                break;

            case 3:
                printf("Exiting program... [Time Travel Activated]\n");
                exit(0);

            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n"); // New line for better separation in output
    }
    
    return 0;
}