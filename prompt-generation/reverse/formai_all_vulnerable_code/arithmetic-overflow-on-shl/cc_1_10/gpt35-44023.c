//FormAI DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>

// function to convert decimal to binary
long long decimalToBinary(int decimal) {
    long long binary = 0;
    int remainder, factor = 1;

    while (decimal) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * factor;
        factor *= 10;
    }

    return binary;
}

// function to convert binary to decimal
int binaryToDecimal(long long binary) {
    int decimal = 0, factor = 1, remainder;

    while (binary) {
        remainder = binary % 10;
        binary /= 10;
        decimal += remainder * factor;
        factor *= 2;
    }

    return decimal;
}

int main() {
    int num1, num2, result;

    printf("Welcome to my Bitwise Operation Program\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // bitwise AND operator
    result = num1 & num2;
    printf("%d AND %d = %d\n", num1, num2, result);

    // bitwise OR operator
    result = num1 | num2;
    printf("%d OR %d = %d\n", num1, num2, result);

    // bitwise XOR operator
    result = num1 ^ num2;
    printf("%d XOR %d = %d\n", num1, num2, result);

    // bitwise complement operator
    result = ~num1;
    printf("Complement of %d = %d\n", num1, result);

    // left shift operator
    result = num1 << 2;
    printf("%d << 2 = %d\n", num1, result);

    // right shift operator
    result = num1 >> 2;
    printf("%d >> 2 = %d\n", num1, result);

    // left rotate operator
    result = (num1 << 2) | (num1 >> (sizeof(num1) * 8 - 2));
    printf("%d left rotation by 2 = %d\n", num1, result);

    // right rotate operator
    result = (num1 >> 2) | (num1 << (sizeof(num1) * 8 - 2));
    printf("%d right rotation by 2 = %d\n", num1, result);

    // binary representation of num1
    long long binary1 = decimalToBinary(num1);
    printf("Binary representation of %d = %lld\n", num1, binary1);

    // decimal conversion of binary1
    int decimal1 = binaryToDecimal(binary1);
    printf("Decimal conversion of %lld = %d\n", binary1, decimal1);

    printf("Thanks for using my program!\n");

    return 0;
}