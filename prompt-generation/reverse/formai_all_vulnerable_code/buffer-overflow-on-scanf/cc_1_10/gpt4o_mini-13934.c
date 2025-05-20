//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256
#define BUFFER_SIZE 16

void to_hex(int value, char *output) {
    sprintf(output, "%X", value);
}

void to_dec(const char *hex_input, int *dec_output) {
    sscanf(hex_input, "%x", dec_output);
}

void cleanup_input(char *input) {
    // Convert input to uppercase and remove potential leading zeros
    for (int i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }
    
    // Check for invalid characters
    for (int i = 0; input[i]; i++) {
        if (!isxdigit(input[i])) {
            fprintf(stderr, "Invalid hex character detected: %c\n", input[i]);
            exit(EXIT_FAILURE);
        }
    }
}

void hex_to_dec_conversion() {
    char hex_input[MAX_INPUT];
    int dec_output;

    printf("In the ruins of the old world, we must cling to knowledge.\n");
    printf("Enter a hexadecimal number (0 to exit): ");

    while (fgets(hex_input, sizeof(hex_input), stdin) != NULL) {
        // Remove trailing newline character
        hex_input[strcspn(hex_input, "\n")] = 0;

        if (strcmp(hex_input, "0") == 0) {
            printf("Farewell, traveler. Remember the past.\n");
            break;
        }

        cleanup_input(hex_input);
        to_dec(hex_input, &dec_output);
        printf("Hexadecimal: %s | Decimal: %d\n", hex_input, dec_output);
        printf("Enter another hexadecimal number (0 to exit): ");
    }
}

void dec_to_hex_conversion() {
    char input[MAX_INPUT];
    int value;

    printf("In this world of desolation, can you still count?\n");
    printf("Enter a decimal number (0 to exit): ");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "0") == 0) {
            printf("The cycle ends here. Be vigilant!\n");
            break;
        }

        value = atoi(input);
        char hex_output[BUFFER_SIZE];
        to_hex(value, hex_output);
        printf("Decimal: %d | Hexadecimal: %s\n", value, hex_output);
        printf("Enter another decimal number (0 to exit): ");
    }
}

int main() {
    int menu_selection;

    printf("Amidst the chaos of a collapsing world, knowledge is power.\n");
    printf("Choose your path:\n");
    printf("1. Convert Hexadecimal to Decimal\n");
    printf("2. Convert Decimal to Hexadecimal\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &menu_selection);
        getchar(); // To consume leftover newline character

        switch (menu_selection) {
            case 1:
                hex_to_dec_conversion();
                break;
            case 2:
                dec_to_hex_conversion();
                break;
            case 3:
                printf("A wise choice. Goodbye, survivor.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Choose again...\n");
        }
    }

    return 0;
}