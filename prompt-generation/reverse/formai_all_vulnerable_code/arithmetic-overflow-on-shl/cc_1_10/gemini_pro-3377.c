//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Prepare for the shock! ⚡️

    // Binary representation of 10 is 1010
    int num1 = 10;

    // Binary representation of 15 is 1111
    int num2 = 15;

    // ⚡ Bitwise AND (&) Operation ⚡
    // Result: 1010 & 1111 = 1010 (10)
    int result_and = num1 & num2;
    printf("Bitwise AND (&) of %d and %d is: %d\n", num1, num2, result_and);

    // ⚡ Bitwise OR (|) Operation ⚡
    // Result: 1010 | 1111 = 1111 (15)
    int result_or = num1 | num2;
    printf("Bitwise OR (|) of %d and %d is: %d\n", num1, num2, result_or);

    // ⚡ Bitwise XOR (^) Operation ⚡
    // Result: 1010 ^ 1111 = 0101 (5)
    int result_xor = num1 ^ num2;
    printf("Bitwise XOR (^) of %d and %d is: %d\n", num1, num2, result_xor);

    // ⚡ Bitwise NOT (~) Operation ⚡
    // Result: ~1010 = 0101 (-11 in 2's complement)
    int result_not = ~num1;
    printf("Bitwise NOT (~) of %d is: %d\n", num1, result_not);

    // ⚡ Bitwise Left Shift (<<) Operation ⚡
    // Result: 10 << 2 = 101000 (40)
    int result_lshift = num1 << 2;
    printf("Bitwise Left Shift (<<) of %d by 2 is: %d\n", num1, result_lshift);

    // ⚡ Bitwise Right Shift (>>) Operation ⚡
    // Result: 10 >> 2 = 10 (2)
    int result_rshift = num1 >> 2;
    printf("Bitwise Right Shift (>>) of %d by 2 is: %d\n", num1, result_rshift);

    // ⚡ Flag your surprise! 🚩 ⚡
    // Check if the least significant bit is set (flag is up!)
    int flag = num1 & 1;
    if (flag) {
        printf("The least significant bit of %d is set (flag is up!) 🎉\n", num1);
    } else {
        printf("The least significant bit of %d is not set (flag is down) 😞\n", num1);
    }

    // ⚡ Mask your secret! 🎭 ⚡
    // Mask out the lower 4 bits of num2
    int mask = 0x0F; // Represents 1111 in binary
    int masked_num2 = num2 & mask;
    printf("Masking out the lower 4 bits of %d: %d\n", num2, masked_num2);

    // ⚡ Toggle your switch! 💡 ⚡
    // Toggle the 3rd bit of num1
    int toggle_mask = 1 << 2; // Represents 00000100 in binary
    num1 ^= toggle_mask;
    printf("Toggling the 3rd bit of %d: %d\n", num1, num1);

    // ⚡ Clear your bits! 🧹 ⚡
    // Clear the 2nd and 5th bits of num2
    int clear_mask = ~(3 << 1); // Represents 11111001 in binary
    num2 &= clear_mask;
    printf("Clearing the 2nd and 5th bits of %d: %d\n", num2, num2);

    // ⚡ Set your bits! 🧰 ⚡
    // Set the 1st and 4th bits of num1
    int set_mask = 1 << 0 | 1 << 3; // Represents 00001011 in binary
    num1 |= set_mask;
    printf("Setting the 1st and 4th bits of %d: %d\n", num1, num1);

    // ⚡ Get your bit count! 🧮 ⚡
    // Count the number of set bits in num1
    int count = 0;
    while (num1) {
        count += num1 & 1;
        num1 >>= 1;
    }
    printf("Number of set bits in %d: %d\n", num1, count);

    // ⚡ Reverse your bits! 🔄 ⚡
    // Reverse the bits of num2
    int reversed_num2 = 0;
    for (int i = 0; i < 32; i++) {
        reversed_num2 |= ((num2 >> i) & 1) << (31 - i);
    }
    printf("Reversed bits of %d: %d\n", num2, reversed_num2);

    // ⚡ Signed or Unsigned? 🤔 ⚡
    // Check if num1 is signed or unsigned
    if (num1 < 0) {
        printf("%d is a signed integer\n", num1);
    } else {
        printf("%d is an unsigned integer\n", num1);
    }

    return 0;
}