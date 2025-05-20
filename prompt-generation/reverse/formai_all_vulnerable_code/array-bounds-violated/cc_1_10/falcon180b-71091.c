//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_NUM_SIZE 32

int main() {
    char hex_str[MAX_NUM_SIZE];
    int i = 0, j = 0, num_size = 0;
    int decimal = 0;
    int is_negative = FALSE;

    printf("Enter a hexadecimal number: ");
    fgets(hex_str, MAX_NUM_SIZE, stdin);

    // Remove newline character from input
    hex_str[num_size - 1] = '\0';

    // Check if the input is a negative number
    if (hex_str[0] == '-') {
        is_negative = TRUE;
        i = 1;
    } else {
        i = 0;
    }

    // Convert hexadecimal to decimal
    while (hex_str[i]!= '\0') {
        if (isdigit(hex_str[i])) {
            decimal = decimal * 16 + hex_str[i] - '0';
        } else if (isupper(hex_str[i])) {
            decimal = decimal * 16 + hex_str[i] - 'A' + 10;
        } else if (islower(hex_str[i])) {
            decimal = decimal * 16 + hex_str[i] - 'a' + 10;
        } else {
            printf("Invalid character found in input.\n");
            return 1;
        }
        i++;
    }

    // Print the decimal equivalent
    if (is_negative) {
        printf("-");
    }
    printf("%d\n", decimal);

    return 0;
}