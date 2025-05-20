//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 100 // Maximum length of input number

int main() {
    char input_num[MAX_NUM_LENGTH]; // Input number as string
    int num_length; // Length of input number
    int i, j; // Loop variables
    char binary_num[MAX_NUM_LENGTH]; // Binary number as string
    int binary_length; // Length of binary number
    int is_negative = 0; // Flag to indicate negative number

    // Get input number from user
    printf("Enter a decimal number: ");
    scanf("%s", input_num);

    // Check if input number is negative
    if (input_num[0] == '-') {
        is_negative = 1;
        num_length = strlen(input_num) - 1;
    } else {
        num_length = strlen(input_num);
    }

    // Convert decimal to binary
    for (i = num_length - 1, j = 0; i >= 0; i--, j++) {
        int remainder = input_num[i] - '0';
        int quotient = 0;
        while (remainder > 0) {
            binary_num[j] = remainder % 2 + '0';
            remainder /= 2;
            j++;
        }
        while (quotient > 0) {
            binary_num[j] = quotient % 2 + '0';
            quotient /= 2;
            j++;
        }
    }
    binary_num[j] = '\0';
    binary_length = j;

    // Add leading zeros if necessary
    while (binary_length < MAX_NUM_LENGTH) {
        binary_num[binary_length++] = '0';
    }

    // Print binary number
    if (is_negative) {
        printf("-");
    }
    printf("%s\n", binary_num + binary_length - num_length);

    return 0;
}