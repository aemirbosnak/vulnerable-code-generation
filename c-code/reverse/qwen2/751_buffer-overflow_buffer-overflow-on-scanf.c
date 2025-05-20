#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

void hexToDec(const char *hex) {
    long int dec = strtol(hex, NULL, 16);
    printf("Decimal: %ld\n", dec);
}

void decToHex(long int dec) {
    if (dec == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }
    char hex[100];
    int i = 0;
    while (dec != 0) {
        int remainder = dec % 16;
        if (remainder < 10)
            hex[i++] = remainder + '0';
        else
            hex[i++] = remainder - 10 + 'A';
        dec /= 16;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("Hexadecimal: %c", hex[j]);
    printf("\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    int choice;

    printf("Enter your choice:\n1. Hexadecimal to Decimal\n2. Decimal to Hexadecimal\n");
    scanf("%d", &choice);

    getchar(); // Consume newline character left by scanf

    printf("Enter the number: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    switch (choice) {
        case 1:
            hexToDec(input);
            break;
        case 2:
            decToHex(atol(input));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
