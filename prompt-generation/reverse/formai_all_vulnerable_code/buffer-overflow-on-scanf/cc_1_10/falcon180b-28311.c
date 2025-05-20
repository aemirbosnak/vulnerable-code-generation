//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 33 // Maximum length of a number in binary format

int main() {
    int decimal;
    char binary[MAX_NUM_LENGTH];
    char input[MAX_NUM_LENGTH];
    int i = 0, j = 0;
    int isNegative = 0;

    // Prompt user to enter a decimal number
    printf("Enter a decimal number (up to %d digits): ", MAX_NUM_LENGTH - 1);
    scanf("%[^\n]", input);

    // Check if input is negative
    if (input[0] == '-') {
        isNegative = 1;
        i = 1;
    } else {
        i = 0;
    }

    // Convert input string to integer
    decimal = atoi(input);

    // Convert decimal to binary
    while (decimal > 0) {
        binary[j++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Reverse binary string
    for (int k = 0; k < j / 2; k++) {
        char temp = binary[k];
        binary[k] = binary[j - k - 1];
        binary[j - k - 1] = temp;
    }

    // Add leading zeros if necessary
    while (j < MAX_NUM_LENGTH - 1) {
        binary[j++] = '0';
    }

    // Add negative sign if input is negative
    if (isNegative) {
        binary[0] = '-';
        i++;
    }

    // Print binary string
    printf("Binary: ");
    for (int k = i; k < j; k++) {
        printf("%c", binary[k]);
    }

    return 0;
}