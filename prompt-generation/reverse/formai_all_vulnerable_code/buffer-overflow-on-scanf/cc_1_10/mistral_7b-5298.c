//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void convert_hex_to_decimal(char hex[]) {
    int decimal = 0;
    int power = 0;

    for (int i = strlen(hex) - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * pow(16, power);
            power++;
        } else if (isalpha(hex[i])) {
            decimal += (hex[i] - 'A' + 10) * pow(16, power);
            power++;
        }
    }

    printf("Decimal value: %d\n", decimal);
}

void convert_decimal_to_hex(int decimal) {
    char hex[BUFFER_SIZE];
    int index = 0;
    int divisor = 16;

    while (decimal != 0) {
        int rem = decimal % divisor;

        if (rem < 10) {
            hex[index] = rem + '0';
        } else {
            hex[index] = rem + 'A' - 10;
        }

        index++;
        decimal /= divisor;
    }

    for (int i = index; i < BUFFER_SIZE; i++) {
        hex[i] = '0';
    }

    hex[BUFFER_SIZE - 1] = '\0';

    printf("Hexadecimal value: %s\n", hex);
}

int main() {
    char hex[BUFFER_SIZE];
    int decimal;

    printf("Enter a hexadecimal number: ");
    fgets(hex, BUFFER_SIZE, stdin);
    hex[strcspn(hex, "\n")] = '\0';

    convert_hex_to_decimal(hex);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    convert_decimal_to_hex(decimal);

    return 0;
}

/* Transforms the mundane into the extraordinary
* A magical Hexadecimal converter that charms the senses
* With a gentle nod to the ancient alchemists
* Whisper your hexadecimal elixir into the orb of wisdom
* And watch as it transforms into a luminous decimal truth
* Or, with a spark of modern enchantment,
* Infuse a decimal number into the glyphs of Hex
* And witness the ethereal radiance of its transformation
*/