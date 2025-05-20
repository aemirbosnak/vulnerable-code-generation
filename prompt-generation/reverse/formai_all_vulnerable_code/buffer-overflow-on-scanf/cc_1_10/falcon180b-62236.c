//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LEN 8

// Function to convert a string of hexadecimal characters to an integer
unsigned int hex_to_int(char *hex) {
    unsigned int result = 0;
    int i = 0;
    while (hex[i]!= '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result = (result << 4) | (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result = (result << 4) | (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result = (result << 4) | (hex[i] - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
        i++;
    }
    return result;
}

// Function to convert an integer to a string of hexadecimal characters
char *int_to_hex(unsigned int num, char *hex) {
    int i = 0;
    while (num!= 0) {
        hex[i] = (num % 16 < 10)? (num % 16) + '0' : (num % 16) + 'A' - 10;
        num /= 16;
        i++;
    }
    hex[i] = '\0';
    return hex;
}

int main() {
    char hex_str[MAX_HEX_LEN + 1] = {0};
    unsigned int decimal_num;

    // Prompt the user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_str);

    // Convert the hexadecimal string to an integer
    decimal_num = hex_to_int(hex_str);

    // Convert the integer to a string of hexadecimal characters
    char decimal_hex[MAX_HEX_LEN + 1] = {0};
    int_to_hex(decimal_num, decimal_hex);

    // Print the result
    printf("Hexadecimal number: %s\n", hex_str);
    printf("Decimal number: %s\n", decimal_hex);

    return 0;
}