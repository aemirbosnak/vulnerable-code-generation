//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol;
    unsigned int value;
} hex_t;

const hex_t hex_array[] = {
    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
    {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
};

unsigned int hex_string_to_decimal(const char* hex_string) {
    unsigned int decimal = 0;
    unsigned int power = 0;

    for (int i = strlen(hex_string) - 1; i >= 0; --i) {
        for (int j = 0; j < sizeof(hex_array) / sizeof(hex_t); ++j) {
            if (hex_array[j].symbol == toupper(hex_string[i])) {
                decimal += (hex_array[j].value << power);
                break;
            }
            power += 4;
        }
    }

    return decimal;
}

void decimal_to_hex_string(unsigned int decimal, char* hex_string, int length) {
    for (int i = 0; i < length; ++i) {
        hex_t hex_char = hex_array[decimal & 0xF];
        decimal >>= 4;

        hex_string[i] = hex_char.symbol;
        if (!decimal) break;
    }

    if (!decimal) return;

    hex_string[length] = ' '; // Add a space for odd-length hex numbers
    decimal_to_hex_string(decimal, hex_string, length + 1);
}

void print_hexenbox_welcome() {
    printf("\n===============\n");
    printf("| The Hexenbox |");
    printf("\n===============\n");
    printf("| Hexadecimal  |");
    printf("\n| Converter    |");
    printf("\n===============\n");
}

int main() {
    char input[32];
    char output[32];
    unsigned int decimal;

    print_hexenbox_welcome();

    printf("\nEnter a hexadecimal string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    decimal = hex_string_to_decimal(input);

    printf("\nThe decimal equivalent of \"%s\" is: %u\n", input, decimal);

    printf("\nEnter a decimal number: ");
    scanf("%u", &decimal);

    printf("\nThe hexadecimal equivalent of %u is: ", decimal);
    int length = sizeof(output) / sizeof(output[0]);
    decimal_to_hex_string(decimal, output, length);
    printf("%s\n", output);

    return 0;
}