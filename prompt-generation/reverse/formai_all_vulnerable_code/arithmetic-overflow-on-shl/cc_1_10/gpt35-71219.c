//FormAI DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/* Function to convert decimal to binary */
void decimalToBinary(int n)
{
    int binary[32];
    int i = 0;

    // Convert decimal to binary
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print binary representation
    printf("Binary representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

/* Function to perform bitwise operations */
void bitwiseOps(int a, int b)
{
    printf("a = %d, b = %d\n", a, b);

    // Perform bitwise AND
    int resultAND = a & b;
    printf("a & b = %d\n", resultAND);

    // Perform bitwise OR
    int resultOR = a | b;
    printf("a | b = %d\n", resultOR);

    // Perform bitwise XOR
    int resultXOR = a ^ b;
    printf("a ^ b = %d\n", resultXOR);

    // Perform bitwise NOT
    int resultNOT = ~a;
    printf("~a = %d\n", resultNOT);

    // Perform left shift
    int resultLS = a << 1;
    printf("a << 1 = %d\n", resultLS);

    // Perform right shift
    int resultRS = a >> 1;
    printf("a >> 1 = %d\n", resultRS);

    // Convert a to binary
    decimalToBinary(a);

    // Convert b to binary
    decimalToBinary(b);

    // Convert resultAND to binary
    decimalToBinary(resultAND);

    // Convert resultOR to binary
    decimalToBinary(resultOR);

    // Convert resultXOR to binary
    decimalToBinary(resultXOR);

    // Convert resultNOT to binary
    decimalToBinary(resultNOT);

    // Convert resultLS to binary
    decimalToBinary(resultLS);

    // Convert resultRS to binary
    decimalToBinary(resultRS);
}

/* Main function */
int main()
{
    printf("Enter two integers: ");
    int a, b;
    scanf("%d %d", &a, &b);

    bitwiseOps(a, b);

    return 0;
}