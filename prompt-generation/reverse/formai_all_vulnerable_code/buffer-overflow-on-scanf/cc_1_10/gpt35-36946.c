//FormAI DATASET v1.0 Category: Color Code Converter ; Style: grateful
//Welcome to my gratitude-filled C Color Code Converter program!

#include <stdio.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char hex[]) {
    int len = strlen(hex);
    int dec = 0;
    int base = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 97 + 10) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 65 + 10) * base;
            base *= 16;
        }
    }
    return dec;
}

// Function to convert decimal to hexadecimal
void dec_to_hex(int dec) {
    int rem;
    char hex[100];
    int i = 0;
    while (dec != 0) {
        rem = dec % 16;
        if (rem < 10)
            hex[i++] = 48 + rem;
        else
            hex[i++] = 55 + rem;
        dec /= 16;
    }
    printf("\nEquivalent hexadecimal number: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
}

int main() {
    char hex[100];
    int dec;
    printf("Welcome to my Color Code Converter program!\n\n");

    // Converting hexadecimal color code to decimal color code
    printf("Enter hexadecimal color code: ");
    scanf("%s", hex);
    dec = hex_to_dec(hex);
    printf("Equivalent decimal color code: %d\n", dec);

    // Converting decimal color code to hexadecimal color code
    printf("\nEnter decimal color code: ");
    scanf("%d", &dec);
    dec_to_hex(dec);

    printf("\nThank you for using my Color Code Converter program!\n");
    return 0;
}