//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char hex[100];
    char input[100];
    int i;
    int j;
    int len;
    int dec;
    int base;
    int count;
    int flag;
    int num;
    int temp;
    int sum;
    int digit;
    int output;
    int sign;

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Please enter a hexadecimal number:\n");
    scanf("%s", hex);
    len = strlen(hex);

    // Check if input is valid
    for (i = 0; i < len; i++) {
        if (!isxdigit(hex[i])) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return 0;
        }
    }

    // Convert hexadecimal to decimal
    dec = 0;
    base = 1;
    flag = 0;
    for (i = len - 1; i >= 0; i--) {
        digit = hex[i] - '0';
        if (digit > 9) {
            digit = digit - 7;
        }
        dec += digit * base;
        base *= 16;
    }

    // Convert decimal to hexadecimal
    count = 0;
    output = dec;
    sign = output / 16;
    while (output!= 0) {
        temp = output % 16;
        if (temp < 10) {
            num = temp + 48;
        } else {
            num = temp + 55;
        }
        hex[count] = num;
        output /= 16;
        count++;
    }
    if (sign < 0) {
        hex[count] = '-';
        count++;
    }

    // Print output
    printf("The decimal equivalent of %s is %d.\n", hex, output);
    printf("The hexadecimal equivalent of %d is %s.\n", output, hex);

    return 0;
}