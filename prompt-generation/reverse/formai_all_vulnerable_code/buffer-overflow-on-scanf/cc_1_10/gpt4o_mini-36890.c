//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

int recursiveAND(int a, int b);
int recursiveOR(int a, int b);
int recursiveXOR(int a, int b);
int recursiveNOT(int a);
int recursiveLeftShift(int a, int n);
int recursiveRightShift(int a, int n);

void printBinary(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    int a, b, n;

    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);
    
    printf("Enter number of positions to shift: ");
    scanf("%d", &n);

    printf("Bitwise AND of %d and %d is: ", a, b);
    printBinary(recursiveAND(a, b));

    printf("Bitwise OR of %d and %d is: ", a, b);
    printBinary(recursiveOR(a, b));

    printf("Bitwise XOR of %d and %d is: ", a, b);
    printBinary(recursiveXOR(a, b));

    printf("Bitwise NOT of %d is: ", a);
    printBinary(recursiveNOT(a));

    printf("Left shift of %d by %d is: ", a, n);
    printBinary(recursiveLeftShift(a, n));

    printf("Right shift of %d by %d is: ", a, n);
    printBinary(recursiveRightShift(a, n));

    return 0;
}

int recursiveAND(int a, int b) {
    if (b == 0) return 0;
    return (a & 1) + recursiveAND(a >> 1, b >> 1);
}

int recursiveOR(int a, int b) {
    if (b == 0) return a;
    return (a & 1) | recursiveOR(a >> 1, b >> 1);
}

int recursiveXOR(int a, int b) {
    if (b == 0) return a;
    return (a & 1) ^ recursiveXOR(a >> 1, b >> 1);
}

int recursiveNOT(int a) {
    return ~a;
}

int recursiveLeftShift(int a, int n) {
    if (n == 0) return a;
    return recursiveLeftShift(a << 1, n - 1);
}

int recursiveRightShift(int a, int n) {
    if (n == 0) return a;
    return recursiveRightShift(a >> 1, n - 1);
}