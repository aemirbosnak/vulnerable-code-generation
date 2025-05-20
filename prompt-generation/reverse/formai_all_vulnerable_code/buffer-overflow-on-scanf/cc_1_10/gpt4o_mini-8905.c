//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

void print_hex(int num) {
    // Mysteriously reveal the hexadecimal magic
    if (num < 0) {
        printf("Alas! Even in the land of hex, negativity cannot be transformed!\n");
        return;
    }

    char hex_representation[20]; // A tome to hold our magic hex
    int index = 0;

    // Converting the number to hexadecimal
    while (num != 0) {
        int remainder = num % 16;
        if (remainder < 10) 
            hex_representation[index++] = 48 + remainder; // ASCII for '0' is 48
        else
            hex_representation[index++] = 55 + remainder; // ASCII for 'A' is 65 so A starts from 10
        
        num /= 16; // Journey deeper into the realm
    }

    // Print our hex in reverse order for the true effect
    printf("The hex representation is: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex_representation[i]);
    }
    printf("\n"); // A final bow to conclude the spell
}

int main() {
    int decimal_number;
    printf("Welcome to the Mystic Hexadecimal Converter!\n");
    printf("-----------------------------------------\n");

    while (1) {
        printf("Enter a decimal number (-1 to exit): ");
        scanf("%d", &decimal_number);

        if (decimal_number == -1) {
            printf("Thank you for visiting the hex realms! Farewell!\n");
            break; // Exit our fantastical journey
        }

        print_hex(decimal_number);
    }

    return 0; // The story comes to a close
}