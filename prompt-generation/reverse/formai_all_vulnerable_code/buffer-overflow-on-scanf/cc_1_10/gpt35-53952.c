//FormAI DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>

/* Function to convert decimal to binary */
void dec_to_bin(int num) {
    int binary[8];
    int i = 0;

    /* Convert decimal to binary */
    while(num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    /* Print binary number */
    printf("Binary: ");
    for(int j=7; j>=0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

/* Bitwise AND example */
void bitwise_and(int num1, int num2) {
    int result = num1 & num2;

    /* Print binary of num1 */
    printf("Num1: %d\n", num1);
    dec_to_bin(num1);

    /* Print binary of num2 */
    printf("Num2: %d\n", num2);
    dec_to_bin(num2);

    /* Print binary of result */
    printf("Result: %d\n", result);
    dec_to_bin(result);
}

/* Bitwise OR example */
void bitwise_or(int num1, int num2) {
    int result = num1 | num2;

    /* Print binary of num1 */
    printf("Num1: %d\n", num1);
    dec_to_bin(num1);

    /* Print binary of num2 */
    printf("Num2: %d\n", num2);
    dec_to_bin(num2);

    /* Print binary of result */
    printf("Result: %d\n", result);
    dec_to_bin(result);
}

/* Bitwise XOR example */
void bitwise_xor(int num1, int num2) {
    int result = num1 ^ num2;

    /* Print binary of num1 */
    printf("Num1: %d\n", num1);
    dec_to_bin(num1);

    /* Print binary of num2 */
    printf("Num2: %d\n", num2);
    dec_to_bin(num2);

    /* Print binary of result */
    printf("Result: %d\n", result);
    dec_to_bin(result);
}

/* Bitwise NOT example */
void bitwise_not(int num) {
    int result = ~num;

    /* Print binary of num */
    printf("Num: %d\n", num);
    dec_to_bin(num);

    /* Print binary of result */
    printf("Result: %d\n", result);
    dec_to_bin(result);
}

int main() {
    int num1, num2;

    /* Get input from user */
    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    /* Perform bitwise operations */
    bitwise_and(num1, num2);
    bitwise_or(num1, num2);
    bitwise_xor(num1, num2);

    printf("Enter num: ");
    scanf("%d", &num1);

    /* Perform bitwise NOT operation */
    bitwise_not(num1);

    return 0;
}