//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToHex(int decimal, char* hex) {
    int index = 0, temp;

    if (decimal == 0) {
        strcpy(hex, "0");
        return;
    }

    while (decimal != 0) {
        temp = decimal % 16;

        if (temp < 10) {
            hex[index++] = temp + '0';
        } else {
            hex[index++] = temp - 10 + 'A';
        }

        decimal /= 16;
    }

    hex[index] = '\0';

    // Reverse the string
    int start = 0;
    int end = index - 1;
    char tempChar;
    while (start < end) {
        tempChar = hex[start];
        hex[start] = hex[end];
        hex[end] = tempChar;
        start++;
        end--;
    }
}

int main() {
    char hex[20];
    int decimal;
    char choice;

    printf("Welcome to the C Hexadecimal Converter!\n");
    printf("This program will convert decimal numbers to hexadecimal.\n");
    printf("Enter 'q' to quit at any time.\n\n");

    do {
        printf("Please enter a decimal number: ");
        if (scanf("%d", &decimal) != 1) {
            // Handle input errors
            fscanf(stdin, "%c", &choice);
            if (choice == 'q') {
                break;
            } else {
                printf("Invalid input! Please try again.\n");
                while (getchar() != '\n'); // clear buffer
                continue;
            }
        }

        convertToHex(decimal, hex);
        printf("Decimal: %d -> Hexadecimal: %s\n", decimal, hex);
        
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice);

        while (getchar() != '\n'); // clear buffer
    } while (choice == 'y');

    printf("Thank you for using the C Hexadecimal Converter. Goodbye!\n");
    return 0;
}