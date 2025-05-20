//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hexToChar(char hex[]) {
    int decimal = 0;
    for (int i = 0; i < strlen(hex); i++) {
        decimal += hex[i] * (1 << (4 * (strlen(hex) - i - 1)));
    }
    return (char) decimal;
}

char* charToHex(char c) {
    char* hex = malloc(3 * sizeof(char));
    sprintf(hex, "%02x", c);
    return hex;
}

void convertHexToChar() {
    char hex[17];
    printf("Enter a hexadecimal string (max length 16): ");
    scanf("%16s", hex);

    char c = hexToChar(hex);

    printf("Hex string %s is equivalent to character '%c' (decimal value: %d)\n", hex, c, (int) c);
}

void convertCharToHex() {
    char c;
    printf("Enter a character to convert to hexadecimal: ");
    scanf(" %c", &c);

    char* hex = charToHex(c);

    printf("Character '%c' (decimal value: %d) is equivalent to hexadecimal string %s\n", c, (int) c, hex);
    free(hex);
}

int main() {
    char input[10];

    printf("Welcome to the Hexadecimal Converter program!\n");

    while (1) {
        printf("Please select an option:\n1. Convert hexadecimal to char\n2. Convert char to hexadecimal\n3. Quit\n");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            convertHexToChar();
        } else if (strcmp(input, "2") == 0) {
            convertCharToHex();
        } else if (strcmp(input, "3") == 0) {
            printf("Thank you for using the Hexadecimal Converter program.\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}