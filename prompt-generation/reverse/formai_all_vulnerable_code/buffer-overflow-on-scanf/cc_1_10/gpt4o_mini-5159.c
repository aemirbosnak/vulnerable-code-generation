//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int num1, num2;
    printf("Welcome to the Bitwise Adventure!\n");
    printf("Let's explore the magical world of bitwise operations!\n");
    
    printf("Please enter the first positive integer (num1): ");
    scanf("%u", &num1);
    printf("Please enter the second positive integer (num2): ");
    scanf("%u", &num2);

    printf("\nSuccess! You've entered num1 = %u and num2 = %u\n", num1, num2);

    printf("\nLet's see their binary representations!\n");
    printf("Binary of num1: ");
    printBinary(num1);
    printf("Binary of num2: ");
    printBinary(num2);
    
    printf("\nNow, let's perform some bitwise operations!\n");

    // AND operation
    unsigned int and_result = num1 & num2;
    printf("1. Bitwise AND (num1 & num2): %u\n", and_result);
    printf("   Binary of AND result: ");
    printBinary(and_result);

    // OR operation
    unsigned int or_result = num1 | num2;
    printf("\n2. Bitwise OR (num1 | num2): %u\n", or_result);
    printf("   Binary of OR result: ");
    printBinary(or_result);

    // XOR operation
    unsigned int xor_result = num1 ^ num2;
    printf("\n3. Bitwise XOR (num1 ^ num2): %u\n", xor_result);
    printf("   Binary of XOR result: ");
    printBinary(xor_result);

    // NOT operation on num1
    unsigned int not_num1 = ~num1;
    printf("\n4. Bitwise NOT (~num1): %u\n", not_num1);
    printf("   Binary of NOT num1: ");
    printBinary(not_num1);

    // NOT operation on num2
    unsigned int not_num2 = ~num2;
    printf("\n5. Bitwise NOT (~num2): %u\n", not_num2);
    printf("   Binary of NOT num2: ");
    printBinary(not_num2);

    // Left shift operation
    unsigned int left_shift_num1 = num1 << 1;
    printf("\n6. Left Shift (num1 << 1): %u\n", left_shift_num1);
    printf("   Binary of Left Shift result: ");
    printBinary(left_shift_num1);

    // Right shift operation
    unsigned int right_shift_num1 = num1 >> 1;
    printf("\n7. Right Shift (num1 >> 1): %u\n", right_shift_num1);
    printf("   Binary of Right Shift result: ");
    printBinary(right_shift_num1);

    // Combination of operations
    unsigned int combined_result = (num1 & num2) | (num1 ^ num2);
    printf("\n8. Combined Operation ((num1 & num2) | (num1 ^ num2)): %u\n", combined_result);
    printf("   Binary of Combined result: ");
    printBinary(combined_result);

    printf("\nThank you for participating in this Bitwise Adventure!\n");
    printf("Remember: Bitwise operations are like magic spells!\n");
    printf("Each operator lets you manipulate bits in different ways!\n");
    printf("Have a fantastic day with your newfound knowledge!\n");

    return 0;
}