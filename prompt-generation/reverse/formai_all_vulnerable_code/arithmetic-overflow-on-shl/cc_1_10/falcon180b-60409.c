//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>

int main() {

    // Define variables
    int num1, num2;

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Bitwise AND operation
    int result1 = num1 & num2;
    printf("Bitwise AND: %d\n", result1);

    // Bitwise OR operation
    int result2 = num1 | num2;
    printf("Bitwise OR: %d\n", result2);

    // Bitwise XOR operation
    int result3 = num1 ^ num2;
    printf("Bitwise XOR: %d\n", result3);

    // Bitwise NOT operation
    int result4 = ~num1;
    printf("Bitwise NOT: %d\n", result4);

    // Bitwise left shift operation
    int result5 = num1 << 2;
    printf("Bitwise left shift by 2: %d\n", result5);

    // Bitwise right shift operation
    int result6 = num1 >> 2;
    printf("Bitwise right shift by 2: %d\n", result6);

    // Bitwise right shift with sign extension operation
    int result7 = num1 >> 2;
    printf("Bitwise right shift with sign extension by 2: %d\n", result7);

    // Bitwise complement operation
    int result8 = ~num1;
    printf("Bitwise complement: %d\n", result8);

    // Bitwise AND with complement operation
    int result9 = num1 & ~num2;
    printf("Bitwise AND with complement: %d\n", result9);

    // Bitwise OR with complement operation
    int result10 = num1 | ~num2;
    printf("Bitwise OR with complement: %d\n", result10);

    return 0;
}