//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include<stdio.h>

//function to print binary representation of a number
void printBinary(int n) {
    for(int i=31; i>=0; i--) {
        if(n & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

//function to swap two numbers using XOR operation
void swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

//function to check if a number is power of 2 or not
int isPowerOfTwo(int n) {
    return (n != 0) && ((n & (n - 1)) == 0);
}

//function to get absolute value of a number using Bitwise operations
int abs(int n) {
    int mask = n >> 31;
    return (n ^ mask) - mask;
}

//function to count number of set bits in a number
int countSetBits(int n) {
    int count = 0;
    while(n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int a = 15, b = 30;
    printf("Binary representation of %d: ", a);
    printBinary(a);
    printf("\nBinary representation of %d: ", b);
    printBinary(b);
    printf("\n");
    
    printf("Swapping %d and %d using XOR operation: ", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    
    int c = 16, d = 20;
    printf("%d is power of 2: %s\n", c, isPowerOfTwo(c) ? "true" : "false");
    printf("%d is power of 2: %s\n", d, isPowerOfTwo(d) ? "true" : "false");
    
    int e = -23, f = 45;
    printf("Absolute value of %d: %d\n", e, abs(e));
    printf("Absolute value of %d: %d\n", f, abs(f));
    
    int g = 12345;
    printf("Number of set bits in %d: %d\n", g, countSetBits(g));
    
    return 0;
}