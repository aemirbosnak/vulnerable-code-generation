//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAX_DIGITS 10

int main() {
    srand(time(NULL));
    int num1, num2, result, i, j, carry, digit, max_digit;
    char num1_str[MAX_DIGITS + 1], num2_str[MAX_DIGITS + 1], result_str[MAX_DIGITS + 1];

    // Generate random numbers
    num1 = rand() % MAX_NUM;
    num2 = rand() % MAX_NUM;

    // Convert numbers to strings
    i = 0;
    while (num1 > 0) {
        digit = num1 % 10;
        num1_str[i++] = digit + '0';
        num1 /= 10;
    }
    num1_str[i] = '\0';
    i = 0;
    while (num2 > 0) {
        digit = num2 % 10;
        num2_str[i++] = digit + '0';
        num2 /= 10;
    }
    num2_str[i] = '\0';

    // Calculate maximum number of digits in result
    max_digit = 0;
    if (strlen(num1_str) > strlen(num2_str)) {
        max_digit = strlen(num1_str);
    } else {
        max_digit = strlen(num2_str);
    }

    // Add numbers and handle carry
    carry = 0;
    i = max_digit - 1;
    while (i >= 0) {
        result = (num1_str[i] - '0') + (num2_str[i] - '0') + carry;
        if (result > 9) {
            result_str[i] = result - 10 + '0';
            carry = 1;
        } else {
            result_str[i] = result + '0';
            carry = 0;
        }
        i--;
    }

    // Handle carry from last digit
    while (carry > 0) {
        result_str[i++] = carry + '0';
        carry--;
    }
    result_str[i] = '\0';

    // Print result
    printf("Result: %s\n", result_str);

    return 0;
}