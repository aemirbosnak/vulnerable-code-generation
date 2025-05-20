//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a hexadecimal string to a decimal integer
long int hex_to_dec(char* hex_str) {
    int i, j, len;
    long int result = 0;
    char buffer[100];

    // Check for leading zeros
    if (hex_str[0] == '0' && hex_str[1] == 'x') {
        strcat(hex_str, &hex_str[2]);
    }

    // Check for uppercase letters
    for (i = 0; i < strlen(hex_str); i++) {
        if (isupper(hex_str[i])) {
            hex_str[i] = tolower(hex_str[i]);
        }
    }

    // Check for invalid characters
    for (i = 0; i < strlen(hex_str); i++) {
        if (!isxdigit(hex_str[i])) {
            printf("Invalid character found in input string.\n");
            exit(1);
        }
    }

    // Convert hexadecimal string to decimal integer
    len = strlen(hex_str);
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        if (isdigit(hex_str[i])) {
            result += hex_str[i] - '0';
        } else {
            result += hex_str[i] - 'a' + 10;
        }
        result *= 16;
    }

    return result;
}

int main() {
    char hex_str[100];
    long int dec_num;

    // Prompt user for hexadecimal string input
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_str);

    // Convert hexadecimal string to decimal integer
    dec_num = hex_to_dec(hex_str);

    // Print the result
    printf("The decimal equivalent of %s is %ld.\n", hex_str, dec_num);

    return 0;
}