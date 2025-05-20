//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>

/* Function to print bits in binary format */
void printBinary(unsigned int num){
    unsigned int mask = 1 << 31; // 10000000 00000000 00000000 00000000
    for(int i = 0; i < 32; i++){
        printf("%c", num & mask ? '1' : '0');
        num <<= 1;
    }
    printf("\n");
}

int main(){
    unsigned int a = 87;
    unsigned int b = 23;
    unsigned int c;

    /* Bitwise AND */
    printf("Bitwise AND\n");
    printf("%u & %u = %u\n", a, b, a&b);
    printBinary(a);
    printBinary(b);
    printBinary(a&b);
    printf("\n");

    /* Bitwise OR */
    printf("Bitwise OR\n");
    printf("%u | %u = %u\n", a, b, a|b);
    printBinary(a);
    printBinary(b);
    printBinary(a|b);
    printf("\n");

    /* Bitwise XOR */
    printf("Bitwise XOR\n");
    printf("%u ^ %u = %u\n", a, b, a^b);
    printBinary(a);
    printBinary(b);
    printBinary(a^b);
    printf("\n");

    /* Bitwise NOT */
    printf("Bitwise NOT\n");
    printf("~%u = %u\n", a, ~a);
    printBinary(a);
    printBinary(~a);
    printf("\n");

    /* Bitwise LEFT SHIFT */
    printf("Bitwise LEFT SHIFT\n");
    printf("%u << 2 = %u\n", a, a<<2);
    printBinary(a);
    printBinary(a<<2);
    printf("\n");

    /* Bitwise RIGHT SHIFT */
    printf("Bitwise RIGHT SHIFT\n");
    printf("%u >> 2 = %u\n", a, a>>2);
    printBinary(a);
    printBinary(a>>2);
    printf("\n");

    /* Bitwise ASSIGNMENT OPERATORS */
    printf("Bitwise ASSIGNMENT OPERATORS\n");
    c = a;
    printf("c = %u, a = %u\n", c, a);
    c |= b;
    printf("c |= %u, c = %u\n", b, c);
    c ^= a;
    printf("c ^= %u, c = %u\n", a, c);
    c >>= 2;
    printf("c >>= 2, c = %u\n", c);
    printf("\n");

    return 0;
}