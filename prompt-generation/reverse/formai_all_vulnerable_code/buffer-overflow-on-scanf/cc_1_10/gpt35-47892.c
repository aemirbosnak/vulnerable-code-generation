//FormAI DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>

// Function to check if a number is odd or even
int is_even(int x) {
    return !(x & 1);
}

// Function to count the number of set bits in an integer
int count_set_bits(int x) {
    int count = 0;
    while(x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main() {
    printf("Enter two numbers: ");

    int a, b;
    scanf("%d %d", &a, &b);

    // Perform bitwise AND operation
    int and_result = a & b;
    printf("%d & %d = %d\n", a, b, and_result);

    // Perform bitwise OR operation
    int or_result = a | b;
    printf("%d | %d = %d\n", a, b, or_result);

    // Perform bitwise XOR operation
    int xor_result = a ^ b;
    printf("%d ^ %d = %d\n", a, b, xor_result);

    // Perform bitwise NOT operation on a
    int not_a = ~a;
    printf("~%d = %d\n", a, not_a);

    // Perform bitwise left shift operation on b
    int b_shifted = b << 2;
    printf("%d << 2 = %d\n", b, b_shifted);

    // Perform bitwise right shift operation on a
    int a_shifted = a >> 1;
    printf("%d >> 1 = %d\n", a, a_shifted);

    printf("Is %d even? %s\n", a, is_even(a) ? "Yes": "No");
    printf("Is %d even? %s\n", b, is_even(b) ? "Yes": "No");

    printf("Number of set bits in %d = %d\n", a, count_set_bits(a));
    printf("Number of set bits in %d = %d\n", b, count_set_bits(b));

    return 0;
}