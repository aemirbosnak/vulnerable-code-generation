//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void print_binary(int n);
void banner();
void pause();

int main() {
    int number;
    banner();
    
    printf("Enter a decimal number to convert to binary (or -1 to exit): ");
    while (scanf("%d", &number) && number != -1) {
        if (number < 0) {
            printf("The realm of negative numbers is a different dimension! 🌌\n");
        } else {
            printf("The magical binary representation of %d is: ", number);
            print_binary(number);
            printf("\n");
        }
        printf("Enter another number (or -1 to exit): ");
    }

    printf("Farewell, brave traveler! Until we meet again in the world of 1s and 0s! 👋\n");
    return 0;
}

void print_binary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    
    // A vessel of bits, crafted to hold our binary treasures
    char binary[32]; // For up to a 32-bit integer
    int index = 0;

    // Let the conversion spell begin 🧙‍♂️
    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Save the current bit
        n /= 2; // Divide by 2 for the next iteration
    }

    // The bits of existence are backwards, let's fix that!
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
}

void banner() {
    printf("=======================================\n");
    printf("      Welcome to the Binary Realm!    \n");
    printf("     Transforming Numbers to Binary!   \n");
    printf("=======================================\n");
}

void pause() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // Wait for the user to press Enter
}