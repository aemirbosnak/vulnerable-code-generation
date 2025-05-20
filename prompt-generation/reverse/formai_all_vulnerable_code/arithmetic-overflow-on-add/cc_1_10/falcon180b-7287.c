//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM_LENGTH 32 // maximum number of digits in a decimal number

void convert_decimal_to_binary(char *decimal_num, char *binary_num) {
    int decimal_value = 0;
    int binary_value = 0;
    int i = 0;
    int j = 0;

    // convert decimal number to integer
    while (decimal_num[i]!= '\0') {
        if (!isdigit(decimal_num[i])) {
            printf("Invalid input: %s is not a decimal number\n", decimal_num);
            exit(1);
        }
        decimal_value = decimal_value * 10 + (decimal_num[i] - '0');
        i++;
    }

    // convert integer to binary
    while (decimal_value!= 0) {
        binary_value = binary_value * 10 + decimal_value % 2;
        decimal_value /= 2;
    }

    // reverse binary number
    for (i = 0, j = strlen(binary_num) - 1; i < j; i++, j--) {
        char temp = binary_num[i];
        binary_num[i] = binary_num[j];
        binary_num[j] = temp;
    }

    // add leading zeros if necessary
    while (strlen(binary_num) < MAX_NUM_LENGTH) {
        strcat(binary_num, "0");
    }
}

int main() {
    char decimal_num[MAX_NUM_LENGTH];
    char binary_num[MAX_NUM_LENGTH];

    // get user input for decimal number
    printf("Enter a decimal number: ");
    fgets(decimal_num, MAX_NUM_LENGTH, stdin);

    // remove newline character from input
    decimal_num[strcspn(decimal_num, "\n")] = '\0';

    // convert decimal to binary
    convert_decimal_to_binary(decimal_num, binary_num);

    // print binary number
    printf("Binary number: %s\n", binary_num);

    return 0;
}