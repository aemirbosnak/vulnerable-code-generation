//LLAMA2-13B DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>
#include <stdint.h>

int main() {
    int a, b, i;
    uint32_t result;

    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);

    // 1. Bitwise AND
    result = a & b;
    printf("Bitwise AND: %08x\n", result);

    // 2. Bitwise OR
    result = a | b;
    printf("Bitwise OR: %08x\n", result);

    // 3. Bitwise XOR
    result = a ^ b;
    printf("Bitwise XOR: %08x\n", result);

    // 4. Bitwise NOT
    result = ~a;
    printf("Bitwise NOT: %08x\n", result);

    // 5. Shift left
    result = a << 2;
    printf("Shift left by 2: %08x\n", result);

    // 6. Shift right
    result = a >> 2;
    printf("Shift right by 2: %08x\n", result);

    // 7. Bitwise AND with mask
    result = a & 0x1F;
    printf("Bitwise AND with mask 0x1F: %08x\n", result);

    // 8. Bitwise OR with mask
    result = a | 0x1F;
    printf("Bitwise OR with mask 0x1F: %08x\n", result);

    // 9. Bitwise XOR with mask
    result = a ^ 0x1F;
    printf("Bitwise XOR with mask 0x1F: %08x\n", result);

    // 10. Bitwise NOT with mask
    result = ~(a & 0x1F);
    printf("Bitwise NOT with mask 0x1F: %08x\n", result);

    return 0;
}