//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a hexadecimal digit
int is_hex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

// Function to convert a hexadecimal string to decimal
int hex_to_dec(char* hex) {
    int dec = 0;
    int len = strlen(hex);

    // Iterate over each character in the hexadecimal string
    for (int i = 0; i < len; i++) {
        // Convert the character to its decimal equivalent
        char c = tolower(hex[i]);
        if (is_hex(c)) {
            dec = dec * 16 + (c - '0');
        } else {
            return -1; // Invalid character
        }
    }

    return dec;
}

// Function to convert a decimal number to hexadecimal
void dec_to_hex(int dec, char* hex) {
    int len = 0;
    char buf[32];

    // Convert the decimal number to hexadecimal
    while (dec!= 0) {
        buf[len++] = "0123456789abcdef"[dec % 16];
        dec /= 16;
    }

    // Reverse the order of the characters in the buffer and copy to output string
    for (int i = len - 1; i >= 0; i--) {
        hex[i] = buf[i];
    }
    hex[len] = '\0';
}

int main() {
    char hex[33], dec[33];
    int len;

    // Prompt the user to enter a hexadecimal string
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    // Convert the hexadecimal string to decimal
    len = hex_to_dec(hex);
    if (len == -1) {
        printf("Invalid hexadecimal string\n");
        return 1;
    }

    // Convert the decimal number to hexadecimal
    dec_to_hex(len, dec);

    // Print the result
    printf("The decimal equivalent of %s is %s\n", hex, dec);

    return 0;
}