//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function prototypes
void display_menu();
void convert_to_hex(int decimal);
void convert_from_hex(char *hex_str);
void clear_input_buffer();

int main() {
    int choice;
    char hex_input[MAX_INPUT_SIZE];

    while (1) {
        display_menu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            clear_input_buffer();
            continue;
        }

        clear_input_buffer(); // Clear the input buffer for safety

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number to convert to hexadecimal: ");
                if (scanf("%d", &decimal) != 1 || decimal < 0) {
                    printf("Invalid input. Please enter a non-negative integer.\n");
                    clear_input_buffer();
                    continue;
                }
                convert_to_hex(decimal);
                break;
            }
            case 2: {
                printf("Enter a hexadecimal number to convert to decimal: ");
                fgets(hex_input, MAX_INPUT_SIZE, stdin);
                hex_input[strcspn(hex_input, "\n")] = 0; // Remove newline character
                convert_from_hex(hex_input);
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            case 4:
                printf("Invalid choice. Please select a valid option.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

// Function to display the menu
void display_menu() {
    printf("\nHexadecimal Converter Menu:\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
}

// Function to convert decimal to hexadecimal
void convert_to_hex(int decimal) {
    char hex_str[20];
    snprintf(hex_str, sizeof(hex_str), "%X", decimal); // Convert decimal to hex and store in hex_str
    printf("Decimal: %d -> Hexadecimal: %s\n", decimal, hex_str);
}

// Function to convert hexadecimal to decimal
void convert_from_hex(char *hex_str) {
    int decimal = (int)strtol(hex_str, NULL, 16); // Use strtol to convert hex string to decimal
    if (decimal == 0 && strcmp(hex_str, "0") != 0) {
        printf("Invalid hexadecimal input.\n");
    } else {
        printf("Hexadecimal: %s -> Decimal: %d\n", hex_str, decimal);
    }
}

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer until newline or EOF
}