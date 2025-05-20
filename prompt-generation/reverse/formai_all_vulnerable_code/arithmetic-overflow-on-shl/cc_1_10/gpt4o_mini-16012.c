//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void printBinary(int n) {
    for (int i = 31; i >= 0; --i) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

void bitwiseOperations(int a, int b) {
    int and_result = a & b;
    int or_result = a | b;
    int xor_result = a ^ b;
    int not_a = ~a;
    int not_b = ~b;
    int left_shift_a = a << 1; // Shift left by 1 (multiply by 2)
    int right_shift_a = a >> 1; // Shift right by 1 (divide by 2)
    
    printf("Bitwise Operations on:\n");
    printf("a = ");
    printBinary(a);
    printf("b = ");
    printBinary(b);
    printf("a & b = ");
    printBinary(and_result);
    printf("a | b = ");
    printBinary(or_result);
    printf("a ^ b = ");
    printBinary(xor_result);
    printf("~a = ");
    printBinary(not_a);
    printf("~b = ");
    printBinary(not_b);
    printf("a << 1 = ");
    printBinary(left_shift_a);
    printf("a >> 1 = ");
    printBinary(right_shift_a);
}

void manipulateBit(int number, int position, int set) {
    printf("Before manipulation: ");
    printBinary(number);
    
    if (set) {
        number |= (1 << position);
        printf("Set bit at position %d\n", position);
    } else {
        number &= ~(1 << position);
        printf("Clear bit at position %d\n", position);
    }
    
    printf("After manipulation: ");
    printBinary(number);
}

void toggleBit(int number, int position) {
    printf("Before toggling: ");
    printBinary(number);
    number ^= (1 << position);
    printf("After toggling bit at position %d\n", position);
    printBinary(number);
}

int main() {
    printf("Bitwise Operation Demo\n");
    
    int a = 29; // 00000000000000000000000000011101
    int b = 15; // 00000000000000000000000000001111
    
    bitwiseOperations(a, b);
    
    int number = 42; // 00000000000000000000000000101010
    int position = 3; // We will manipulate the 4th bit (counting from 0)
    
    manipulateBit(number, position, 1); // Set the bit at position 3
    manipulateBit(number, position, 0); // Clear the bit at position 3
    
    toggleBit(number, position); // Toggle the bit at position 3
    
    printf("Final value of number: ");
    printBinary(number);
    
    return 0;
}