//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

int main() {
    printf("Welcome to the mind-bending Bitwise operations example program!\n");
    printf("Enter two integers: ");

    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("\nLet's perform some Bitwise operations on %d and %d\n\n", num1, num2);

    int and_result = num1 & num2;
    printf("%d & %d = %d\n", num1, num2, and_result);

    int or_result = num1 | num2;
    printf("%d | %d = %d\n", num1, num2, or_result);

    int xor_result = num1 ^ num2;
    printf("%d ^ %d = %d\n", num1, num2, xor_result);

    int left_shift_result = num1 << 2;
    printf("%d << 2 = %d\n", num1, left_shift_result);

    int right_shift_result = num2 >> 3;
    printf("%d >> 3 = %d\n", num2, right_shift_result);

    printf("\nNow, let's try something mind-bending!\n");
    printf("Enter a number to flip a specific bit (0-31): ");

    int bit;
    scanf("%d", &bit);

    // Flipping a specific bit using XOR operator
    int flipped_num = num1 ^ (1 << bit);
    printf("Flipping bit %d in %d = %d\n", bit, num1, flipped_num);

    printf("\nLet's try another mind-bending trick!\n");
    printf("Enter a number to check if a specific bit is set (0-31): ");

    scanf("%d", &bit);

    // Checking if a specific bit is set using AND operator
    if (num2 & (1 << bit)) {
        printf("Bit %d is set in %d\n", bit, num2);
    } else {
        printf("Bit %d is not set in %d\n", bit, num2);
    }

    printf("\nThat's it for the mind-bending Bitwise operations example program.\n");
    return 0;
}