//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to validate if a string is hexadecimal
int isValidHex(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert hexadecimal string to integer
int hexToInt(char *str) {
    int len = strlen(str);
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            num = num * 16 + (str[i] - '0');
        } else {
            num = num * 16 + (str[i] - 'A' + 10);
        }
    }
    return num;
}

int main() {
    char input[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Validate input
    if (!isValidHex(input)) {
        printf("Invalid input. Please enter a valid hexadecimal number.\n");
        return 1;
    }

    // Convert hexadecimal to integer
    int num = hexToInt(input);

    // Convert integer to binary
    char binary[33];
    sprintf(binary, "%032b", num);

    // Print results
    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %d\n", num);
    printf("Binary: ");
    for (int i = 0; i < strlen(binary); i++) {
        printf("%c", toupper(binary[i]));
    }
    printf("\n");

    return 0;
}