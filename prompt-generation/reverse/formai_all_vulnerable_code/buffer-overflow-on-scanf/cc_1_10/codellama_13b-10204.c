//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: innovative
/*
* C Binary Converter Program
*
* Author: [Your Name]
* Date: [Current Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int bin_to_dec(char* bin_str) {
    int dec_val = 0, len = strlen(bin_str);
    for (int i = 0; i < len; i++) {
        dec_val += (bin_str[i] - '0') * pow(2, len - i - 1);
    }
    return dec_val;
}

// Function to convert decimal to binary
char* dec_to_bin(int dec_val) {
    int len = 0;
    char* bin_str = NULL;
    while (dec_val > 0) {
        bin_str = (char*)realloc(bin_str, (len + 1) * sizeof(char));
        bin_str[len] = '0' + (dec_val % 2);
        dec_val /= 2;
        len++;
    }
    bin_str = (char*)realloc(bin_str, (len + 1) * sizeof(char));
    bin_str[len] = '\0';
    return bin_str;
}

// Main function
int main() {
    // Take input from user
    char bin_str[100];
    printf("Enter binary number: ");
    scanf("%s", bin_str);
    // Convert binary to decimal
    int dec_val = bin_to_dec(bin_str);
    // Convert decimal to binary
    char* bin_str_dec = dec_to_bin(dec_val);
    // Print output
    printf("Binary: %s\n", bin_str);
    printf("Decimal: %d\n", dec_val);
    printf("Binary (decimal): %s\n", bin_str_dec);
    return 0;
}