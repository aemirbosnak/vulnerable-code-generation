//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

// Function prototypes
void convert_to_hex(int number);
void convert_to_dec(char *hex_str);
void display_menu();
void clear_input_buffer();

int main() {
    int choice;
    char hex_input[MAX_INPUT_SIZE];
    int decimal_input;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer(); // Clear input buffer to avoid issues with fgets

        switch(choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal_input);
                convert_to_hex(decimal_input);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                fgets(hex_input, MAX_INPUT_SIZE, stdin);
                // Remove newline character if present
                hex_input[strcspn(hex_input, "\n")] = 0;
                convert_to_dec(hex_input);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please select a valid option.\n");
        }
        
        printf("\n");
    } while(choice != 3);

    return 0;
}

// Function to convert a decimal number to hexadecimal
void convert_to_hex(int number) {
    char hex[20];
    int index = 0;

    if (number == 0) {
        strcpy(hex, "0");
    } else {
        while (number > 0) {
            int remainder = number % 16;
            if (remainder < 10) {
                hex[index++] = 48 + remainder; // 48 is ASCII for '0'
            } else {
                hex[index++] = 55 + remainder; // 55 is for 'A' in ASCII
            }
            number /= 16;
        }
        hex[index] = '\0';

        // Reverse the string
        for(int i = 0; i < index / 2; i++) {
            char temp = hex[i];
            hex[i] = hex[index - 1 - i];
            hex[index - 1 - i] = temp;
        }
    }

    printf("Hexadecimal representation: %s\n", hex);
}

// Function to convert a hexadecimal string to a decimal number
void convert_to_dec(char *hex_str) {
    int decimal_value = 0;
    int base = 1; // 16^0

    // Start from the last character of the hex string
    int length = strlen(hex_str);
    for (int i = length - 1; i >= 0; i--) {
        char current_char = hex_str[i];
        int value;
        
        if (current_char >= '0' && current_char <= '9') {
            value = current_char - '0';
        } else if (current_char >= 'A' && current_char <= 'F') {
            value = current_char - 'A' + 10;
        } else if (current_char >= 'a' && current_char <= 'f') {
            value = current_char - 'a' + 10;
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        
        decimal_value += value * base;
        base *= 16;
    }

    printf("Decimal representation: %d\n", decimal_value);
}

// Function to display the menu
void display_menu() {
    printf("Hexadecimal Converter\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
}

// Function to clear the input buffer
void clear_input_buffer() {
    while ((getchar()) != '\n');
}