//FormAI DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>

// This function prints the binary representation of an unsigned integer
void printBinary(unsigned int num){
    for(int i = 31; i >= 0; i--){
        if(num & (1 << i)){
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main(){
    unsigned int a = 1234;  // Decimal representation for 0b0000010011010010
    unsigned int b = 5678;  // Decimal representation for 0b0001011000101110

    // Bitwise AND
    printf("a & b = ");
    printBinary(a & b);

    // Bitwise OR
    printf("a | b = ");
    printBinary(a | b);

    // Bitwise XOR
    printf("a ^ b = ");
    printBinary(a ^ b);

    // Bitwise NOT
    printf("~a = ");
    printBinary(~a);

    // Left shift
    printf("a << 2 = ");
    printBinary(a << 2);

    // Right shift
    printf("b >> 3 = ");
    printBinary(b >> 3);

    // Bitwise AND assignment
    a &= b;
    printf("a &= b = ");
    printBinary(a);

    // Bitwise XOR assignment
    a ^= b;
    printf("a ^= b = ");
    printBinary(a);

    // Left shift assignment
    a <<= 5;
    printf("a <<= 5 = ");
    printBinary(a);

    // Right shift assignment
    a >>= 6;
    printf("a >>= 6 = ");
    printBinary(a);

    return 0;
}