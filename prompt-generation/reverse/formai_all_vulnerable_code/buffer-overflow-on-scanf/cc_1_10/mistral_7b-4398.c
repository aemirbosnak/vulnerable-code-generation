//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// Function to convert a hexadecimal string to an integer
int hex_to_dec(char hex[]) {
    int dec = 0, i;
    for (i = 0; i < 2; i++) {
        if (isdigit(hex[i])) dec += (hex[i] - '0') * (16 * (1 - i));
        else dec += (isupper(hex[i]) ? (10 + (hex[i] - 'A')) : (hex[i] - 'a')) * 16;
    }
    return dec;
}

// Function to swap two bits at given positions in an integer
void swap_bits(int *num, int pos1, int pos2) {
    int mask1 = (1 << pos1) | (~(1 << pos2) & *num);
    int mask2 = ~(mask1);
    *num = mask1 | mask2;
}

// Function to print a custom color palette based on user input
void print_palette(int r, int g, int b) {
    int red = r, green = g, blue = b;

    // Apply bitwise operations to create custom colors
    swap_bits(&red, 5, 3); // Swap R's bit 5 and 3
    swap_bits(&green, 3, 5); // Swap G's bit 3 and 5
    swap_bits(&blue, 2, 6); // Swap B's bit 2 and 6

    printf("\nCustom Color Palette:\n");
    printf("R: %d (%#02X)\n", red, red);
    printf("G: %d (%#02X)\n", green, green);
    printf("B: %d (%#02X)\n", blue, blue);
}

int main() {
    char input[11];
    int r, g, b;

    printf("Enter a hexadecimal RGB color (e.g., #FF00FF): ");
    scanf("%s", input);

    // Validate input and extract RGB components
    if (strlen(input) != 7) {
        printf("Invalid input.\n");
        return 1;
    }

    r = hex_to_dec(input + 1);
    g = hex_to_dec(input + 3);
    b = hex_to_dec(input + 5);

    print_palette(r, g, b);

    return 0;
}