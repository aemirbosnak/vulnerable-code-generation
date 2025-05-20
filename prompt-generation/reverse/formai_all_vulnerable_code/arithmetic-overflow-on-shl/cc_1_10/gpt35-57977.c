//FormAI DATASET v1.0 Category: Bitwise operations ; Style: protected
#include <stdio.h>

// Functions to calculate bitwise operations
int andGate(int a, int b) {
    return a & b;
}

int orGate(int a, int b) {
    return a | b;
}

int xorGate(int a, int b) {
    return a ^ b;
}

int notGate(int a) {
    return ~a;
}

int shiftLeft(int a, int b) {
    return a << b;
}

int shiftRight(int a, int b) {
    return a >> b;
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n--- Bitwise Operations on %d and %d ---\n", a, b);

    // AND Gate
    printf("\nAND Gate: %d & %d = %d\n", a, b, andGate(a, b));

    // OR Gate
    printf("\nOR Gate: %d | %d = %d\n", a, b, orGate(a, b));

    // XOR Gate
    printf("\nXOR Gate: %d ^ %d = %d\n", a, b, xorGate(a, b));

    // NOT Gate
    printf("\nNOT Gate: ~%d = %d && ~%d = %d\n", a, notGate(a), b, notGate(b));

    // Shift Left
    printf("\nShift Left: %d << %d = %d && %d << %d = %d\n", a, b, shiftLeft(a, b), b, a, shiftLeft(b, a));

    // Shift Right
    printf("\nShift Right: %d >> %d = %d && %d >> %d = %d\n", a, b, shiftRight(a, b), b, a, shiftRight(b, a));

    return 0;
}