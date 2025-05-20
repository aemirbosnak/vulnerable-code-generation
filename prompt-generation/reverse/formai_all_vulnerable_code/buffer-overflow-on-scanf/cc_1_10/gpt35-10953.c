//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

/* function to perform bitwise AND */
int bitwise_and(int num1, int num2) {
    return num1 & num2;
}

/* function to perform bitwise OR */
int bitwise_or(int num1, int num2) {
    return num1 | num2;
}

/* function to perform bitwise XOR */
int bitwise_xor(int num1, int num2) {
    return num1 ^ num2;
}

/* function to perform bitwise NOT */
int bitwise_not(int num) {
    return ~num;
}

/* function to perform left shift operation */
int left_shift(int num, int shift) {
    return num << shift;
}

/* function to perform right shift operation */
int right_shift(int num, int shift) {
    return num >> shift;
}

int main() {
    /* get user input */
    int num1, num2, shift;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    /* perform bitwise operations */
    int and_result = bitwise_and(num1, num2);
    int or_result = bitwise_or(num1, num2);
    int xor_result = bitwise_xor(num1, num2);

    /* print results */
    printf("Bitwise AND: %d\n", and_result);
    printf("Bitwise OR: %d\n", or_result);
    printf("Bitwise XOR: %d\n", xor_result);

    /* get user input for shift operation */
    printf("Enter a number and a shift amount for left shift: ");
    scanf("%d %d", &num1, &shift);

    /* perform left shift operation */
    int left_shift_result = left_shift(num1, shift);

    /* print result */
    printf("Left shifted result: %d\n", left_shift_result);

    /* get user input for right shift operation */
    printf("Enter a number and a shift amount for right shift: ");
    scanf("%d %d", &num1, &shift);

    /* perform right shift operation */
    int right_shift_result = right_shift(num1, shift);

    /* print result */
    printf("Right shifted result: %d\n", right_shift_result);

    /* perform bitwise NOT operation */
    int not_result = bitwise_not(num1);

    /* print result */
    printf("Bitwise NOT of %d: %d\n", num1, not_result);

    return 0;
}