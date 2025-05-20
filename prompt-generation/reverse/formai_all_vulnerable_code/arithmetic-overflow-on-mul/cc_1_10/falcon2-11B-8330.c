//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEX_SIZE 16

// Function to convert a hexadecimal number to decimal
int hex_to_dec(char* hex) {
    int decimal = 0;
    for (int i = 0; i < strlen(hex); i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal *= 16;
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal *= 16;
            decimal += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal *= 16;
            decimal += hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            return -1;
        }
    }
    return decimal;
}

// Function to convert a decimal number to hexadecimal
char* dec_to_hex(int decimal) {
    static char hex[MAX_HEX_SIZE];
    int hex_size = 0;
    int i = MAX_HEX_SIZE;

    while (decimal > 0) {
        if (decimal >= 16) {
            hex[hex_size++] = 'A' + (decimal % 16);
            decimal /= 16;
        } else if (decimal >= 10) {
            hex[hex_size++] = 'A' + (decimal % 10);
            decimal /= 10;
        } else if (decimal >= 0) {
            hex[hex_size++] = '0' + decimal;
            decimal = 0;
        } else {
            printf("Invalid decimal number: %d\n", decimal);
            return NULL;
        }
    }

    while (hex_size < MAX_HEX_SIZE) {
        hex[hex_size++] = '0';
    }

    return hex;
}

int main() {
    char hex[MAX_HEX_SIZE];
    int decimal;

    // Prompt the user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");
    fgets(hex, sizeof(hex), stdin);

    // Convert the hexadecimal number to decimal
    decimal = hex_to_dec(hex);
    if (decimal == -1) {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }

    // Convert the decimal number to hexadecimal
    char* hex_str = dec_to_hex(decimal);
    if (hex_str == NULL) {
        printf("Invalid decimal number.\n");
        return 1;
    }

    // Print the hexadecimal number
    printf("Hexadecimal representation: %s\n", hex_str);

    // Free the memory allocated for the hexadecimal string
    free(hex_str);

    return 0;
}