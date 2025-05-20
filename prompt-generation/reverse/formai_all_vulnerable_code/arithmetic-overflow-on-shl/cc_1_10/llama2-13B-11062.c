//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

int main() {
    int a = 0x12345678;  // 32-bit integer with all bits set to 1
    int b = 0x01234567;  // 32-bit integer with all bits set to 0
    int c = 0x56543210;  // 32-bit integer with random bits set

    // Bitwise AND operation
    int result = a & b;
    printf("Bitwise AND of 0x12345678 and 0x01234567: %08x\n", result);

    // Bitwise OR operation
    result = a | b;
    printf("Bitwise OR of 0x12345678 and 0x01234567: %08x\n", result);

    // Bitwise XOR operation
    result = a ^ b;
    printf("Bitwise XOR of 0x12345678 and 0x01234567: %08x\n", result);

    // Shift left operation
    result = a << 4;
    printf("0x12345678 shifted left by 4: %08x\n", result);

    // Shift right operation
    result = a >> 4;
    printf("0x12345678 shifted right by 4: %08x\n", result);

    // Bitwise NOT operation
    result = ~a;
    printf("Bitwise NOT of 0x12345678: %08x\n", result);

    // Bitwise AND with a mask
    result = a & 0x1F;
    printf("Bitwise AND of 0x12345678 with mask 0x1F: %04x\n", result);

    // Bitwise OR with a mask
    result = a | 0x1F;
    printf("Bitwise OR of 0x12345678 with mask 0x1F: %04x\n", result);

    // Bitwise XOR with a mask
    result = a ^ 0x1F;
    printf("Bitwise XOR of 0x12345678 with mask 0x1F: %04x\n", result);

    // Bitwise AND with a range
    result = a & (0x12345678 - 0x01234567);
    printf("Bitwise AND of 0x12345678 with range 0x01234567: %08x\n", result);

    // Bitwise OR with a range
    result = a | (0x12345678 - 0x01234567);
    printf("Bitwise OR of 0x12345678 with range 0x01234567: %08x\n", result);

    // Bitwise XOR with a range
    result = a ^ (0x12345678 - 0x01234567);
    printf("Bitwise XOR of 0x12345678 with range 0x01234567: %08x\n", result);

    return 0;
}