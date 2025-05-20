//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

//Function to display bits in binary format
void displayBits(unsigned int num) {
    for(int i=31; i>=0; i--) {
        if(num & (1<<i)) 
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    unsigned int a = 0xAAAA;
    unsigned int b = 0x5555;
    unsigned int c = 0;

    printf("Initial values of a and b: \n");
    printf("a = "); displayBits(a);
    printf("b = "); displayBits(b);
    printf("\n");

    //Bitwise operators
    c = a & b;
    printf("After performing AND operation between a and b: \n");
    printf("c = "); displayBits(c);
    printf("\n");

    c = a | b;
    printf("After performing OR operation between a and b: \n");
    printf("c = "); displayBits(c);
    printf("\n");

    c = a ^ b;
    printf("After performing XOR operation between a and b: \n");
    printf("c = "); displayBits(c);
    printf("\n");

    c = ~a;
    printf("After performing NOT operation on a: \n");
    printf("c = "); displayBits(c);
    printf("\n");

    c = a << 2;
    printf("After performing LEFT SHIFT operation on a: \n");
    printf("c = "); displayBits(c);
    printf("\n");

    c = a >> 2;
    printf("After performing RIGHT SHIFT operation on a: \n");
    printf("c = "); displayBits(c);
    printf("\n");

    return 0;
}