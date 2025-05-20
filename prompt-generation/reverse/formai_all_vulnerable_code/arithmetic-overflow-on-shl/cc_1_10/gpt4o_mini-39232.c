//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>

void print_binary(int n) {
    for(int i = 31; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

int bitwise_and(int a, int b) {
    return a & b;
}

int bitwise_or(int a, int b) {
    return a | b;
}

int bitwise_xor(int a, int b) {
    return a ^ b;
}

int bitwise_not(int a) {
    return ~a;
}

int left_shift(int a, int n) {
    return a << n;
}

int right_shift(int a, int n) {
    return a >> n;
}

void bitwise_operations() {
    int a, b, result;

    printf("Welcome to the Bitwise Operations Funhouse!\n");
    printf("Let's play with some numbers.\n\n");

    printf("Enter two integers:\n");
    printf("Integer A: ");
    scanf("%d", &a);
    printf("Integer B: ");
    scanf("%d", &b);
    
    printf("\nLet's see their binary representations!\n");
    printf("Binary representation of A ( %d ): ", a);
    print_binary(a);
    printf("Binary representation of B ( %d ): ", b);
    print_binary(b);

    // Bitwise AND
    result = bitwise_and(a, b);
    printf("A & B = %d -> ", result);
    print_binary(result);

    // Bitwise OR
    result = bitwise_or(a, b);
    printf("A | B = %d -> ", result);
    print_binary(result);

    // Bitwise XOR
    result = bitwise_xor(a, b);
    printf("A ^ B = %d -> ", result);
    print_binary(result);
    
    // Bitwise NOT
    result = bitwise_not(a);
    printf("~A = %d -> ", result);
    print_binary(result);

    result = bitwise_not(b);
    printf("~B = %d -> ", result);
    print_binary(result);

    // Left Shift
    int shift_amount;
    printf("Enter an amount to shift A left: ");
    scanf("%d", &shift_amount);
    result = left_shift(a, shift_amount);
    printf("A << %d = %d -> ", shift_amount, result);
    print_binary(result);

    // Right Shift
    printf("Enter an amount to shift A right: ");
    scanf("%d", &shift_amount);
    result = right_shift(a, shift_amount);
    printf("A >> %d = %d -> ", shift_amount, result);
    print_binary(result);
    
    printf("\nThanks for playing with Bitwise Operations!\n");
    printf("Remember, in the world of numbers, every bit counts!\n");
}

int main() {
    bitwise_operations();
    return 0;
}