//FormAI DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>

/* Define the maximum length of the binary representation of a number */
#define MAX_LEN 32

/* Print the binary representation of a number using bitwise operators */
void printBinary(int num) {
    /* Create a binary string */
    char binary[MAX_LEN];
    int i = 0;

    /* Loop through the integer and shift the bits */
    while (num > 0) {
        if (num & 1)
            binary[i] = '1';
        else
            binary[i] = '0';
        num >>= 1;
        i++;
    }

    /* Add padding zeros if needed */
    while (i < MAX_LEN) {
        binary[i] = '0';
        i++;
    }

    /* Print the binary string with spaces every four bits */
    for (i = MAX_LEN-1; i >= 0; i--) {
        printf("%c", binary[i]);
        if (i % 4 == 0)
            printf(" ");
    }
}

int main() {
    int a, b;

    /* Get input values from the user */
    printf("Enter the first integer value: ");
    scanf("%d", &a);
    printf("Enter the second integer value: ");
    scanf("%d", &b);

    /* Perform bitwise AND operation */
    printf("\na & b = ");
    printBinary(a & b);
    printf("\n");

    /* Perform bitwise OR operation */
    printf("\na | b = ");
    printBinary(a | b);
    printf("\n");

    /* Perform bitwise XOR operation */
    printf("\na ^ b = ");
    printBinary(a ^ b);
    printf("\n");

    /* Perform bitwise NOT operation */
    printf("\n~a = ");
    printBinary(~a);
    printf("\n");
    printf("~b = ");
    printBinary(~b);
    printf("\n");

    /* Perform left shift operation */
    printf("\na << 1 = ");
    printBinary(a << 1);
    printf("\n");

    /* Perform right shift operation */
    printf("\na >> 1 = ");
    printBinary(a >> 1);
    printf("\n");

    /* Perform logical AND operation */
    printf("\n(a > 5) && (b < 10) = ");
    if ((a > 5) && (b < 10))
        printf("true\n");
    else
        printf("false\n");

    /* Perform logical OR operation */
    printf("(a < 5) || (b > 10) = ");
    if ((a < 5) || (b > 10))
        printf("true\n");
    else
        printf("false\n");

    return 0;

}