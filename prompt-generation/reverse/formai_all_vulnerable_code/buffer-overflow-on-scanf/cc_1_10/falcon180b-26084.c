//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input_str[100];
    int len, i, j, base, decimal_num, sign;
    char *ptr;

    // Prompt the user to enter a binary number
    printf("Enter a binary number (up to 100 bits): ");
    scanf("%s", input_str);

    // Check if the input is a valid binary number
    len = strlen(input_str);
    for (i = 0; i < len; i++) {
        if (!isdigit(input_str[i]) && input_str[i]!= '-') {
            printf("Error: Invalid binary number!\n");
            return 1;
        }
    }

    // Determine the sign of the input number
    if (input_str[0] == '-') {
        sign = -1;
        ptr = &input_str[1];
    } else {
        sign = 1;
        ptr = input_str;
    }

    // Convert the binary number to decimal
    decimal_num = 0;
    base = 1;
    for (i = strlen(ptr) - 1; i >= 0; i--) {
        if (ptr[i] == '1') {
            decimal_num += base;
        }
        base *= 2;
    }

    // Print the result
    if (sign == -1) {
        printf("-");
    }
    printf("%d\n", decimal_num);

    return 0;
}