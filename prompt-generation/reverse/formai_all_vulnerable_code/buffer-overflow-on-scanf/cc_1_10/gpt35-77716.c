//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

int main() {

    unsigned int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    
    printf("Enter sixteen 1s or 0s (Press enter after each input):\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p);
    
    printf("Numbers entered: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
    
    // NOT operation
    printf("\nNOT of the first number: %d\n", ~a);
    printf("NOT of the fifth number: %d\n", ~e);
    
    // AND operation
    printf("\nAND of first and second number: %d\n", a & b);
    printf("AND of third and fourth number: %d\n", c & d);
    printf("AND of fifth and sixth number: %d\n", e & f);
    printf("AND of seventh and eighth number: %d\n", g & h);
    printf("AND of ninth and tenth number: %d\n", i & j);
    printf("AND of eleventh and twelfth number: %d\n", k & l);
    printf("AND of thirteenth and fourteenth number: %d\n", m & n);
    printf("AND of fifteenth and sixteenth number: %d\n", o & p);
    
    // OR operation
    printf("\nOR of first and second number: %d\n", a | b);
    printf("OR of third and fourth number: %d\n", c | d);
    printf("OR of fifth and sixth number: %d\n", e | f);
    printf("OR of seventh and eighth number: %d\n", g | h);
    printf("OR of ninth and tenth number: %d\n", i | j);
    printf("OR of eleventh and twelfth number: %d\n", k | l);
    printf("OR of thirteenth and fourteenth number: %d\n", m | n);
    printf("OR of fifteenth and sixteenth number: %d\n", o | p);
    
    // XOR operation
    printf("\nXOR of first and second number: %d\n", a ^ b);
    printf("XOR of third and fourth number: %d\n", c ^ d);
    printf("XOR of fifth and sixth number: %d\n", e ^ f);
    printf("XOR of seventh and eighth number: %d\n", g ^ h);
    printf("XOR of ninth and tenth number: %d\n", i ^ j);
    printf("XOR of eleventh and twelfth number: %d\n", k ^ l);
    printf("XOR of thirteenth and fourteenth number: %d\n", m ^ n);
    printf("XOR of fifteenth and sixteenth number: %d\n", o ^ p);

    // Left shift
    printf("\nLeft shifting the first number by 3 bits: %d\n", a << 3);
    printf("Left shifting the eighth number by 2 bits: %d\n", h << 2);
    
    // Right shift
    printf("\nRight shifting the second number by 4 bits: %d\n", b >> 4);
    printf("Right shifting the fifteenth number by 7 bits: %d\n", o >> 7);
    
    return 0;
}