//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int decimal, char *hex) {
    int index = 0;
    if (decimal == 0) {
        sprintf(hex, "0");
        return;
    }
    
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = remainder - 10 + 'A';
        }
        decimal = decimal / 16;
    }
    
    hex[index] = '\0';
    
    // Reverse the hex string to get the correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

void printShape(int number) {
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int decimal;
    char hex[20];

    printf("Welcome to the Shape-Shifting Hexadecimal Converter!\n");
    printf("--------------------------------------------------\n");

    // Print a triangle shape
    printShape(5);

    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);

    convertToHex(decimal, hex);

    printf("Hexadecimal Representation: %s\n", hex);
    printf("Thank you for using the converter!\n");

    // Print a square shape at the end
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}