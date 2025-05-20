//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

void to_hex(int decimal, char* hex_output) {
    sprintf(hex_output, "0x%X", decimal);
}

int is_valid_integer(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void display_menu() {
    printf("\n=========================\n");
    printf("  Hexadecimal Converter  \n");
    printf("=========================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("=========================\n");
    printf("Choose an option: ");
}

void handle_conversion() {
    char input[MAX_INPUT_LENGTH];
    int decimal_input;
    char hex_output[20];

    while (1) {
        printf("Enter a decimal number: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting conversion...\n");
            break;
        }

        if (!is_valid_integer(input)) {
            printf("Invalid input! Please enter a valid decimal integer.\n");
            continue;
        }

        decimal_input = atoi(input);
        to_hex(decimal_input, hex_output);
        printf("Decimal: %d --> Hexadecimal: %s\n", decimal_input, hex_output);
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                handle_conversion();
                break;
            case 2:
                printf("Thank you for using the Hexadecimal Converter. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}