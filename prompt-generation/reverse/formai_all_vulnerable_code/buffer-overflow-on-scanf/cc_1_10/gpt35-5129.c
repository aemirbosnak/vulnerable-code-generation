//FormAI DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>

// Function to print binary representation of decimal number
void printBinary(int num)
{
    int binary[32];
    int i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary Representation: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);

    printf("\n");
}

int main()
{
    int x, y, z;

    // Input two integer numbers
    printf("Enter two numbers: ");
    scanf("%d%d", &x, &y);

    printBinary(x);
    printBinary(y);

    // OR operation
    z = x | y;
    printf("OR Operation: %d | %d = %d\n", x, y, z);
    printBinary(z);

    // AND operation
    z = x & y;
    printf("AND Operation: %d & %d = %d\n", x, y, z);
    printBinary(z);

    // XOR operation
    z = x ^ y;
    printf("XOR Operation: %d ^ %d = %d\n", x, y, z);
    printBinary(z);

    // Complement operation
    printf("Complement Operation: ~%d = %d\n", x, ~x);
    printBinary(~x);

    // Left shift operation
    printf("Left Shift Operation: %d << 2 = %d\n", x, x << 2);
    printBinary(x << 2);

    // Right shift operation
    printf("Right Shift Operation: %d >> 2 = %d\n", x, x >> 2);
    printBinary(x >> 2);

    return 0;
}