//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Converts a hexadecimal string to an integer value.
 *
 * @param[in] hex The hexadecimal string to convert.
 *
 * @return The integer value of the hexadecimal string.
 */
int hex_to_int(char* hex) {
    int len = strlen(hex);
    int power = len - 1;
    int result = 0;

    for (int i = 0; i < len; i++) {
        int digit = hex[i];
        if (digit >= '0' && digit <= '9') {
            result += (digit - '0') * pow(16, power);
        } else if (digit >= 'A' && digit <= 'F') {
            result += (digit - 'A' + 10) * pow(16, power);
        } else if (digit >= 'a' && digit <= 'f') {
            result += (digit - 'a' + 10) * pow(16, power);
        } else {
            printf("Invalid hexadecimal character: %c\n", digit);
            exit(EXIT_FAILURE);
        }
        power--;
    }

    return result;
}

/**
 * Converts an integer value to a hexadecimal string.
 *
 * @param[in] num The integer value to convert.
 *
 * @return The hexadecimal string representing the integer value.
 */
char* int_to_hex(int num) {
    char* hex = malloc(sizeof(char) * 9);
    sprintf(hex, "%08X", num);
    return hex;
}

int main() {
    char hex_input[9];
    int menu_choice, int_input;

    // Display the menu
    printf("*----------------------*\n");
    printf("|   Hexadecimal Menu   |\n");
    printf("*----------------------*\n");
    printf("|                      |\n");
    printf("| 1. Convert to Decimal |\n");
    printf("| 2. Convert to Binary  |\n");
    printf("|                      |\n");
    printf("*----------------------*\n");

    // Get user input
    printf("Enter a hexadecimal number (up to 8 digits): ");
    scanf("%s", hex_input);

    // Convert hexadecimal to integer
    int_input = hex_to_int(hex_input);

    // Loop until user chooses to exit
    do {
        // Get user choice
        printf("\nEnter a menu option (1-2, or 0 to exit): ");
        scanf("%d", &menu_choice);

        // Perform menu action
        switch (menu_choice) {
            case 1:
                // Convert hexadecimal to decimal
                printf("%s in decimal is: %d\n", hex_input, int_input);
                break;
            case 2:
                // Convert hexadecimal to binary
                printf("%s in binary is: ", hex_input);
                for (int i = 31; i >= 0; i--) {
                    int bit = (int_input >> i) & 1;
                    printf("%d", bit);
                }
                printf("\n");
                break;
            default:
                // Invalid menu choice
                printf("Invalid menu choice!\n");
                break;
        }
    } while (menu_choice != 0);

    // Free memory allocated for hexadecimal string
    free(hex_input);

    return 0;
}