//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 32

// Function prototypes
void print_binary(int num);
int get_num_length(int num);
void convert_decimal_to_binary(int decimal, char* binary);

int main() {
    int decimal;
    char binary[MAX_NUM_LENGTH];

    // Prompt user for input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary and print result
    convert_decimal_to_binary(decimal, binary);
    printf("Binary equivalent: %s\n", binary);

    return 0;
}

void print_binary(int num) {
    char binary[MAX_NUM_LENGTH];
    int i = 0;

    // Initialize binary string with leading zeros
    memset(binary, '0', MAX_NUM_LENGTH);

    // Convert integer to binary string
    sprintf(binary + i, "%d", num);

    // Print binary string
    printf("%s\n", binary);
}

int get_num_length(int num) {
    int count = 0;

    // Count number of digits in the integer
    while (num!= 0) {
        num /= 10;
        count++;
    }

    return count;
}

void convert_decimal_to_binary(int decimal, char* binary) {
    int remainder, quotient;
    int i = 0;

    // Convert decimal to binary
    while (decimal!= 0) {
        remainder = decimal % 2;
        quotient = decimal / 2;
        binary[i++] = remainder + '0';
        decimal = quotient;
    }

    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    // Add leading zeros if necessary
    int num_length = get_num_length(decimal);
    if (i < num_length) {
        for (int k = i; k < num_length; k++) {
            binary[k] = '0';
        }
    }
}