//FormAI DATASET v1.0 Category: Bitwise operations ; Style: decentralized
#include <stdio.h>

//Bitwise AND of two numbers
int bitwise_AND(int x, int y){
    return (x & y);
}

//Bitwise OR of two numbers
int bitwise_OR(int x, int y){
    return (x | y);
}

//Bitwise XOR of two numbers
int bitwise_XOR(int x, int y){
    return (x ^ y);
}

//Bitwise NOT of a number
int bitwise_NOT(int x){
    return (~x);
}

//Bitwise Left Shift of a number
int bitwise_LShift(int x, int shift){
    return (x << shift);
}

//Bitwise Right Shift of a number
int bitwise_RShift(int x, int shift){
    return (x >> shift);
}

int main(){

    int x, y;
    printf("Enter the value of x : ");
    scanf("%d",&x);
    printf("Enter the value of y : ");
    scanf("%d",&y);

    printf("\nBitwise Operations on x = %d, y = %d\n", x, y);

    printf("\nx & y : %d\n", bitwise_AND(x, y));
    printf("x | y : %d\n", bitwise_OR(x, y));
    printf("x ^ y : %d\n", bitwise_XOR(x, y));
    printf("~x   : %d\n", bitwise_NOT(x));
    printf("x << 2 : %d\n", bitwise_LShift(x, 2));
    printf("x >> 2 : %d\n", bitwise_RShift(x, 2));

    return 0;
}