//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

void rgb_to_hex(int r, int g, int b, char hex[7]) {
    int values[3] = {r, g, b};
    char hex_digits[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < 3; i++) {
        int digit1 = values[i] / 16;
        int digit2 = values[i] % 16;

        if (digit1 > 9) {
            digit1 += 55;
            hex[i * 2] = hex_digits[digit1];
        } else {
            hex[i * 2] = hex_digits[digit1];
        }

        if (digit2 > 9) {
            digit2 += 55;
            hex[i * 2 + 1] = hex_digits[digit2];
        } else {
            hex[i * 2 + 1] = hex_digits[digit2];
        }
    }

    hex[6] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <R> <G> <B>\n", argv[0]);
        return 1;
    }

    int r, g, b;

    if (sscanf(argv[1], "%d%*c", &r) != 1 ||
        sscanf(argv[2], "%d%*c", &g) != 1 ||
        sscanf(argv[3], "%d%*c", &b) != 1) {
        printf("Invalid arguments. Please provide valid RGB values.\n");
        return 1;
    }

    char hex[SIZE];
    rgb_to_hex(r, g, b, hex);

    printf("The hexadecimal color code for RGB(%d, %d, %d) is: #%s\n", r, g, b, hex);

    return 0;
}